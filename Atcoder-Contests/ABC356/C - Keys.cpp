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

	int n, m, k;
	input(n, m, k);

	vector<vector<int>> a(m);
	vector<bool> b(m);
	range(i, 0, m) {
		int x;
		input(x);
		a[i].resize(x);
		arrPut(a[i]);
		char c;
		input(c);
		b[i] = c == 'o';
	}

	int res = 0;
	range(i, 0, 1 << n) {
		vector<bool> v(n);
		range(j, 0, n) {
			v[j] = i & (1 << j);
		}

		bool flag = true;
		range(j, 0, m) {
			int c = 0;
			for (int k : a[j]) {
				c += v[k - 1];
			}

			if ((c >= k) != b[j]) {
				flag = false;
				break;
			}
		}
		res += flag;
	}

	print(res);
}
