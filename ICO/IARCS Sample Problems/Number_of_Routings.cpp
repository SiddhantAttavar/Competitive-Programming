#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

const int MOD = 42373;
int n;

vector<vector<int>> matMult(vector<vector<int>> &a,vector<vector<int>> &b) {
	vector<vector<int>> res(n, vector<int>(n, 0));
	range(i, 0, n) {
		range(j, 0, n) {
			range(k, 0, n) {
				long long mult = a[i][k] * b[k][j];
				res[i][j] = (res[i][j] + (mult) % MOD) % MOD;
			}
		}
	}
	return res;
}

vector<vector<int>> solve(int k, vector<vector<int>> &a) {
	if (k == 1) {
		return a;
	}
	if (k % 2 == 0) {
		vector<vector<int>> b = solve(k / 2, a);
		return matMult(b, b);
	}
	vector<vector<int>> b = solve(k - 1, a);
	return matMult(a, b);
}

int main() {
	setup();
	
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	range(i, 0, n) {
		range(j, 0, n) {
			cin >> a[i][j];
		}
	}
	int s, t, k;
	cin >> s >> t >> k;
	vector<vector<int>>  res = solve(k, a);
	print(res[s - 1][t - 1]);
}