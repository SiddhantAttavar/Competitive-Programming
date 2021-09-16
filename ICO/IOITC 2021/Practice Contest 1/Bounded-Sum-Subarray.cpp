#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int n, m;
	input(n, m);
	int a[n]; arrPut(a);

	ll prefSum[n + 1] = {0};
	range(i, 1, n + 1) {
		prefSum[i] = prefSum[i - 1] + a[i - 1];
	}

	vector<pair<ll, int>> sums;
	for (int i = n; i >= 0; i--) {
		if (sums.size() == 0 || prefSum[i] < sums[sums.size() - 1].first) {
			sums.push_back({prefSum[i], i});
		}
	}
	reverse(sums.begin(), sums.end());

	int maxLength = 0, start = 0;
	range(l, 0, n) {
		//We have to find the largest r such that prefSum[r] - prefSum[l] <= m
		//We have to find the largest r such that prefSum[r] <= m + prefSum[l]
		//The length becomes r - l
		vector<pair<ll, int>>::iterator it = upper_bound(sums.begin(), sums.end(), make_pair(m + prefSum[l], n));
		if (it == sums.begin()) {
			continue;
		}
		it--;
		int r = (*it).second;
		if (r - l > maxLength) {
			maxLength = r - l;
			start = l;
		}
	}

	print(maxLength, start + 1);
}