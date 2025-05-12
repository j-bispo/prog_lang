/*
Program: Linked tree usage
Author: Douglas Almonfrey
Date: May 28, 2024
Description: Implementation of a linked tree
License: CC BY
*/

#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the BST
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} tNode;

// Function to create a new node
tNode *create_node(int key) {
    tNode *new_node = (tNode *) malloc(sizeof(tNode)); // Usando o typedef
    if (new_node == NULL) {
        fprintf(stderr, "Error: Impossible to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the BST
tNode *insert_node(tNode *root, int key) {
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->key) {
        root->left = insert_node(root->left, key);
    } else {  // Allow duplicates to be inserted in the right subtree
        root->right = insert_node(root->right, key);
    }

    return root;
}

// Function to find the minimum value node in a subtree
tNode *min_value_node(tNode *node) {
    tNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to remove a node from the BST
tNode *remove_node(tNode *root, int key) {
    if (root == NULL) {
        fprintf(stderr, "Error: The key is not in the tree.\n");
        return root;
    }

    if (key < root->key) {
        root->left = remove_node(root->left, key);
    } else if (key > root->key) {
        root->right = remove_node(root->right, key);
    } else {
        if (root->left == NULL) {
            tNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tNode *temp = root->left;
            free(root);
            return temp;
        }

        tNode *temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = remove_node(root->right, temp->key);
    }

    return root;
}

// Function to delete the BST and free memory
void delete_tree(tNode *root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

// Function to print the BST in inorder traversal
void inorder_traversal(tNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

void search_tree(tNode *root, int key) {
    if (root == NULL) {
        printf("Key %d not found in the tree.\n", key);
        return;
    }
    if (key < root->key) {
        search_tree(root->left, key);
    } else if (key > root->key) {
        search_tree(root->right, key);
    } else {
        printf("Key %d found in the tree.\n", key);
    }
}

int main() {
    tNode *root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    insert_node(root, 50); // Inserting duplicate key

    search_tree(root, 50);
    search_tree(root, 100);
    search_tree(root, 20);

    printf("BST in inorder traversal: ");
    inorder_traversal(root);
    printf("\n\n");

    root = remove_node(root, 20);
    printf("BST after removing 20: ");
    inorder_traversal(root);
    printf("\n");

    search_tree(root, 50);
    search_tree(root, 100);
    search_tree(root, 20);

    delete_tree(root); // Free memory

    return 0;
}