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

bool checkWin(vector<int> &a, vector<int> &b) {
	int x = 0, y = 0;
	for (int i : a) {
		for (int j : b) {
			x += i > j;
			y += i < j;
		}
	}
	return x > y;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		vector<int> a(4), b(4);
		arrPut(a);
		arrPut(b);

		if (checkWin(b, a)) {
			swap(a, b);
		}

		bool flag = false;
		range(i, 1, 11) {
			range(j, i, 11) {
				range(k, j, 11) {
					range(l, k, 11) {
						vector<int> c = {i, j, k, l};
						if (checkWin(b, c) and checkWin(c, a)) {
							print("yes");
							flag = true;
							break;
						}
					}
					if (flag) {
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			print("no");
		}
	}
}
