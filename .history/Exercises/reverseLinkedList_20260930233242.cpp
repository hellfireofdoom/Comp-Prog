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
    ListNode* prev = head;
    ListNode* temp;
    head = head->next;
    prev->next = nullptr;
    while(head){
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
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

    head = reverseLinkedList(head);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    
  }