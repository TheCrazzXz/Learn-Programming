#ifndef __LIST_H__
#define __LIST_H__

/*  Definition du type Booléen  */
typedef enum
{
    false,
    true
}Bool;


/*   Définition d'un maillon de la Dliste   */
typedef struct DListNode
{
    int value;
    struct DListNode *back;
    struct DListNode *next;
    
}DListNode;

/*   Définition d'une DListe   */
typedef struct DList
{
    int length;
    struct DListNode *begin;
    struct DListNode *end;
}*DList;

/*   Prototypes   */
DList new_dlist(void);
Bool is_empty_dlist(DList li);
int dlist_length(DList li);
int dlist_first(DList li);
int dlist_last(DList li);
void print_dlist(DList li);
DList push_back_dlist(DList li, int x);
DList push_front_dlist(DList li, int x);
DList pop_back_dlist(DList li);
DList pop_front_dlist(DList li);
DList clear_dlist(DList li);

#endif