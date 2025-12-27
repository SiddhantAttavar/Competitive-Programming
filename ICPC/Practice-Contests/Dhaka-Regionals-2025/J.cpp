#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	string s;
    cin >> s;

    int res = 0;
    bool flag = false;
    for (char c : s) {
        if (c == '0') {
            if (flag) {
                flag = false;
                break;
            }
            res++;
        }
        else {
            if (flag) {
                res++;
                flag = false;
            }
            else {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "INVALID\n";
    }
    else {
        cout << res << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
