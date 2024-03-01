#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    binary_tree_t *left, *right;

    left = NULL;
    right = NULL;

    if (tree == NULL)
        return (0);

    left = tree->left;
    right tree->right;

    return (binary_tree_height(left) - binary_tree_height(right));
}
