/* 10.3.2.8 Seite 256 Datei: for6.c Primzahlen */
#include <stdio.h>
int main (void)
{
   int lv1;
   int lv2;
   int teiler;
   printf ("Primzahlen:\n");
   for (lv1 = 2, teiler = 0; lv1 <= 101; lv1 = lv1 + 1, teiler = 0)
   {
      for (lv2 = 2; lv2 < lv1; lv2 = lv2 + 1)
      {
         if (lv1 % lv2 == 0)
         {
            teiler = 1;
         }
      }
      if (teiler == 0)
      {
         printf ("%d", lv1);
         if (lv1 < 101)
         {
            printf (", ");
         }
      }
   }

   return 0;
}
