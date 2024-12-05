#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree (number of nodes), or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    /* If tree is NULL, return 0 */
    if (tree == NULL)
        return (0);
    
    /* Recursively count nodes by summing:
     * 1 (current node) + size of left subtree + size of right subtree */
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
