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
	setup();

	string s;
	int k;
	input(s, k);

	int n = s.size();
	int a = 0, c = 0, x = 0;
	int i = 9;
	while (i >= 0 and c <= k and x < n - k) {
		range(j, a, min(n, a + k - c + 1)) {
			if (s[j] - '0' == i) {
				c += j - a;
				a = j + 1;
				cout << i;
				i = 10;
				x++;
				break;
			}
		}
		i--;
	}
}
