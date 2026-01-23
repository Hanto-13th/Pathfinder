#pragma once

typedef struct Node node_t;
typedef enum Vector_of_movements vector_of_mov_t;

struct Node {
    node_t *next_nodes[8]; //init a array of 8 pointer (node_t) to points other nodes 
    //in 8 directions around the node
    int id;
    float value; //used by algorith to know the better value to access at this node
    bool locked; //to know if the node is locked at the better possible value (min)
    bool in_queue; //to know if the node is in progress to test (the better value non finded)
};

enum Vector_of_movements {
    LEFT = 0,
    UP = 1,
    DOWN = 2,
    RIGHT = 3,

    DIAG_UP_LEFT = 4,
    DIAG_UP_RIGHT = 5,
    DIAG_DOWN_RIGHT = 6,
    DIAG_DOWN_LEFT = 7
};

//functions prototype for node creation
void node_creation_in_matrice(int matrice_size,node_t *matrice_of_nodes[]);
void neighbor_node_assignment(int matrice_size,int matrice_limit,node_t *matrice_of_nodes[]);
