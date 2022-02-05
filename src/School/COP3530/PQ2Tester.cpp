#include "PQ2.h"

#include <ctime>
#include <chrono>
#include <iomanip> 

using namespace std;
using chrono::duration_cast;
using chrono::milliseconds;
using chrono::seconds;
using chrono::system_clock;

bool greaterThan(ListNode* head)
{
  int data = head->data;
  while(head != nullptr)
  {
    if(data < head->data) return false;
    head = head->next;
  }
  return true;
}

int main()
{
  srand((unsigned) time(nullptr));

  int tests = 500000;

  for(int i = 0; i < tests; i++)
  {
    ListNode* tester = nullptr;
    int cases = (rand() % 25) + 1;

    for(int j = 0; j < (cases * 3)-1; j++)
    {
      tester = addEnd(tester, (rand() % 256) + 1);
    }

    vector<int> output = encryptImage(tester);
    
    ListNode* temp = tester;

    bool incorrect = false;
    for(int j = 0; j < output.size(); j++)
    {
      if(incorrect) break;

      temp = tester;
      for(int k = 0; k < j; k++)
      {
        temp = temp->next;
      }

      for(int k = j; k < output.size(); k++)
      {
        if(output[j] == 0)
        {
          incorrect = !greaterThan(temp);
          break;
        }
        else if(output[j] > temp->data) temp = temp->next;
        else if(output[j] == temp->data) 
        {
          break;
        }
        else if(output[j] < temp->data)
        {
          incorrect = true;
          break;
        }
      }
    }

    if(incorrect)
    {
      for(int j = 0; j < output.size(); j++)
      {
        cout << setw(4) << temp->data;
        temp = temp->next;
      }
      cout << endl;

      for(int j = 0; j < output.size(); j++)
      {
        cout << setw(4) << output[j];
      }
      cout << endl;
    }

  }

  return 0;
}