#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string t = "nanjing";
    int tc; cin >> tc; while (tc--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        s += s;

        vector<bool> b(2 * n);
        rep(i, 0, 2 * n - 6) {
            b[i] = (s.substr(i, 7) == t);
        }

        int c = accumulate(b.begin(), b.begin() + max(0ll, n - 6), 0ll);
        int res = c;
        rep(d, 1, min(n - 1, k) + 1) {
            int a = c;
            rep(i, max(0ll, d - 6), d) {
                a -= b[i];
            }
            rep(i, max(0ll, n - 6), min(n, n + d - 6)) {
                a += b[i];
            }
            res = max(res, a);
        }
        cout << res << endl;
    }
}
