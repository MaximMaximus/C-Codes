#include <stdio.h>

int main()
{   
    int i = 4771;
    int *ip = &i;
    int **ipp = &ip;
    int ***ippp = &ipp;

    printf("&i Adresse: %d \n", &i); // 1
    printf("i Wert: %d \n\n", i); // 4771
    
    printf("&ip Adresse: %d \n", &ip); // 2
    printf("ip Wert ist Zeiger auf Adresse von i: %d \n", ip); // 1
    printf("*ip zeigt auf Wert von i: %d \n\n", *ip); // 4771
    
    printf("&ipp Adresse: %d \n", &ipp); // 3
    printf("ipp Wert ist Zeiger auf Adresse von ip: %d \n", ipp); // 2
    printf("*ipp zeigt auf Wert von ip und Adresse von i: %d \n", *ipp); // 1
    printf("**ipp zeigt auf Wert von *ip und i: %d \n\n", **ipp); // 4771

    printf("&ippp Adresse: %d \n", &ippp); // 4
    printf("ippp Wert ist Zeiger auf Adresse von ipp: %d \n", ippp); // 3
    printf("*ippp zeigt auf Wert von ipp Adresse von ip: %d \n", *ippp); // 2
    printf("**ippp zeigt auf Wert von ip Adresse von i: %d \n", **ippp); // 1
    printf("***ippp zeigt auf Wert von *ip, **ipp und i: %d \n\n", ***ippp); // 4771
    
    return 0;
}
