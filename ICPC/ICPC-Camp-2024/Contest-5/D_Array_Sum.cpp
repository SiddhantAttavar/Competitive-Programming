#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc; cin >> tc; while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }

        vector<pair<int, int>> v(m);
        rep(i, 0, m) {
            int x, y;
            cin >> x >> y;
            v[i] = {x - 1, y};
        }
        sort(v.begin(), v.end());

        multiset<int> s;
        int l = 0;
        s.insert(a[0]);
        for (auto [x, y] : v) {
            while (l < x) {
                l++;
                s.insert(a[l]);
            }
            int z = *s.begin();
            s.erase(s.begin());
            s.insert(z - y);
        }
        while (l < n - 1) {
            l++;
            s.insert(a[l]);
        }

        int c = 0;
        rep(i, 0, n) {
            c += *s.begin();
            s.erase(s.begin());
            cout << c << ' ';
        }
        cout << endl;
    }
}
