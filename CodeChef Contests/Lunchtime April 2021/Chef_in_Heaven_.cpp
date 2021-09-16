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
typedef long long ll;

int main() {
	setup(); int tc; input(tc); while (tc--) {
		int l; input(l);
		string s; input(s);
		bool flag = false;
		int score = 0;
		range(i, 0, l) {
			score += s[i] == '1';
			if (score >= ceil((i + 1) / 2.0)) {
				flag = true;
				print("YES");
				break;
			}
		}
		if (!flag) {
			print("NO");
		}
	}
}