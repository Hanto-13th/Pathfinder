#pragma once

typedef struct Node node_t;
typedef struct Array_of_nodes arr_of_nodes_t;

typedef enum Vector_of_movements vector_of_mov_t;

struct Node {
    node_t *next_nodes[8]; //init a array of 8 pointer (node_t) to points other nodes 
    //in 8 directions around the node
    int id;
    float value;
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





