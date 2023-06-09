
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
        
        ListNode* itr1 = l1, *itr2 = l2;
        ListNode* result = new ListNode(), *itr = result;
        int carry = 0;

        while (itr1 && itr2) {
            int val = (itr1->val + itr2->val + carry) % 10;
            itr->next = new ListNode(val);
            itr = itr->next;
            carry = (itr1->val + itr2->val + carry) / 10;
            itr1 = itr1->next;
            itr2 = itr2->next;
        }

        while (itr1) {
            int val = (itr1->val + carry) % 10;
            carry = (itr1->val + carry) / 10;
            itr->next = new ListNode(val);
            itr = itr->next;
            itr1 = itr1->next;
        }

        while (itr2) {
            int val = (itr2->val + carry) % 10;
            carry = (itr2->val + carry) / 10;
            itr->next = new ListNode(val);
            itr = itr->next;
            itr2 = itr2->next;
        }

        if (carry) {
            itr->next = new ListNode(carry);
        }
        // itr = nullptr;
        return result->next;
    }
};