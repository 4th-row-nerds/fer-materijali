#include <stdio.h>

void PomicniProsjek(double const *ulaz, double *izlaz, const size_t len, int prozor) {
    for (size_t i = 0; i < len; i++) {
        double sum = 0;
        size_t koristen_prozor = 0;
        for (size_t j = 0; j < prozor; j++) {
            if (i >= j) {
                sum += ulaz[i - j];
                koristen_prozor++;
            }
        }
        double SMAk = sum / (double)koristen_prozor;
        izlaz[i] = SMAk;
    }
}

int main(void) {
    printf("Unesite broj elemenata ulaznog niza: \n");
    size_t len;
    scanf("%zu", &len);

    double ulaz[len];
    double izlaz[len];
    printf("Unesite elemente ulaznog niza:\n");
    for (size_t i = 0; i < len; i++) {
        scanf("%lf", &ulaz[i]);
    }

    printf("Unesite velicinu prozora: \n");
    int k;
    scanf("%d", &k);

    PomicniProsjek(ulaz, izlaz, len, k);

    printf("Ulazni niz:");
    for (size_t i = 0; i < len; i++) {
        printf(" %.2lf", ulaz[i]);
    }
    printf("\nFiltrirani niz:");
    for (size_t i = 0; i < len; i++) {
        printf(" %.2lf", izlaz[i]);
    }
    printf("\n");

    return 0;
}
