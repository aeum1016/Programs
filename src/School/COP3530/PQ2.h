#include <iostream>
#include <vector>
#include <stack>

struct ListNode
{
    int data;
    ListNode* next;
};

ListNode* addEnd(ListNode* head, int value)
{
    ListNode* newNode = new ListNode;
    newNode -> data = value;
    newNode -> next = nullptr;
    
    if (head == nullptr)
        return newNode;
        
    ListNode* curr = head;
    while(curr -> next != nullptr)
        curr = curr -> next;
        
    curr -> next = newNode; 

    return head;
}

std::vector<int> encryptImage(ListNode* head)
{
   std::stack<int> priors;
   std::vector<int> output;
   while(head != nullptr)
   {
        if(!priors.empty())
        {
            while(head->data > priors.top())
            {
                for(int i = 1; i <= output.size(); i++)
                {
                    if(output[output.size()-i] == 0)
                    {
                        output[output.size()-i] = head->data;
                        break;
                    }
                }
                priors.pop();
                if(priors.empty()) break;
            }
        }
        output.push_back(0);
        priors.push(head->data);
        head = head->next;
   }
   return output;
}