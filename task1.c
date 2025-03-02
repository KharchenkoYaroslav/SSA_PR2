#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>

int main() {
    time_t max_time = (time_t)((1ULL << (sizeof(time_t) * 8 - 1)) - 1);

    printf("Max time_t value: %lld\n", (long long)max_time);

    char *time_str = ctime(&max_time);
    if (time_str == NULL) {
        printf("ctime() returned NULL (invalid time value)\n");
    } else {
        printf("Time_t will overflow on: %s", time_str);
    }

    return 0;
}
