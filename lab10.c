
#include <stdio.h>

int isLeapYear(int year)
{
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
        return 1;

    return 0;
}

int getFirstDay(int year)
{
    int day = 1;

    for (int y = 1; y < year; y++)
    {
        day += isLeapYear(y) ? 366 : 365;
    }

    return day % 7;
}

int main()
{
    int year, firstDay, days, month;

    char *months[] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    int monthDays[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    printf("Enter year: ");
    scanf("%d", &year);

    if (year < 1)
    {
        printf("Invalid year!");
        return 0;
    }

    if (isLeapYear(year))
        monthDays[1] = 29;

    firstDay = getFirstDay(year);

    printf("\nCALENDAR FOR YEAR %d\n", year);

    for (month = 0; month < 12; month++)
    {
        printf("\n\n      %s\n", months[month]);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        for (int i = 0; i < firstDay; i++)
            printf("    ");

        days = monthDays[month];

        for (int date = 1; date <= days; date++)
        {
            printf("%3d ", date);

            firstDay++;

            if (firstDay == 7)
            {
                firstDay = 0;
                printf("\n");
            }
        }
    }

    printf("\n");
    return 0;
}
