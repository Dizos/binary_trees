#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 * 
 * A full binary tree is one where every node has either 0 or 2 children
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    /* If tree is NULL, return 0 */
    if (tree == NULL)
        return (0);
    
    /* If node is a leaf (no children), it's full */
    if (tree->left == NULL && tree->right == NULL)
        return (1);
    
    /* If node has only one child, it's not full */
    if ((tree->left == NULL && tree->right != NULL) || 
        (tree->left != NULL && tree->right == NULL))
        return (0);
    
    /* Recursively check left and right subtrees */
    return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
