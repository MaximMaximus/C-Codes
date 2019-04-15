#include <stdio.h>

int main()
{
    int wertX = 100;
    
    float endwert = 0.00;
    float i = 0;
    float j = 2;
    for(i=1; endwert <= wertX; i+=2)
    {
        if(wertX == 1) return 1;
        else {
            endwert = endwert + (1 / i) - ( 1 / j);
            printf("%f\n", endwert);
        }
        j+=2;
    }
    
    printf("Ihre Eingabe ist: %i\n", wertX);
    printf("Der Wert %i wird ab den Wert %.0f ueberstiegen!\n", wertX, i);

    return 0;
}
