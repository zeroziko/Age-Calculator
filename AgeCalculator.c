#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Variables for birth date, current date, and day count
    int year_b, month_b, day_b, k = 0;
    int temp_month, temp_year, temp_day;

    printf("Please enter your date of birth:\n");
    printf("Day: ");
    do {
        scanf("%d", &day_b);
        if (day_b > 31 || day_b < 1) {
            printf("Day should be between 1 and 31: ");
        }
    } while (day_b > 31 || day_b < 1);

    printf("Month: ");
    do {
        scanf("%d", &month_b);
        if (month_b > 12 || month_b < 1) {
            printf("Month should be between 1 and 12: ");
        }
    } while (month_b > 12 || month_b < 1);

    printf("Year: ");
    do {
        scanf("%d", &year_b);
        if (year_b > tm.tm_year + 1900 || year_b < 1900) {
            printf("Year should be between 1900 and %d: ", tm.tm_year + 1900);
        }
        temp_day = day_b;
        temp_month = month_b;
        temp_year = year_b;
    } while (year_b > tm.tm_year + 1900 || year_b < 1900);

    // Calculate the age in days
    while (1) {
        if (year_b == tm.tm_year + 1900 && month_b == tm.tm_mon + 1 && day_b == tm.tm_mday) {
            break;
        }

        day_b++;

        if (day_b > 31 && (month_b == 1 || month_b == 3 || month_b == 5 || month_b == 7 || month_b == 8 || month_b == 10 || month_b == 12)) {
            month_b++;
            day_b = 1;
        } else if (day_b > 30 && (month_b == 4 || month_b == 6 || month_b == 9 || month_b == 11)) {
            month_b++;
            day_b = 1;
        } else if (day_b > 28 && month_b == 2) {
            if ((year_b % 4 == 0 && year_b % 100 != 0) || (year_b % 400 == 0)) {
                if (day_b > 29) {
                    month_b++;
                    day_b = 1;
                }
            } else {
                month_b++;
                day_b = 1;
            }
        }

        if (month_b > 12) {
            year_b++;
            day_b = 1;
            month_b = 1;
        }

        k++; // Increment day count
    }

    // Calculate the age in years, months, and days
    if (tm.tm_mon + 1 >= temp_month && tm.tm_mday >= temp_day && tm.tm_year + 1900 >= temp_year) {
        printf("Your age is %d Years %d Months %d Days\n\n", (tm.tm_year + 1900) - temp_year, (tm.tm_mon + 1) - temp_month, tm.tm_mday - temp_day);
    }

    if (tm.tm_mon + 1 > temp_month && tm.tm_mday < temp_day && tm.tm_year + 1900 >= temp_year) {
        tm.tm_mday += 30;
        printf("Your age is %d Years %d Months %d Days\n\n", (tm.tm_year + 1900) - temp_year, (tm.tm_mon) - temp_month, tm.tm_mday - temp_day);
    }

    if (tm.tm_mon + 1 <= temp_month && tm.tm_mday < temp_day && tm.tm_year + 1900 >= temp_year) {
        tm.tm_mday += 30;
        tm.tm_mon += 12;
        tm.tm_year = (tm.tm_year + 1900) - 1;
        printf("Your age is %d Years %d Months %d Days\n\n", (tm.tm_year) - temp_year, (tm.tm_mon) - temp_month, tm.tm_mday - temp_day);
    }

    // Print the age in total days
    printf("Your age in days is: %d\n", k);

    return 0;
}
