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
		string s;
		input(s);

		string res;
		range(i, 1, s.size()) {
			if (s[i] == s[i - 1]) {
				res = s.substr(0, i);
				if (s[i] == 'z') {
					res += 'a';
				}
				else {
					res += s[i] + 1;
				}
				res += s.substr(i);
				break;
			}
		}

		if (res.size()) {
			print(res);
			continue;
		}

		if (s.back() == 'z') {
			print(s + 'a');
		}
		else {
			print(s + ((char) (s.back() + 1)));
		}
	}
}
