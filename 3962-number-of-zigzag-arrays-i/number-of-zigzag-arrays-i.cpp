class Solution {
public:
static const int MOD = 1e9 + 7;

// Count zig-zag arrays of length n with values in [l…r].
int zigZagArrays(int n, int l, int r) {
    int m = r - l + 1;
    // dp_next[idx][0] = # of ways for suffix starting at pos+1 
    //                  when next relation is “down” (we must do a decrease)
    // dp_next[idx][1] = # of ways when next relation is “up” (we must do an increase)
    vector<array<int,2>> dp_next(m, {1,1}), dp_curr(m);

    // Build from pos = n-1 down to 1
    for(int pos = n - 1; pos >= 1; --pos) {
        // pref[i]   = sum of dp_next[j][0] for j < i
        // suf[i]   = sum of dp_next[j][1] for j > i
        vector<int> pref(m, 0), suf(m, 0);

        // prefix over “down” states
        for(int i = 1; i < m; ++i) {
            pref[i] = pref[i-1] + dp_next[i-1][0];
            if(pref[i] >= MOD) pref[i] -= MOD;
        }
        // suffix over “up” states
        for(int i = m-2; i >= 0; --i) {
            suf[i] = suf[i+1] + dp_next[i+1][1];
            if(suf[i] >= MOD) suf[i] -= MOD;
        }

        // fill dp_curr for position = pos
        for(int i = 0; i < m; ++i) {
            dp_curr[i][0] = suf[i];    // we must go down next: sum of all ups to the right
            dp_curr[i][1] = pref[i];   // we must go up next: sum of all downs to the left
        }
        swap(dp_next, dp_curr);
    }

    // sum both starting directions at pos = 1
    long long ans = 0;
    for(int i = 0; i < m; ++i) {
        ans += dp_next[i][0] + dp_next[i][1];
        if(ans >= MOD) ans %= MOD;
    }
    return int(ans);
}

};