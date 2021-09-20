<<<<<<< HEAD
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
		int n, m; input(n, m);
		int x, y; input(x, y);

		range(i, 0, n) {
			int full = 0, partial = 0;
			string s; input(s);
			for (char c : s) {
				full += c == 'F';
				partial += c == 'P';
			}
			cout << (full >= x || (full == (x - 1) && partial >= y));
		}
		cout << endl;
	}
=======
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
		int n, m; input(n, m);
		int x, y; input(x, y);

		range(i, 0, n) {
			int full = 0, partial = 0;
			string s; input(s);
			for (char c : s) {
				full += c == 'F';
				partial += c == 'P';
			}
			cout << (full >= x || (full == (x - 1) && partial >= y));
		}
		cout << endl;
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}