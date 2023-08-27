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
		string s;
		input(s);

		vector<string> dmy(3);
		int i = 0;
		bool flag = false;
		for (char c : s) {
			if (c == '.') {
				i++;
			}
			else if (c == '/') {
				flag = true;
				i++;
			}
			else {
				dmy[i] += c;
			}
		}

		string x = dmy[0], y = dmy[1], z = dmy[2];

		if (flag) {
			swap(x, y);
		}

		if (x.size() == 1) {
			x = '0' + x;
		}

		if (y.size() == 1) {
			y = '0' + y;
		}

		if (z.size() == 1) {
			z = "000" + z;
		}
		else if (z.size() == 2) {
			z = "00" + z;
		}
		else if (z.size() == 3) {
			z = '0' + z;
		}

		cout << x << '.' << y << '.' << z << ' ' << y << '/' << x << '/' << z << endl;
	}
}
