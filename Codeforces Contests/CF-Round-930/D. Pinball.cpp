#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		int a = 0, x = 0, b = 0, y = 0;
		range(i, 1, n) {
			if (s[i] == '<') {
				b++;
				y += i;
			}
		}

		vector<int> res(n);
		range(i, 0, n) {
			x += a;
			y -= b;

			if (s[i] == '<') {
				b--;
			}

			pair<int, int> p = {a, i + 1}, q = {b, n - i};
			if (s[i] == '<') {
				swap(p, q);
			}

			res[i] = 2 * (x + y);
			if (q.first < p.first) {
				res[i] += q.second;
			}
			else {
				res[i] += p.second;
			}

			if (s[i] == '>') {
				a++;
			}
		}

		arrPrint(res);
	}
}
