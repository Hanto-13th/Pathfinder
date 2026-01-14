#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include "main.h"
#include "func.h"

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
                            .value = INFINITY
                        };
        //add the adress in matrice
        matrice_of_nodes[i] = new_node;
        
    }
}

//This function get all neighbor node for each node using vector

void neighbor_node_assignment(int matrice_size,int matrice_limit,node_t *matrice_of_nodes[]) {
    for(int i = 0;i<matrice_size;i++) {
        //the pointer recieve the adress of each nodes in the matrice
        node_t *ptr_node = matrice_of_nodes[i];
        printf("ID NODE --- %d\n",ptr_node->id); 

        //init the col and row variable to verify if the vector is in the limit of the matrice
        int row = i / 8;
        int col = i % 8;

        for(int j = 0; j < matrice_limit; j++)
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
                printf("LEFT --\nid>%d\nnode stocked>%p\nmatrice>%p\n",matrice_of_nodes[i - 1]->id,ptr_node->next_nodes[0],matrice_of_nodes[i - 1]); }
                break;
            case UP:
                if(row > 0) {
                ptr_node->next_nodes[1] = matrice_of_nodes[i - 8];
                printf("UP --\nid>%d\nnode stocked>%p\nmatrice>%p\n",matrice_of_nodes[i - 8]->id,ptr_node->next_nodes[1],matrice_of_nodes[i - 8]); }
                break;
            case DOWN:
                if(row < 7) {
                ptr_node->next_nodes[2] = matrice_of_nodes[i + 8];
                printf("DOWN --\nid>%d\nnode stocked>%p\nmatrice>%p\n",matrice_of_nodes[i + 8]->id,ptr_node->next_nodes[2],matrice_of_nodes[i + 8]); }
                break;
            case RIGHT:
                if(col < 7) {
                ptr_node->next_nodes[3] = matrice_of_nodes[i + 1];
                printf("RIGHT --\nid>%d\nnode stocked>%p\nmatrice>%p\n",matrice_of_nodes[i + 1]->id,ptr_node->next_nodes[3],matrice_of_nodes[i + 1]); }
                break;
            
            case DIAG_DOWN_LEFT:
                if(row < 7 && col > 0) {
                ptr_node->next_nodes[7] = matrice_of_nodes[i + 7];
                printf("DIAG_DOWN_LEFT --\nid>%d\nnode stocked>%p\nmatrice>%p\n",matrice_of_nodes[i + 7]->id,ptr_node->next_nodes[7],matrice_of_nodes[i + 7]); }
                break;
            case DIAG_UP_LEFT:
                if(row > 0 && col > 0) {
                ptr_node->next_nodes[4] = matrice_of_nodes[i - 9];
                printf("DIAG_UP_LEFT --\nid>%d\nnode stocked>%p\nmatrice>%p\n",matrice_of_nodes[i - 9]->id,ptr_node->next_nodes[4],matrice_of_nodes[i - 9]); }
                break;
            case DIAG_UP_RIGHT:
                if(row > 0 && col < 7) {
                ptr_node->next_nodes[5] = matrice_of_nodes[i - 7];
                printf("DIAG_UP_RIGHT --\nid>%d\nnode stocked>%p\nmatrice>%p\n",matrice_of_nodes[i - 7]->id,ptr_node->next_nodes[5],matrice_of_nodes[i - 7]); }
                break;
            case DIAG_DOWN_RIGHT:
                if(row < 7 && col < 7) {
                ptr_node->next_nodes[6] = matrice_of_nodes[i + 9];
                printf("DIAG_DOWN_RIGHT --\nid>%d\nnode stocked>%p\nmatrice>%p\n",matrice_of_nodes[i + 9]->id,ptr_node->next_nodes[6],matrice_of_nodes[i + 9]); }
                break;
            default:
                break;
            }
        }

       
    }


}

//function to compute the weight between two nodes 
//(regular cost >> next neighbor = 1, diag neighbor = 2)
int weight_between_two_nodes(node_t *node1, node_t *node2) {
    int array_size = sizeof(node1->next_nodes)/sizeof(node1->next_nodes[0]);
    //for each iteration, verify if the node2 adress is in the node1 array and
    //if the index corresponding with next or diag neighbor
    //if not, return 0
    for(int i = 0;i < array_size;i++) {
        //if next neighbor
        if(i < 4 && node2 == node1->next_nodes[i]) {
            return 1;
        }
        //if diag neighbor
        else if(i >= 4 && node2 == node1->next_nodes[i]) {
            return 2;
        }
    }

    return -1;
    
}

node_t add_in_non_tested_array(node_t *initial_node, node_t *non_tested_nodes) {
    int array_size = sizeof(initial_node->next_nodes)/sizeof(initial_node->next_nodes[0]);
    int non_tested_size = sizeof(non_tested_nodes);
    for (int i = 0; i < non_tested_size; i++)
    {
        
    }
    
    for (int i = 0; i < array_size; i++)
    {
        /* code */
    }
    
}

int sum_initial_to_actual_node(int matrice_size,int matrice_limit,node_t *matrice_of_nodes,
    node_t *initial_node) {
    //alloc an array to contains all the nodes already tested
    node_t *tested_nodes[] = malloc(matrice_size * sizeof(node_t));
    node_t *non_tested_nodes[] = malloc(matrice_limit * sizeof(node_t));
    //int *the_good_path[] = malloc(matrice_size * sizeof(int));
    node_t *actual_node = initial_node;
    while (sizeof(non_tested_nodes) != 0)
    {
        /* code */
    }
    
    

    



}
