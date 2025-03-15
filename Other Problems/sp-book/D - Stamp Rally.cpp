#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

	int n, m;
	input(n, m);

	vector<pair<int, int>> e(m);
	rep(i, 0, m) {
		input(e[i].first, e[i].second);
		e[i].first--;
		e[i].second--;
	}

	int q;
	input(q);

	vector<int> x(q), y(q), z(q);
	rep(i, 0, q) {
		input(x[i], y[i], z[i]);
		x[i]--;
		y[i]--;
	}

	vector<int> l(q, 0), r(q, m - 1), res(q, m - 1);
	int h = 20;
	rep(i, 0, h) {
		vector<vector<int>> v(m);
		rep(j, 0, q) {
			if (l[j] <= r[j]) {
				v[(l[j] + r[j]) / 2].push_back(j);
			}
		}

		UF d(n);
		rep(j, 0, m) {
			d.join(e[j].first, e[j].second);

			for (int k : v[j]) {
				int c = d.size(x[k]);
				if (!d.sameSet(x[k], y[k])) {
					c += d.size(y[k]);
				}

				if (c >= z[k]) {
					r[k] = j - 1;
					res[k] = j;
				}
				else {
					l[k] = j + 1;
				}
			}
		}
	}

	for (int i  : res) {
		print(i + 1);
	}
}
