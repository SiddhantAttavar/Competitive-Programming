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
		int n;
		input(n);
		vector<int> h(n);
		arrPut(h);

		if (n == 1) {
			print(0);
			continue;
		}

		if (h[0] > h[1] or h[n - 2] < h[n - 1]) {
			print(-1);
			continue;
		}

		bool flag = true;
		int res = 0;
		for (int i = 0; i < n - 2; i += 2) {
			if (h[i] > h[i + 1]) {
				flag = false;
				break;
			}
			else {
				int x = h[i + 1] - h[i];
				res += x;
				h[i + 1] -= x;
				if (h[i + 2] < x) {
					flag = false;
					break;
				}
				h[i + 2] -= x;
			}
		}
		if (!flag) {
			print(-1);
			continue;
		}
		if (n % 2 == 0 and h[n - 2] != h[n - 1]) {
			print(-1);
			continue;
		}

		int m = *min_element(h.begin(), h.end());
		if (n % 2 == 1 and h[n - 1] != m) {
			print(-1);
			continue;
		}
		for (int i = 0; i < n - 1; i += 2) {
			res += h[i] - m;
		}

		print(res * 2);
	}
}
