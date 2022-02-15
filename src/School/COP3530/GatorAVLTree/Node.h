#include <iostream>
#include <vector>
#include <string>

#pragma once

using namespace std;

class Node
{
  private:
    string name = "";
    string gatorID = "";

    Node* left = nullptr;
    Node* right = nullptr;

    int height = 0;
    int balance = 0;

    /**
     * Updates the balance of each node using the heights 
     * of its child nodes
     * 
     * @return null;
     */
    void updateBalance()
    {
      if(this == nullptr) return;

      int leftHeight = left == nullptr ? -1 : left->height;
      int rightHeight = right == nullptr ? -1 : right->height;

      height = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
      balance = leftHeight - rightHeight;
    }

    /**
     * Perform a left rotation on itself
     * and returns its right child after
     * updating balances.
     * 
     * @return Right child (new parent node)
     */
    Node* leftRotation()
    {
      Node* grandchild = this->right->left;
      Node* newParent = this->right;

      newParent->left = this;
      this->right = grandchild;

      this->updateBalance();
      newParent->updateBalance();

      return newParent;
    }

    /**
     * Perform a right rotation on itself
     * and returns its left child after
     * updating balances.
     * 
     * @return Left child (new parent node)
     */
    Node* rightRotation()
    {
      Node* grandchild = this->left->right;
      Node* newParent = this->left;

      newParent->right = this;
      this->left = grandchild;

      this->updateBalance();
      newParent->updateBalance();
      
      return newParent;
    }

    /**
     * Perform a left rotation on its 
     * left child. Then performs a right
     * rotation on itself
     * 
     * @return Left child (new parent node)
     */
    Node* leftRightRotation()
    {
      left = left->leftRotation();
      return rightRotation();
    }

    /**
     * Perform a right rotation on its 
     * right child. Then performs a left
     * rotation on itself
     * 
     * @return Right child (new parent node)
     */
    Node* rightLeftRotation()
    {
      right = right->rightRotation();
      return leftRotation();
    }

  public:

    Node(string name, string gatorID)
    {
      this->name = name;
      this->gatorID = gatorID;
    }

    /**
     * Updates balance, then calls any
     * necessary rotations on itself.
     * 
     * @return Node where the original node was.
     */
    Node* fixBalance()
    {
      updateBalance();
      if(balance >= 2) // left heavy
      {
        return ((left->balance < 0) ? leftRightRotation() : rightRotation());
      }
      else if(balance <= -2)
      {
        return ((right->balance > 0) ? rightLeftRotation() : leftRotation());
      }
      else
      {
        return this;
      }
    }

    /**
     * Returns the left child the instance.
     * 
     * @return Left child of this.
     */
    Node* getLeftChild()
    {
      return left;
    }

    /**
     * Returns the right child the instance.
     * 
     * @return Right child of this.
     */
    Node* getRightChild()
    {
      return right;
    }
    
    /**
     * @return # of children that this node.
     */
    int getNumChildren()
    {
      return (left != nullptr) + (right != nullptr);
    }

    /**
     * @return The gator ID of this node.
     */
    string getGatorID()
    {
      return gatorID;
    }

    /**
     * @return The name of the node.
     */
    string getName()
    {
      return name;
    }

    /**
     * @return The balance of the node
     */
    int getBalance()
    {
      return balance;
    }

    /**
     * @return The height of the node
     */
    int getHeight()
    {
      return height;
    }

    /**
     * Sets the left child of this node
     * 
     * @param newLeft the new right child of the node
     */
    void setLeftChild(Node* newLeft)
    {
      left = newLeft;
    }

    /**
     * Sets the right child of this node
     * 
     * @param newRight the new right child of the node
     */
    void setRightChild(Node* newRight)
    {
      right = newRight;
    }

    /**
     * Sets the gatorID of this node
     * 
     * @param newGatorID the new gatorID for the node
     */
    void setGatorID(string newGatorID)
    {
      gatorID = newGatorID;
    }

    /**
     * Sets the name of this node
     * 
     * @param newName the new name for the node
     */
    void setName(string newName)
    {
      name = newName;
    }

    /**
     * returns whether the node has a left child
     * 
     * @return true if the node has a left child, false if not
     */
    bool hasLeftChild()
    {
      return left != nullptr;
    }
    
    /**
     * returns whether the node has a right child
     * 
     * @return true if the node has a right child, false if not
     */
    bool hasRightChild()
    {
      return right != nullptr;
    }
    
};