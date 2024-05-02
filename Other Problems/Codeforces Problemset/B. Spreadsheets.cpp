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

		if (s[0] == 'R' and isdigit(s[1])) {
			int x = -1;
			string y;
			bool flag = false;
			range(i, 2, s.size()) {
				if (s[i] == 'C') {
					y = s.substr(1, i - 1);
					x = stoi(s.substr(i + 1));
					flag = true;
					break;
				}
			}

			if (flag) {
				string res;
				while (x) {
					res += (x % 26 - 1) + 'A';
					x /= 26;
				}
				reverse(res.begin(), res.end());
				print(res + y);
				continue;
			}
		}

		int res = 0;
		range(i, 0, s.size()) {
			if (isdigit(s[i])) {
				printf("R%sC%lld\n", s.substr(i).c_str(), res);
				break;
			}
			res = 26 * res + (s[i] - 'A') + 1;
		}
	}
}
