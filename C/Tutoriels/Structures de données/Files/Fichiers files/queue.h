#ifndef __QUEUE_H__
#define __QUEUE_H__
/*  Definition du type Booléen  */
typedef enum
{
    false,
    true
}Bool;

/*  Definition d'une file   */
typedef struct QueueElement
{
    int value;
    struct QueueElement *next;
}QueueElement, *Queue;

/*   Paramètres de la file   */
static QueueElement *first = NULL;
static QueueElement *last = NULL;
static int nb_elemnts = 0;

/*   Prototypes   */
Bool is_empty_queue(void);
int queue_length(void);
int queue_first(void);
int queue_last(void);
void print_queue(void);
void push_queue(int x);
void pop_queue(void);
void clear_queue(void);

#endif