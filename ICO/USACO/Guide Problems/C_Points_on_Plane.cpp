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

int k;

int32_t main() {
	setup();
	
	int n;
	input(n);

	vector<pair<pair<int, int>, int>> a(n);
	range(i, 0, n) {
		input(a[i].first.first, a[i].first.second);
		a[i].second = i;
	}
	
	k = sqrt(n);
	sort(a.begin(), a.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		if (a.first.first / k != b.first.first / k) {
			return a.first.first < b.first.first;
		}
		if ((a.first.first / k) % 2 == 0) {
			return a.first.second < b.first.second;
		}
		return a.first.second > b.first.second;
	});
	
	int res = 0;
	range(i, 1, n) {
		res += (abs(a[i].first.first - a[i - 1].first.first) + 
				abs(a[i].first.second - a[i - 1].first.second));
	}

	assert(res <= 25e8);
	range(i, 0, n) {
		cout << a[i].second + 1 << ' ';
	}
}
