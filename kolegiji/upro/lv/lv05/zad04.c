int PovecajKonvertiraj(float *placa, const float bonus, float *postotak) {
   float kn = *placa;
   *placa += bonus;
   *placa /= 7.5345f;

   *postotak = (bonus / kn)*100;

   if (*postotak >= 10) {
      return 1;
   }

   return 0;
}
