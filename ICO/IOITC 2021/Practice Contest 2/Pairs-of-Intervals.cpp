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

int main() {
	setup();

	int n; input(n);
	pair<int, pair<int, bool>> points[2 * n];
	range(i, 0, n) {
		int l, r, L, R;
		input(l, r, L, R);
		points[2 * i] = {l, {i, true}};
		points[2 * i + 1] = {L, {i, false}};
	}
	sort(points, points + (2 * n));

	pair<int, int> dp[2 * n];
	int curr = -1;
	range(i, 0, 2 * n) {
		dp[i] = {1, -1};
		int x = 2 * n - 1;
		bool flag = false;
		range(j, 0, i) {
			if (points[j].first < points[i].first) {
				if (points[j].second.first == points[i].second.first) {
					if ((j == 0 || points[j].first != points[j - 1].first) && points[j].first != points[j + 1].first) {
						x = j;
					}
				}
				else {
					if (points[x].first < points[j].first) {
						flag = true;
					}
					if (dp[i].first < dp[j].first + 1 - flag) {
						dp[i] = {dp[j].first + 1 - flag, j};
					}
				}
			}
		}
	}

	int u = -1;
	range(i, 0, 2 * n) {
		if (dp[i].first == n) {
			u = i;
			break;
		}
	}

	if (u == -1) {
		print("No");
		return 0;
	}

	print("Yes");
	bool chooseFirst[n];
	while (u != -1) {
		chooseFirst[points[u].second.first] = !points[u].second.second;
		u = dp[u].second;
	}

	for (bool b : chooseFirst) {
		cout << b + 1 << ' ';
	}
}