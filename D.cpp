#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int res = 0;
        rep(i, 0, n) {
            res += s[i] == '1';
        }

        bool flag = true;
        rep(i, 1, n) {
            if (s[i] == '0' and s[i - 1] == '0') {
                flag = false;
                break;
            }
        }

        if (flag and s[0] == '1' and s[n - 1] == '1') {
            int x = 0, c = n;
            rep(i, 0, n) {
                if (s[i] == '0') {
                    c = min(c, x);
                    x = 0;
                }
                else {
                    x++;
                }
            }
            c = min(c, x);
            res += c;
        }

        cout << res << endl;
	}

    return 0;
}
