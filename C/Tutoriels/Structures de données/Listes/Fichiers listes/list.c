#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Creer la liste :
List new_list(void)
{
    return NULL;
}

/*--------------------------------------------------------------------------*/
//Verifier si la liste est vide :
Bool is_empty_list(List li)
{
    if(li == NULL)
    {
        return true;
    }
    return false;
}
/*--------------------------------------------------------------------------*/
//Spécifier la taille de la liste :
int list_length(List li)
{
    int size = 0;

    if(!is_empty_list(li))
    {
        while(li != NULL)
        {
            ++size;
            li = li->next;
        }
    }

    return size;
}
/*--------------------------------------------------------------------------*/
//Afficher tous les éléments de la liste
void print_list(List li)
{
    if(is_empty_list(li))
    {
        printf("Rien a afficher, la liste est vide\n");
        return;
    }
    while(li != NULL)
    {
        printf("[%d]", li->value);
        li = li->next;
    }
    printf("\n");
}

/*--------------------------------------------------------------------------*/
//Ajouter un élément à l'arrière de la liste :
List push_back_list(List li, int x)
{
    ListElement *element;

    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr, "Erreur : probleme d'allocation dynamique\n");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = NULL;

    if(is_empty_list(li))
    {
        return element;
    }

    ListElement *temp;
    temp = li;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = element;

    return li;
}
/*--------------------------------------------------------------------------*/
//Ajouter un élément à l'avant de la liste :
List push_front_list(List li, int x)
{
    ListElement *element;

    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr, "Erreur : probleme d'allocation dynamique\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    
    if(is_empty_list(li))
    {
        element->next = NULL;
    }
    else
    {
        element->next = li;
    }

    return element;
}
/*--------------------------------------------------------------------------*/
//Supprimer l'élément à l'arrière de la liste :
List pop_back_list(List li)
{
    if(is_empty_list(li))
    {
        return new_list();
    }
    if(li->next == NULL)
    {
        free(li);
        li = NULL;

        return new_list();
    }

    ListElement *temp = li;
    ListElement *before = li;

    while(temp->next != NULL)
    {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    free(temp);
    temp = NULL;

    return li;
}
/*--------------------------------------------------------------------------*/
//Supprimer l'élément l'élément à l'avant de la liste :
List pop_front_list(List li)
{
    if(is_empty_list(li))
    {
        return li;
    }

    ListElement *element;

    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr, "Erreur : probleme d'allocation dynamique\n");
        exit(EXIT_FAILURE);
    }

    element = li->next;

    free(li);
    li = NULL;

    return element;
    
}
/*--------------------------------------------------------------------------*/
//Supprimer tous les éléments de la liste
List clear_list(List li)
{
    if(is_empty_list(li))
    {
        return new_list();
    }
    while(li != NULL)
    {
        li = pop_front_list(li);
    }
}