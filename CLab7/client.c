#define _CRT_SECURE_NO_WARNINGS
#include "client.h"
#include <stdio.h>    
#include <stdlib.h>  
#include <string.h> 

Client* ReadClient(FILE* f) {
    Client* client = (Client*)malloc(sizeof(Client));
    char buffer[100];


    if (fgets(buffer, sizeof(buffer), f) == NULL) {
        free(client);
        return NULL;
    }
    sscanf(buffer, "%d", &client->id);


    if (fgets(buffer, sizeof(buffer), f) == NULL) {
        free(client);
        return NULL;
    }
    sscanf(buffer, "%29s %29s %29s", client->fname, client->sname, client->lname);


    if (fgets(buffer, sizeof(buffer), f) == NULL) {
        free(client);
        return NULL;
    }
    sscanf(buffer, "%d", &client->trCount);


    client->trList = (Transaction*)malloc(client->trCount * sizeof(Transaction));


    for (int i = 0; i < client->trCount; i++) {
        if (fgets(buffer, sizeof(buffer), f) == NULL) {
            free(client->trList);
            free(client);
            return NULL;
        }
        client->trList[i] = ParseTransaction(buffer);
    }

    return client;
}