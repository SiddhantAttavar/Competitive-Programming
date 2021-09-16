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
		int n; input(n);
		string s; input(s);

		bool flag = true;
		int tCount = 0, mCount = 0;
		for (char c : s) {
			tCount += c == 'T';
			mCount += c == 'M';

			if (mCount > tCount) {
				flag = false;
				break;
			}
		}

		flag &= tCount == mCount * 2;

		reverse(s.begin(), s.end());
		tCount = 0;
		mCount = 0;
		for (char c : s) {
			tCount += c == 'T';
			mCount += c == 'M';

			if (mCount > tCount) {
				flag = false;
				break;
			}
		}

		print((flag ? "YES" : "NO"));
	}
}