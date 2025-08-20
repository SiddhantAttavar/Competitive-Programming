#include <bits/stdc++.h>
using namespace std;
#define int long long

int square_root(__int128_t x) {
    if (x < 0) {
        return -1;
    }
    __int128_t l = 0, r = 1e18;
    while (l <= r) {
        __int128_t m = l + (r - l) / 2;
        if (m * m == x) {
            return m;
        }
        else if (m * m < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

signed main() {
    int y, l;
    cin >> y >> l;

    int res = 10;
    for (int b = 2; b <= 1e6; b++) {
        string s;
        int o = y;
        bool flag = true;
        while (o) {
            if (o % b >= 10) {
                flag = false;
                break;
            }
            s += '0' + (o % b);
            o /= b;
        }
        reverse(s.begin(), s.end());
        if (flag and (s.size() >= 18 or stoll(s) >= l)) {
            res = b;
        }
    }

    for (int x = l; x < 1e3; x++) {
        int a2 = (x / 100) % 10, a1 = (x / 10) % 10, a0 = x % 10;
        if (a2 == 0) {
            if ((y - a0) % a1 == 0) {
                res = max(res, (y - a0) / a1);
            }
            continue;
        }
        __int128_t c = a0 - y;
        int d = square_root((a1 * a1) - (4 * c * a2));
        int n = d - a1;
        if (d == -1 or n < 0 or n % (2 * a2) != 0) {
            continue;
        }
        res = max(res, n / (2 * a2));
    }
    cout << res << endl;
}
