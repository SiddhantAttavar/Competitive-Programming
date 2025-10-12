#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    int x = 0;
    rep(i, 0, n) {
        string s;
        cin >> s;

        x += s[0] == s[1] or s[0] == s[2] or s[1] == s[2];
    }

    cout << x * min(b, 2 * a) + (3 * n - 2 * x) * min(a, b) << endl;
}
