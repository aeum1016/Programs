#include <iostream>
#include <vector>
#include <string>

#include "Node.h"

#pragma once

using namespace std;


class AVLTree
{
    public:
        Node* root = nullptr;

        void insert(string name, int id)
        {
            try
            {
                name = name.substr(1, name.size()-2);
                root = insertInternal(name, id, root);
                cout << "successful" << endl;
            }
            catch(...)
            {
                cout << "unsuccessful" << endl;
            }
        }

        Node* insertInternal(string name, int id, Node* rootNode)
        {
            if(rootNode == nullptr)
            {
                return new Node(name, id);
            }
            else if(id < rootNode->getGatorID())
            {
                rootNode->setLeftChild(insertInternal(name, id, rootNode->getLeftChild()));
                rootNode = rootNode->fixBalance();
            }
            else if(id > rootNode->getGatorID())
            {
                rootNode->setRightChild(insertInternal(name, id, rootNode->getRightChild()));
                rootNode = rootNode->fixBalance();
            }
            else 
            {
                throw("Failed");
            }
            return rootNode;
        }

        void searchID(int searchID)
        {
            try
            {
                Node* foundNode = searchIDInternal(root, searchID);
                cout << foundNode->getName() << endl;
            }
            catch(...)
            {
                cout << "unsuccessful" << endl;
            }
        }

        Node* searchIDInternal(Node* root, int searchID)
        {
            if(root == nullptr) throw("Failed Search, ID not Found");
            else if(searchID < root->getGatorID())
            {
                return searchIDInternal(root->getLeftChild(), searchID);
            }
            else if(searchID > root->getGatorID())
            {
                return searchIDInternal(root->getRightChild(), searchID);
            }
            else
            {
                return root;
            }
        }

        void searchName(string searchName)
        {
            searchName = searchName.substr(1, searchName.size()-2);
            Node* foundNode = searchNameInternal(root, searchName);
            cout << (foundNode != nullptr ? to_string(foundNode->getGatorID()) : "unsuccessful") << endl;
        }

        Node* searchNameInternal(Node* root, string searchName)
        {
            if(root == nullptr) return nullptr;
            if(root->getName() != searchName)
            {
                Node* leftFound = searchNameInternal(root->getLeftChild(), searchName); 
                if(leftFound != nullptr) return leftFound;
                Node* rightFound = searchNameInternal(root->getRightChild(), searchName);
                if(rightFound != nullptr) return rightFound;
                else return nullptr;
            }
            else return root;
        }

        void printInorder()
        {
            printInorderRecursive(root);
        }
        
        void printInorderRecursive(Node* rootNode)
        {
            if(rootNode == nullptr) return;
            printInorderRecursive(rootNode->getLeftChild());
            cout << rootNode->getGatorID() << " " << rootNode->getName() << endl;
            printInorderRecursive(rootNode->getRightChild());
        }

        void printPreorder()
        {
            printPreorderRecursive(root);
        }

        void printPreorderRecursive(Node* rootNode)
        {
            if(rootNode == nullptr) return;
            cout << rootNode->getGatorID() << " " << rootNode->getName() << endl;
            printPreorderRecursive(rootNode->getLeftChild());
            printPreorderRecursive(rootNode->getRightChild());
        }

        void printPostorder()
        {
            printPostorderRecursive(root);
        }

        void printPostorderRecursive(Node* rootNode)
        {
            if(rootNode == nullptr) return;
            cout << rootNode->getGatorID() << " " << rootNode->getName() << endl;
            printPostorderRecursive(rootNode->getLeftChild());
            printPostorderRecursive(rootNode->getRightChild());
        }

        void printLevelCount()
        {
            cout << root->getHeight()+1 << endl;
        }
};