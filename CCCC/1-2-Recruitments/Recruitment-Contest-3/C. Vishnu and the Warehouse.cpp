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

	vector<vector<int>> a(n);
	range(i, 0, n) {
		int x;
		input(x);
		a[i].resize(x);
		arrPut(a[i]);
	}

	vector<int> b;
	range(i, 0, n) {
		b.insert(b.end(), a[i].begin(), a[i].end());
	}
	sort(b.begin(), b.end());

	map<int, int> m;
	range(i, 0, b.size()) {
		m[b[i]] = i;
	}

	range(i, 0, n) {
		range(j, 0, a[i].size()) {
			a[i][j] = m[a[i][j]];
		}
	}

	int x = n;
	range(i, 0, n) {
		int p = a[i][0];
		range(j, 1, a[i].size()) {
			if (a[i][j] == p + 1) {
				p++;
			}
			else {
				p = a[i][j];
				x++;
			}
		}
	}

	print(x - n, x - 1);
}
