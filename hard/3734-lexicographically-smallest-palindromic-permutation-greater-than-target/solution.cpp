#include <vector>
#include <array>
#include <string>
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int cntFull[26] = {0};
        for (char c : s) cntFull[c - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (cntFull[i] % 2 == 1) { oddCount++; oddChar = i; }
        }
        // A palindromic permutation must have at most one odd-count letter,
        // and exactly one if n is odd, none if n is even.
        if ((n % 2 == 0 && oddCount != 0) || (n % 2 == 1 && oddCount != 1))
            return "";

        int h = n / 2;
        int M[26];
        for (int i = 0; i < 26; i++) M[i] = cntFull[i] / 2; // multiset for the first half

        // Snapshot of available counts BEFORE placing position p (tight path).
        vector<array<int,26>> snapshots(h);
        array<int,26> cur;
        for (int i = 0; i < 26; i++) cur[i] = M[i];

        int failPos = -1;
        vector<char> tightChars(h, 0);
        for (int p = 0; p < h; p++) {
            snapshots[p] = cur;
            int idx = target[p] - 'a';
            if (cur[idx] > 0) {
                cur[idx]--;
                tightChars[p] = target[p];
            } else {
                failPos = p;
                break;
            }
        }
        bool fullyTight = (failPos == -1);

        auto buildFull = [&](vector<char>& A, int midC) {
            string res(n, ' ');
            for (int i = 0; i < h; i++) res[i] = A[i];
            if (n % 2 == 1) res[h] = 'a' + midC;
            for (int i = 0; i < h; i++) res[n - 1 - i] = A[i];
            return res;
        };

        auto tryBump = [&](int p) -> string {
            array<int,26>& snap = snapshots[p];
            int tc = target[p] - 'a';
            for (int c = tc + 1; c < 26; c++) {
                if (snap[c] > 0) {
                    vector<char> B(h);
                    for (int i = 0; i < p; i++) B[i] = target[i];
                    B[p] = 'a' + c;
                    array<int,26> rem = snap;
                    rem[c]--;
                    int idx2 = p + 1;
                    for (int cc = 0; cc < 26; cc++)
                        while (rem[cc] > 0) { B[idx2++] = 'a' + cc; rem[cc]--; }
                    return buildFull(B, oddChar);
                }
            }
            return "";
        };

        if (fullyTight) {
            vector<char> A = tightChars;
            string cand = buildFull(A, oddChar);
            if (cand > target) return cand;
            for (int p = h - 1; p >= 0; p--) {
                string r = tryBump(p);
                if (!r.empty()) return r;
            }
            return "";
        } else {
            for (int p = failPos; p >= 0; p--) {
                string r = tryBump(p);
                if (!r.empty()) return r;
            }
            return "";
        }
    }
};