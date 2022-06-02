#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... y) {cin >> x; input(y ...);}
template<typename T> inline void print(T x) {cout << x << endl;}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
#define range(i, j, n) for (int i = j; i < n; i++)
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} cout << endl;
#define int long long
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, m, k;
vector<int> a, x, b, y;

int32_t main() {
	setup();
	
	input(n, m, k);

	a.resize(k);
	x.resize(k);
	b.resize(k);
	y.resize(k);
	range(i, 0, k) {
		input(a[i], b[i], x[i], y[i]);
		if (b[i] > y[i]) {
			swap(a[i], x[i]);
			swap(b[i], y[i]);
		}
	}

	map<int, int> my;
	for (int i : b) {
		my[i]++
	}

	int res = 1e9;
	int curr = 0;
	range(i, 0, k) {
		curr += min(
			2 * abs(x1 - x2),
			abs(x1 - x2) + 4 * (y[i] - 1)
		);
	}

	int numPrev = 0;
	int sumPrev = 0;
	int numAfter = 0;
	int sumAfter = 0;
	range(i, 0, n) {
		
	}

	range(i, 2, m + 1) {

	}
}
