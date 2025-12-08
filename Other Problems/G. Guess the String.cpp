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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool debug = false;
int K = 789;
string S, T;
vi P, Q;

int query(int i, bool b) {
	assert(K);
	K--;
	if (!debug) {
		cout << 1 + b << ' ' << i + 1 << endl;
		cout.flush();
		int x;
		cin >> x;
		assert(x != -1);
		return x;
	}
	int n = sz(S) / 2;
	for (int j = i; j > 0; j--) {
		if (!b and P[n + i - j + 1] >= j or b and Q[n + i - j + 1] >= j) {
			return j;
		}
	}
	return 0;
}

vi Z(const string& S) {
	vi z(sz(S));
	int l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

void solve() {
	int n;
	cin >> n;

	K = 789;
	if (debug) {
		cin >> S;
		T.clear();
		for (char c : S) {
			T += c ^ '0' ^ '1';
		}
		T += S;
		S += S;
		P = Z(S);
		Q = Z(T);
	}

	string s(n, '0');
	s[1] = query(1, false) ? '0' : '1';
	vector<int> a(n, -1), b(n, -1);
	int i = n - 1;
	while (i > 1) {
		bool f = rng() & 1;
		int j = query(i, f);
		if (j == 1 and s[1] == '0') {
			s[i - 1] = '0' + !f;
			s[i] = s[i - 1] ^ '0' ^ '1';
			i -= 2;
			continue;
		}
		if (j == 0 and s[1] == '1') {
			s[i - 1] = '0' + !f;
			s[i] = s[i - 1];
			i -= 2;
			continue;
		}
		if (j == 0) {
			j = 1;
			f = !f;
		}
		rep(k, 0, j) {
			if (!f) {
				a[i - k] = j - k;
			}
			else {
				b[i - k] = j - k;
			}
		}
		i -= j;
	}

	rep(i, 2, n) {
		if (a[i] != -1) {
			s[i] = s[a[i] - 1];
		}
		else if (b[i] != -1) {
			s[i] = s[b[i] - 1] ^ '0' ^ '1';
		}
	}
	cout << "0 " << s << endl;
	cout.flush();
	if (debug) {
		s += s;
		assert(s == S);
	}
	int x;
	cin >> x;
	assert(x != -1);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
