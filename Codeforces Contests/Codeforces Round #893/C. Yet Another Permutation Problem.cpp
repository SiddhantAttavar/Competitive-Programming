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

int32_t main() {
	vector<int> p;
	vector<bool> s((int) 1e5 + 1, true);
	range(i, 2, (int) 1e5 + 1) {
		if (s[i]) {
			p.push_back(i);
			for (int j = i * 2; j <= (int) 1e5; j += i) {
				s[j] = false;
			}
		}
	}

	// setup();
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		/* vector<int> par(n + 1, -1);
		vector<int> last(n + 1, -1);
		range(i, 1, n + 1) {
			last[i] = i;
		}

		for (int i = n; i > 1; i--) {
			for (int j : p) {
				if (i % j == 0) {
					int x = i / j;
					par[i] = last[x];
					last[x] = last[i];
					break;
				}
			}
		}

		// arrPrint(par);
		// arrPrint(last);

		int x = last[1];
		// print(x);
		vector<int> res;
		while (x != -1) {
			// print(x);
			res.push_back(x);
			x = par[x];
		}
		reverse(res.begin(), res.end());
		arrPrint(res); */

		vector<int> res;
		res.push_back(1);
		range(i, 2, n / 2 + 1) {
			res.push_back(i);
			res.push_back(2 * i);
		}
		if (n & 1) {
			res.push_back(n);
		}
		arrPrint(res);
	}
}
