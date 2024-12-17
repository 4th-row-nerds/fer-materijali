#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FREQ_LEN 256
#define min(x, y) ((x) < (y) ? (x) : (y))

bool anagram(char *s1, char *s2, size_t *istih_ch) {

    // Broj pojavljivanja slova u nizovima s1 i s2 za svako slovo u ASCII-u
    size_t f_s1[FREQ_LEN] = {0};
    size_t f_s2[FREQ_LEN] = {0};

    // Prebrojavanje znakova za s1
    for (size_t i = 0; i < strlen(s1); i++) {
        // Element s indeksom istim kao i trenutni znak povecavamo, time prebrojavamo pojavljivanje tog znaka
        f_s1[(size_t)s1[i]] += 1;
    }

    // Prebrojavanje znakova za s2
    for (size_t i = 0; i < strlen(s2); i++) {
        // Element s indeksom istim kao i trenutni znak povecavamo, time prebrojavamo pojavljivanje tog znaka
        f_s2[(size_t)s2[i]] += 1;
    }

    *istih_ch = 0;
    for (size_t i = 0; i < FREQ_LEN; i++) {
        // Ima onoliko istih znakova koliko ima znakova u onom nizu koji ih ima manje
        *istih_ch += min(f_s1[i], f_s2[i]);
    }

    if (*istih_ch == strlen(s1)) return true;
    else return false;
}

int main(void) {

	printf("Unesi dvije rijeci > \n");
    char s1[24], s2[24];
    scanf("%s %s", s1, s2);

    size_t istih_ch;
    if (anagram(s1, s2, &istih_ch)) {
	    printf("Anagrami.\n");
    } else {
        printf("Nisu anagrami.\n");
    }
	printf("Broj podudaranja: %zu", istih_ch);
	return 0;
}
