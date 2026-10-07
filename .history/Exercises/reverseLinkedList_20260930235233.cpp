#include <iostream>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


  ListNode* reverseLinkedList(ListNode* head){
    if(!head){
        return nullptr;
    }

    ListNode* cur = head;
    ListNode* prev = cur;
    ListNode* temp;
    cur = cur->next;
    prev->next = nullptr;

    while(cur){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
  }
  int main(){
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    for(int i = 1; i < 10; i ++){
        cur->next = new ListNode(i);
        cur = cur->next;

    }
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";

    reverseLinkedList(head);
    cout << head->next << "\n";
    cout << nullptr << "\n";
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    
  }