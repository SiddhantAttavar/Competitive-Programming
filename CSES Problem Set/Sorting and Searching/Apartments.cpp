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

	int n, m, k;
	input(n, m, k);

	vector<int> a(n);
	arrPut(a);

	vector<int> b(m);
	arrPut(b);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> l(n), r(n, -1);
	range(i, 0, n) {
		l[i] = lower_bound(b.begin(), b.end(), a[i] - k) - b.begin();
		if (l[i] != m and b[l[i]] <= a[i] + k) {
			r[i] = upper_bound(b.begin(), b.end(), a[i] + k) - b.begin() - 1;
		}
	}

	int c = -1, res = 0;;
	range(i, 0, n) {
		if (r[i] != -1 and c < r[i]) {
			res++;
			c = max(c + 1, l[i]);
		}
	}

	print(res);
}
