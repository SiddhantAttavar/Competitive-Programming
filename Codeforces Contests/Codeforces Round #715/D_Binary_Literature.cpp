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
typedef long long ll;

int main() {
	setup(); int tc; input(tc); while (tc--) {
		int n; input(n);
		string a, b, c;
		input(a, b, c);

		int x = 0, y = 0, z = 0;
		
		string res1;
		while (x < 2 * n && y < 2 * n && res1.size() < 3 * n) {
			if (x == 2 * n) {
				res1 += b[y];
				y++;
			}
			else if (y == 2 * n) {
				res1 += a[x];
				x++;
			}
			else {
				res1 += a[x];
				y += a[x] == b[y];
				x++;
			}
		}
		if (x == 2 * n && y == 2 * n) {
			print(res1);
			continue;
		}

	}
}