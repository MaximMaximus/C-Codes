/* 11.8.3 Seite 301 Datei: binaerit.c */
#include <stdio.h>

void binaerZahlIter (unsigned int zahl1)
{
   /* Anzahl Bytes des Typs int * 8 Bit je Byte */
   int array [sizeof (int)*8];
   int zahl2;
   int index;

   for (index = 0; index < (sizeof (int) * 8); index++)
   {
      array[index] = 0;
   }
   for (zahl2 = 0; zahl1; zahl2++, zahl1 /= 2)
   {
      array[zahl2] = zahl1 % 2;
      //printf ("%d ", array[zahl2]);
   }
   for (--zahl2; zahl2 >= 0; zahl2--)
   {
      printf ("%d ", array[zahl2]);
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
      fflush(stdin);
      rueck = scanf ("%d", &zahl);
      binaerZahlIter (zahl);
   } while (rueck != 0);
   return 0;
}
