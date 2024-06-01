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

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);
	sort(a.begin(), a.end());

	vector<int> b(1e6 + 1, -1);
	int res = 0;
	range(i, 0, n) {
		if (b[a[i]] != -1) {
			res += b[a[i]];
			continue;
		}

		b[a[i]] = 0;
		int l = i + 1;
		range(j, 1, 1e6 + 1) {
			int r = lower_bound(a.begin(), a.end(), a[i] * (j + 1)) - a.begin();
			b[a[i]] += j * (r - l);
			if (r == a.size()) {
				break;
			}
			l = r;
		}
		res += b[a[i]];
	}

	vector<int> c(1e6 + 1, 0);
	for (int i : a) {
		c[i]++;
	}

	for (int i : c) {
		res -= i * (i - 1) / 2;
	}

	print(res);
}
