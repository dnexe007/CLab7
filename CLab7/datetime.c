#define _CRT_SECURE_NO_WARNINGS
#include "datetime.h"
#include <stdio.h>  


Time ParseTime(const char* str) {
    Time time;
    
    sscanf(str, "%d:%d:%d", &time.h, &time.m, &time.s);
    return time;
}

Date ParseDate(const char* str) {
    Date date;
    int d, m, y = NULL;
    sscanf(str, "%d.%d.%d", &d, &m, &y);
    date.d = d;
    date.m = m;
    date.y = y;
    return date;
}

int CompareDates(Date d1, Date d2) {
    if (d1.y != d2.y) {
        return(d1.y > d2.y) ? 1 : -1;
    }
    if (d1.m != d2.m) {
        return(d1.m > d2.m) ? 1 : -1;
    }
    if (d1.d != d2.d) {
        return(d1.d > d2.d) ? 1 : -1;
    }
    return 0;
}