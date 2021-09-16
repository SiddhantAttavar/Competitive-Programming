#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n;
pair<int, int> books[150];
unordered_map<long long, int> memo[150];

long long combine(int a, int b) {
	return 150 * 300 * a + b;
}

int solve(int i, int a, int b) {
	if (a > b) {
		swap(a, b);
	}
	if (i == n) {
		return b - a;
	}
	long long k = combine(a, b);
	if (memo[i].find(k) != memo[i].end()) {
		return memo[i][k];
	}

	int x = solve(i + 1, a + books[i].first, b + books[i].second);
	int y = solve(i + 1, a + books[i].second, b + books[i].first);
	return memo[i][k] = min(x, y);
}

int main() {
	setup()
	cin >> n;
	range(i, 0, n) {
		cin >> books[i].first >> books[i].second;
	}
	print(solve(0, 0, 0));
}