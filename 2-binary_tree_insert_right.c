#include "binary_trees.h"

/**
 * binary_tree_insert_right - Creates a binary tree node to the right side
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node, *temp;

    if (parent == NULL)
        return (NULL);

    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    if (parent->right == NULL)
    {
        parent->right = new_node;
    }

    else
    {
        temp = parent->right;
        parent->right = new_node;
        new_node->right = temp;
        temp->parent = new_node;
    }

    return (new_node);
}
