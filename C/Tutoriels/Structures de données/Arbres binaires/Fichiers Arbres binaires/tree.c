#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

//Creer l'arbre binaire :
Tree *new_tree(int x)
{
    Tree *tr = malloc(sizeof(*tr));

    if(tr == NULL)
    {
        fprintf(stderr, "Erreur : Prblème d'allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }

    tr->value = x;
    tr->tleft = NULL;
    tr->tright = NULL;
    tr->parent = NULL;

    //Aide pour le développeur :
    printf("Creation de %d\n", tr->value);

    return tr;
}
/*-------------------------------------------------------*/
//Supprimer tous les éléments de l'arbre : 
void clean_tree(Tree *tr)
{
    if(tr == NULL)
    {
        return;
    }
    //Aide pour le développeur : 
    printf("Suppression de : %d\n", tr->value);

    clean_tree(tr->tleft);
    clean_tree(tr->tright);

    free(tr);
}
/*-------------------------------------------------------*/
Tree *join_tree(Tree *left, Tree *right, int node)
{
    Tree *tr = new_tree(node);

    tr->tleft = left;
    tr->tright = right;

    if(left != NULL)
    {
        left->parent = tr;
    }

    if(right != NULL)
    {
        right->parent = tr;
    }

    return tr;
}
/*-------------------------------------------------------*/
//Afficher la structure de l'arbre en commençant par la gauche :
void print_tree_prefix(Tree *tr)
{
    if(tr == NULL)  
    {
        printf("Rien à afficher, l'arbre est vide.\n");
        return;
    }

    
    if(tr->parent != NULL)
    {
        printf("(%d) -> (%d)\n", tr->parent->value, tr->value);
    }
    else
    {
        printf("(%d)\n", tr->value);
    }

    if(tr->tleft != NULL)
    {
        printf(" ");
        print_tree_prefix(tr->tleft);
    }

    if(tr->tright != NULL)
    {
        printf(" ");
        print_tree_prefix(tr->tright);
    }
    
}
/*-------------------------------------------------------*/
//Afficher la structure de l'arbre en commençant par la droite :
void print_tree_postfix(Tree *tr)
{
    if(tr = NULL)  
    {
        printf("Rien à afficher, l'arbre est vide.\n");
        return;
    }
    if(tr->parent != NULL)
    {
        printf("(%d) -> (%d)", tr->parent->value, tr->value);
    }
    else
    {
        printf("(%d)\n", tr->value);
    }

    if(tr->tright != NULL)
    {
        printf(" ");
        print_tree_prefix(tr->tright);
    }

    if(tr->tleft != NULL)
    { 
        printf(" ");
        print_tree_prefix(tr->tleft);
    }    
}
/*-------------------------------------------------------*/
//Compter les noeux de l'arbre :
int count_tree_node(Tree *tr)
{
    if(tr == NULL)
    {
        return 0;
    }
    return (count_tree_node(tr->tleft) + count_tree_node(tr->tright) + 1);
}
/*-------------------------------------------------------*/

/*-------------------------------------------------------*/

/*-------------------------------------------------------*/

/*-------------------------------------------------------*/
