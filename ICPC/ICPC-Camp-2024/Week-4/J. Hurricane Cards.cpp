#include <bits/stdc++.h>
using namespace std;
#define int long long

#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define vi vector<int>

const int inf = 1e9;

// n-2 -> (n-1) -> 0

int rec(vector<vi> &s, int p)
{
    int n = s.size();
    bool block = !s[p].back();
    if (block)
        s[p].pop_back();
    map<int, int> f;
    for (int card : s[p])
        f[card]++;
    pii give = {100, 100};
    for (auto [e, c] : f)
        give = min(give, {c, e});
    int idx = -1;
    rep(i, 0, s[p].size()) if (s[p][i] == give.second) idx = i;
    assert(idx >= 0 && idx < s[p].size());
    s[p].erase(s[p].begin() + idx);
    s[(p + 1) % n].push_back(give.second);
    if (block)
        s[p].push_back(0), f[0] = 1;
    int cnt = 0;
    f[give.second]--;
    for (auto [e, c] : f)
        if (c)
            cnt++;
    if (cnt == 1)
        return p;
    return rec(s, (p + 1) % n);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> curr(n);
    unordered_map<char, int> cv = {{'A', 1}, {'D', 10}, {'Q', 11}, {'J', 12}, {'K', 13}};
    rep(i, 0, n)
    {
        string s;
        cin >> s;
        rep(j, 0, 4)
        {
            if (s[j] >= '0' && s[j] <= '9')
                curr[i].push_back(s[j] - '0');
            else
                curr[i].push_back(cv[s[j]]);
        }
    }
    curr[k - 1].push_back(0);
    cout << rec(curr, k - 1) + 1;
    }
}
