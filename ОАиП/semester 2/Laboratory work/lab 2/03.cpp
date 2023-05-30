/*
Реализовать модуль для работы с АВЛ-деревом (конструктор, деструктор, очищение, размер дерева, вставка элемента, удаление элемента, поиск, балансировка)
*/

#include <stdio.h>
#include <stdlib.h>

// Структура для представления узла АВЛ-дерева
struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
};

// Конструктор: создание нового узла дерева
struct AVLNode* createNode(int data) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функция для получения высоты узла
int getHeight(struct AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Функция для вычисления баланса узла
int getBalance(struct AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Функция для обновления высоты узла
void updateHeight(struct AVLNode* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Функция для выполнения правого поворота
struct AVLNode* rightRotate(struct AVLNode* node) {
    struct AVLNode* newRoot = node->left;
    struct AVLNode* temp = newRoot->right;
    newRoot->right = node;
    node->left = temp;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// Функция для выполнения левого поворота
struct AVLNode* leftRotate(struct AVLNode* node) {
    struct AVLNode* newRoot = node->right;
    struct AVLNode* temp = newRoot->left;
    newRoot->left = node;
    node->right = temp;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// Функция для балансировки узла
struct AVLNode* balanceNode(struct AVLNode* node) {
    if (node == NULL) {
        return node;
    }
    updateHeight(node);
    int balance = getBalance(node);
    if (balance > 1) {
        if (getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
    }
    if (balance < -1) {
        if (getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
    return node;
}

// Деструктор: освобождение памяти узла и всех его потомков
void destroyNode(struct AVLNode* node) {
    if (node != NULL) {
        destroyNode(node->left);
        destroyNode(node->right);
        free(node);
    }
}
// Очистка дерева
void clearTree(struct AVLNode** root) {
    if (*root != NULL) {
        destroyNode(*root);
        *root = NULL;
    }
}
// Размер дерева: количество узлов
int treeSize(struct AVLNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + treeSize(root->left) + treeSize(root->right);
    }
}
// Вставка элемента в дерево
struct AVLNode* insert(struct AVLNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
// Если элемент уже существует в дереве
        return root;
    }

// Балансировка после вставки
    return balanceNode(root);
}
// Удаление элемента из дерева
struct AVLNode* deleteNode(struct AVLNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Узел с данными для удаления найден

        // Удаление узла с одним или без потомков
        if (root->left == NULL) {
            struct AVLNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct AVLNode* temp = root->left;
            free(root);
            return temp;
        }

        // Удаление узла с двумя потомками
        struct AVLNode* minValueNode = root->right;
        while (minValueNode->left != NULL) {
            minValueNode = minValueNode->left;
        }
        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }

// Балансировка после удаления
    return balanceNode(root);
}

// Поиск элемента в дереве
struct AVLNode* search(struct AVLNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}
// Пример использования
int main() {
    struct AVLNode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    printf("Size of tree: %d\n", treeSize(root));

    root = deleteNode(root, 30);
    root = deleteNode(root, 40);

    printf("Size of tree: %d\n", treeSize(root));

    clearTree(&root);

    return 0;
}
