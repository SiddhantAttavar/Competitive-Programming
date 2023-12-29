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
		int n;
		input(n);

		string s;
		input(s);

		vector<string> res;
		res.push_back("");
		for (int i = n - 1; i >= 0; i--) {
			res.back() += s[i];
			if (res.back().size() != 1 and (s[i] == 'b' or s[i] == 'c' or s[i] == 'd')) {
				res.push_back("");
			}
		}
		res.pop_back();

		string t;
		reverse(res.begin(), res.end());
		for (string i : res) {
			reverse(i.begin(), i.end());
			t += i + '.';
		}
		t.pop_back();
		print(t);
	}
}
