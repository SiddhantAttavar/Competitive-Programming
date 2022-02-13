#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... y) {cin >> x; input(y ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
#define range(i, j, n) for (int i = j; i < n; i++)
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} << cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();

	int n;
	input(n);
	vector<pair<int, int>> a(n + 1, {-1, 0});
	range(i, 1, n + 1) {
		input(a[i].first);
		while ((a[i].first & 1) == 0) {
			a[i].first >>= 1;
			a[i].second++;
		}
		a[i].second = 1 << a[i].second;
	}

	range(i, 0, n) {
		a[i + 1].second += a[i].second;
	}

	int q;
	input(q);
	while (q--) {
		int x;
		input(x);
		
		int l = 0, r = n - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (a[m].second < x and x <= a[m + 1].second) {
				print(a[m + 1].first);
				break;
			}
			else if (a[m].second < x) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
	}
}

