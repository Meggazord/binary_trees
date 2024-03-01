#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    binary_tree_t *left, *right;

    left = NULL;
    right = NULL;

    if (tree == NULL)
        return (0);

    if ((tree->left == NULL) && (tree->right == NULL))
        return (1);

    if (tree->left == NULL ^ tree->right == NULL)
        return (0);

    if (binary_tree_balance(tree) != 0)
        return (0);

    left = tree->left;
    right = tree->right;

    return (1 && binary_tree_is_perfect(left) && binary_tree_is_perfect(right));

}

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
    right = tree->right;

    return (binary_tree_height(left) - binary_tree_height(right));
}

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
        return (1);

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

