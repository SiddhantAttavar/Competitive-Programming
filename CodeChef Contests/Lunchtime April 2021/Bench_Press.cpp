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
#define int ll

signed main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, a, b;
		input(n, a, b);
		int w[n]; arrPut(w);

		unordered_map<int, int> freq;
		for (int i : w) {
			freq[i]++;
		}

		ll res = 0;
		for (pair<int, int> p : freq) {
			res += (p.second / 2) * 2 * p.first;
		}
		print(res + b >= a ? "YES" : "NO");
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
#define int ll

signed main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, a, b;
		input(n, a, b);
		int w[n]; arrPut(w);

		unordered_map<int, int> freq;
		for (int i : w) {
			freq[i]++;
		}

		ll res = 0;
		for (pair<int, int> p : freq) {
			res += (p.second / 2) * 2 * p.first;
		}
		print(res + b >= a ? "YES" : "NO");
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}