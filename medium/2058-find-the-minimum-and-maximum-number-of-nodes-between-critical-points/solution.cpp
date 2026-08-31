class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstIdx = -1, prevIdx = -1, idx = 1;
        int minDist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr->next != nullptr) {
            bool isMaxima = curr->val > prev->val && curr->val > curr->next->val;
            bool isMinima = curr->val < prev->val && curr->val < curr->next->val;
            
            if (isMaxima || isMinima) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDist = min(minDist, idx - prevIdx);
                }
                prevIdx = idx;
            }
            
            prev = curr;
            curr = curr->next;
            idx++;
        }
        
        if (firstIdx == -1 || firstIdx == prevIdx) {
            // fewer than 2 critical points found
            return {-1, -1};
        }
        
        int maxDist = prevIdx - firstIdx;
        return {minDist, maxDist};
    }
};