#ifndef _BST_HPP_
#define _BST_HPP_

#include <iostream>
#include <cstring>

template <class Type>
class BST {
    struct Node {
        Type data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* makeEmpty(Node* t) {              //Метод удаления дерева
        if(!t)
            return 0;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        return 0;
    }

    Node* insert(Type x, Node* t) {         //Метод вставки элемента в дерево
        if(!t) {
            t = new Node;
            t->data = x;
            t->left = t->right = 0;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    Node* findMin(Node *t) {            //Метод нахождения минимального элемента в дереве
        if(!t)
            return 0;
        else if(!t->left)
            return t;
        else return findMin(t->left);
    }

    Node* findMax(Node* t) {            //Метод нахождения максимального элемента в дереве
        if(!t)
            return 0;
        else if(!t->right)
            return t;
        else return findMax(t->right);
    }

    Node* remove(Type x, Node* t) {     //Метод удаления элемента в дереве
        Node* temp;
        if(!t)
            return 0;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else {
            temp = t;
            if(!t->left)
                t = t->right;
            else if(!t->right)
                t = t->left;
            delete temp;
        }
        return t;
    }

    void printSpaces(size_t deep) {         //Метод печати пробелов в соответствии с глубиной дерева
        for(size_t i = 0; i < deep; i++) 
            std::cout << ' ';
    }

    void inorder(Node* t, size_t lvl) {     //Метод выводящая значение текущего элемента в дереве
        if(!t) {
            printSpaces(lvl);
            std::cout << "#" << std::endl;
            return;
        }
        inorder(t->right, lvl+4);
        if(lvl) 
            printSpaces(lvl);
        std::cout << "  /" << std::endl;
        printSpaces(lvl);
        std::cout << t->data << std::endl << ' ';
        printSpaces(lvl);
        std::cout << " \\" << std::endl;
        inorder(t->left, lvl+4);
    }

    Node* find(Type x, Node* t) {        //Метод поиска элемента в дереве
        if(!t)
            return 0;
        else if(x < t->data) {
            std::cout << "Element  " << x << " is less than " << t->data << " , go to the left subtree." << std::endl;
            std::cout << "Element " << t->data << " was not " << x << '!' << std::endl;
            return find(x, t->left);
        }
        else if(x > t->data) {
            std::cout << "Element  " << x << " is more than " << t->data << " , go to the right subtree." << std::endl;
            std::cout << "Element " << t->data << " was not " << x << '!' << std::endl;
            return find(x, t->right);
        }
        else return t;
    }

    public:
        BST() {                         
            root = NULL;
        }

        ~BST() {                        
            root = makeEmpty(root);
        }

        void insert(Type x) {
            root = insert(x, root);
        }

        void remove(Type x) {
            root = remove(x, root);
        }

        void display() {        //Метод отображения дерева
            if(!root) {
                std::cout << "BST is empty!" << std::endl;
                return;
            }
            inorder(root, 0);
            std::cout << std::endl;
        }

        int search (Type x) {   //Метод поиска элемента в дереве
            Node* temp = find(x, root);
            if(temp) {
                std::cout << "Element was found!" << std::endl;
                return 1;
            }
            else return 0;
        }
};

#endif