#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a;
    cin >> a;

    int x = 0, y = 0, s = 0, t = 0;
    bool flag = true;
    for (char c : a) {
        if (c == 'Q') {
            if (max(s, t) < 2) {
                cout << s << " (" << x;
                if (flag) {
                    cout << '*';
                }
                cout << ") - " << t << " (" << y;
                if (!flag) {
                    cout << '*';
                }
                cout << ')' << endl;
            }
            else {
                cout << s;
                if (s == 2) {
                    cout << " (winner)";
                }
                cout << " - " << t;
                if (t == 2) {
                    cout << " (winner)";
                }
                cout << endl;
            }
            continue;
        }

        if ((c == 'S') == flag) {
            flag = true;
            
            x++;
            if (x >= 5 and x - y >= 2 or x == 10) {
                s++;
                x = 0;
                y = 0;
            }
        }
        else {
            flag = false;

            y++;
            if (y >= 5 and y - x >= 2 or y == 10) {
                t++;
                x = 0;
                y = 0;
            }
        }
    }
}
