#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int res = 0, x = 0;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        res = max(res, x + z);
        x = max(x, z);
    }
    cout << res << endl;
}
