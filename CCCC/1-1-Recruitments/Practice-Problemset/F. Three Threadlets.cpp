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
		vector<int> a(3);
		arrPut(a);
		sort(a.begin(), a.end());
		
		int x = 0, y = 0;

		if (a[1] == a[0]) {
			x = 0;
		}
		else if (a[1] == 2 * a[0]) {
			x = 1;
		}
		else if (a[1] == 3 * a[0]) {
			x = 2;
		}
		else if (a[1] == 4 * a[0]) {
			x = 3;
		}
		else {
			print("NO");
			continue;
		}

		if (a[2] == a[0]) {
			y = 0;
		}
		else if (a[2] == 2 * a[0]) {
			y = 1;
		}
		else if (a[2] == 3 * a[0]) {
			y = 2;
		}
		else if (a[2] == 4 * a[0]) {
			y = 3;
		}
		else {
			print("NO");
			continue;
		}

		if (x + y <= 3) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
