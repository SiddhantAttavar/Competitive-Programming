#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, b, c;
    cin >> n >> b >> c;

    vector<pair<int, int>> v(n);
    rep(i, 0, n) {
        cin >> v[i].first >> v[i].second;
    }
    v.push_back({1e18, 0});

    deque<pair<int, int>> d;
    int z = 0, y = 0;
    rep(i, 0, v.size() - 1) {
        auto [x, p] = v[i];
        if (z < x) {
            break;
        }

        while (!d.empty() and d.back().second >= p) {
            y -= d.back().first;
            d.pop_back();
        }
        d.push_back({c - y, p});
        y = c;
        
        while (!d.empty() and z < v[i + 1].first and b>= d.front().second) {
            int t = min({b / d.front().second, v[i + 1].first - z, d.front().first});
            z += t;
            y -= t;
            b -= t * d.front().second;
            d.front().first -= t;
            if (d.front().first == 0) {
                d.pop_front();
            }
        }
    }
    cout << z << endl;
}
