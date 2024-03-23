#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int h, w, m;
	input(h, w, m);

	vector<tuple<int, int, int>> queries(m);
	range(i, 0, m) {
		int t, a, x;
		input(t, a, x);
		queries[i] = {t, a - 1, x};
	}
	reverse(queries.begin(), queries.end());

	int l = h, r = w;
	map<int, int> res;
	vector<bool> u(h, true), v(w, true);
	for (tuple<int, int, int> q : queries) {
		int t, a, x;
		tie(t, a, x) = q;

		if (t == 1) {
			if (!u[a] or r == 0) {
				continue;
			}

			res[x] += r;
			u[a] = false;
			l--;
		}
		else {
			if (!v[a] or l == 0) {
				continue;
			}

			res[x] += l;
			v[a] = false;
			r--;
		}
	}

	if (l and r) {
		res[0] += l * r;
	}

	print(res.size());
	for (pair<int, int> p : res) {
		print(p.first, p.second);
	}
}
