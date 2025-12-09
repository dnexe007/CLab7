#ifndef CLIENT_H
#define CLIENT_H

#include "transaction.h" 
#include <stdio.h>

typedef struct Client
{
    int id;
    char fname[30];
    char sname[30];
    char lname[30];
    int trCount;
    Transaction* trList;
} Client;


Client* ReadClient(FILE* f);

#endif