#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "datetime.h"
#include "transaction.h"
#include "client.h"


int main() {
    FILE* f;
    f = fopen("db.txt", "r");

    Client** db = NULL;
    int count = 0;
    for (;;) {
        Client* client = ReadClient(f);
        if (client != NULL) {
            db = realloc(db, ++count * sizeof(*client));
            db[count - 1] = client;
        }
        else break;
    }

    int id = NULL;
    char date_from[20], date_to[20];
    printf("Enter client data: ");
    scanf("%d %19s %19s", &id, date_from, date_to);
    
    Date df = ParseDate(date_from);
    Date dt = ParseDate(date_to);

    

    if
    (
        id == NULL ||
        df.d == NULL || df.m == NULL || df.y == NULL||
        dt.d == NULL || dt.m == NULL || dt.y == NULL
    ) 
    {

        printf("parsing error");
        return 0;
    }

    int isFound = 0;
    for (int i = 0; i < count; i++) {

        Client* cur = db[i];
        if (cur->id == id) {
            isFound = 1;
            float sum = 0;

            for (int j = 0; j < cur->trCount; j++) {
                Transaction tr = cur->trList[j];
                Date dc = tr.date;
                if (CompareDates(df, dc) <= 0 && CompareDates(dc, dt) <= 0)
                    sum += tr.sum * tr.type;
            }
            printf("Result: %f", sum);
        }

    }
    if (!isFound) printf("id is not found");

    fclose(f);
    return 0;

}