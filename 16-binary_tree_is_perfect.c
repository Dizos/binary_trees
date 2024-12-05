#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    if (tree == NULL)
        return (0);

    while (tree->parent)
    {
        depth++;
        tree = tree->parent;
    }

    return (depth);
}

/**
 * is_perfect_recursive - Recursively checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @depth: Depth of the tree
 * @level: Current level in the tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
    /* If tree is NULL, it's perfect at this point */
    if (tree == NULL)
        return (1);

    /* If it's a leaf node */
    if (tree->left == NULL && tree->right == NULL)
        return (depth == level);

    /* If node has only one child, it's not perfect */
    if (tree->left == NULL || tree->right == NULL)
        return (0);

    /* Recursively check left and right subtrees */
    return (is_perfect_recursive(tree->left, depth, level + 1) &&
            is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t depth;

    /* If tree is NULL, return 0 */
    if (tree == NULL)
        return (0);

    /* Calculate the depth of the tree */
    depth = binary_tree_depth(tree);
    while (tree->parent)
        tree = tree->parent;

    /* Check if the tree is perfect recursively */
    return (is_perfect_recursive(tree, depth, 0));
}
