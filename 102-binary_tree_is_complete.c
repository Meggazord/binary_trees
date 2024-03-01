#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    int is_complete = 1;
    int seen_null = 0;

    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);  // Assuming a maximum of 1024 nodes
    int front = 0, rear = 0;

    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        binary_tree_t *current = queue[front++];

        if (!current)
        {
            seen_null = 1;
        }
        else
        {
            if (seen_null)
            {
                is_complete = 0;
                break;
            }

            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }

    free(queue);
    return (is_complete);
}
