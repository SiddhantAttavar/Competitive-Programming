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
		int n;
		input(n);

		string s;
		input(s);

		vector<int> a(n);
		range(i, 0, n) {
			a[i] = s[i] - '0';
		}

		if (n == 2) {
			print(a[0] * 10 + a[1]);
			continue;
		}

		if (n == 3) {
			int x = a[0] * 10 + a[1], y = a[1] * 10 + a[2];
			print(min({x * a[2], x + a[2], y * a[0], y + a[0]}));
			continue;
		}

		bool flag = false;
		for (int i : a) {
			if (i == 0) {
				flag = true;
				break;
			}
		}

		if (flag) {
			print(0);
			continue;
		}

		int res = 0, x = 0;
		for (int i : a) {
			res += i;
			x += i == 1;
		}

		int v = min_element(a.begin(), a.begin() + n - 1) - a.begin();
		res += 9 * a[v];

		bool b = false;
		range(i, 0, n - 1) {
			if (a[i] == a[v] and a[i + 1] != 1) {
				b = true;
				break;
			}
		}
		res -= x - (a[v] == 1) - !b;
		print(res);
	}
}
