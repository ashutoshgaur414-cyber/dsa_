# Reverse Nodes in k-Group

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 
Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]


Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


 
Constraints:


	The number of nodes in the list is n.
	1 <= k <= n <= 5000
	0 <= Node.val <= 1000


 
Follow-up: Can you solve the problem in O(1) extra memory space?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 16.4 MB (beats 70.79%)  
**Submitted:** 2026-08-22T17:36:15.620Z  

```cpp
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        // Check whether k nodes are available
        for (int i = 0; i < k; i++) {
            if (temp == nullptr)
                return head;
            temp = temp->next;
        }

        // Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // head is now the last node of this group
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-nodes-in-k-group/)