#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, k;
vector<int> v, b;
vector<vector<int>> memo;

int solve(int i, int j) {
	if (i >= j) {
		return 0;
	}
	if (memo[i][j] != numeric_limits<int>::min()) {
		return memo[i][j];
	}

	memo[i][j] = max(0, solve(i + 1, j));
	range(l, i + 1, j + 1) {
		if (b[l] - b[i] == k) {
			memo[i][j] = max(memo[i][j], v[i] + v[l] + solve(i + 1, l - 1) + solve(l + 1, j));
		}
	}
	return memo[i][j];
}

int main() {
	setup();
	cin >> n >> k;
	
	v = vector<int>(n);
	b = vector<int>(n);
	range(i, 0, n) {
		cin >> v[i];
	}
	range(i, 0, n) {
		cin >> b[i];
	}

	memo = vector<vector<int>>(n, vector<int>(n, numeric_limits<int>::min()));
	print(solve(0, n - 1));
}