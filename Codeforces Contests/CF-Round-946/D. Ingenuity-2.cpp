#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		int x = 0, y = 0;
		range(i, 0, n) {
			if (s[i] == 'N') {
				y++;
			}
			else if (s[i] == 'S') {
				y--;
			}
			else if (s[i] == 'E') {
				x++;
			}
			else {
				x--;
			}
		}

		if (x % 2 or y % 2) {
			print("NO");
			continue;
		}

		string res;
		int a = 0, b = 0;
		bool p = true, q = true;
		if (x == 0 and y == 0) {
			p = false;
		}
		range(i, 0, n) {
			if (s[i] == 'N') {
				if (p) {
					res += 'R';
					a++;
					if (a == y / 2) {
						p = false;
					}
				}
				else {
					res += 'H';
				}
			}
			else if (s[i] == 'S') {
				if (p) {
					res += 'R';
					a--;
					if (a == y / 2) {
						p = false;
					}
				}
				else {
					res += 'H';
				}
			}
			else if (s[i] == 'E') {
				if (q) {
					res += 'R';
					b++;
					if (b == x / 2) {
						q = false;
					}
				}
				else {
					res += 'H';
				}
			}
			else {
				if (q) {
					res += 'R';
					b--;
					if (b == x / 2) {
						q = false;
					}
				}
				else {
					res += 'H';
				}
			}
		}

		bool flag = false;
		for (char c : res) {
			if (c == 'H') {
				flag = true;
				break;
			}
		}

		if (!flag) {
			print("NO");
			continue;
		}

		flag = false;
		for (char c : res) {
			if (c == 'R') {
				flag = true;
				break;
			}
		}

		if (flag) {
			print(res);
		}
		else {
			print("NO");
		}
	}
}
