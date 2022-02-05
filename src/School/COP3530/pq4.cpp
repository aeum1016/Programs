#include <iostream>

#include <queue>
#include <vector>

using namespace std;

 class TreeNode 
 {
     public:
       int val;
       int level;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x, int lev) : val(x), level(lev), left(nullptr), right(nullptr) {}
 };

TreeNode* insert(TreeNode* root, int data, int level = 0) 
{
      if (root == nullptr)
        return new TreeNode(data, level);
      if (root->val < data)
        root->right = insert(root->right, data, level+1);
      else 
        root->left = insert(root->left, data, level+1);
      return root;
}

int sumOfLevel(TreeNode* root, int level) 
{
  queue<TreeNode*> DFS;
  DFS.push(root);
  int sum = 0;
  bool levelReached = false;
  while(!DFS.empty())
  {
    if(DFS.front() != nullptr){
      if(DFS.front()->level == level){
        sum += DFS.front()->val;
        levelReached = true;
      }
      else if(DFS.front()->level > level) break;
      DFS.push(DFS.front()->left);
      DFS.push(DFS.front()->right);
      DFS.pop();
    }
    else DFS.pop();
  }
  return levelReached ? sum : -1;
}
