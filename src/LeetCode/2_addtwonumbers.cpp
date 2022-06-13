
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // adding
        // instinct: one pass
        // create a new linked list
        // add nodes, put remainder after mode 10 in new node
        // if greater than 10, boolean true
        // keep going until the end and no boolean true
        
        ListNode* ans = new ListNode(-1);
        ListNode* curNode = ans;

        int sum = 0;

        while(l1 != nullptr && l2 != nullptr || sum != 0)
        {
          if(l1 != nullptr)
          {
            sum += l1->val;
            l1 = l1->next;
          }
          if(l2 != nullptr)
          {
            sum += l2->val;
            l2 = l2->next;
          }

          ListNode* newNode = new ListNode(sum%10);

          if(ans->val == -1)
          {
            ans = newNode;
          }
          else
          {
            curNode->next = newNode;
          }
          curNode = newNode;

          sum >= 10 ? sum = 1 : sum = 0;

        }

      return ans;
    }
};