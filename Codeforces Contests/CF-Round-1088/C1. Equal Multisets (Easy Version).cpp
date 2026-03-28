#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

bool dfs(int i, int k, vi &a, vi &b, vi &v) {
	if (v[b[i]]) {
		return false;
	}
	v[b[i]] = true;
	int n = sz(a);
	if (a[i] == b[i]) {
		if (i >= k) {
			if (b[i - k] == -1) {
				b[i - k] = a[i - k];
				if (!dfs(i - k, k, a, b, v)) {
					return false;
				}
			}
			else if (b[i - k] != a[i - k]) {
				return false;
			}
		}
		if (i + k < n) {
			if (b[i + k] == -1) {
				b[i + k] = a[i + k];
				if (!dfs(i + k, k, a, b, v)) {
					return false;
				}
			}
			else if (b[i + k] != a[i + k]) {
				return false;
			}
		}
	}
	else {
		if (i >= k and i + k < n) {
			return false;
		}

		if (i >= k) {
			if (b[i] != a[i - k]) {
				return false;
			}
			if (b[i - k] == -1) {
				b[i - k] = a[i];
				if (!dfs(i - k, k, a, b, v)) {
					return false;
				}
			}
			else if (b[i - k] != a[i]) {
				return false;
			}
		}
		if (i + k < n) {
			if (b[i] != a[i + k]) {
				return false;
			}
			if (b[i + k] == -1) {
				b[i + k] = a[i];
				if (!dfs(i + k, k, a, b, v)) {
					return false;
				}
			}
			else if (b[i + k] != a[i]) {
				return false;
			}
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vi a(n), b(n), v(n + 1, false);
		arrput(a);
		arrput(b);

		bool flag = true;
		auto put = [&](int i, int x) {
			if (v[x]) {
				flag = false;
				return;
			}
			if (b[i] != -1 and b[i] != x) {
				flag = false;
				return;
			}
			b[i] = x;
			v[x] = true;
		};

		vi l;
		set<int> t;
		rep(i, 0, k) {
			set<int> s;
			for (int j = i; j < n; j += k) {
				s.insert(a[j]);
			}
			if (sz(s) >= 2) {
				for (int j = i; j < n; j += k) {
					put(j, a[j]);
				}
			}
			else if (sz(s) == 2) {
				if (b[i] == -1 or a[i] == b[i]) {
					put(i, a[i]);
					put(i + k, a[i + k]);
				}
				else {
					put(i, a[i + k]);
					put(i + k, a[i]);
				}
			}
			else {
				l.push_back(i);
				t.insert(a[i]);
			}
		}

		for (int i : l) {
			if (b[i] != -1) {
				put(i, b[i]);
				t.erase(b[i]);
			}
		}

		for (int i : l) {
			if (b[i] == -1) {
				put(i, *t.begin());
				t.erase(t.begin());
			}
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
