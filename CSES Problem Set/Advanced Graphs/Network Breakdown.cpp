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

#define vi vector<int>

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	set<pair<int, int>> s;
	rep(i, 0, m) {
		int u, v;
		input(u, v);
		u--;
		v--;
		if (u > v) {
			swap(u, v);
		}
		s.insert({u, v});
	}
	vector<pair<int, int>> t;
	rep(i, 0, k) {
		int u, v;
		input(u, v);
		u--;
		v--;
		if (u > v) {
			swap(u, v);
		}
		s.erase({u, v});
		t.push_back({u, v});
	}

	UF d(n);
	int c = n;
	for (auto [u, v] : s) {
		c -= d.join(u, v);
	}

	vector<int> res(k);
	for (int i = k - 1; i >= 0; i--) {
		res[i] = c;
		c -= d.join(t[i].first, t[i].second);
	}
	arrprint(res);
}
