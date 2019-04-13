/* 11.7 Seite 291 Datei: ellipse.c */
#include <stdio.h>
#include <stdarg.h>

const double SCHWELLE = 3.0;
const double ENDE = -1;

double qualitaet (double, ...);

int main (void)
{
   printf ("Der Ausschuss betraegt %5.2f %% \n\n", 100 * qualitaet (SCHWELLE, 2.5, 3.1, 2.9, 3.2, ENDE));
   printf ("Der Ausschuss betraegt %5.2f %% \n\n", 100 * qualitaet (SCHWELLE, 4.2, 3.8, 3.4, 2.9, 2.7, ENDE));
/* Beachten Sie, dass das Prozent-Zeichen bei printf()         */
/* als %% angegeben wird                                       */
   return 0;
}

double qualitaet (double schwellwert, ...)
{
   int anzahl_schlechter_Teile = 0;
   double wert;
   int lv = 0;

   va_list listenposition;

   printf("Listenwerte: \n");
   for (va_start (listenposition, schwellwert); (wert = va_arg (listenposition, double)) != ENDE; lv ++) {
      printf("%.2f ", wert);
      if (wert > schwellwert) anzahl_schlechter_Teile++;
   }

   printf("\n\n");

   printf("Nicht zulaessige Werte: \n");
   for (va_start (listenposition, schwellwert); (wert = va_arg (listenposition, double)) != ENDE; ) {
   if (wert > schwellwert) printf("%.2f ", wert);
   }

   printf("\n\n");

   va_end (listenposition);

   return (double)anzahl_schlechter_Teile / lv;
}
