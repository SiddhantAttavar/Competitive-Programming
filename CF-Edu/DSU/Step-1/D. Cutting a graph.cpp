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

	vector<vector<pair<int, int>>> a = {{}};
	vector<pair<int, int>> b;
	rep(i, 0, k) {
		string t;
		int u, v;
		input(t, u, v);

		u--;
		v--;
		if (u > v) {
			swap(u, v);
		}

		if (t == "cut") {
			a.back().push_back({u, v});
			s.erase({u, v});
		}
		else {
			a.push_back({});
			b.push_back({u, v});
		}
	}
	s.insert(a.back().begin(), a.back().end());
	a.pop_back();

	UF d(n);
	for (auto [u, v] : s) {
		d.join(u, v);
	}

	vector<bool> res;
	while (!b.empty()) {
		auto [u, v] = b.back();
		res.push_back(d.sameSet(u, v));
		b.pop_back();

		for (auto [u, v] : a.back()) {
			d.join(u, v);
		}
		a.pop_back();
	}

	reverse(res.begin(), res.end());
	for (bool b : res) {
		if (b) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
