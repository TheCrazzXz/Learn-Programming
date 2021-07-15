#include <stdio.h>

int main()
{
	int variable = 98;
	printf("Variable `variable` cree : \n\tContenu : %d\n\tAdresse : %p\n", variable, &variable);
	int *pointeur_variable = NULL; //Le pointeur ne pointe vers rien par défaut
	printf("Pointeur `pointeur_variable` cree, il ne pointe vers rien\n");
	pointeur_variable = &variable;
	
	printf("Le pointeur `pointeur_variable` pointe vers `variable`:\n" //Oui il est possible de faire ça en C
	"\tContenu (adresse de variable pointee): %p\n"
	"\tContenu de la variable pointee (contenu de %p) : %d\n"
	"\tAdresse du pointeur : %p\n",
	pointeur_variable, pointeur_variable, *pointeur_variable, &pointeur_variable
	);
	
	*pointeur_variable = 12;
	printf("*pointeur_variable est maintenant egal a 12\n");
	printf("Le pointeur `pointeur_variable` a ete modifie :\n" //Oui il est possible de faire ça en C
	"\tContenu (adresse de variable pointee): %p\n"
	"\tContenu de la variable pointee (contenu de %p) : %d\n"
	"\tAdresse du pointeur : %p\n",
	pointeur_variable, pointeur_variable, *pointeur_variable, &pointeur_variable
	);
}