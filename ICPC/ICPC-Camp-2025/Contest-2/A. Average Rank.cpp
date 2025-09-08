#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, w;
	cin >> n >> w;

	vector<array<int, 3>> s(w + 1);
	vector<array<int, 2>> p(n, {0, 0});
	s[0] = {1, 1, 0};

	rep(i, 1, w + 1) {
		int k;
		cin >> k;

		vector<int> c(k);
		map<int, int> f;
		rep(j, 0, k) {
			cin >> c[j];
			c[j]--;
			f[p[c[j]][0]]++;
		}

		for (auto [y, m] : f) {
			s[y] = {
				s[y][0] + m,
				i,
				s[y][0] * (i - s[y][1]) + s[y][2]
			};
			if (s[y + 1][0] == 0) {
				s[y + 1] = {1, i, 0};
			}
		}

		for (int j : c) {
			p[j][1] += s[p[j][0]][2] + s[p[j][0]][0] * (i - s[p[j][0]][1]);
			p[j][0]++;
			p[j][1] -= s[p[j][0]][2] + s[p[j][0]][0] * (i - s[p[j][0]][1]);
		}
	}

	cout << fixed << setprecision(9);
	rep(j, 0, n) {
		p[j][1] += s[p[j][0]][2] + s[p[j][0]][0] * (w + 1 - s[p[j][0]][1]);
		cout << ((double) p[j][1]) / w << endl;
	}
}
