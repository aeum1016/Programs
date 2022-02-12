#include <iostream>
#include <vector>
#include <string>

#pragma once

using namespace std;


class Node
{

  string name = "";
  int gatorID = 0;
  Node* left = nullptr;
  Node* right = nullptr;
  int height = 0;
  int balance = 0;
  
  public:

    Node(string name, int gatorID, Node* left = nullptr, Node* right = nullptr)
    {
      this->name = name;
      this->gatorID = gatorID;
      this->left = left;
      this->right = right;
      updateBalance();
    }

    Node* fixBalance()
    {
      updateBalance();
      if(balance >= 2) // left heavy
      {
        if(left->balance < 0) // child is right heavy
        {
          return leftRightRotation();
        }
        else 
        {
          return rightRotation();
        }
      }
      else if(balance <= -2)
      {
        if(right->balance > 0) // child is left heavy
        {
          return rightLeftRotation();
        }
        else 
        {
          return leftRotation();
        }
      }
      return this;
    }

    void updateBalance()
    {
      if(this == nullptr) return;
      int leftH = left == nullptr ? -1 : left->height;
      int rightH = right == nullptr ? -1 : right->height;
      height = max(leftH, rightH) + 1;
      balance = leftH - rightH;
    }

    void updateBalanceRecur()
    {
      if(this == nullptr) return;
      if(left != nullptr) left->updateBalanceRecur();
      if(right != nullptr) right->updateBalanceRecur();
      int leftH = left == nullptr ? -1 : left->height;
      int rightH = right == nullptr ? -1 : right->height;
      height = max(leftH, rightH) + 1;
      balance = leftH - rightH;
    }

    Node* leftRotation()
    {
      Node* grandchild = this->right->left;
      Node* newParent = this->right;
      newParent->left = this;
      this->right = grandchild;
      this->updateBalance();
      grandchild->updateBalance();
      return newParent;
    }

    Node* rightRotation()
    {
      Node* grandchild = this->left->right;
      Node* newParent = this->left;
      newParent->right = this;
      this->left = grandchild;
      this->updateBalance();
      grandchild->updateBalance();
      return newParent;
    }

    Node* leftRightRotation()
    {
      left = left->leftRotation();
      return rightRotation();
    }

    Node* rightLeftRotation()
    {
      right = right->rightRotation();
      return leftRotation();
    }

    Node* getLeftChild()
    {
      return left;
    }

    Node* getRightChild()
    {
      return right;
    }

    void setLeftChild(Node* newLeft)
    {
      left = newLeft;
    }

    void setRightChild(Node* newRight)
    {
      right = newRight;
    }

    int getGatorID()
    {
      return gatorID;
    }

    string getName()
    {
      return name;
    }

    int getBalance()
    {
      return balance;
    }

    int getHeight()
    {
      return height;
    }
};