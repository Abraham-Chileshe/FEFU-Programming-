/*
Реализовать модуль для работы с бинарным деревом (конструктор, деструктор, очищение, размер дерева, вставка элемента, удаление элемента, поиск)
*/

#include <stdio.h>
#include <stdlib.h>

// Структура для представления узла бинарного дерева
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Конструктор: создание нового узла дерева
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Деструктор: освобождение памяти узла и всех его потомков
void destroyNode(struct TreeNode* node) {
    if (node != NULL) {
        destroyNode(node->left);
        destroyNode(node->right);
        free(node);
    }
}

// Очистка дерева
void clearTree(struct TreeNode** root) {
    if (*root != NULL) {
        destroyNode(*root);
        *root = NULL;
    }
}

// Размер дерева: количество узлов
int treeSize(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + treeSize(root->left) + treeSize(root->right);
    }
}

// Вставка элемента в дерево
void insert(struct TreeNode** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else {
        if (data < (*root)->data) {
            insert(&((*root)->left), data);
        } else {
            insert(&((*root)->right), data);
        }
    }
}

// Удаление элемента из дерева
struct TreeNode* deleteNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* minValueNode = root->right;
        while (minValueNode->left != NULL) {
            minValueNode = minValueNode->left;
        }

        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }

    return root;
}

// Поиск элемента в дереве
struct TreeNode* search(struct TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Пример использования модуля
int main() {
    struct TreeNode* root = NULL;

    // Вставка элементов в дерево
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    insert(&root, 90);

// Поиск элемента
    struct TreeNode* searchResult = search(root, 40);
    if (searchResult != NULL) {
        printf("Item found: %d\n", searchResult->data);
    } else {
        printf("Element not found\n");
    }

// Размер дерева
    int size = treeSize(root);
    printf("tree size: %d\n", size);

// Удаление элемента
    root = deleteNode(root, 40);

// Очистка дерева
    clearTree(&root);

    return 0;
}
