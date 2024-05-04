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

vector<int> get_digits(int x) {
	vector<int> res;
	while (x) {
		res.push_back(x % 10);
		x /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int count(int n, int x, int y) {
	if (n == 0) {
		return x == 0;
	}

	int res = 0;
	vector<int> d = get_digits(n);
	bool flag = true;
	range(i, 0, (int) d.size()) {
		if (d[i] < x) {
			flag = false;
			break;
		}

		int k = d.size() - i - 1;
		range(j, x, min(y + 1, d[i])) {
			res += pow(y - x + 1, k);
		}

		if (d[i] > y) {
			flag = false;
			break;
		}
	}

	if (x and d.size() > 1) {
		if (y > x) {
			res += (y - x + 1) * (pow(y - x + 1, d.size() - 1) - 1) / (y - x);
		}
		else {
			res += d.size() - 1;
		}
	}

	return res + flag;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int l, r;
		input(l, r);

		int a = 0, b = 9;
		range(i, 0, 10) {
			range(x, 0, 10 - i) {
				int y = x + i;
				if (i < b - a and count(r, x, y) > count(l - 1, x, y)) {
					a = x;
					b = y;
				}
			}
		}

		int x = l, y = r, res = r;
		while (x <= y) {
			int m = (x + y) / 2;
			if (count(m, a, b) > count(l - 1, a, b)) {
				res = m;
				y = m - 1;
			}
			else {
				x = m + 1;
			}
		}

		print(res);
	}
}
