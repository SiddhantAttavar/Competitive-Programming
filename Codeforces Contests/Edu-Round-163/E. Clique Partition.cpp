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
const int MOD = (int) 1e9 + 7;

vector<int> solve(int x) {
	// print('e', x);
	if (x == 0) {
		return {};
	}

	if (x == 1) {
		return {1};
	}

	vector<int> res;
	for (int i = (x + 1) / 2 - 1; i >= 1; i--) {
		res.push_back(i);
	}
	for (int i = x; i >= (x + 1) / 2; i--) {
		res.push_back(i);
	}
	return res;

	// vector<int> a = {1}, b = {2};
	// for (int i = 3; i <= x; i += 2) {
	// 	a.push_back(i);
	// }
	//
	// for (int i = 4; i <= x; i += 2) {
	// 	b.push_back(i);
	// }
	//
	// reverse(b.begin(), b.end());
	// a.insert(a.end(), b.begin(), b.end());
	// return a;
}

vector<int> shift(vector<int> a, int x) {
	vector<int> b(a.begin(), a.end());
	range(i, 0, b.size()) {
		b[i] += x;
	}
	return b;
}

bool check(int x, int k) {
	vector<int> v = solve(x);
	range(i, 0, v.size()) {
		range(j, 0, i) {
			if ((i - j + abs(v[i] - v[j])) > k) {
				return false;
			}
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		int y = 1;
		while (y < n and check(y + 1, k)) {
			y++;
		}
		// print('d', y);

		vector<int> v = solve(y);

		vector<int> res;
		range(i, 0, n / y) {
			vector<int> t = shift(v, i * y);
			res.insert(res.end(), t.begin(), t.end());
		}

		v = solve(n % y);
		v = shift(v, n  - n % y);
		res.insert(res.end(), v.begin(), v.end());

		arrPrint(res);

		vector<int> a(n);
		range(i, 0, n) {
			a[i] = i / y + 1;
		}

		print(a.back());
		arrPrint(a);
	}
}
