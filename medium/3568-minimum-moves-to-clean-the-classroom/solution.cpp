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