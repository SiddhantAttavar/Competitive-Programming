#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

vector<int> solve(vector<int> &l, int n, int k) {
    if (l.empty()) {
        return {};
    }
    int c = 0;
    vector<int> res;
    for (int i : l) {
        if (c >= i) {
            continue;
        }

        int r = i + k - 1;
        res.push_back(i);
        if (r < n) {
            c = r;
            continue;
        }
        
        c = n - 1;
        int y = r - n + 1;
        for (int j = res.size() - 1; j >= 0; j--) {
            res[j] -= y;
            if (j > 0 and res[j] > res[j - 1] + k - 1) {
                break;
            }
            y = res[j - 1] + k - res[j];
        }
        if (res[0] <= 0) {
            return {-1};
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc; cin >> tc; while (tc--) {
        int n, m, k, w;
        cin >> n >> m >> k >> w;

        vector<int> a(n), b(m);
        rep(i, 0, n) {
            cin >> a[i];
        }
        rep(i, 0, m) {
            cin >> b[i];
        }
        b.push_back(0);
        b.push_back(w + 1);

        vector<pair<int, bool>> v;
        for (int i : a) {
            v.push_back({i, false});
        }
        for (int i : b) {
            v.push_back({i, true});
        }
        sort(v.begin(), v.end());

        vector<int> res;
        int c = 0;
        vector<int> l;
        for (auto [x, b] : v) {
            if (b) {
                vector<int> y = solve(l, x - c, k);
                if (y.size() == 1 and y[0] == -1) {
                    res = {-1};
                    break;
                }
                for (int i : y) {
                    res.push_back(i + c);
                }
                l.clear();
                c = x;
            }
            else {
                l.push_back(x - c);
            }
        }
        if (res.size() == 1 and res[0] == -1) {
            cout << "-1\n";
        }
        else {
            cout << res.size() << endl;
            for (int i : res) {
                cout << i << ' ';
            }
            cout << endl;
        }
    }
}
