#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>

/*   Définition de l'arbre binaire   */
typedef struct Tree
{
    int value;
    struct Tree *tleft;
    struct Tree *tright;
    struct Tree *parent;
}Tree;


/*   Prototypes   */
Tree *new_tree(int x);
void clean_tree(Tree *tr);
Tree *join_tree(Tree *left, Tree *right, int node);
void print_tree_prefix(Tree *tr);
void print_tree_postfix(Tree *tr);
int count_tree_node(Tree *tr);
#endif