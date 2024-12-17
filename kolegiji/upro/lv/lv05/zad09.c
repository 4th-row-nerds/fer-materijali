#include <math.h>
#include <stdio.h>

#define PI 3.1415926

void IzracunajRezultantu(const float *sila1, const float *sila2, const float *kut_deg, float *rez) {
    const float kud_rad = *kut_deg / 180 * PI;
    const float f1 = *sila1, f2 = *sila2;

    *rez = sqrt(f1*f1 + f2*f2 + 2*f1*f2*cos(kud_rad));
}

int main(void) {
    printf("Unesite prvu silu (u Newtonima): \n");
    float f1;
    scanf("%f", &f1);

	printf("Unesite drugu silu (u Newtonima): \n");
    float f2;
    scanf("%f", &f2);

	printf("Unesite kut između sila (u stupnjevima): \n");
    float kut_deg;
    scanf("%f", &kut_deg);

    float rez;
    IzracunajRezultantu(&f1, &f2, &kut_deg, &rez);
	printf("Rezultanta sila iznosi: %.2f N\n", rez);
}
