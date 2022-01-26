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
#define int long long

int32_t main() {
	setup();
	
	int g, a, n;
	input(g, a, n);
	vector<int> x(g), y(a);
	arrPut(x);
	arrPut(y);
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	priority_queue<
		pair<int, pair<int, int>>, 
		vector<pair<int, pair<int, int>>>, 
		greater<pair<int, pair<int, int>>>
	> pq;
	pq.push({x[0] + y[0], {0, 0}});
	int res = 0;
	range(k, 0, n) {
		int i, j;
		tie(i, j) = pq.top().second;
		pq.pop();

		res += x[i] + y[j];
		if (i < g - 1) {
			pq.push({x[i + 1] + y[j], {i + 1, j}});
		}
		if (j < a - 1) {
			pq.push({x[i] + y[j + 1], {i, j + 1}});
		}
	}
	print(res);
	
	// vector<int> xPrefSum(g + 1), yPrefSum(a + 1);
	// range(i, 0, g) {
	// 	xPrefSum[i + 1] = xPrefSum[i] + x[i];
	// }
	// range(i, 0, a) {
	// 	yPrefSum[i + 1] = yPrefSum[i] + y[i];
	// }

	// int res = 1e9;
	// range(i, 1, g + 1) {
	// 	int xCost = xPrefSum[i] * (n / i) + xPrefSum[n % i];
		
	// 	if ((n / i) + min(1ll, n % i) > a) {
	// 		continue;
	// 	}
		
	// 	int yCost = yPrefSum[n / i] * i;
	// 	if (n % i > 0) {
	// 		yCost += y[n / i] * (n % i);
	// 	}

	// 	res = min(res, xCost + yCost);
	// }
	// print(res);
}
