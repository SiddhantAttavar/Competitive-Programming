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
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n);
		arrPut(a);

		vector<int> c(m, 0);
		vector<int> b(n);
		b[0] = a[0];
		c[a[0] - 1]++;
		
		range(i, 1, n) {
			int x = *max_element(c.begin(), c.end());

			int j = i;
			while (j < n and c[a[j] - 1] == x) {
				j++;
			}

			if (j == n) {
				b[i] = a[i];
				c[a[i] - 1]++;
			}
			else {
				b[i] = a[j];
				c[a[j] - 1]++;
			}
		}

		arrPrint(b);
	}
}
