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

void insert(vector<pii> &tree, int c) {
	int u = 0;
	for (int i = 29; i >= 0; i--) {
		if (c >> i & 1) {
			if (tree[u].first == -1) {
				tree[u].first = sz(tree);
				tree.push_back({-1, -1});
			}
			u = tree[u].first;
		}
		else {
			if (tree[u].second == -1) {
				tree[u].second = sz(tree);
				tree.push_back({-1, -1});
			}
			u = tree[u].second;
		}
	}
}

int get(vector<pii> &tree, int c) {
	int u = 0, res = 0;
	for (int i = 29; i >= 0; i--) {
		if (c >> i & 1) {
			if (tree[u].first != -1) {
				u = tree[u].first;
			}
			else {
				u = tree[u].second;
				res |= 1ll << i;
			}
		}
		else {
			if (tree[u].second != -1) {
				u = tree[u].second;
			}
			else {
				u = tree[u].first;
				res |= 1ll << i;
			}
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, p;
		input(n, p);
		p--;

		vi a(n);
		arrput(a);

		if (p == n - 1) {
			p = 0;
			reverse(all(a));
		}
		if (p == 0) {
			int c = a[0], res = a[0];
			rep(i, 1, n - 1) {
				c ^= a[i];
				res = min(res, c);
			}
			print(res);
			continue;
		}

		vector<pii> tree = {{-1, -1}};

		int res = a[p], c = 0;
		rep(i, 1, n - 1) {
			insert(tree, c);
			c ^= a[i];
			res = min(res, get(tree, c));
		}
		print(res);
	}
}
