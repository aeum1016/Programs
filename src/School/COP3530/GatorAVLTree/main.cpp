#include "AVLTree.h"
#include "Node.h"


int main()
{
  
  AVLTree tree;

  int q;

  cin >> q;

  for(int i = 0; i < q; i++)
  {
    string command;
    cin >> command;
    if(command == "insert")
    {
      string name;
      int gatorID;
      cin >> name >> gatorID;
      tree.insert(name, gatorID);
    }
    else if(command == "search")
    {
      string searchQuery;
      cin >> searchQuery;
      try
      {
        int searchID = stoi(searchQuery);
        tree.searchID(searchID);
      }
      catch(...)
      {
        tree.searchName(searchQuery);
      }
    }
    else if(command == "remove")
    {
      int removeID;
      cin >> removeID;
      tree.deleteID(removeID);
    }
    else if(command == "removeInorder")
    {
      int removeNumber;
      cin >> removeNumber;
      tree.deleteInorder(removeNumber);
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

    tree.printInorder();
  }

  return 0;
};