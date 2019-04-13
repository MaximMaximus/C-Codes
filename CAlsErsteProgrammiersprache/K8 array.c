/* 8.3.2 Seite 173 Datei: array.c */ 
 
#include <stdio.h>
#define MAX 40
int main (void)
{
   int fahrenheit [MAX+1];
   int index;
   /* Tabelle fuer Fahrenheitwerte von 0 bis MAX Grad Celsius */
   for (index = 0; index <= MAX; index = index + 1)
   {
      fahrenheit[index] = ((9 * index) / 5) + 32;
      printf("Fahrenheitwerte[%d] = %d\n", index, fahrenheit[index]);
   }
   while ( 1 )
   {
      printf ("Geben Sie bitte eine Temperatur zwischen");
      printf (" 0 und %d Grad Celsius ein ", MAX);
      printf ("(Abbruch durch Eingabe von -1):\n");
      scanf ("%d", &index);
      if (index < 0 || index > MAX) break;
      printf ("\n\nDas sind %d Grad Fahrenheit\n", fahrenheit[index]);
   }
   return 0;
} 
