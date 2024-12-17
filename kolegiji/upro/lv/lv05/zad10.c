#include <stdio.h>
#include <stdbool.h>

typedef enum {
    EXTREM_MAX = false,
    EXTREM_MIN = true,
} ekstrem_type_t;

bool Ekstrem(float a, float b, float c, float *x, float *y) {

    *x = -b / (2*a); // x koordinata tjemena parabole
    *y = (4*a*c - b*b) / (4*a); // y koordinata tjemena parabole

    if (b == 0) *x = 0; // pobrine se da ne ostane -0.000 u x
    if (c == 0 && b == 0) *y = 0; // pobrine se da ne ostane -0.000 u y

    if (a > 0) { // Odredi ima li funkcija minimum ili maksimum s obzirom na a
        return EXTREM_MIN;
    } else {
        return EXTREM_MAX;
    }
}

int main(void) {


    printf("Upisite koeficijente kvadratne funkcije > \n");
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    float x, y;
    if (Ekstrem(a, b, c, &x, &y) == EXTREM_MIN) {
        printf("Funkcija ima minimum u (%.2f, %.2f)", x, y);
    } else {
        printf("Funkcija ima maksimum u (%.2f, %.2f)", x, y);
    }

    return 0;
}
