#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves
 *
 * Return: The number of leaves in the tree, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    binary_tree_t *left, *right;

    left = NULL;
    right = NULL;

    if (tree == NULL)
        return (0);

    if (tree->left == NULL && tree->right == NULL)
        return (1);

    left = tree->left;
    right = tree->right;

    return (binary_tree_leaves(left) + binary_tree_leaves(right));
}
