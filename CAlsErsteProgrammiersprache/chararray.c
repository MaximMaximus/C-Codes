/* 8.3.5 Seite 175  Datei: char_array.c */
/* Entscheiden, ob eine Zeichenkette ein 'a' enthaelt             */
#include <stdio.h>
#include <string.h>

#define MAX 40

int main (void)
{
   int index;
   char eingabe [MAX+1];
   printf ("Bitte String eingeben (max. %d Zeichen): ", MAX);
   if (fgets (eingabe, sizeof (eingabe), stdin) != NULL)
   {
      for (index = 0; eingabe[index] != '\0'; index = index + 1)
      {
         if (eingabe[index] == 'a')
         {
            break;
         }
      }
          if (eingabe[index] == '\0')
      {
         printf ("\nIhr String enthaelt kein 'a'\n");
      }
      else
      {
         printf ("\nDas a befand sich an der %d. Stelle\n", index + 1);
      }
   }
   return 0;
}
