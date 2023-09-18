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

		vector<int> c(n);
		arrPut(c);

		int k;
		input(k);

		vector<pair<int, int>> a(n);
		range(i, 0, n) {
			a[i] = {c[i], i};
		}
		sort(a.begin(), a.end());

		priority_queue<int> v;
		int x = k;
		for (pair<int, int> p : a) {
			while (x >= p.first) {
				x -= p.first;
				v.push(p.second);
			}
		}

		int j = 0;
		vector<int> l(n, 0);
		while (!v.empty()) {
			int i = v.top();
			v.pop();

			while (j < n and a[j].second <= i) {
				j++;
			}
			if (j == n) {
				l[i]++;
				continue;
			}

			if (x >= (a[j].first - c[i])) {
				x -= a[j].first - c[i];
				v.push(a[j].second);
			}
			else {
				l[i]++;
			}
		}

		int q = 0;
		vector<int> res(n);
		for (int i = n - 1; i >= 0; i--) {
			q += l[i];
			res[i] = q;
		}
		arrPrint(res);
	}
}
