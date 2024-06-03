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

bool check(vector<int> &a, int u) {
	vector<int> b(a.begin(), a.end());
	b.erase(b.begin() + u);
	vector<int> c(b.size() - 1);
	range(i, 0, b.size() - 1) {
		c[i] = __gcd(b[i], b[i + 1]);
	}
	range(i, 0, c.size() - 1) {
		if (c[i] > c[i + 1]) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		int u = -1;
		range(i, 2, n) {
			if (__gcd(a[i], a[i - 1]) < __gcd(a[i - 1], a[i - 2])) {
				u = i;
				break;
			}
		}

		if (u == -1) {
			print("YES");
			continue;
		}

		if (check(a, u - 2) or check(a, u - 1) or check(a, u)) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
