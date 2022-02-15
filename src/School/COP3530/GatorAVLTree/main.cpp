#include "AVLTree.h"

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