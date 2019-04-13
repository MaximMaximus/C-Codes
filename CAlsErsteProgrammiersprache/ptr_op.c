/* 8.1.7 Seite 169 Datei: ptr_op.c */ 
#include <stdio.h> 
 
int main (void) 
{ 
   int alpha; 
   int * pointer1; 
   int * pointer2; 
   printf ("\nWert Alpha: %d", alpha);
   printf ("\nAddresse Alpha: %p", &alpha); 

   pointer1 = &alpha;                                 /* pointer1 wird initialisiert   */ 
                                                      /* und zeigt auf alpha           */ 
   *pointer1 = 5;                                     /* alpha wird 5 zugewiesen       */ 
   printf ("\nWert Pointer 1: %d", *pointer1);        /* 5 wird ausgegeben             */ 
   printf ("\nAddresse Pointer 1: %p", &pointer1);
   *pointer1 = *pointer1 + 1;                         /* alpha wird um 1 inkrementiert */ 
   pointer2 = pointer1;                               /* pointer2 wird initialisiert   */ 
                                                      /* und zeigt auch auf alpha      */ 
   printf ("\nWert Pointer 2: %d", *pointer2);        /* 6 wird ausgegeben             */ 
   printf ("\nAddresse Pointer 2: %p", &pointer2);   
   printf ("\nWert Alpha: %d", alpha);
   printf ("\nAddresse Alpha: %p", &alpha);
   return 0; 
} 
