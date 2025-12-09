#define _CRT_SECURE_NO_WARNINGS
#include "datetime.h"
#include <stdio.h>  


Time ParseTime(const char* str, int* isCorrect)
{
    Time time = {0, 0, 0};
    int parsed = sscanf(str, "%d:%d:%d", &time.h, &time.m, &time.s);
    *isCorrect = parsed == 3;
    return time;
}

Date ParseDate(const char* str, int* isCorrect)
{
    Date date = { 0, 0, 0 };
    int parsed = sscanf(str, "%d.%d.%d", &date.d, &date.m, &date.y);
    *isCorrect = parsed == 3;
    return date;
}

int CompareDates(Date d1, Date d2)
{
    if (d1.y != d2.y) 
        return(d1.y > d2.y) ? 1 : -1;
    if (d1.m != d2.m) 
        return(d1.m > d2.m) ? 1 : -1;
    if (d1.d != d2.d) 
        return(d1.d > d2.d) ? 1 : -1;
    return 0;
}