#define _CRT_SECURE_NO_WARNINGS
#include "transaction.h"
#include "datetime.h"    
#include <stdio.h>      
#include <string.h>    

Transaction ParseTransaction(const char* str) {
    Transaction tr;
    char date[20], time[20], type_str[20];
    float sum;

    sscanf(str, "%19s %19s %19s %f", date, time, type_str, &sum);
    tr.time = ParseTime(time);
    tr.date = ParseDate(date);
    tr.sum = sum;


    if (strcmp(type_str, "Приход") == 0) {
        tr.type = 1;
    }
    else if (strcmp(type_str, "Расход") == 0) {
        tr.type = -1;
    }
    else {
        tr.type = 0;
    }

    return tr;
}