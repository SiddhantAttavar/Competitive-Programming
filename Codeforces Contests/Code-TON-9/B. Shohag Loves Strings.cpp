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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool check(string s) {
	set<string> res;
	rep(i, 0, s.size()) {
		string t;
		rep(j, i, s.size()) {
			t += s[j];
			res.insert(t);
		}
	}
	return res.size() % 2 == 0;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		if (s.size() == 1) {
			print(-1);
			continue;
		}

		if (s.size() == 2) {
			if (s[0] == s[1]) {
				print(s);
			}
			else {
				print(-1);
			}
			continue;
		}

		string res;
		rep(i, 0, s.size() - 1) {
			if (s[i] == s[i + 1]) {
				res = s.substr(i, 2);
				break;
			}
		}

		if (!res.empty()) {
			print(res);
			continue;
		}

		rep(i, 0, s.size() - 2) {
			if (s[i] != s[i + 1] and s[i + 1] != s[i + 2] and s[i] != s[i + 2]) {
				res = s.substr(i, 3);
				break;
			}
		}

		if (!res.empty()) {
			print(res);
			continue;
		}

		print(-1);
	}
}
