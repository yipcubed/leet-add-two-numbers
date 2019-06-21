#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
      void addTwoNumbersR(ListNode* l1, ListNode* l2, ListNode* prev1, ListNode* prev2, int carry) {
        // both finished, take care of carry
        if (!l2 & !l1) {
          // both list finished
          if (carry != 0)
            prev1->next = new ListNode(1);
          return;
        }
        
        // l1 finished, swap them
        if (!l1 && l2) {
          // connect last node in l1 to l2 since
          // we will return the head of l1 when recursion is done
          prev1->next = l2;
          return addTwoNumbersR(l2, l1, prev2, prev1, carry);
        }

        // l1 is not finished
        // l2 may or may not be finished
        l1->val += l2 ? l2->val : 0;
        l1->val += carry;
        if (l1->val > 9) {
            carry = 1;
            l1->val -= 10;
          } else {
            carry = 0;
          }
        return addTwoNumbersR(l1->next, l2 ? l2->next : nullptr, l1, l2, carry);
      }
      
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      addTwoNumbersR(l1, l2, nullptr, nullptr, 0);
      return l1;
    }
};

ostream& operator<<(ostream& os, ListNode* tr) {
  os << "[";
  if (tr)
    os << tr->val;
  tr = tr->next;
  while (tr) {
    os << "," << tr->val;
    tr = tr->next;
  }
  os << "]";
  return os;
}

void test1() {
    Solution S;

  // 2 -> 4 -> 3
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  cout << "l1: " << l1 << endl;
  cout << "l2: " << l2 << endl;
  cout << "708?" << S.addTwoNumbers(l1, l2) << endl;
}

void test2() {
    Solution S;

    // 2 -> 4 -> 3
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(7);

    cout << "l1: " << l1 << endl;
    cout << "l2: " << l2 << endl;
    cout << "342+765?" << S.addTwoNumbers(l1, l2) << endl;
}

void test3() {
    Solution S;

    // 2 -> 4 -> 3
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(7);

    cout << "l1: " << l1 << endl;
    cout << "l2: " << l2 << endl;
    cout << "342+765?" << S.addTwoNumbers(l2, l1) << endl;
}

void test4() {
    Solution S;

    // 2 -> 4 -> 3
    ListNode *l1 = new ListNode(0);

    ListNode *l2 = new ListNode(7);
    l2->next = new ListNode(3);

    cout << "l1: " << l1 << endl;
    cout << "l2: " << l2 << endl;
    cout << "73?" << S.addTwoNumbers(l1, l2) << endl;
}

int main() {

  test1();
  test2();
  test4();

  std::cout << "Done\n";
}