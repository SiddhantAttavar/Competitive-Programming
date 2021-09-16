#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T& outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T& outVar, S&... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int n, m, o; input(n, m, o);
	
	pair<int, int> a[n], b[m];
	for (pair<int, int> &p : a) {
		input(p.first, p.second);
	}
	for (pair<int, int> &p : b) {
		input(p.first, p.second);
	}

	sort(a, a + n, [](pair<int, int> x, pair<int, int> y) {
		if (x.second == y.second) {
			return x.first >= y.first;
		}
		return x.second < y.second;
	});

	sort(b, b + m, [](pair<int, int> x, pair<int, int> y) {
		if (x.second == y.second) {
			return x.first < y.first;
		}
		return x.second < y.second;
	});

	int prev[n] = {-1};
	range(i, 1, n) {
		if (a[i].second == a[i - 1].second) {
			prev[i] = prev[i - 1];
		}
		else {
			prev[i] = a[i - 1].second;
		}
	}

	int l = n - 1, r = m - 1;
	vector<int> maxProfit;
	while (l >= 0 && r >= 0) {
		if (a[l].second < b[r].second) {
			r--;
		}
		else if (prev[l] != -1 && prev[l] >= b[r].second) {
			l--;
		}
		else {
			maxProfit.push_back((0, b[r].first - a[l].first));
			l--;
			r--;
		}
	}

	sort(maxProfit.begin(),maxProfit.end());
	reverse(maxProfit.begin(), maxProfit.end());

	ll res = 0;
	range(i, 0, min(o, (int) maxProfit.size())) {
		res += maxProfit[i];
	}

	print(res);
}