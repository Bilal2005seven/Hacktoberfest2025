/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Function to merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = nullptr;
        if (l1->val < l2->val) {
            head = l1;
            head->next = merge(l1->next, l2);
        } else {
            head = l2;
            head->next = merge(l1, l2->next);
        }
        return head;
    }

    // Function to find the middle of the list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Main merge sort function
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Split into two halves
        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        // Recursively sort both halves
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        // Merge sorted halves
        return merge(leftSorted, rightSorted);
    }
};
