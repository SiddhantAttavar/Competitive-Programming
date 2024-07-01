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

bool beautiful(vector<int> &x, vector<int> &y, vector<int> b) {
	// arrPrint(x);
	// arrPrint(y);
	// arrPrint(b);
	// cout.flush();
	vector<int> p, q;
	range(i, 0, (int) b.size()) {
		if (i % 2 == 0) {
			p.push_back(b[i]);
		}
		else {
			q.push_back(b[i]);
		}
	}
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());

	return (p == x and q == y);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	vector<int> x, y;
	range(i, 0, n) {
		if (i % 2 == 0) {
			x.push_back(a[i]);
		}
		else {
			y.push_back(a[i]);
		}
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	// arrPrint(x);
	// arrPrint(y);

	vector<vector<int>> res;
	do {
		do {
			vector<int> t(n);
			range(i, 0, n) {
				if (i % 2 == 0) {
					t[i] = x[i / 2];
				}
				else {
					t[i] = y[i / 2];
				}
			}
			res.push_back(t);
			// arrPrint(t);
		} while (next_permutation(y.begin(), y.end()));
	} while (next_permutation(x.begin(), x.end()));
	sort(res.begin(), res.end());

	int l;
	input(l);
	while (l--) {
		int k;
		input(k);

		// print(k);
		// cout.flush();

		arrPrint(res[k - 1]);
	}
}
