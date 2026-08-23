            if (num[i] == '?') cnt1++;
            else sum1 += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') cnt2++;
            else sum2 += num[i] - '0';
        }

        int cnt = cnt1 + cnt2;
        if (cnt % 2 == 1) return true; // odd number of '?', Alice always 
        wins

        // even case: Bob can pair up moves and force each pair to sum to 9
        return sum1 - sum2 != (cnt2 - cnt1) / 2 * 9;
    }
};
