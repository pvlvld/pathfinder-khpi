#include "../inc/pathfinder.h"

static inline void init_all_paths(int num_islands, s_PathSet all_paths[num_islands][num_islands]) {
    for (int i = 0; i < num_islands; i++) {
        for (int j = 0; j < num_islands; j++) {
            all_paths[i][j].count = 0;
            all_paths[i][j].capacity = num_islands * num_islands;
            all_paths[i][j].paths = NULL;
        }
    }
}

static inline void add_path(s_PathSet *ps, s_Path *path, int num_islands) {
    if (ps->paths == NULL) {
        ps->paths = malloc(sizeof(s_Path) * ps->capacity);
        if (ps->paths == NULL) return;
    }
    if (ps->count < ps->capacity) {
        s_Path new_path;
        new_path.length = path->length;
        new_path.distance = path->distance;
        new_path.path = malloc(sizeof(int) * num_islands);
        if (new_path.path == NULL) return;
        for (int i = 0; i < path->length; i++) { new_path.path[i] = path->path[i]; }
        ps->paths[ps->count++] = new_path;
    }
}

static inline void find_all_paths(int start, int end, int num_islands, int cost_matrix[num_islands][num_islands],
                                  int visited[num_islands], s_Path *current_path,
                                  s_PathSet all_paths[num_islands][num_islands]) {
    if (start == end) {
        s_PathSet *ps = &all_paths[current_path->path[0]][end];
        if (ps->count == 0 || current_path->distance < ps->paths[0].distance) {
            // New shortest
            for (int i = 0; i < ps->count; i++) free(ps->paths[i].path);
            ps->count = 0;
            add_path(ps, current_path, num_islands);
        } else if (current_path->distance == ps->paths[0].distance) {
            // Same length shortest
            add_path(ps, current_path, num_islands);
        }
        return;
    }

    visited[start] = 1;

    for (int next = 0; next < num_islands; next++) {
        if (!visited[next] && cost_matrix[start][next] > 0) {
            int new_distance = current_path->distance + cost_matrix[start][next];

            if (all_paths[current_path->path[0]][end].count == 0 ||
                new_distance <= all_paths[current_path->path[0]][end].paths[0].distance) {
                current_path->path[current_path->length++] = next;
                current_path->distance = new_distance;

                find_all_paths(next, end, num_islands, cost_matrix, visited, current_path, all_paths);

                current_path->length--;
                current_path->distance -= cost_matrix[start][next];
            }
        }
    }

    visited[start] = 0;
}

static inline void find_all_pairs_shortest_paths(int num_islands, int cost_matrix[num_islands][num_islands],
                                                 s_PathSet all_paths[num_islands][num_islands]) {
    init_all_paths(num_islands, all_paths);
    for (int start = 0; start < num_islands - 1; start++) {
        for (int end = start + 1; end < num_islands; end++) {
            int visited[num_islands];
            for (int i = 0; i < num_islands; i++) visited[i] = 0;

            int path[num_islands];
            s_Path current_path = {path, 1, 0};
            current_path.path[0] = start;

            find_all_paths(start, end, num_islands, cost_matrix, visited, &current_path, all_paths);
        }
    }
}

static inline void print_all_paths(int num_islands, char *island_names[], int cost_matrix[num_islands][num_islands],
                                   s_PathSet all_paths[num_islands][num_islands]) {
    for (int start = 0; start < num_islands; start++) {
        for (int end = 0; end < num_islands; end++) {
            if (start != end) {
                s_PathSet *ps = &all_paths[start][end];
                for (int i = 0; i < ps->count; i++) {
                    s_Path *path = &ps->paths[i];
                    write(1, SEPARATOR_LINE, 41);
                    write(1, "Path: ", 6);
                    pf_print(island_names[start], false);
                    write(1, " -> ", 4);
                    pf_print(island_names[end], true);

                    write(1, "Route: ", 7);
                    for (int j = 0; j < path->length; j++) {
                        pf_print(island_names[path->path[j]], false);
                        if (j < path->length - 1) write(1, " -> ", 4);
                    }

                    write(1, "\nDistance: ", 11);
                    if (path->length > 2) {
                        for (int j = 0; j < path->length - 1; j++) {
                            pf_print(cost_matrix[path->path[j]][path->path[j + 1]], false);
                            if (j < path->length - 2) write(1, " + ", 3);
                        }
                        write(1, " = ", 3);
                    }
                    pf_print(path->distance, true);
                    write(1, SEPARATOR_LINE, 41);
                }
            }
        }
    }
}

static inline char *pf_parse_filename(int argc, char *argv[]) {
    if (argc < 2) pf_error_exit(EInvalArg, NULL, NULL, 0, 0, NULL);
    return argv[1];
}

static inline int push_island_name(int size, char *islands[size], char *name, int *unique_islands) {
    for (int i = 0; i < size; i++) {
        if (islands[i] && mx_strcmp(islands[i], name) == 0) { return i; }
    }
    for (int i = 0; i < size; i++) {
        if (!islands[i]) {
            islands[i] = name;
            *unique_islands += 1;
            return i;
        }
    }
    return -1;
}

