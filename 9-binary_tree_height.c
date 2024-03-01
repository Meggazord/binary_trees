#include "binary_trees.h"
#include <math.h>

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    binary_tree_t *left, *right;

    left = NULL;
    right = NULL;

    if (tree == NULL)
        return (0);

    if (tree->left == NULL && tree->right == NULL)
        return (0);

    left = tree->left;
    right = tree->right;

    return (max_size(binary_tree_height(left), binary_tree_height(right)) + 1);
}


/**
* max_size - return the max of 2 no.s
* @x: 1st no
* @y: 2nd no
*
* Return: max of 2 numbers
*/
size_t max_size(int x, int y)
{
    return (x >= y ? x : y);
}
