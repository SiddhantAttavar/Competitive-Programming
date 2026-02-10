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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) { b++; // (for right inclusive)
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

void solve() {
    int n, q;
    cin >> n >> q;

	string s;
    cin >> s;
    
    vi a(n);
    rep(i, 0, n) {
        a[i] = s[i] - 'a';
    }

    vi x(n), y(n);
    x[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= a[i + 1]) {
            x[i] = x[i + 1];
        }
        else {
            x[i] = i;
        }
    }
    y[0] = 0;
    rep(i, 1, n) {
        if (a[i] == a[i - 1]) {
            y[i] = y[i - 1];
        }
        else {
            y[i] = i;
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        if (x[l] > r) {
            cout << max(l, y[r]) + 1 << endl;
        }
        else {
            cout << max(l, y[x[l]]) + 1 << endl;
        }
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
