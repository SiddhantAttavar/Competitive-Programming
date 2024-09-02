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

int solve1(string s, char a, char b) {
	int n = s.size();
	int res = n;
	for (int i = 0; i < n; i += 2) {
		res -= s[i] == a;
	}
	for (int i = 1; i < n; i += 2) {
		res -= s[i] == b;
	}
	return res;
}

int solve2(string s, char a, char b) {
	int n = s.size();
	if (n == 1) {
		return 1;
	}

	vector<int> p(n), q(n);
	p[0] = s[0] != a;
	range(i, 1, n) {
		p[i] = p[i - 1] + (s[i] != (i % 2 ? b : a));
	}

	q[n - 1] = s[n - 1] != b;
	for (int i = n - 2; i >= 0; i--) {
		q[i] = q[i + 1] + (s[i] != (i % 2 ? a : b));
	}

	int res = min(p[n - 2], q[1]) + 1;
	range(i, 1, n - 1) {
		res = min(res, p[i - 1] + q[i + 1] + 1);
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		int res = n;
		range(i, 0, 26) {
			range(j, 0, 26) {
				if (n % 2) {
					res = min(res, solve2(s, 'a' + i, 'a' + j));
				}
				else {
					res = min(res, solve1(s, 'a' + i, 'a' + j));
				}
			}
		}

		print(res);
	}
}
