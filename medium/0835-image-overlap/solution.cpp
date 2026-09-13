        for (auto& a : onesA) {
            for (auto& b : onesB) {
                int dx = a.first - b.first;
                int dy = a.second - b.second;
                int key = dx * 200 + dy; // encode (dx, dy) into 
                a single key
                count[key]++;
                maxOverlap = max(maxOverlap, count[key]);
            }
        }
        
        return maxOverlap;
    }
};
