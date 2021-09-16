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

int n;
pair<int, int> points[int(2e6)];

int solve(int i, int minA, int maxA, int minB, int maxB) {
	if (i == n) {
		if (minA == (1e8 + 1) or maxA == -1 or minB == (1e8 + 1) or minB == -1) {
			return 1e8;
		}
		return (maxA - minA) + (maxB - minB);
	}

	return min(
		solve(i + 1, min(points[i].first, minA), max(points[i].first, maxA), minB, maxB),
		solve(i + 1, minA, maxA, min(points[i].second, minB), max(points[i].second, maxB))
	);
}

int main() {
	setup();
	
	input(n);
	range(i, 0, n) {
		input(points[i].first, points[i].second);
	}
	sort(points, points + n);

	return 0;print(solve(0, 1e8 + 1, -1, 1e8 + 1, -1));
}