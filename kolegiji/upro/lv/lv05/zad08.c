#include <stdlib.h>
#include <stdio.h>

int najmanjiElement(int *polje, size_t len, size_t *koliko) {

    int min = polje[0];
    *koliko = 0;

    for (size_t i = 0; i < len; i++) {
        if (min > polje[i]) {
            min = polje[i];
            *koliko = 1;
        } else if (min == polje[i]) {
            *koliko += 1;
        }
    }

   return min;
}

int main(void) {
	printf("Unesi velicinu niza > \n");
    size_t len;
    scanf("%zu", &len);

    int polje[len];
    printf("Unesi elemente niza > \n");
    for (size_t i = 0; i < len; i++) {
        scanf("%d", &polje[i]);
    }

    size_t koliko;
    int el = najmanjiElement(polje, len, &koliko);
    printf("Najmanji element %d s %zu ponavljanja.", el, koliko);
    return 0;
}
