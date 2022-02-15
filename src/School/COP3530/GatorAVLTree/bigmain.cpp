#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

/**
 * reads and loads the name and gatorID input from cin
 */
void loadInput(string& name, string& gatorID)
{
      getline(cin, name);

      int secondQuotation = name.find('\"', 2);
      gatorID = name.substr(secondQuotation+2);
      name = name.substr(1, secondQuotation);
}

/**
 * returns whether the input string is
 * a valid gatorID.
 * 
 * @return is the input a valid gatorID
 */
bool isValidGatorID(string gatorID)
{
  regex id("^[0-9]{8}$");
  return regex_match(gatorID, id);
}

/**
 * returns whether the input string is
 * a valid name.
 * 
 * @return is the input a valid name.
 */
bool isValidName(string name)
{
  regex nameRegEx("^\"[A-Za-z\\s]+\"$");
  return regex_match(name, nameRegEx);
}

/**
 * returns whether the input strings are both
 * valid
 * 
 * @return are the inputs a valid name and valid gatorID
 */
bool isValidInput(string name, string gatorID)
{
  return isValidName(name) && isValidGatorID(gatorID);
}

/**
 * prints "successful"
 */
void printSuccessful()
{
  cout << "successful" << endl;
}

/**
 * prints "unsuccessful"
 */
void printUnsuccessful()
{
  cout << "unsuccessful" << endl;
}

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

class AVLTree
{
    private:
        Node* root = nullptr;
        
        /**
         * Inserts a new node into the tree using recursion.
         *
         * The function recursively sets the left or right child
         * of the previous node, eventually ending with the
         * new node.
         *
         * @param name  Name value of the new node.
         * @param id    GatorID value of the new node.
         * @param rootNode Initial root node.
         * @return      Returns the new root node.
         */
        Node* insertRecursive(string name, string id, Node* rootNode)
        {
            if(rootNode == nullptr)
            {
                return new Node(name, id);
            }
            else if(stoi(id) < stoi(rootNode->getGatorID()))
            {
                rootNode->setLeftChild(insertRecursive(name, id, rootNode->getLeftChild()));
                rootNode = rootNode->fixBalance();
            }
            else if(stoi(id) > stoi(rootNode->getGatorID()))
            {
                rootNode->setRightChild(insertRecursive(name, id, rootNode->getRightChild()));
                rootNode = rootNode->fixBalance();
            }
            else 
            {
                throw("Failed");
            }
            return rootNode;
        }

        /**
         * Searches for a node in the tree using recursion.
         *
         * The function recursively travels to the left or 
         * right child to find the Node with the given
         * gatorID
         *
         * @param root Root of the tree.
         * @param searchID GatorID to look for in the tree.
         * @return Returns the node with the given GatorID or throws an error if it can't be found.
         */
        Node* searchIDRecursive(Node* root, string searchID)
        {
            if(root == nullptr) throw("Failed Search, ID not Found");
            else if(stoi(searchID) < stoi(root->getGatorID()))
            {
                return searchIDRecursive(root->getLeftChild(), searchID);
            }
            else if(stoi(searchID) > stoi(root->getGatorID()))
            {
                return searchIDRecursive(root->getRightChild(), searchID);
            }
            else
            {
                return root;
            }
        }

        /**
         * Searches for a node in the tree using recursion.
         *
         * The function recursively travels to both the left and 
         * right child to find Nodes with the given name and
         * adds them to an output vector.
         *
         * @param root Root of the tree.
         * @param searchname Name to look for in the tree.
         * @param foundNodes The previous nodes that were found.
         * @return Returns a vector of nodes with the given name.
         */
        vector<Node*> searchNameRecursive(Node* root, string searchName, vector<Node*>& foundNodes)
        {
            if(root == nullptr) return foundNodes;

            if(root->getName() == searchName)
            {
                foundNodes.push_back(root);
            }

            foundNodes = searchNameRecursive(root->getLeftChild(), searchName, foundNodes); 
            foundNodes = searchNameRecursive(root->getRightChild(), searchName, foundNodes);

            return foundNodes;
        }

