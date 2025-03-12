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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool get(int x, int y, vector<int> &spf) {
	if (x == y) {
		return true;
	}

	x += x;
	if (x > y) {
		return false;
	}

	if (y % 2 == 0) {
		return true;
	}

	y -= spf[y];

	return y >= x;
}

int32_t main() {
	int N = 4e5;
	vector<int> spf(N + 1);
	rep(i, 0, N + 1) {
		spf[i] = i;
	}
	vector<int> p;
	rep(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}

		p.push_back(i);
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		int x = -1;
		for (int i : a) {
			if (spf[i] == i) {
				x = i;
				break;
			}
		}

		if (x == -1) {
			print(2);
			continue;
		}

		bool flag = true;
		for (int i : a) {
			if (!get(x, i, spf)) {
				// print(i, x);
				flag = false;
				break;
			}
		}

		if (flag) {
			print(x);
		}
		else {
			print(-1);
		}
	}
}
