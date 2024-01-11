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

pair<bool, vector<int>> check(int x, int n, vector<int> &a) {
	vector<int> b;
	if (x < n) {
		pair<bool, vector<int>> p = check(2 * x, n, a);
		if (!p.first) {
			return {false, {}};
		}
		b.resize(p.second.size() / 2);
		range(i, 0, (int) b.size()) {
			b[i] = min(p.second[2 * i], p.second[2 * i + 1]);
		}
	}
	else {
		b = a;
	}

	range(i, 0, (int) b.size() / 2) {
		if (abs(b[2 * i] - b[2 * i + 1]) != 1) {
			return {false, {}};
		}
	}

	return {true, b};
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		if (check(1, n, a).first) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
