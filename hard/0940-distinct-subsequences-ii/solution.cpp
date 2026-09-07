                dp[i] = (dp[i] - dp[last[c - 'a'] - 1] + MOD) % MOD;
            }
            last[c - 'a'] = i;
        }

        return (dp[n] - 1 + MOD) % MOD; // subtract the empty subsequence
    }
};