static inline short push_path_cost(int size, int cost_matrix[size][size], int i1_idx, int i2_idx, char *cost_s,
                                   size_t *total_cost) {
    int cost_i = pf_atoi(cost_s);
    if (cost_i <= 0) return -1;                      // data error
    if (cost_matrix[i1_idx][i2_idx] != 0) return -2; // duplicated bridges
    cost_matrix[i1_idx][i2_idx] = cost_i;
    cost_matrix[i2_idx][i1_idx] = cost_i;
    *total_cost += cost_i;
    volatile bool overflow = (size_t)*total_cost < (size_t)cost_i;
    if (overflow || *total_cost > INT_MAX) return -3; // total cost is too big
    return 0;
}

static inline void init_iarray(int size, int arr[size]) {
    while (size-- > 0) arr[size] = 0;
}

static inline void init_sarray(int size, char *arr[size]) {
    while (size-- > 0) arr[size] = NULL;
}

static inline void init_matrix(int size, int matrix[size][size]) {
    for (int i = 0; i < size; i++) init_iarray(size, matrix[i]);
}

static inline char *extract_until_delim(char **ptr, int *remaining_len, char delimiter) {
    int d_idx = -1;
    switch (delimiter) {
    case '\n':
        d_idx = pf_memchridx(*ptr, delimiter, *remaining_len, NULL);
        break;
    case ',':
        d_idx = pf_memchridx(*ptr, delimiter, *remaining_len, pf_is_letter);
        break;
    case '-':
        d_idx = pf_memchridx(*ptr, delimiter, *remaining_len, pf_is_letter);
        break;
    }
    if (d_idx == -1 || d_idx >= *remaining_len) return NULL;
    (*ptr)[d_idx] = '\0';
    char *result = *ptr;
    *ptr += d_idx + 1;
    *remaining_len -= d_idx + 1;
    return result;
}

static inline void free_all(int islands_count, char *data, s_PathSet all_paths[islands_count][islands_count]) {
    for (int i = 0; i < islands_count; i++) {
        for (int j = 0; j < islands_count; j++) {
            for (int k = 0; k < all_paths[i][j].count; k++) free(all_paths[i][j].paths[k].path);
            free(all_paths[i][j].paths);
        }
    }
    free(data);
}

int main(int argc, char *argv[]) {
    int len = 0;
    int remaining_len = 0;
    int islands_count = 0;
    int line_counter = 1;
    size_t total_cost = 0;
    int unique_islands = 0;
    char *str = pf_file_to_str(pf_parse_filename(argc, argv), &len);

    char *ptr = str;
    remaining_len = len;

    char *i_count = extract_until_delim(&ptr, &remaining_len, '\n');
    islands_count = pf_atoi(i_count);
    if (errno == 69) pf_error_exit(EInvalIslandCount, NULL, str, line_counter, 0, NULL);
    if (errno == 420) pf_error_exit(EInvalLine, NULL, str, line_counter, 0, NULL);
    if (islands_count <= 0) pf_error_exit(EInvalLine, NULL, str, line_counter, 0, NULL);

    char *islands[islands_count];
    int cost_matrix[islands_count][islands_count];
    s_PathSet all_paths[islands_count][islands_count];

    init_sarray(islands_count, islands);
    init_matrix(islands_count, cost_matrix);

    while (++line_counter) {
        char *island1 = extract_until_delim(&ptr, &remaining_len, '-');
        if (island1 == NULL || *island1 == '\0')
            pf_error_exit(EInvalLine, NULL, str, line_counter, islands_count, NULL);
        char *island2 = extract_until_delim(&ptr, &remaining_len, ',');
        if (island2 == NULL || *island2 == '\0')
            pf_error_exit(EInvalLine, NULL, str, line_counter, islands_count, NULL);

        if (mx_strcmp(island1, island2) == 0) pf_error_exit(EInvalLine, NULL, str, line_counter, islands_count, NULL);

        char *cost_s = extract_until_delim(&ptr, &remaining_len, '\n');
        // if (cost == NULL) cost = extract_until_delim(&ptr, &remaining_len, '\0'); // out of bound read?!
        if (cost_s == NULL) {
            cost_s = ptr;
            remaining_len = 0;
        };

        int i1_idx = push_island_name(islands_count, islands, island1, &unique_islands);
        int i2_idx = push_island_name(islands_count, islands, island2, &unique_islands);
        if (i2_idx == -1 || i1_idx == -1)
            pf_error_exit(EInvalIslandCount, NULL, str, line_counter, islands_count, NULL);
        short path_cost_status = push_path_cost(islands_count, cost_matrix, i1_idx, i2_idx, cost_s, &total_cost);
        if (path_cost_status == -1) pf_error_exit(EInvalLine, NULL, str, line_counter, islands_count, NULL);
        if (path_cost_status == -2) pf_error_exit(EDupBridge, NULL, str, line_counter, islands_count, NULL);
        if (path_cost_status == -3) pf_error_exit(ETotalCostOverflow, NULL, str, line_counter, islands_count, NULL);
        if (remaining_len <= 0) break;
    }

    if (unique_islands != islands_count) pf_error_exit(EInvalIslandCount, NULL, str, 0, islands_count, NULL);
    find_all_pairs_shortest_paths(islands_count, cost_matrix, all_paths);
    print_all_paths(islands_count, islands, cost_matrix, all_paths);

    free_all(islands_count, str, all_paths);

    return 0;
}
