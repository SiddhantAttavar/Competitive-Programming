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

	int h, n;
	input(h, n);
	vector<pair<int, int>> a(n);
	range(i, 0, n) {
		input(a[i].first);
		a[i].second = i;
	}

	vector<bool> visited(n);
	int res = 0;
	range(i, 0, n) {
		if (visited[i]) {
			continue;
		}

		res++;
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] >= a[j + 1]) {
				break;
			}
			res++;
		}
		range(j, i + 1, n) {
			if (a[j] >= a[j - 1]) {
				break;
			}
			res++;
		}
	}
	print(res);
}
