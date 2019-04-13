#include <stdio.h>
#include <time.h> //for sleep() function
 
int main()
{
 
    char sym = 37;
    char sym2 = 44;
    int lenght = 10;
    
    int i = 0;
    int j = lenght;
    
    int bewegungR = 0;
    int bewegungL = 0;
   
    while(1)
    {
        system("clear");
        printf("%*s" , i, "");
        printf("%c\n", sym);
        printf("%*s" , j, "");
        printf("%c\n", sym2);
        printf("%*s" , i, "");
        printf("%c\n", sym);
        printf("%*s" , j, "");
        printf("%c\n", sym2);
        printf("%*s" , i, "");
        printf("%c\n", sym);
        printf("%*s" , j, "");
        printf("%c\n", sym2);
        printf("%*s" , i, "");
        printf("%c\n", sym);
        printf("%*s" , j, "");
        printf("%c\n", sym2);
        printf("%*s" , i, "");
        printf("%c\n", sym);
        printf("%*s" , j, "");
        printf("%c\n", sym2);
        fflush(stdout);
        
        if ( i == 0 ) {
            bewegungR = 1;
        }
        
        if ( i >= lenght ) {
            bewegungR = 0;
            bewegungL = 1;
        }
        
        if ( bewegungR == 1 ) {
            bewegungL = 0;
            i++;
            j--;
        }
        if ( bewegungL == 1 ) {
            bewegungR = 0;
            i--;
            j++;
        }

        sym++;
        if ( sym == 44 ) {
            sym = 37;
        }
        sym2--;
        if ( sym2 == 37 ) {
            sym2 = 44;
        }

        sleep(1);
    }
 /*
    while(1)
    {
        //clear output screen
        system("clear");
        
        printf("%c",sym);
            fflush(stdout);
        sym++;
        if ( sym == 57 ) {
            sym = 48;
        }
         
        sleep(1);   //wait till 1 second
    }
 */
    return 0;
}
