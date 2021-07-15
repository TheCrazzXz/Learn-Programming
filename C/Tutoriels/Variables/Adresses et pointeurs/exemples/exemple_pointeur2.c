#include <stdio.h>

void changerVariable(int* variable, int nouveau_contenu)
{
	*variable = nouveau_contenu; //on écrit à l'adresse la variable pointée `nouveau_contenu`
}

int main()
{
	int variable = 0;
	printf("`variable` avant l'appel a la fonction : %d\n", variable);
	changerVariable(&variable, 56);
	printf("`variable` apres l'appel a la fonction : %d\n", variable);
}