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

bool debug = false;
int K;
vector<int> P;
int query(int l, int r) {
	assert(K);
	K--;
	if (debug) {
		set<int> a(P.begin() + l, P.begin() + r + 1);
		int x = 0;
		while (a.count(x)) {
			x++;
		}
		print(l, r, x);
		cout.flush();
		return x;
	}
	print('?', l + 1, r + 1);
	cout.flush();
	int x;
	input(x);
	return x;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		K = max(300ll, (n + 1) / 1 + 2);

		if (debug) {
			P.clear();
			P.resize(n);
			arrput(P);
		}

		vector<pair<int, int>> v(q);
		rep(i, 0, q) {
			int l, r;
			input(l, r);
			v[i] = {l - 1, r - 1};
		}

		if (query(0, (n - 1) / 2)) {
			vector<int> a(n, -1);
			for (auto [l, r] : v) {
				a[l] = max(a[l], r);
			}
			int res = 0;
			rep(i, 0, (n - 1) / 2 + 1) {
				if (a[i] != -1) {
					res = max(res, query(i, a[i]));
				}
			}
			print('!', res);
		}
		else {
			vector<int> a(n, n);
			for (auto [l, r] : v) {
				a[r] = min(a[r], l);
			}
			int res = 0;
			rep(i, (n - 1) / 2 + 1, n) {
				if (a[i] != n) {
					res = max(res, query(a[i], i));
				}
			}
			print('!', res);
		}
		cout.flush();
	}
}
