#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct classroom {
    int id;
    int cap;
};

struct course {
    int id;
    int people;
    int start;
    int end;
    int len;
};

struct result {
    int cid;
    int rid;
};

int best_hours = 0;
int best_count = 0;
struct result *final_result;
int final_cnt = 0;

int cmp_result(const void *a, const void *b) {
    struct result *x = (struct result *)a;
    struct result *y = (struct result *)b;
    return x->cid - y->cid;
}

int time_overlap(struct course *a, struct course *b) {
    return (a->start < b->end && a->end > b->start);
}

void solve(struct course *courses, struct classroom *rooms, int n, int m, int check_cap,
           int idx, int *room_assign, struct result *temp_result,
           int result_cnt, int cur_hours, int cur_count) {

    if (cur_hours > best_hours || (cur_hours == best_hours && cur_count > best_count)) {
        best_hours = cur_hours;
        best_count = cur_count;
        final_cnt = result_cnt;
        memcpy(final_result, temp_result, result_cnt * sizeof(struct result));
    }

    if (idx >= n) return;

    // skip current course
    solve(courses, rooms, n, m, check_cap, idx + 1, room_assign, temp_result,
          result_cnt, cur_hours, cur_count);

    // try assign current course to each room
    for (int r = 0; r < m; r++) {
        if (check_cap && courses[idx].people > rooms[r].cap) continue;

        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (room_assign[i] == r && time_overlap(&courses[idx], &courses[i])) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            room_assign[idx] = r;
            temp_result[result_cnt].cid = courses[idx].id;
            temp_result[result_cnt].rid = rooms[r].id;

            solve(courses, rooms, n, m, check_cap, idx + 1, room_assign, temp_result,
                  result_cnt + 1, cur_hours + courses[idx].len, cur_count + 1);

            room_assign[idx] = -1;
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    struct classroom *rooms = malloc(m * sizeof(struct classroom));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &rooms[i].id, &rooms[i].cap);
    }

    struct course *courses = malloc(n * sizeof(struct course));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &courses[i].id, &courses[i].people,
              &courses[i].start, &courses[i].end);
        courses[i].len = courses[i].end - courses[i].start;
    }

    int b;
    scanf("%d", &b);

    int *room_assign = malloc(n * sizeof(int));
    struct result *temp_result = malloc(n * sizeof(struct result));
    final_result = malloc(n * sizeof(struct result));

    for (int i = 0; i < n; i++) room_assign[i] = -1;

    solve(courses, rooms, n, m, (b > 0), 0, room_assign, temp_result, 0, 0, 0);

    printf("max hours %d\n", best_hours);
    printf("max courses %d\n", best_count);

    if (b == 2) {
        qsort(final_result, final_cnt, sizeof(struct result), cmp_result);
        for (int i = 0; i < final_cnt; i++) {
            printf("%d %d\n", final_result[i].cid, final_result[i].rid);
        }
    }

    free(rooms);
    free(courses);
    free(room_assign);
    free(temp_result);
    free(final_result);

    return 0;
}
