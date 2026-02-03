#include <stdio.h>  
#include <stdlib.h>

#include "visualization.h"
#include "node.h"


//function to display the original matrice without algo
void visu_base_matrice(int matrice_size,int matrice_limit) {
    printf("MATRICE VISUALIZATION BEFORE DJIKSTRA:\n\n");

    for (int i = 0 ; i < matrice_size ; i++) {
        
        putchar('#');
        putchar(' ');
        if((i + 1) % matrice_limit == 0) {
            putchar('\n');

        }

    }
    putchar('\n'); 
    putchar('\n'); 
    putchar('\n'); 

}

//function to display the matrice with the algo
//A = START NODE
//B = TARGET NODE
//# = UNKNOWN NODE
//Display the value of distance between node A and B
void visu_djikstra(int matrice_size,int matrice_limit,node_t *matrice_of_nodes[], node_t *initial_node,node_t *target_node) {
    printf("MATRICE VISUALIZATION AFTER DJIKSTRA:\n\n");
    for (int i = 0; i < matrice_size ; i++) {
        
        if (initial_node->id == matrice_of_nodes[i]->id) {
            putchar('A');
        }
        else if (target_node->id == matrice_of_nodes[i]->id) {
            putchar('B');
        }
        else if (matrice_of_nodes[i]->value <= matrice_size) {
            printf("%d",(int)matrice_of_nodes[i]->value);
        }
        else {
            putchar('#');
        }

        putchar(' ');

        if ((i + 1) % matrice_limit == 0) {
            putchar('\n');
        }

    }   
}


