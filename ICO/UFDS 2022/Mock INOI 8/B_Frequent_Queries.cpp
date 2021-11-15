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
	int s; input(s);
	int n, q, a, b; input(n, q, a, b);
	vector<int> v(n); arrPut(v);
	
	vector<pair<int, int>> x(n);
	range(i, 0, n) {
		x[i] = {v[i], i};
	}
	sort(x.begin(), x.end());

	vector<vector<int>> dp(n, vector<int>(n, -1));
	range(l, 0, n) {
		priority_queue<pair<int, int>> pq;
		map<int, int> prefSum;
		range(r, l, n) {
			prefSum[v[r]]++;
			pq.push({prefSum[v[r]], v[r]});
			int i, j;
			tie(i, j) = pq.top();
			i = prefSum[j];
			while (i > b) {
				pq.pop();
				if (pq.empty()) {
					break;
				}
				tie(i, j) = pq.top();
				i = prefSum[j];
			}
			if (!pq.empty() and i >= a) {
				dp[l][r] = j;
			}
		}
	}

	while (q--) {
		int l, r; input(l, r);
		print(dp[l - 1][r - 1]);
	}
}