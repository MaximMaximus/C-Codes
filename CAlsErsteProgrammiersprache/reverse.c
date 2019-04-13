/* 9.6.7.3 Seite 214 Datei: revers.c */
#include <stdio.h>

int main (void)
{
   char text1 [4] = "EIN";
   char text2 [4];
   int index1, index2;
   for (index2 = 0, index1 = 2; index1 >= 0; index2++, index1--)
   {
      text2 [index2] = text1 [index1];
   }
   text2 [index2] = '\0';
   printf ("\n%s\n%s\n", text1, text2);
   return 0;
}
