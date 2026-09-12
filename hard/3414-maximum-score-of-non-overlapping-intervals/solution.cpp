                take.idx.push_back((int)v[i - 1][3]);

                // Keep indices sorted because answer must be
                // lexicographically compared by original indices
                sort(take.idx.begin(), take.idx.end());

                if (better(take, dp[i][k])) {
                    dp[i][k] = take;
                }
            }
        }

        return dp[n][4].idx;
    }
};
