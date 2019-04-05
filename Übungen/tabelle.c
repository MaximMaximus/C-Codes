#include <stdio.h>

int main()
{   
    int start = 0;
    int ende = 127;
    
    int bereich = ende - start;
    
    int i = 0;
    int s = 0;
    
    int spalte = 4;
    
    int save = 0;
    
    int differenz = 0;
    
    differenz = (bereich / spalte) +1;
   
    printf("Zeilen: %d Spalten: %d\n", differenz, spalte );

    for ( i = 1; i <= differenz; i++ ) {

        for ( s = 1; s <= spalte; s++ ) {
            
            save = i+differenz*s-differenz+start-1; 

            if ( s == 1 ) {
                printf("%.3d: %3c | ", save, save); 
            } else {
                if ( save > ende ) {
                    printf("");
                } else {
                    printf("%.3d: %3c | ", save, save);
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}
