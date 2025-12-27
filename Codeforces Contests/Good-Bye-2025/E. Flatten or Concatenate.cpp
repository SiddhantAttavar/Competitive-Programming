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
int K = 300;
vector<int> p;

int query(int l, int r) {
	assert(K);
	K--;
	if (debug) {
		return p[r + 1] - p[l];
	}
	print('?', l + 1, r + 1);
	cout.flush();
	int res;
	input(res);
	return res;
}

int get(int l, int r, int x) {
	int s = l, e = r - 1;
	while (s <= e) {
		int m = (s + e) / 2;
		int y = query(l, m);
		if (y == x / 2) {
			return m;
		}
		else if (y < x / 2) {
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	return -1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		K = 300;
		if (debug) {
			p.assign(n + 1, 0);
			vector<int> a(n);
			arrput(a);
			rep(i, 0, n) {
				p[i + 1] = p[i] + a[i];
			}
		}

		int l = 0, r = n - 1, x = query(0, n - 1);
		while (l < r) {
			int m = get(l, r, x);
			if (m - l + 1 < r - m) {
				r = m;
			}
			else {
				l = m + 1;
			}
			x /= 2;
		}
		print('!', x);
		cout.flush();
	}
}
