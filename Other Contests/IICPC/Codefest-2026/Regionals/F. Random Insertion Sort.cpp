#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;

int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

void solve() {

}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc = 1;
	cin >> tc;
	while (tc--) solve();
}
