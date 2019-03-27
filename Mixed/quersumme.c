// calculation of the cross sum with a recursive function

#include <stdio.h>

int quersumme(int zahl)
{
	int speicher = 0;
	
    if(zahl > 0) speicher =  zahl%10 + quersumme(zahl/10);
    else speicher = 0;
    
	return speicher;
}

int main()
{
    printf("%i\n", quersumme(1234));


	return 0;
}
