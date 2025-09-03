#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

int f(vector<int> &v, int k, int x, vector<vector<int>> &ncr) {
    int res = 0;
    int n = v.size();
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] > x) {
            continue;
        }
        if (2 * v[i] <= x) {
            return res + ncr[i + 1][k];
        }
        else {
            res += ncr[i][k];
            x -= v[i];
            k--;
            if (k == 0) {
                return res + 1;
            }
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 50;
    vector<vector<int>> ncr(N + 1, vector<int>(N + 1, 0));
    ncr[0][0] = 1;
    rep(n, 1, N + 1) {
        ncr[n][0] = 1;
        rep(r, 1, N + 1) {
            ncr[n][r] = ncr[n - 1][r - 1] + ncr[n - 1][r];
        }
    }

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    rep(i, 0, n) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int a, b;
    cin >> a >> b;

    int res = 0;
    cout << f(v, k, b, ncr) - f(v, k, a - 1, ncr) << endl;
    // cout << f(v, k, b, ncr) << ' ' << f(v, k, a - 1, ncr) << endl;
}
