# Minimum Moves to Clean the Classroom

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:


	'S': Starting position of the student
	'L': Litter that must be collected (once collected, the cell becomes empty)
	'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
	'X': Obstacle the student cannot pass through
	'.': Empty space


You are also given an integer energy, representing the student's maximum energy capacity. The student starts with this energy from the starting position 'S'.

Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area 'R', which resets the energy to its maximum capacity energy.

Return the minimum number of moves required to collect all litter items, or -1 if it's impossible.

 
Example 1:


Input: classroom = ["S.", "XL"], energy = 2

Output: 2

Explanation:


	The student starts at cell (0, 0) with 2 units of energy.
	Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
	A valid sequence of moves to collect all litter is as follows:
	
		Move 1: From (0, 0) → (0, 1) with 1 unit of energy and 1 unit remaining.
		Move 2: From (0, 1) → (1, 1) to collect the litter 'L'.
	
	
	The student collects all the litter using 2 moves. Thus, the output is 2.



Example 2:


Input: classroom = ["LS", "RL"], energy = 4

Output: 3

Explanation:


	The student starts at cell (0, 1) with 4 units of energy.
	A valid sequence of moves to collect all litter is as follows:
	
		Move 1: From (0, 1) → (0, 0) to collect the first litter 'L' with 1 unit of energy used and 3 units remaining.
		Move 2: From (0, 0) → (1, 0) to 'R' to reset and restore energy back to 4.
		Move 3: From (1, 0) → (1, 1) to collect the second litter 'L'.
	
	
	The student collects all the litter using 3 moves. Thus, the output is 3.



Example 3:


Input: classroom = ["L.S", "RXL"], energy = 3

Output: -1

Explanation:

No valid path collects all 'L'.


 
Constraints:


	1 <= m == classroom.length <= 20
	1 <= n == classroom[i].length <= 20
	classroom[i][j] is one of 'S', 'L', 'R', 'X', or '.'
	1 <= energy <= 50
	There is exactly one 'S' in the grid.
	There are at most 10 'L' cells in the grid.

## Solution

**Language:** C++  
**Runtime:** 1191 ms (beats 40.82%)  
**Memory:** 425 MB (beats 27.55%)  
**Submitted:** 2026-09-01T13:57:21.184Z  

```cpp
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<pair<int,int>> litterPos;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i][j];
                if (c == 'S') { sr = i; sc = j; }
                else if (c == 'L') {
                    litterIdx[i][j] = litterPos.size();
                    litterPos.push_back({i, j});
                }
            }
        }
        
        int numLitter = litterPos.size();
        if (numLitter == 0) return 0;
        
        int fullMask = (1 << numLitter) - 1;
        
        // dist[r][c][e][mask] visited flag
        // Dimensions: m x n x (energy+1) x (1<<numLitter)
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << numLitter, false)
                )
            )
        );
        
        // state: row, col, energy, mask, moves
        queue<tuple<int,int,int,int,int>> q;
        q.push({sr, sc, energy, 0, 0});
        visited[sr][sc][energy][0] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c, e, mask, moves] = q.front();
            q.pop();
            
            if (mask == fullMask) return moves;
            
            if (e == 0) continue; // stuck, can't move further
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (classroom[nr][nc] == 'X') continue;
                
                int newE = e - 1;
                int newMask = mask;
                
                if (classroom[nr][nc] == 'R') {
                    newE = energy; // full recharge
                }
                if (classroom[nr][nc] == 'L' && litterIdx[nr][nc] != -1) {
                    int bit = litterIdx[nr][nc];
                    newMask = mask | (1 << bit);
                }
                
                if (!visited[nr][nc][newE][newMask]) {
                    visited[nr][nc][newE][newMask] = true;
                    q.push({nr, nc, newE, newMask, moves + 1});
                }
            }
        }
        
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/)