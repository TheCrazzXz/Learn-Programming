/*
> Lien vidéo : https://www.youtube.com/watch?v=OQP3kgexXtU&list=PLrSOXFDHBtfF6lXQpJ4hBha76DsQufiEQ&index=2
> Ceci est l'exercice à réaliser : 
*/
#include <stdio.h>
int main(void)
{
    int askbuy = 0;
    printf("Entrez la montant pour l'achat : ");
    scanf("%d", &askbuy);

    int buy = askbuy;
    printf("Entrez un billet pour l'achat : ");
    int askbillet = 0;
    scanf("%d", &askbillet);
    int argent = askbillet;

    if(argent < buy)
    {
        printf("Veuillez saisir un montant suffisant pour vos achats");
    }
    else if(argent >= buy)

    {
        int paiement = argent - buy;
        int monnaie = paiement;
        printf("Voilà la monnaie : %d\n Bonne journée !", monnaie);
    }
    else
    {
        printf("Veuillez rentrer un montant valide");
    }
}


/*
Correction :
Note : 6.5/10 
Erreur 1 : Pas d'inclusion de <stdio.h> (#include <stdio.h>)
Erreur 2 : Ligne 22 : if(argent < buy) Avant : mis "if(buy < argent)"
*/
