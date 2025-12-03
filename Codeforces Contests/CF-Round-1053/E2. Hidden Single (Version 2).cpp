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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool debug = false;
vector<int> z;
int k = 0;

bool query(vector<int> &v, int x) {
	if (v.empty()) {
		return false;
	}
	assert(k);
	k--;
	if (debug) {
		for (int i : v) {
			if (z[i] == x) {
				return true;
			}
		}
		return false;
	}
	cout << "? " << x + 1 << ' ' << v.size() << ' ';
	for (int i : v) {
		cout << i + 1 << ' ';
	}
	cout << endl;
	cout.flush();
	int res;
	input(res);
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		k = 925;
		if (debug) {
			z.resize(2 * n - 1);
			arrput(z);
			rep(i, 0, 2 * n - 1) {
				z[i]--;
			}
		}

		vector<int> a(2 * n - 1);
		iota(a.begin(), a.end(), 0);
		shuffle(a.begin(), a.end(), rng);

		vector<int> s, t;
		int x = 0, y = 0;
		vector<int> p(a.begin(), a.begin() + n), q(a.begin() + n, a.end());
		rep(i, 0, n) {
			if (!query(p, i)) {
				t.push_back(i);
				y += 2;
			}
			else if (!query(q, i)) {
				s.push_back(i);
				x += 2;
			}
			else {
				x++;
				y++;
			}
		}

		vector<array<int, 3>> v;
		if (x > n) {
			for (int i : s) {
				v.push_back({0, n - 1, i});
			}
		}
		else {
			for (int i : t) {
				v.push_back({n, 2 * n - 2, i});
			}
		}

		while (v.size() > 1) {
			vector<array<int, 3>> nv;
			for (auto [l, r, i] : v) {
				int m = (l + r) / 2;
				vector<int> p(a.begin() + l, a.begin() + m + 1);
				vector<int> q(a.begin() + m + 1, a.begin() + r + 1);
				if (!query(p, i)) {
					nv.push_back({m + 1, r, i});
				}
				else if (!query(q, i)) {
					nv.push_back({l, m, i});
				}
			}
			v = nv;
		}

		print('!', v[0][2] + 1);
		cout.flush();

		if (debug) {
			vector<int> c(n, 0);
			for (int i : z) {
				c[i]++;
			}
			assert(find(c.begin(), c.end(), 1) - c.begin() == v[0][2]);
		}
	}
}
