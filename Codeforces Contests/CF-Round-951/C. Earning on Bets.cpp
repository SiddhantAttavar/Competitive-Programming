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

bool check(vector<int> &a, vector<int> &k) {
	int x = 0;
	for (int i : a) {
		x += i;
	}
	range(i, 0, (int) a.size()) {
		if (k[i] * a[i] <= x) {
			return false;
		}
	}
	return true;
}

pair<int, int> add(pair<int, int> a, pair<int, int> b) {
	pair<int, int> res = {a.first * b.second + a.second * b.first, a.second * b.second};
	int x = __gcd(res.first, res.second);
	return {res.first / x, res.second / x};
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> k(n);
		arrPut(k);

		pair<int, int> x = {0, 1};
		for (int i : k) {
			x = add(x, {1, i});
		}

		if (x.first >= x.second) {
			print(-1);
			continue;
		}

		int y = k[0];
		for (int i : k) {
			y = (y * i) /__gcd(y, i);
		}

		vector<int> res(n);
		range(i, 0, n) {
			res[i] = n * y / k[i] + 1;
		}
		arrPrint(res);
		cout.flush();
		assert(check(res, k));
	}
}
