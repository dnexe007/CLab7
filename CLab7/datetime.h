#ifndef DATETIME_H
#define DATETIME_H

typedef struct Time {
    int h;
    int m;
    int s;
} Time;

typedef struct Date {
    int d;
    int m;
    int y;
} Date;

Time ParseTime(const char* str);
Date ParseDate(const char* str);
int CompareDates(Date d1, Date d2);

#endif