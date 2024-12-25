#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'

// #define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ff first
#define ss second
#define vi vector<int>

bool check(vector<int> &a, vector<int> &b, vector<pair<int, int>> &swaps) {
	assert(swaps.size() <= a.size() * (a.size() - 1) / 2);
	// cout << endl;
	for (pair<int, int> p : swaps) {
		if (p.first > p.second or a[p.first] < a[p.second]) {
			cout << p.first + 1 << ' ' << p.second + 1 << endl;
			return false;
		}
		swap(a[p.first], a[p.second]);
	}
	rep(i, 0, a.size()) {
		if (a[i] != b[i]) {
			cout << i << endl;
			return false;
		}
	}
	return true;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i,0,n)cin >> a[i];
    rep(i,0,n)cin >> b[i];

	rep(i, 0, n) {
		a[i]--;
		b[i]--;
	}

	vector<int> oa(a.begin(), a.end());
	vector<pair<int, int>> res;
	bool flag = true;
	for (int i = n - 1; i >= 0; i--) {
		if (b[i] < a[i]) {
			flag = false;
			break;
		}
		if (b[i] == a[i]) {
			continue;
		}

		int j = -1;
		while (a[j] != b[i]) {
			j++;
		}
		// cout << j << ' ' << i << endl;
		vector<pair<int, int>> v;
		rep(k, j + 1, i + 1) {
			if (a[k] <= a[j] and a[k] >= a[i]) {
				v.push_back({a[k], k});
			}
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		for (pair<int, int> p : v) {
			if (p.second > j) {
				// cout << j << ' ' << p.second << ' ' << i << endl;
				res.push_back({j, p.second});
				swap(a[j], a[p.second]);
				j = p.second;
			}
		}
	}

	if (!flag) {
		cout << "-1\n";
		return;
	}

	cout << res.size() << endl;
	rep(i, 0, res.size()) {
		if (res[i].first > res[i].second) {
			swap(res[i].first, res[i].second);
		}
	}
	for (pair<int, int> p : res) {
		cout << p.first + 1 << ' ' << p.second + 1 << endl;
	}
	// assert(check(oa, b, res));
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}
