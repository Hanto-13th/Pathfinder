#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "node.h"

//This function init all nodes and add in the matrice [index 0 >> 63]
//Each node struct has an array to point through his neighbors node,
//and unique ID to identify

void node_creation_in_matrice(int matrice_size,node_t *matrice_of_nodes[]) {
    for(int i=0;i<matrice_size;i++) {
        //each iteration create a new empty node, add his adress in the matrice

        //alloc memory for each node
        node_t *new_node = malloc(sizeof(node_t));
        //for each node, init an empty node with id and array of neighbor nodes
        *new_node = (node_t){.next_nodes = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
                            .id = i,
                            .value = INFINITY,
                            .locked = false,
                            .in_queue = false
                        };
        //add the adress in matrice
        matrice_of_nodes[i] = new_node;
        
    }
}

//This function get all neighbor node for each node using vector adapted for matrice limit
void neighbor_node_assignment(int matrice_size,int matrice_limit,node_t *matrice_of_nodes[]) {
    int number_of_neighbor = 8;
    for(int i = 0;i<matrice_size;i++) {
        //the pointer recieve the adress of each nodes in the matrice
        node_t *ptr_node = matrice_of_nodes[i];

        //init the col and row variable to verify if the vector is in the limit of the matrice
        int row = i / matrice_limit;
        int col = i % matrice_limit;

        for(int j = 0; j < number_of_neighbor; j++)
        {
            vector_of_mov_t mov_vector = (vector_of_mov_t)j; //init the enum to list all vector of movement

            //we look if the vector is in the limit of the matrice for each movement
            //if good, the vector verified node is register into the 'adjacent nodes' array 
            //of actual pointed node
            switch (mov_vector)
            {
            case LEFT:
                if(col > 0) {
                ptr_node->next_nodes[0] = matrice_of_nodes[i - 1];
                }
                break;
            case UP:
                if(row > 0) {
                ptr_node->next_nodes[1] = matrice_of_nodes[i - matrice_limit];
                }
                break;
            case DOWN:
                if(row < matrice_limit - 1) {
                ptr_node->next_nodes[2] = matrice_of_nodes[i + matrice_limit];
                }
                break;
            case RIGHT:
                if(col < matrice_limit - 1) {
                ptr_node->next_nodes[3] = matrice_of_nodes[i + 1];
                }
                break;
            
            case DIAG_DOWN_LEFT:
                if(row < matrice_limit - 1 && col > 0) {
                ptr_node->next_nodes[7] = matrice_of_nodes[i + matrice_limit - 1];
                }
                break;
            case DIAG_UP_LEFT:
                if(row > 0 && col > 0) {
                ptr_node->next_nodes[4] = matrice_of_nodes[i - matrice_limit - 1];
                }
                break;
            case DIAG_UP_RIGHT:
                if(row > 0 && col < matrice_limit - 1) {
                ptr_node->next_nodes[5] = matrice_of_nodes[i - matrice_limit + 1];
                }
                break;
            case DIAG_DOWN_RIGHT:
                if(row < matrice_limit - 1 && col < matrice_limit - 1) {
                ptr_node->next_nodes[6] = matrice_of_nodes[i + matrice_limit + 1];
                }
                break;
            default:
                break;
            }
        }

       
    }


}

node_t *user_choose_start_node(node_t *matrice_of_nodes[]) {
    //Get the start node choose by user
    int id;
    printf("Enter the ID for the start: ");
    scanf("%d", &id);
    return matrice_of_nodes[id];
}

node_t *user_choose_end_node(node_t *matrice_of_nodes[]) {
    //Get the end node choose by user
    int id;
    printf("Enter the ID for the end: ");
    scanf("%d", &id);
    return matrice_of_nodes[id];
}

