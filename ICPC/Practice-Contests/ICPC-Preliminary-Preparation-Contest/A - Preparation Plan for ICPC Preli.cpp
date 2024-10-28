#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	vector<int> f(n + 1), g(n + 1), h(n + 1);
	for (int i = 0; i < n; i++) {
		f[i + 1] = a[i] + max(g[i], h[i]);
		g[i + 1] = b[i] + max(h[i], f[i]);
		h[i + 1] = c[i] + max(f[i], g[i]);
	}
	cout << max({f[n], g[n], h[n]}) << endl;
}
