#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n; input(n);
		vector<int> a(n); arrPut(a);
		sort(a.begin(), a.end());

		// Edge cases
		if (n <= 2) {
			print(0);
			continue;
		}
		else if (n == 3) {
			print(min(a[1] - a[0], a[2] - a[1]));
			continue;
		}
		
		// B1 smallest element: a[0]
		// B1 largest element: a[l]
		// B2 smallest element: a[r]
		// B2 largest element: a[n-1]
		// 0 <= l, r <= n - 1
		// l != n - 1, r != 0
		// 0 < r < l or r = l + 1

		int x = 0, y = 0;
		range(i, 0, n - 1) {
			x += abs(a[i] - a[(n - 1) / 2]);
		}
		range(i, 1, n) {
			y += abs(a[i] - a[(n - 1) / 2 + 1]);
		}
		int res = min(x, y);


		/*
		// First we will solve for case where r = l + 1
		range(l, 0, n - 1) {
			int leftBeauty = a[l] - a[0];
			int rightBeauty = a[n - 1] - a[l + 1];
			res = min(res, abs(leftBeauty - rightBeauty));
		}
		*/

		// Now we will solve for case where 0 < r < l
		int l = n - 2, r = 1;
		while (r < l) {
			int leftBeauty = a[l] - a[0];
			int rightBeauty = a[n - 1] - a[r];
			res = min(res, abs(leftBeauty - rightBeauty));

			if (leftBeauty == rightBeauty) {
				// res = 0
				// we cannot improve this
				break;
			}
			else if (leftBeauty < rightBeauty) {
				// We need to decrease rightBeauty
				// If we increase r, a[r] will increase which will decrease a[n - 1] - a[r]
				r++;
			}
			else {
				// We need to decrease leftBeauty
				// If we decrease l, a[l] will decrease which will decrease a[l] - a[0]
				l--;
			}
		}

		// Print the minimum value of res calculated
		print(res);
	}
}