        /**
         * Removes the node with the given GatorID.
         *
         * The function recursively travels to the left or 
         * right child to find the Node with the given
         * gatorID. Then deletes the node. Followed by fixing
         * the balance of the tree.
         *
         * @param root Root of the tree.
         * @param removedID GatorID to look for in the tree.
         * @return Returns the new root of the given tree.
         */
        Node* removeIDRecursive(Node* root, string removedID)
        {
            if(root == nullptr) throw("Failed deletion");
            if(stoi(root->getGatorID()) > stoi(removedID))
            {
                root->setLeftChild(removeIDRecursive(root->getLeftChild(), removedID));
                root = root->fixBalance();
            }
            else if(stoi(root->getGatorID()) < stoi(removedID))
            {
                root->setRightChild(removeIDRecursive(root->getRightChild(), removedID));
                root = root->fixBalance();
            }
            else
            {
                if(root->getNumChildren() == 0)
                {
                    delete root;
                    return nullptr;
                }
                else if(!root->hasLeftChild())
                {
                    Node* temp = root->getRightChild();
                    delete root;
                    return temp;
                }
                else if(!root->hasRightChild())
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
                    root->setName(IOSuccessor->getName());
                    root->setGatorID(IOSuccessor->getGatorID());
                    root->setRightChild(removeIDRecursive(root->getRightChild(), IOSuccessor->getGatorID()));
                }
            }
            return root;
        }

        /**
         * Removes a node in the tree based on its position
         * in an inorder traversal.
         *
         * The function performs an inorder traversal until a certain
         * given term, then calls removeID on the node that the 
         * traversal stops on.
         *
         * @param rootNode Root of the tree.
         * @param curTerm The current term of the inorder traversal.
         * @param nthTerm The term of the inorder traversal to stop on.
         * @return Returns -1 if removeID is called successfully, any other number otherwise.
         */
        int removeInorderRecursive(Node* rootNode, int curTerm, int nthTerm)
        {
            if(rootNode == nullptr) return curTerm;
            curTerm = removeInorderRecursive(rootNode->getLeftChild(), curTerm, nthTerm);
            if(curTerm == -1) return -1;
            if(curTerm == nthTerm) 
            {
                removeID(rootNode->getGatorID());
                return -1;
            }
            else curTerm++;
            curTerm = removeInorderRecursive(rootNode->getRightChild(), curTerm, nthTerm);
            return curTerm;
        }

        /**
         * Returns the inorder traversal of the given tree with terms
         * separated by commas.
         *
         * @param rootNode Root of the tree.
         * @param output The output to be added onto by each recursion of the function.
         * @return Returns the inorder traversal in the form of a string.
         */
        string getInorderTraversal(Node* rootNode, string output)
        {
            if(rootNode == nullptr) return output;
            output = getInorderTraversal(rootNode->getLeftChild(), output);
            output.append(rootNode->getName() + ", ");
            output = getInorderTraversal(rootNode->getRightChild(), output);
            return output;
        }

        /**
         * Returns the preorder traversal of the given tree with terms
         * separated by commas.
         *
         * @param rootNode Root of the tree.
         * @param output The output to be added onto by each recursion of the function.
         * @return Returns the preorder traversal in the form of a string.
         */
        string getPreorderTraversal(Node* rootNode, string output)
        {
            if(rootNode == nullptr) return output;
            output.append(rootNode->getName() + ", ");
            output = getPreorderTraversal(rootNode->getLeftChild(), output);
            output = getPreorderTraversal(rootNode->getRightChild(), output);
            return output;
        }

        /**
         * Returns the postorder traversal of the given tree with terms
         * separated by commas.
         *
         * @param rootNode Root of the tree.
         * @param output The output to be added onto by each recursion of the function.
         * @return Returns the postorder traversal in the form of a string.
         */
        string getPostorderTraversal(Node* rootNode, string output)
        {
            if(rootNode == nullptr) return output;
            output = getPostorderTraversal(rootNode->getLeftChild(), output);
            output = getPostorderTraversal(rootNode->getRightChild(), output);
            output.append(rootNode->getName() + ", ");
            return output;
        }

    public:

        /**
         * Inserts a node into the tree
         * 
         * Performs a validation check on the given input before
         * attempting to add the node into the tree.
         *
         * @param name Name of the node to be added.
         * @param id GatorID of the node to be added.
         * @return Prints "successful" if successful, "unsuccessful" if unsuccessful
         */
        void insert(string name, string id)
        {
            if(isValidInput(name, id))
            {
                try
                {
                    string nameNoQuotations = name.substr(1, name.size()-2);
                    root = insertRecursive(nameNoQuotations, id, root);
                    printSuccessful();
                }
                catch(...)
                {
                    printUnsuccessful();
                }
            }
            else
            {
                printUnsuccessful();
            }
        }

        /**
         * Searches for a node in the tree
         * 
         * Tests is the input is a valid gatorID. If 
         * it is, searches for the input as an ID. Otherwise searches
         * for the input as a name
         *
         * @param searchQuery Either a name or GatorID to search for
         * @return Prints the name of any found GatorID. Prints the IDs of all found names
         */
        void search(string searchQuery)
        {
                if(isValidGatorID(searchQuery)) cout << searchID(searchQuery);
                else cout << searchName(searchQuery);
        }

        /**
         * Searches for a node in the tree with the given gatorID
         * 
         * Tests is the input is a valid gatorID. If 
         * it is, searches for the input as an ID. Prints
         * the name of the node if found, otherwise prints
         * "unsuccessful"
         *
         * @param searchID GatorID to search for
         * @return Prints the name of any found GatorID. Prints "unsuccessful" if fails.
         */
        string searchID(string searchID)
        {
            try
            {
                isValidGatorID(searchID);
                Node* foundNode = searchIDRecursive(root, searchID);
                return foundNode->getName() + "\n";
            }
            catch(...)
            {
                printUnsuccessful();
                return "";
            }
        }

        /**
         * Searches for nodes in the tree with the given name
         * 
         * Removes expected quotations from the name input. Calls
         * searchNameRecursive and prints the ID value of the nodes
         * that are returned.
         *
         * @param searchName Name to search for
         * @return Prints the GatorID of all found nodes. Prints "unsuccessful" if no nodes found.
         */
        string searchName(string searchName)
        {
            searchName = searchName.substr(1, searchName.size()-2);

            vector<Node*> foundNodes;

            foundNodes = searchNameRecursive(root, searchName, foundNodes);
                        
            if(foundNodes.empty()) 
            {
                printUnsuccessful();
                return "";
            }

            string output;

            for(Node* node : foundNodes)
            {
                output.append(node->getGatorID() + "\n");
            }

            return output;
        }

        /**
         * Removes the node with the given ID.
         * 
         * If the removalID is a valid integer, tries to 
         * remove the ID by calling removeIDRecursive. 
         *
         * @param removedID GatorID to be removed
         * @return Prints "successful" if successfully removed. Prints "unsuccessful" if no nodes found.
         */
        void removeID(string removedID)
        {
            try
            {
                isValidGatorID(removedID);
                root = removeIDRecursive(root, removedID);
                printSuccessful();
            }
            catch(...)
            {
                printUnsuccessful();
            }
        }

        /**
         * Removes the nth term in the preorder traversal
         * of the given tree.
         * 
         * Calls removeInorderRecursive to remove the node.
         * Prints the output ("successful" or "unsuccessful").
         *
         * @param nthTerm The term in the preorder traversal to be removed
         * @return Prints "successful" if successfully removed. Prints "unsuccessful" if no nodes found.
         */
        void removeInorder(int nthTerm)
        {
            if(removeInorderRecursive(root, 0, nthTerm) != -1) printUnsuccessful();
        }
        
        /**
         * Gets the inorder traversal of the tree by
         * calling getInorderTraversal.
         * 
         * @return The inorder traversal separated by commas.
         */
        string getInorder()
        {
            string inorder = getInorderTraversal(root, "");
            return inorder.substr(0, inorder.size()-2);
        }

        /**
         * Prints the return value of getInorder.
         * 
         * @return Prints the inorder traversal.
         */
        void printInorder()
        {
            cout << getInorder() << endl;
        }

        /**
         * Gets the preorder traversal of the tree by
         * calling getPreorderTraversal.
         * 
         * @return The preorder traversal separated by commas.
         */
        string getPreorder()
        {
            string preorder = getPreorderTraversal(root, "");
            return preorder.substr(0, preorder.size()-2);
        }

        /**
         * Prints the return value of getPreorder.
         * 
         * @return Prints the preorder traversal.
         */
        void printPreorder()
        {
            cout << getPreorder() << endl;
        }

        /**
         * Gets the postorder traversal of the tree by
         * calling getPostorderTraversal.
         * 
         * @return The postorder traversal separated by commas.
         */
        string getPostorder()
        {
            string postorder = getPostorderTraversal(root, "");
            return postorder.substr(0, postorder.size()-2);
        }

        /**
         * Prints the return value of getPostorder.
         * 
         * @return Prints the postorder traversal.
         */
        void printPostorder()
        {      
            cout << getPostorder() << endl;
        }

        /**
         * Returns the one based height of the tree
         * 
         * @return 1-based height of the tree. 0 if root is a nullptr;
         */
        int getLevelCount()
        {
            if(root == nullptr)
            {
                return 0 ;
            }
            else return root->getHeight() + 1;
        }

        /**
         * Prints the height of the tree from getLevelCount
         * 
         * @return Prints the 1-based height of the tree;
         */
        void printLevelCount()
        {
            cout << getLevelCount() << endl;
        }
};

int main()
{
  
  AVLTree tree;

  int numberOfCommands;
  cin >> numberOfCommands;

  for(int i = 0; i < numberOfCommands; i++)
  {

    string command;
    cin >> command;

    if(command == "insert")
    {
      string name;
      string gatorID;
      loadInput(name, gatorID); // Reads the input and stores it to name and gatorID
      tree.insert(name, gatorID);
    }
    else if(command == "search")
    {
      string searchQuery;
      cin >> searchQuery;
      tree.search(searchQuery);
    }
    else if(command == "remove")
    {
      string removeQuery;
      cin >> removeQuery;
      tree.removeID(removeQuery);
    }
    else if(command == "removeInorder")
    {
      int removeQuery;
      cin >> removeQuery;
      tree.removeInorder(removeQuery);
    }
    else if(command == "printInorder")
    {
      tree.printInorder();
    }
    else if(command == "printPreorder")
    {
      tree.printPreorder();
    }
    else if(command == "printPostorder")
    {
      tree.printPostorder();
    }
    else if(command == "printLevelCount")
    {
      tree.printLevelCount();
    }
  }

  return 0;
};