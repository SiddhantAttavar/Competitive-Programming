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
	
	int n;
	input(n);

	vector<pair<int, int>> a(n);
	range(i, 0, n) {
		input(a[i].first, a[i].second);
	}
	sort(a.begin(), a.end());

	vector<int> dp1(n), dp2(n), dp3(n);
	dp1[0] = 0;
	dp2[0] = 1;
	dp3[0] = a[0].first + a[0].second < a[1].first;

	range(i, 1, n) {
		if (a[i - 1].first + a[i - 1].second < a[i].first) {
			dp1[i] = max({dp1[i - 1], dp2[i - 1], dp3[i - 1]});
		}
		else {
			dp1[i] = max(dp1[i - 1], dp2[i - 1]);
		}

		if (a[i - 1].first + a[i - 1].second < a[i].first - a[i].second) {
			dp2[i] = max({dp1[i - 1], dp2[i - 1], dp3[i - 1]}) + 1;
		}
		else if (a[i - 1].first < a[i].first - a[i].second) {
			dp2[i] = max(dp1[i - 1], dp2[i - 1]) + 1;
		}

		if (a[i - 1].first + a[i - 1].second < a[i].first) {
			dp3[i] = max({dp1[i - 1], dp2[i - 1], dp3[i - 1]}) + 1;
		}
		else {
			dp3[i] = max(dp1[i - 1], dp2[i - 1]) + 1;
		}
	}


	print(max({dp1[n - 1], dp2[n - 1], dp3[n - 1]}));
}
