/* Simple example of how to use veradic functions */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


/* Simple way to use veradic */
void print_nums(int len, ...)
{
    int i, val;
    
    /* Create our list */
    va_list args;

    /* Initlize the list and get the arguments */
    va_start(args, len);

    /* Iterate throught the arguments and print it */
    for (i = 0; i < len; ++i) {
        /* Get the next argument */
        val = va_arg(args, int);
        printf("%i ", val);
    }
    printf("\n");

    /* Delete and free the list */
    va_end(args);
}



typedef struct node_t {
    int val;
    struct node_t *next;
} Node;


/* Create a new instace of node */
Node *create_node()
{
    Node *new_node;
    
    if ((new_node = (Node *) malloc(sizeof(Node))) == NULL)
        return NULL;

    memset(new_node, 0, sizeof(Node));

    return new_node;
}


/* Initlize a new object */
void init_node(Node *node, ...)
{
    va_list args;

    va_start(args, node);
    
    node->val = va_arg(args, int);
    node->next = va_arg(args, Node *);
    
    va_end(args);
}


int main()
{
    Node *node, *node1;
    
    print_nums(4, 1, 2, 3, 4);
    print_nums(3, 1, 2 ,3);

    node = create_node();
    init_node(node, 10);

    node1 = create_node();
    init_node(node1, node);

    printf("%i\n", node->val);
    printf("%i\n", node1->val);
    printf("%p\n", node1->next);
    
    return 0;
}

