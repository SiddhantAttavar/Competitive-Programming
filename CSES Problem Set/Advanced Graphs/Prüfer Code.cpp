#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n - 2);
	arrput(a);

	rep(i, 0, n - 2) {
		a[i]--;
	}

	map<int, int> m;
	for (int i : a) {
		m[i]++;
	}
	set<int> s;
	rep(i, 0, n) {
		if (!m.count(i)) {
			s.insert(i);
		}
	}

	vector<pair<int, int>> res;
	for (int i : a) {
		int u = *s.begin();
		s.erase(u);
		res.push_back({u, i});
		m[i]--;
		if (m[i] == 0) {
			s.insert(i);
		}
	}
	for (auto [u, v] : res) {
		print(u + 1, v + 1);
	}
	int u = *s.begin();
	s.erase(s.begin());
	print(u + 1, *s.begin() + 1);
}
