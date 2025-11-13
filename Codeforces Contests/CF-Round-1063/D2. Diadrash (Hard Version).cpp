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

		K = 30;

		if (debug) {
			P.clear();
			P.resize(n);
			arrput(P);
		}

		vector<int> a(n, -1);
		rep(i, 0, q) {
			int l, r;
			input(l, r);
			a[l - 1] = max(a[l - 1], r - 1);
		}

		int c = -1;
		vector<pair<int, int>> v;
		rep(i, 0, n) {
			if (a[i] > c) {
				c = a[i];
				v.push_back({i, c});
			}
		}

		int l = 0, r = v.size() - 1, res = 0;
		while (l < r) {
			int m = (l + r) / 2;
			int x = query(0, v[m].second), y = query(v[m + 1].first, n - 1);
			if (x < y) {
				res = m + 1;
				l = m + 1;
			}
			else if (x > y) {
				res = m;
				r = m;
			}
		}
		res = query(v[res].first, v[res].second);
		print('!', res);
		cout.flush();
	}
}
