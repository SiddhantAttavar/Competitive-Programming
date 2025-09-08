#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	rep(i, 0, n) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());

	int m;
	cin >> m;
	vector<int> x(m);
	rep(i, 0, m) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());

	vector<int> a(n, 2);
	int l = 0;
	rep(i, 0, n) {
		while (l < m and x[l] < v[i].first) {
			l++;
		}
		while (l < m and x[l] <= v[i].second) {
			a[i]--;
			l++;
		}
		if (l > 0 and x[l - 1] == v[i].second) {
			l--;
		}
	}

	if (*min_element(a.begin(), a.end()) < 0) {
		cout << "impossible\n";
		return 0;
	}

	set<int> s(x.begin(), x.end());
	set<int> res;
	rep(i, 1, n) {
		if (a[i - 1] > 0 and a[i] > 0 and !s.count(v[i].first) and v[i].first == v[i - 1].second) {
			res.insert(v[i].first);
			a[i - 1]--;
			a[i]--;
		}
	}
	rep(i, 0, n) {
		if (a[i] >= 1) {
			res.insert(v[i].first + 1 + s.count(v[i].first + 1));
		}
		if (a[i] == 2) {
			res.insert(v[i].first + 2);
		}
	}

	cout << res.size() << endl;
	for (int i : res) {
		cout << i << ' ';
	}
	cout << endl;
}
