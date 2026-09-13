class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> onesA, onesB;
        
        // Collect coordinates of 1s in both images
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) onesA.push_back({i, j});
                if (img2[i][j] == 1) onesB.push_back({i, j});
            }
        }
        
        // For every pair of 1s (one from each image), compute the shift
        // needed to align them, and count how often each shift occurs.
        unordered_map<int, int> count;
        int maxOverlap = 0;
        
        for (auto& a : onesA) {
            for (auto& b : onesB) {
                int dx = a.first - b.first;
                int dy = a.second - b.second;
                int key = dx * 200 + dy; // encode (dx, dy) into a single key
                count[key]++;
                maxOverlap = max(maxOverlap, count[key]);
            }
        }
        
        return maxOverlap;
    }
};