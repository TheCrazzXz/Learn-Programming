#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>

/*  Definition du type booléen    */
typedef enum
{
    false,
    true
}Bool;

/*   Définition d'un Noeud (sommet)   */
typedef struct NodeListElement
{
    int value;
    struct NodeListElement *next;
}NodeListElement, *NodeList;

/*  Definiton d'une liste d'ajdacense   */
typedef struct AdjencyListElement
{
    NodeListElement *begin;
}AdjencyListElement, *AdjencyList;

/*  Definition d'un Graphe   */
typedef struct GraphElement
{
    Bool is_oriented;
    int nb_vertices;
    AdjencyList tab_neighbours;
}GraphElement, *Graph;



/*   Prototypes   */
Graph new_graph(int vertices, Bool is_oriented);
Bool is_empty_graph(Graph g);
NodeList add_node(int x);
void add_edge(Graph g, int src, int dest);
void print_graph(Graph g);
void erase_graph(Graph g);

#endif