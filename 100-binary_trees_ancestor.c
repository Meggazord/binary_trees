#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (!first || !second)
        return (NULL);

    if (first == second)
        return ((binary_tree_t *)first);

    if (binary_tree_is_descendant(second, first))
        return ((binary_tree_t *)first);

    if (binary_tree_is_descendant(first, second))
        return ((binary_tree_t *)second);

    return binary_trees_ancestor(first->parent, second->parent);
}

/**
 * binary_tree_is_descendant - Checks if a node is a descendant of another
 * @descendant: Pointer to the potential descendant node
 * @ancestor: Pointer to the potential ancestor node
 *
 * Return: 1 if descendant is a descendant of ancestor, 0 otherwise
 */
int binary_tree_is_descendant(const binary_tree_t *descendant, const binary_tree_t *ancestor)
{
    if (!ancestor)
        return (0);

    if (descendant == ancestor)
        return (1);

    return (binary_tree_is_descendant(descendant, ancestor->left) ||
           binary_tree_is_descendant(descendant, ancestor->right));
}
