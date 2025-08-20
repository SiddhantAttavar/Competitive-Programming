#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(vector<pair<int, int>> &v) {
    int x = 0;
    for (pair<int, int> p : v) {
        x = max(x, p.first);
        x += p.second - p.first;
    }
    return x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<pair<int, int>> x, y;
    int z = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) {
            x.push_back({a[i], b[i]});
            z += b[i] - a[i];
        }
        else {
            y.push_back({b[i], a[i]});
        }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << max(solve(x), solve(y)) - z << endl;
}
