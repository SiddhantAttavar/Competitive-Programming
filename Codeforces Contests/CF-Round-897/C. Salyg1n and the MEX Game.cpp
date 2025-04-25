#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int n;
tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> s;

int query(int x) {
	print(x);
	cout.flush();
	s.insert(x);

	int y;
	input(y);
	s.erase(y);
	return y;
}

int mex() {
	int l = 0, r = 1e9, res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (*(s.find_by_order(m)) == m) {
			l = m + 1;
		}
		else {
			res = m;
			r = m - 1;
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		input(n);
		s.clear();
		range(i, 0, n) {
			int x;
			input(x);

			s.insert(x);
		}

		range(i, 0, n + 1) {
			int x = query(mex());
			if (x == -1) {
				break;
			}
			else if (x == -2) {
				return 0;
			}
		}
	}
}
