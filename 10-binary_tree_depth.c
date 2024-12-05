#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
        /* If tree is NULL, return 0 */
        if (tree == NULL)
                return (0);

        /* Recursively calculate depth by moving up to the parent */
        return (tree->parent ? 1 + binary_tree_depth(tree->parent) : 0);
}
