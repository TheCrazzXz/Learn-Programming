#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Bool is_empty_queue(void)
{
    if(first == NULL && last == NULL)
        return true;
    return false;
}

/*--------------------------------------------------------------------------*/
//Longeueur de la file :
int queue_length(void)
{
    return nb_elemnts;
}

/*--------------------------------------------------------------------------*/
//Premier élément de la pile :
int queue_first(void)
{
    if(is_empty_queue())
        printf("La file est vide");
        exit(1);
    return first->value;
}
/*--------------------------------------------------------------------------*/
//Derinier élément de la pile :
int queue_last(void)
{
    if(is_empty_queue())
        printf("La file est vide");
        exit(1);
    return last->value;
}
/*--------------------------------------------------------------------------*/
//Afficher tous les éléments de la pile :
void print_queue(void)
{
    if(is_empty_queue())
    {
        printf("La file est vide\n");
        return;
    }

    QueueElement *temp = first;
    while(temp != NULL)
    {
        printf("[%d]", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
/*--------------------------------------------------------------------------*/
//Ajouter un nouvel élément à la pile :
void push_queue(int x)
{
    QueueElement *element;
    element = malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr, "__Erreur : Problème d'allocation dynamique__\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    element->next = NULL;

    if(is_empty_queue())
    {
        first = element;
        last = element;
    }
    else
    {
        last->next = element;
        last = element;
    }
    nb_elemnts++;
    
}
/*--------------------------------------------------------------------------*/
//Retirer le premier élément de la file :
void pop_queue(void)
{
    if(is_empty_queue())
    {
        printf("Rien à retirer, la file est vide.\n");
        return;
    }
    QueueElement *temp = first;
    if(first == last)
    {
        first = NULL;
        last = NULL;
    }
    else
        first = first->next;
    free(temp);
    nb_elemnts--;
    
}
/*--------------------------------------------------------------------------*/
//Supprimer tous les éléments de la file : 
void clear_queue(void)
{
    if(is_empty_queue())
    {
        printf("Rien à nettoyer, la file est dejà vide.\n");
        return;
    }
    while(!is_empty_queue())
        pop_queue();
}
/*--------------------------------------------------------------------------*/