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
    else if(command == "printLevelCount")
    {
      tree.printLevelCount();
    }
    
  }

  // tree.printInorder();
  // cout << tree.root->getHeight();

  return 0;
};