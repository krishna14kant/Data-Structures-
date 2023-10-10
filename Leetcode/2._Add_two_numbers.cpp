// Add Two Numbers LeetCode Solution

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *preHead = new ListNode(0), *p = preHead;
        int carry = 0;  // Carry from sum

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;  // Calculate the carry
            p->next = new ListNode(sum % 10);  // Add the new node to the result list
            p = p->next;  // Move the pointer to the next node
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return preHead->next;  // Return the result list
    }
};

int main() {
    // Usage example
    Solution solution;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
