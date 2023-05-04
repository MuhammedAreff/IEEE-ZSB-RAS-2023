#include <stdio.h>

int main() {
    int hours, minutes, seconds;
    int time_in_seconds;

    printf("Enter time in the format [hh:mm:ss]:\n");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    time_in_seconds = hours * 3600 + minutes * 60 + seconds;

    printf("The time you entered is: %02d:%02d:%02d\n", hours, minutes, seconds);
    printf("The time in seconds is: %d\n", time_in_seconds);

    return 0;
}