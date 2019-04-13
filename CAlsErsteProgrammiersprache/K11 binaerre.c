/* 11.8.3 Seite 303 Datei: binaerre.c */
#include <stdio.h>

void binaerZahlReku (unsigned int zahl)
{
   if (zahl > 0)
   {
      binaerZahlReku (zahl / 2);
      printf ("%d ", zahl % 2);
   }
}

int main()
{
   unsigned int rueck;
   unsigned int zahl;
   printf ("Binaerdarstellung:\n");
   do
   {
      printf ("\nBitte geben Sie eine Zahl ein: ");
      rueck = scanf ("%d", &zahl);
      binaerZahlReku (zahl);
   } while (rueck != 0);
   return 0;
}
