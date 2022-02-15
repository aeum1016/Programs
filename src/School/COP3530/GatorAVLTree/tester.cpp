#define CATCH_CONFIG_MAIN

#include "AVLTree.h"
#include "catch.h"

vector<string> ones {"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> teens {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string nameForNumber (long number) {
    
    if (number < 10) {
        return ones[number];
    } else if (number < 20) {
        return teens [number - 10];
    } else if (number < 100) {
        return tens[number / 10] + ((number % 10 != 0) ? " " + nameForNumber(number % 10) : "");
    } else if (number < 1000) {
        return nameForNumber(number / 100) + " hundred" + ((number % 100 != 0) ? " " + nameForNumber(number % 100) : "");
    } else if (number < 1000000) {
        return nameForNumber(number / 1000) + " thousand" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
    } else if (number < 1000000000) {
        return nameForNumber(number / 1000000) + " million" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
    } else if (number < 1000000000000) {
        return nameForNumber(number / 1000000000) + " billion" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
    }
    return "error";
}

TEST_CASE("Empty operations", "[empty]")
{
  AVLTree tree;

  REQUIRE(tree.getInorder() == "");
  REQUIRE(tree.getPreorder() == "");
  REQUIRE(tree.getPostorder() == "");
  REQUIRE(tree.getLevelCount() == 0);
}

TEST_CASE("10,000 insertions, test inorder traversal", "[largeInsertions]")
{
  AVLTree tree;

  string inorder = "";

  for(int i = 1; i < 10000; i++)
  {
    tree.insert("\"" + nameForNumber(i) + "\"", to_string(i + 10000000));
    inorder.append(nameForNumber(i) + ", ");
  }
  inorder = inorder.substr(0, inorder.size()-2);
  REQUIRE(tree.getInorder() == inorder);  
}

TEST_CASE("10 insertions, test postorder traversal at each", "[insertions]")
{
  AVLTree tree;
  tree.insert("\"" + nameForNumber(1) + "\"", "10000001");
  REQUIRE(tree.getPostorder() == "one");
  tree.insert("\"" + nameForNumber(2) + "\"", "10000002");
  REQUIRE(tree.getPostorder() == "two, one");
  tree.insert("\"" + nameForNumber(3) + "\"", "10000003");
  REQUIRE(tree.getPostorder() == "one, three, two");
  tree.insert("\"" + nameForNumber(4) + "\"", "10000004");
  REQUIRE(tree.getPostorder() == "one, four, three, two");
  tree.insert("\"" + nameForNumber(5) + "\"", "10000005");
  REQUIRE(tree.getPostorder() == "one, three, five, four, two");
  tree.insert("\"" + nameForNumber(6) + "\"", "10000006");
  REQUIRE(tree.getPostorder() == "one, three, two, six, five, four");
  tree.insert("\"" + nameForNumber(7) + "\"", "10000007");
  REQUIRE(tree.getPostorder() == "one, three, two, five, seven, six, four");
  tree.insert("\"" + nameForNumber(8) + "\"", "10000008");
  REQUIRE(tree.getPostorder() == "one, three, two, five, eight, seven, six, four");
  tree.insert("\"" + nameForNumber(9) + "\"", "10000009");
  REQUIRE(tree.getPostorder() == "one, three, two, five, seven, nine, eight, six, four");
  tree.insert("\"" + nameForNumber(10) + "\"", "10000010");
  REQUIRE(tree.getPostorder() == "one, three, two, five, seven, six, ten, nine, eight, four");
}

TEST_CASE("10 insertions, 10 inorder removals w/ test level count at each removal", "[removals]")
{
  AVLTree tree;
  for(int i = 1; i <= 10; i++)
  {
    tree.insert("\"" + nameForNumber(i) + "\"", to_string(i + 10000000));
  }
  tree.removeInorder(9);
  REQUIRE(tree.getLevelCount() == 4);
  tree.removeInorder(8);
  REQUIRE(tree.getLevelCount() == 4);
  tree.removeInorder(7);
  REQUIRE(tree.getLevelCount() == 3);
  tree.removeInorder(6);
  REQUIRE(tree.getLevelCount() == 3);
  tree.removeInorder(5);
  REQUIRE(tree.getLevelCount() == 3);
  tree.removeInorder(4);
  REQUIRE(tree.getLevelCount() == 3);
  tree.removeInorder(3);
  REQUIRE(tree.getLevelCount() == 2);
  tree.removeInorder(2);
  REQUIRE(tree.getLevelCount() == 2);
  tree.removeInorder(1);
  REQUIRE(tree.getLevelCount() == 1);
  tree.removeInorder(0);
  REQUIRE(tree.getLevelCount() == 0);
  
}

TEST_CASE("1,000 insertions, 999 inorder removals, test level count at end", "[largeRemovals]")
{
  AVLTree tree;
  for(int i = 1; i <= 1000; i++)
  {
    tree.insert("\"" + nameForNumber(i) + "\"", to_string(i + 10000000));
  }
  for(int i = 999; i >= 1; i--)
  {
    tree.removeInorder(i);
  }
  REQUIRE(tree.getLevelCount() == 1);
}

TEST_CASE("10 insertions, search by ID for every node", "[searchID]")
{
  AVLTree tree;
  for(int i = 1; i <= 10; i++)
  {
    tree.insert("\"" + nameForNumber(i) + "\"", to_string(i + 10000000));
  }
  for(int i = 1; i <= 10; i++)
  {
    REQUIRE(tree.searchID(to_string(i + 10000000)) == nameForNumber(i)+"\n");
  }
}

TEST_CASE("5 insertions w/ same name, test search by name", "[searchName]")
{
  AVLTree tree;
  string name = "Firstname Lastname";
  for(int i = 1; i <= 5; i++)
  {
    tree.insert("\"" + name + "\"", to_string(i + 10000000));
  }
  REQUIRE(tree.searchName("\"" + name + "\"") == "10000002\n10000001\n10000004\n10000003\n10000005\n");
}