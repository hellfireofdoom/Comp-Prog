using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  int main(){
    ListNode* head(0);
    ListNode* cur = head;
    for(int i = 1; i < 10; i ++){
        cur->next = new ListNode(i);
        cur = cur->next;

    }
    
  }