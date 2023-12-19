#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

bool check(vector<int> a, int k) {
	int res = 0;
	range(i, 0, (int) a.size() - 1) {
		res += a[i + 1] > a[i];
	}
	return res == k;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> res;
		int l = 1, r = n;
		if (2 * k <= n) {
			range(i, 0, k) {
				res.push_back(l);
				res.push_back(r);
				l++;
				r--;
			}
			range(i, 0, n - 2 * k) {
				res.push_back(r);
				r--;
			}
		}
		else {
			int x = -1;
			range(i, 0, n + 1) {
				if (((i - 1) + (n - i) / 2) == k) {
					x = i;
					break;
				}
			}
			assert(x != -1);
			range(i, 0, x) {
				res.push_back(r);
				r--;
			}
			reverse(res.begin(), res.end());
			range(i, 0, (n - x) / 2) {
				res.push_back(l);
				res.push_back(r);
				l++;
				r--;
			}
		}

		while (l < r) {
			res.push_back(l);
			l++;
		}

		arrPrint(res);
		// print(l, r);
		// cout.flush();
		// assert(check(res, k));
		// assert((int) res.size() == n);
		// assert(l == r + 1);
	}
}
