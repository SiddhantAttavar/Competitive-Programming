#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, k;
    cin >> n >> k;

    stack<int> v;
    while (k--) {
        string s;
        cin >> s;
        
        if (s[0] == 'u') {
            int x;
            cin >> x;
            
            while (x--) {
                v.pop();
            }
        }
        else {
            int x = stoll(s);
            v.push(x);
        }
    }

    int x = 0;
    while (!v.empty()) {
        x = ((x + v.top()) % n + n) % n;
        v.pop();
    }
    cout << x << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
