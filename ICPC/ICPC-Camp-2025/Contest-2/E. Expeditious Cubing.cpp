#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<double> a(4);
	cin >> a[0] >> a[1] >> a[2] >> a[3];

	vector<int> b = {
		(int) round(a[0] * 100),
		(int) round(a[1] * 100),
		(int) round(a[2] * 100),
		(int) round(a[3] * 100)
	};
	sort(b.begin(), b.end());

	double x;
	cin >> x;
	int y = round(x * 100);

	y = 3 * y - b[1] - b[2];
	if (y < b[0]) {
		cout << "impossible\n";
		return 0;
	}
	if (y >= b[3]) {
		cout << "infinite\n";
		return 0;
	}
	cout << fixed << setprecision(2);
	cout << round(y) / 100 << endl;
}
