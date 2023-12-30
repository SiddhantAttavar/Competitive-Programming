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
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);

		int x = 0, y = 0;
		bool flag = true;
		for (int i : a) {
			if (i % 7 == 0) {
				x++;
				i /= 7;
			}
			if (i % 17 == 0) {
				y++;
				i /= 17;
			}
			if (i % 17 == 0) {
				y++;
				i /= 17;
			}
			if (i != 1) {
				flag = false;
				break;
			}
		}

		if (!flag or x > 1 or y > 2) {
			print("NO");
			continue;
		}

		int z = 1;
		if (x == 0) {
			z = 7;
		}
		if (y == 0) {
			z *= 17 * 17;
		}
		else if (y == 1) {
			z *= 17;
		}

		print("YES");
		a.clear();
		a.push_back(z);
		range(i, 0, k - 1) {
			a.push_back(1);
		}
		arrPrint(a);
	}
}
