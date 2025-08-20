#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (accumulate(a.begin(), a.end(), 0ll) % 2) {
        cout << "no quotation" << endl;
        return 0;
    }

    int res = 0;
    if (accumulate(a.begin(), a.end(), 0ll) == 2) {
        res = 1;
    }
    for (int k = 2; k <= 100; k++) {
        deque<int> b(a.begin(), a.end());
        int x = k;
        bool flag = true;
        while (!b.empty() and x > 1) {
            if (b.size() > 1 and min(b.front(), b.back()) < x or b.size() == 1 and b.front() < 2 * x) {
                flag = false;
                break;
            }
            b.front() -= x;
            b.back() -= x;
            if (b.front() == 0) {
                b.pop_front();
            }
            if (b.empty()) {
                flag = false;
                break;
            }
            if (b.back() == 0) {
                b.pop_back();
            }
            x--;
        }

        if (x == 1 and !b.empty()) {
            res = k;
        }
    }

    if (res == 0) {
        cout << "no quotation" << endl;
    }
    else {
        cout << res << endl;
    }
}
