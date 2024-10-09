#include "../inc/pathfinder.h"

void pf_error_exit(enum e_ErrCode err, const char *filename, char *data, int line, int islands_count, void *all_paths) {
    if (data != NULL) free(data);
    if (all_paths != NULL) {
        s_PathSet(*all_paths_ptr)[islands_count] = (s_PathSet(*)[islands_count])all_paths;

        for (int i = 0; i < islands_count; i++) {
            for (int j = 0; j < islands_count; j++) {
                if (all_paths_ptr[i][j].paths != NULL) {
                    for (int k = 0; k < all_paths_ptr[i][j].count; k++) {
                        if (all_paths_ptr[i][j].paths[k].path != NULL) free(all_paths_ptr[i][j].paths[k].path);
                    }
                    free(all_paths_ptr[i][j].paths);
                }
            }
        }
    }

    switch (err) {
    case EInvalArg:
        write(1, "usage: ./pathfinder [filename]\n", 31);
        break;
    case ENoFile:
        pf_print(filename, false);
        write(1, ": No such file or directory\n", 28);
        break;
    case EFileEmpty:
        write(1, "error: file ", 12);
        pf_print(filename, false);
        write(1, " is empty\n", 10);
        break;
    case EInvalLine:
        write(1, "error: line ", 12);
        pf_print(line, false);
        write(1, " is not valid\n", 14);
        break;
    case EInvalIslandCount:
        write(1, "error: invalid number of islands\n", 33);
        break;
    case EDupBridge:
        write(1, "error: duplicate bridges\n", 25);
        break;
    case ETotalCostOverflow:
        write(1, "error: sum of bridges lengths is too big\n", 41);
        break;
    default:
        write(1, "error: unknown error\n", 21);
        break;
    }

    exit(-1);
}
