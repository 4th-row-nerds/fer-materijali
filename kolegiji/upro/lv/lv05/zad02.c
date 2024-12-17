#include <stdio.h>

void BrojSlovaZnamenaka(char *niz, int *brojSlova, int *brojZnamenaka) {
    *brojZnamenaka = 0;
    *brojSlova = 0;
    for(int i = 0; *(niz + i) != '\0'; i++) {
        if(*(niz + i) >= 'a' && *(niz + i) <= 'z') {
            *brojSlova += 1;
        }
        else if(*(niz + i) >= 'A' && *(niz + i) <= 'Z') {
            *brojSlova += 1;
        }
        else if(*(niz + i) >= '0' && *(niz + i) <= '9') {
            *brojZnamenaka += 1;
        }
    }

    return;
}
