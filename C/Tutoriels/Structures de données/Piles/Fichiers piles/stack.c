#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack new_stack(void)
{
    return NULL;
}

/*-------------------------------------------*/
Bool is_empty_stack(Stack st)
{
    if(st == NULL)
        return true;
    return false;
}
/*-------------------------------------------*/
Stack push_stack(Stack st, int x)
{
   StackElement *element;
    element = malloc(sizeof(*element));
    if (element == NULL)
    {
        fprintf(stderr, "Problème allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    element->next = st;

    

    return element;
}
/*-------------------------------------------*/
Stack pop_stack(Stack st)
{
    StackElement *element;
    if(is_empty_stack(st))
        return new_stack();
    element = st->next;
    free(st);
    return element;
}
/*-------------------------------------------*/

void print_stack(Stack st)
{
    if(is_empty_stack(st))
    {
        printf("La pile est vide");
        return;
    }
    while(!is_empty_stack(st))
    {
        printf("[%d]\n", st->value);
        st = st->next;
    }
}
/*-------------------------------------------*/
int top_stack(Stack st)
    {
        if(is_empty_stack(st))
        {
            printf("Aucun sommet, la pile est vide.\n");
            return -1;
        }
        return st->value;
    }

/*-------------------------------------------*/
int stack_length(Stack st)
{
    int length;

    while(!is_empty_stack(st))
    {
        length++;
        st = st->next;
    }
    return length;
}
/*-------------------------------------------*/
Stack clear_stack(Stack st)
{
    while(!is_empty_stack(st))
        st = pop_stack(st);   

    return new_stack();
}

