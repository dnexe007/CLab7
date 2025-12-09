#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "datetime.h"

typedef struct Transaction {
    Date date;
    Time time;
    int type;
    float sum;
} Transaction;

Transaction ParseTransaction(const char* str);

#endif