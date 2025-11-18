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
#define pii pair<int, int>
#define sz(x) (int) x.size()

struct RollbackUF {
	vi e; vector<pii> st;
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	int time() { return sz(st); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int32_t main() {
	setup();

	int n, m, q;
	input(n, m, q);

	map<int, vector<int>> s;
	vector<array<int, 3>> e(m);
	rep(i, 0, m) {
		arrput(e[i]);
		e[i][0]--;
		e[i][1]--;
		s[e[i][2]].push_back(i);
	}

	map<int, map<int, vector<int>>> t;
	rep(i, 0, q) {
		int l;
		input(l);

		rep(j, 0, l) {
			int k;
			input(k);
			k--;
			t[e[k][2]][i].push_back(k);
		}
	}

	vector<bool> res(q, true);
	RollbackUF d(n);
	for (auto [w, l] : s) {
		for (auto [i, v] : t[w]) {
			int c = d.time();
			for (int j : v) {
				res[i] = res[i] and d.join(e[j][0], e[j][1]);
			}
			d.rollback(c);
		}

		for (int i : l) {
			d.join(e[i][0], e[i][1]);
		}
	}

	rep(i, 0, q) {
		if (res[i]) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
