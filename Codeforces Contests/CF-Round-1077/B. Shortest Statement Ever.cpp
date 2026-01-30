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
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

pii small(int x, int y) {
	bool flag = false;
	int z = 0;
	for (int i = 29; i >= 0; i--) {
		if (x >> i & 1) {
			flag |= y >> i & 1;
		}
		else if ((y >> i & 1) or flag) {
			z |= 1ll << i;
		}
	}
	return {x, z};
}

pii large(int x, int y, int h) {
	x |= 1ll << h;
	x &= ~((1ll << h) - 1);
	return small(x, y);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int x, y;
		input(x, y);

		if (!(x & y)) {
			print(x, y);
			continue;
		}

		pii p = small(x, y), q = small(y, x);
		vector<pii> s = {p, {q.second, q.first}};
		rep(i, 0, 31) {
			if (!(x >> i & 1)) {
				pii p = large(x, y, i);
				s.push_back(p);
			}
		}
		rep(i, 0, 31) {
			if (!(y >> i & 1)) {
				pii p = large(y, x, i);
				s.push_back({p.second, p.first});
			}
		}

		array<int, 3> res = {(int) 1e18, -1, -1};
		for (auto [p, q] : s) {
			res = min(res, {abs(x - p) + abs(y - q), p, q});
		}
		print(res[1], res[2]);
	}
}
