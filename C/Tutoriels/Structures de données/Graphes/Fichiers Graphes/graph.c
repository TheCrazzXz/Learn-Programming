#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//Creer le Graphe :
Graph new_graph(int vertices, Bool is_oriented)
{
    int i;
    GraphElement *element;
    element = malloc(sizeof(element));

    if(element == NULL)
    {
        fprintf(stderr, "Erreur : Problème d'allocation dynamique/Création graphe.\n");
        exit(EXIT_FAILURE);
    }

    element->is_oriented = is_oriented;
    element->nb_vertices = vertices;

    element->tab_neighbours = malloc(vertices * sizeof(AdjencyList));

    if(element->tab_neighbours == NULL)
    {
        fprintf(stderr, "Erreur : Problème d'allocation dynamique/Création graphe.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 1 ; i < element->nb_vertices + 1 ; i++)
    {
        element->tab_neighbours[i - 1].begin = NULL;
    }
    return element;
}
/*-------------------------------------------------------*/
//Verifier si le graphe est vide :
Bool is_empty_graph(Graph g)
{
    if(g == NULL)
    {
        return true;
    }
    return false;
}
/*-------------------------------------------------------*/
//Ajouter un noeud :
NodeList add_node(int x)
{
    NodeList n = malloc(sizeof(NodeListElement));

    if(n == NULL)
    {
        fprintf(stderr, "Erreur : Problème d'allocation dynamique/Création noueud (node).\n");
        exit(EXIT_FAILURE);
    }
    n->value = x;
    n->next = NULL;

    return n;
}
/*-------------------------------------------------------*/
void add_edge(Graph g, int src, int dest)
{
    NodeList n = add_node(dest);
    n->next = g->tab_neighbours[src - 1].begin;
    g->tab_neighbours[src - 1].begin = n;

    if(!g->is_oriented)
    {
        NodeList n = add_node(src);
        n->next = g->tab_neighbours[dest - 1].begin;
        g->tab_neighbours[dest - 1].begin = n;
    }
}
/*-------------------------------------------------------*/
void print_graph(Graph g)
{
    int i;

    for(i = 1 ; i < g->nb_vertices + 1 ; i++)
    {
        NodeList n = g->tab_neighbours[i - 1].begin;
        printf("(%d) : ", i);

        while(n != NULL)
        {
            printf("%d, ", n->value);
            n = n->next;
        }
        printf("NULL\n");
    }
}
/*-------------------------------------------------------*/

/*-------------------------------------------------------*/
//Supprimer totalement le graphe :
void erase_graph(Graph g)
{
    if(is_empty_graph(g))
    {
        printf("Rien à supprimer, le graphe n'existe pas.\n");
        return;
    }
    //Si sommet adjacents :
    if(g->tab_neighbours)
    {
        int i;

        for(i = 0 ; i < g->nb_vertices + 1 ; i++)
        {
            NodeList n = g->tab_neighbours[i - 1].begin;
            
            while(n != NULL)
            {
                NodeList tmp = n;
                n = n->next;
                free(tmp);
            }
        }
        //Libération de la liste d'adjacense :
        free(g->tab_neighbours);
    }
    //Libération du Graphe : 
    free(g);
}
/*-------------------------------------------------------*/