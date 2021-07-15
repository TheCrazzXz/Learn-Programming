/*
> Lien vidéo : https://www.youtube.com/watch?v=JpKaxVCjAMw&list=PLrSOXFDHBtfF6lXQpJ4hBha76DsQufiEQ 
> Ceci est l'exercice à réaliser : 
*/
#include <stdio.h>
int main(void)
{
    int asknumber = 0;
    printf("Entrez une valeur (nombre) : ");
    scanf("%d", &asknumber);
    int number = asknumber;
    printf("La valueur que vous avez rentré %d\n", asknumber);
    printf("%d convertit en octal : %o\n", number, number);
    printf("%d convertit en héxadécimal : %X\n", number, number);
}

/*
Correction :
Note : 9/10
*/
