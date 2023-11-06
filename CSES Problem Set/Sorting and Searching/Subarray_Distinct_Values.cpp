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
	setup();

	int n, k;
	input(n, k);

	vector<int> a(n);
	arrPut(a);

	map<int, int> m;
	int l = 0;
	m[a[0]] = 1;
	int res = 1;

	range(i, 1, n) {
		m[a[i]]++;
		while ((int) m.size() > k) {
			m[a[l]]--;
			if (!m[a[l]]) {
				m.erase(a[l]);
			}
			l++;
		}

		res += i - l + 1;
	}

	print(res);
}
