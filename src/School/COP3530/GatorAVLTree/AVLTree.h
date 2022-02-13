#include <iostream>
#include <vector>
#include <string>

#include "Node.h"
#include "Validator.h"

#pragma once

using namespace std;


class AVLTree
{
    public:
        Node* root = nullptr;

        void insert(string name, int id)
        {
            if(validateName(name) && validateGatorID(id))
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
            else
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

        Node* searchParentInternal(Node* root, int searchID)
        {
            if(root == nullptr) throw("Failed Search");
            if(root->getGatorID() == searchID) return root;
            else
            {
                if(root->getLeftChild() != nullptr)
                {
                    if(root->getLeftChild()->getGatorID() == searchID) return root;
                }
                if(root->getRightChild() != nullptr)
                {
                    if(root->getRightChild()->getGatorID() == searchID) return root;
                }

                if(searchID < root->getGatorID())
                {
                    return searchParentInternal(root->getLeftChild(), searchID);
                }
                else
                {
                    return searchParentInternal(root->getRightChild(), searchID);
                }
            }
        }

        void searchName(string searchName)
        {
            searchName = searchName.substr(1, searchName.size()-2);

            vector<Node*> foundNodes;

            foundNodes = searchNameInternal(root, searchName, foundNodes);

            for(Node* node : foundNodes)
            {
                cout << to_string(node->getGatorID()) << endl;
            }

            if(foundNodes.empty()) cout << "unsuccessful" << endl;
        }

        vector<Node*> searchNameInternal(Node* root, string searchName, vector<Node*>& foundNodes)
        {
            if(root == nullptr) return foundNodes;

            if(root->getName() == searchName)
            {
                foundNodes.push_back(root);
            }

            foundNodes = searchNameInternal(root->getLeftChild(), searchName, foundNodes); 
            foundNodes = searchNameInternal(root->getRightChild(), searchName, foundNodes);

            return foundNodes;
        }

        void deleteID(int deletedID)
        {
            try
            {
                root = deleteIDInternal(root, deletedID);
                cout << "successful" << endl;
            }
            catch(...)
            {
                cout << "unsuccessful" << endl;
            }
        }

        Node* deleteIDInternal(Node* root, int deletedID)
        {
            if(root == nullptr) throw("Failed deletion");

            if(root->getGatorID() > deletedID)
            {
                root->setLeftChild(deleteIDInternal(root->getLeftChild(), deletedID));
            }
            else if(root->getGatorID() < deletedID)
            {
                root->setRightChild(deleteIDInternal(root->getRightChild(), deletedID));
            }
            else
            {
                if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr)
                {
                    delete root;
                    return nullptr;
                }
                else if(root->getLeftChild() == nullptr)
                {
                    Node* temp = root->getRightChild();
                    delete root;
                    return temp;
                }
                else if(root->getRightChild() == nullptr)
                {
                    Node* temp = root->getLeftChild();
                    delete root;
                    return temp;
                }
                else
                {
                    Node* IOSuccessor = root->getRightChild();
                    while(IOSuccessor->getLeftChild() != nullptr)
                    {
                        IOSuccessor = IOSuccessor->getLeftChild();
                    }
                    int tempGatorID = IOSuccessor->getGatorID();
                    root->setName(IOSuccessor->getName());
                    root->setGatorID(IOSuccessor->getGatorID());
                    root->setRightChild(deleteIDInternal(root->getRightChild(), IOSuccessor->getGatorID()));
                    return root;
                }
            }
            return root;
        }

        void deleteInorder(int n)
        {
            if(!deleteInorderRecursive(root, 0, n)) cout << "unsuccessful" << endl;
        }

        int deleteInorderRecursive(Node* rootNode, int cur, int n)
        {
            if(rootNode == nullptr) return cur;
            cur = deleteInorderRecursive(rootNode->getLeftChild(), cur, n);
            if(cur == -1) return -1;
            if(cur == n) 
            {
                deleteID(rootNode->getGatorID());
                return -1;
            }
            else cur++;
            cur = deleteInorderRecursive(rootNode->getRightChild(), cur, n);
            return cur;
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
            printPostorderRecursive(rootNode->getLeftChild());
            printPostorderRecursive(rootNode->getRightChild());
            cout << rootNode->getGatorID() << " " << rootNode->getName() << endl;
        }

        void printLevelCount()
        {
            cout << root->getHeight()+1 << endl;
        }
};