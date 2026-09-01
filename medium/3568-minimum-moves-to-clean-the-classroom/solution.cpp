            
            if (e == 0) continue; // stuck, can't move further
            
            if (mask == fullMask) return moves;
            auto [r, c, e, mask, moves] = q.front();
            q.pop();
        
        while (!q.empty()) {
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        visited[sr][sc][energy][0] = true;
        
        q.push({sr, sc, energy, 0, 0});
        queue<tuple<int,int,int,int,int>> q;
        // state: row, col, energy, mask, moves
        
        );
            )
                )
                    energy + 1, vector<bool>(1 << numLitter, false)
                n, vector<vector<bool>>(
            m, vector<vector<vector<bool>>>(
        vector<vector<vector<vector<bool>>>> visited(
        // Dimensions: m x n x (energy+1) x (1<<numLitter)
