#include <stdio.h>
#include <time.h>

#define PST (-8)
#define EST (-5)
#define GMT (0)
#define SST (+8)
#define NZST (+12)

int main(int argc, char *argv[])
{
    struct tm prev_new_year, next_new_year;
    struct tm *current_time;
    clock_t c;
    c = clock();

    time_t now;
    time(&now);

    // localtime returns a pointer to a tm struct with values that represent the correspoding time
    // for the local timezone from the time_t pointer passed
    prev_new_year = *localtime(&now);
    next_new_year = *localtime(&now);

    // reset members of structs to be accurate to each new year
    prev_new_year.tm_hour = 0;
    prev_new_year.tm_min  = 0;
    prev_new_year.tm_sec  = 0;
    prev_new_year.tm_mon  = 0;
    prev_new_year.tm_mday = 1;

    next_new_year.tm_hour = 23;
    next_new_year.tm_min  = 59;
    next_new_year.tm_sec  = 59;
    next_new_year.tm_mon  = 11;
    next_new_year.tm_mday = 31;

    // get the difference in time between the current time and each new year, for next new year add
    // an hour because nex_new_year currently stores an hour before the new year
    // mktime converts a tm struct to a time_t type
    double time_since_new_year = difftime(now, mktime(&prev_new_year));
    double time_until_new_year = difftime(mktime(&next_new_year), now) + (60 * 60);

    printf("Seconds since previous new year: %.fs\n", time_since_new_year);
    printf("Seconds until next new year: %.fs\n", time_until_new_year);

    current_time = localtime(&now);
    // asctime converts the tm struct pointer to a string
    printf("\nasctim: The current date and time is %s\n", asctime(current_time));
    // ctime converts the time_t pointer to a string
    printf("\nctime: The current date and time is %s\n", ctime(&now));

    time_t timer;
    time(&timer);

    printf("\nThere have been %ld seconds since 1 January 1970\n", timer);

    struct tm *tm_p;

    // gmtime returns a pointer to a tm struct with values that represent the correspoding time
    // for UTC from the time_t pointer passed
    tm_p = gmtime(&now);

    printf("\nWorld times:\n");
    printf("PST:  %02d:%02d\n", (tm_p->tm_hour + PST) % 24, tm_p->tm_min);
    printf("EST:  %02d:%02d\n", (tm_p->tm_hour + EST) % 24, tm_p->tm_min);
    printf("GMT:  %02d:%02d\n", (tm_p->tm_hour + GMT) % 24, tm_p->tm_min);
    printf("SST:  %02d:%02d\n", (tm_p->tm_hour + SST) % 24, tm_p->tm_min);
    printf("NZST: %02d:%02d\n", (tm_p->tm_hour + NZST) % 24, tm_p->tm_min);

    c = clock() - c;
    float seconds = (float)c / CLOCKS_PER_SEC;
    printf("\nUsing clock(): Program completed in %lu clicks (%f seconds)\n", c, seconds);

    return 0;
}
