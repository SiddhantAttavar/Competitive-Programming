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
		int n, k;
		input(n, k);

		set<int> a, b;
		range(i, 0, n) {
			int x;
			input(x);
			a.insert(x);
		}
		range(i, 0, n) {
			int x;
			input(x);
			b.insert(x);
		}

		vector<int> l, r, c;
		range(i, 1, n + 1) {
			if (a.count(i) and !b.count(i)) {
				if (l.size() < 2 * k) {
					l.push_back(i);
					l.push_back(i);
				}
			}
			else if (!a.count(i) and b.count(i)) {
				if (r.size() < 2 * k) {
					r.push_back(i);
					r.push_back(i);
				}
			}
			else {
				c.push_back(i);
			}
		}

		for (int i : c) {
			if (l.size() == 2 * k) {
				break;
			}
			l.push_back(i);
			r.push_back(i);
		}

		arrPrint(l);
		arrPrint(r);

		int x = 0, y = 0;
		for (int i : l) {
			x ^= i;
		}
		for (int i : r) {
			y ^= i;
		}
		assert(x == y);
	}
}
