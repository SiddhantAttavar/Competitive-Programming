#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc; cin >> tc; while (tc--) {
        int l, r;
        cin >> l >> r;

        vector<int> v;
        int x = l;
        while (x) {
            v.push_back(x % 3 + 1);
            x /= 3;
        }

        int c = accumulate(v.begin(), v.end(), 0ll);
        int j = 0;
        x = 1;
        while (l <= r) {
            while (j < v.size() and v[j] == 3) {
                x *= 3;
                j++;
            }
            if (j == v.size()) {
                v.back()--;
                j--;
                x /= 3;
                l += 2 * x;
                v.push_back(2);
            }
            else {
                v[j]++;
                l += x;
            }
            // cout << l << ' ' << c << ' ';
            // for (int i : v) cout << i;
            // cout << endl;
            if (l > r) {
                break;
            }
            c++;
        }
        cout << c << endl;
    }
}
