#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

const int N = 50000;
bitset<50000> v[N];

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> p(n);
	for (int &i : p) {
		cin >> i;
	}

	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		x[p[i] - 1] = i;
	}

	for (int i = n - 2; i >= 0; i--) {
		v[x[i]] = v[x[i + 1]];
		v[x[i]][x[i + 1]] = true;
	}

	int res = 0;
	for (int i = 0; i <= n - m; i++) {
		int y = 0;
		for (int j = 0; j < n - i; j++) {
			if (!v[j][i + j]) {
				res += max(0, y - m + 1);
				y = -1;
			}
			y++;
		}
		res += max(0, y - m + 1);
	}
	cout << res << endl;
}
