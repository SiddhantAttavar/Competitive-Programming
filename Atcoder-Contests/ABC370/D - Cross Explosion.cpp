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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int h, w, q;
	input(h, w, q);

	vector<set<int>> a(h), b(w);
	range(i, 0, h) {
		range(j, 0, w) {
			a[i].insert(j);
			b[j].insert(i);
		}
	}

	int res = h * w;
	while (q--) {
		int r, c;
		input(r, c);

		r--;
		c--;

		if (a[r].count(c)) {
			a[r].erase(c);
			b[c].erase(r);
			res--;
			continue;
		}

		if (a[r].lower_bound(c) != a[r].end()) {
			int k = *a[r].lower_bound(c);
			a[r].erase(k);
			b[k].erase(r);
			res--;
		}
		if (a[r].lower_bound(c) != a[r].begin()) {
			int k = *(prev(a[r].lower_bound(c)));
			a[r].erase(k);
			b[k].erase(r);
			res--;
		}

		if (b[c].lower_bound(r) != b[c].end()) {
			int k = *b[c].lower_bound(r);
			a[k].erase(c);
			b[c].erase(k);
			res--;
		}
		if (b[c].lower_bound(r) != b[c].begin()) {
			int k = *(prev(b[c].lower_bound(r)));
			a[k].erase(c);
			b[c].erase(k);
			res--;
		}
	}

	print(res);
}
