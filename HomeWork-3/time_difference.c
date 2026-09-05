#include <stdio.h>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

int main()
{
    struct Time t1, t2, diff;

    printf("Enter first time (HH MM SS): ");
    scanf("%d %d %d",
          &t1.hours, &t1.minutes, &t1.seconds);

    printf("Enter second time (HH MM SS): ");
    scanf("%d %d %d",
          &t2.hours, &t2.minutes, &t2.seconds);

    /* Make sure t1 is greater than t2 */
    if (t1.hours < t2.hours ||
        (t1.hours == t2.hours && t1.minutes < t2.minutes) ||
        (t1.hours == t2.hours &&
         t1.minutes == t2.minutes &&
         t1.seconds < t2.seconds))
    {
        struct Time temp = t1;
        t1 = t2;
        t2 = temp;
    }

    /* Borrow seconds */
    if (t1.seconds < t2.seconds)
    {
        t1.minutes--;
        t1.seconds += 60;
    }

    diff.seconds = t1.seconds - t2.seconds;

    /* Borrow minutes */
    if (t1.minutes < t2.minutes)
    {
        t1.hours--;
        t1.minutes += 60;
    }

    diff.minutes = t1.minutes - t2.minutes;
    diff.hours = t1.hours - t2.hours;

    printf("\nTime Difference = %02d:%02d:%02d\n",
           diff.hours,
           diff.minutes,
           diff.seconds);

    return 0;
}