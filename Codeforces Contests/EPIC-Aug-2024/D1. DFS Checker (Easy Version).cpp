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
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> a(n - 1);
		arrPut(a);

		vector<int> p(n);
		arrPut(p);

		vector<int> m(n + 1);
		range(i, 0, n) {
			m[p[i]] = i;
		}

		vector<int> d(n + 1, n + 1);
		range(i, 2, n + 1) {
			d[i] = d[i / 2] / 2;
		}

		set<int> s;
		if (p[0] != 1) {
			s.insert(1);
		}
		range(i, 2, n + 1) {
			if (m[i] != m[i / 2] + 1 and m[i] != m[i / 2] + d[i]) {
				s.insert(i);
			}
		}

		while (q--) {
			int x, y;
			input(x, y);
			x--;
			y--;

			if (s.count(p[x])) {
				s.erase(p[x]);
			}
			if (s.count(p[y])) {
				s.erase(p[y]);
			}
			if (s.count(p[x] * 2)) {
				s.erase(p[x] * 2);
			}
			if (s.count(p[x] * 2 + 1)) {
				s.erase(p[x] * 2 + 1);
			}
			if (s.count(p[y])) {
				s.erase(p[y]);
			}
			if (s.count(p[y] * 2)) {
				s.erase(p[y] * 2);
			}
			if (s.count(p[y] * 2 + 1)) {
				s.erase(p[y] * 2 + 1);
			}

			swap(p[x], p[y]);
			m[p[x]] = x;
			m[p[y]] = y;

			if (p[0] != 1) {
				s.insert(1);
			}
			if (p[x] != 1 and m[p[x]] != m[p[x] / 2] + 1 and m[p[x]] != m[p[x] / 2] + d[p[x]]) {
				s.insert(p[x]);
			}
			if (p[y] != 1 and m[p[y]] != m[p[y] / 2] + 1 and m[p[y]] != m[p[y] / 2] + d[p[y]]) {
				s.insert(p[y]);
			}
			if (p[x] * 2 <= n and m[p[x] * 2] != m[p[x]] + 1 and m[p[x] * 2] != m[p[x]] + d[p[x] * 2]) {
				s.insert(p[x] * 2);
			}
			if (p[x] * 2 + 1 <= n and m[p[x] * 2 + 1] != m[p[x]] + 1 and m[p[x] * 2 + 1] != m[p[x]] + d[p[x] * 2]) {
				s.insert(p[x] * 2 + 1);
			}
			if (p[y] * 2 <= n and m[p[y] * 2] != m[p[y]] + 1 and m[p[y] * 2] != m[p[y]] + d[p[y] * 2]) {
				s.insert(p[y] * 2);
			}
			if (p[y] * 2 + 1 <= n and m[p[y] * 2 + 1] != m[p[y]] + 1 and m[p[y] * 2 + 1] != m[p[y]] + d[p[y] * 2]) {
				s.insert(p[y] * 2 + 1);
			}

			if (s.size()) {
				print("NO");
			}
			else {
				print("YES");
			}
		}
	}
}
