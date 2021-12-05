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
		int n, k; input(n, k);
		vector<int> p(n), ind(n); arrPut(p);
		range(i, 0, n) {
			p[i]--;
			ind[p[i]] = i;
		}
		int l = 0, r = n - 1;
		while (l < r and p[l] == l) {
			l++;
		}
		while (l < r and p[r] == r) {
			r--;
		}
		if (l == r) {
			print(0);
			continue;
		}
		if (r - l + 1 <= k) {
			print(1);
			continue;
		}
		//2 or 3
		bool flag1 = true, flag2 = true;
		int a = r - k;
		int b = l + k;
		range(i, b, r + 1) {
			if (p[i] <= a) {
				flag1 = false;
			}
		}
		range(i, l, a + 1) {
			if (p[i] >= b) {
				flag2 = false;
			}
		}
		if (flag1 or flag2) {
			print(2);
		}
		else {
			print(3);
		}

		/*int res = 0;
		while (l < r) {
			res++;
			if (r - l + 1 <= k) {
				break;
			}
			sort(p.begin() + l, p.begin() + l + k);
			while (p[l] == l + 1) {
				l++;
			}
			res++;
			sort(p.begin() + r - k + 1, p.begin() + r + 1);
			while (l < r and p[r] == r + 1) {
				r--;
			}
		}
		print(res);*/
	}
}
