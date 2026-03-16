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

int32_t main() {
	const int N = 1e6;
	vector<string> v(N + 1);
	rep(i, 1, N + 1) {
		int x = i;
		while (x > 9) {
			string s = to_string(x);
			v[i] += s;
			x = 0;
			for (char c : s) {
				x += c - '0';
			}
		}
		v[i] += to_string(x);
	}
	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		if (sz(s) == 1) {
			print(s);
			continue;
		}

		vi f(10);
		int x = 0;
		for (char c : s) {
			x += c - '0';
			f[c - '0']++;
		}

		int u = -1;
		rep(i, max(1ll, x - 100), x + 1) {
			vi g = f;
			int y = 0;
			for (char c : v[i]) {
				g[c - '0']--;
				y += c - '0';
			}
			if (*min_element(all(g)) >= 0 and g[0] != accumulate(all(g), 0ll) and x - y == i) {
				u = i;
				break;
			}
		}
		assert(u != -1);

		vi g(10, 0);
		for (char c : v[u]) {
			g[c - '0']++;
		}

		string res;
		for (char c : s) {
			if (g[c - '0']) {
				g[c - '0']--;
			}
			else {
				res += c;
			}
		}
		int l = 0;
		while (res[l] == '0') {
			l++;
		}
		if (l > 0) {
			swap(res[0], res[l]);
		}
		res += v[u];
		print(res);
	}
}
