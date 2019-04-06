#include <stdio.h>

int main()
{   
    int start = 0;
    int ende = 127;
    
    int differenz = ende - start;
    
    int spalte = 4;
    
    int zeilen = 0;
    
    zeilen = (differenz / spalte) +1;
   
    printf("Zeilen: %d Spalten: %d\n", zeilen, spalte );
    
    int wert = 0;
    
    int z = 0;
    int s = 0;
    
    for ( z = 1; z <= zeilen; z++ ) {

        for ( s = 1; s <= spalte; s++ ) {
            
            wert = z+zeilen*s-zeilen+start-1; 

            if ( wert > ende ) {
                printf("");
            } else {
                printf("%.3d: %3c | ", wert, wert);
            }
        }
        printf("\n");
    }
    
    return 0;
}
