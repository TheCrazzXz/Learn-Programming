#ifndef __STACK_H__
#define __STACH_H__

    /*Type booléen*/
    typedef enum
    {
        false, //0
        true //1
    }Bool;

    /*Definition d'une pile*/
    typedef struct StackElement
    {
        unsigned int value;
        struct StackElement *next;
    }StackElement, *Stack;

    /*Prototypes des fonctions*/
    Stack new_stack(void);
    //Verifier que la pile n'est pas vide :
    Bool is_empty_stack(Stack st);

    //Afficher tous les éléments de la pile :
    void print_stack(Stack st);

    //Ajouter un élément à la pile (en haut) :
    Stack push_stack(Stack st, int x);

    //Retirer un élément à la pile (le plus en haut) :
    Stack pop_stack(Stack st);

    //Dernier élément de la pile :
    int top_stack(Stack st);

    //Hauteur de la pile :
    int stack_length(Stack st);

    //Retirer tous les élément de la pile :
    Stack clear_stack(Stack st);


#endif