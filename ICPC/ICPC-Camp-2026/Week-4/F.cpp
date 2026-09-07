#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Median {
	vi l;
	priority_queue<int> p;
	priority_queue<int, vector<int>, greater<int>> q;

	void insert(int x) {
		l.push_back(x);

		p.push(x);
		
		while (true) {
			if (!p.empty() and !q.empty() and p.top() > q.top()) {
				int x = p.top();
				p.pop();
				q.push(x);
			}
			else if (sz(p) > sz(q) + 1) {
				int x = p.top();
				p.pop();
				q.push(x);
			}
			else if (sz(q) > sz(p)) {
				int x = q.top();
				q.pop();
				p.push(x);
			}
			else {
				break;
			}
		}
	}

	int median() {
		return p.top();
	}
};

void solve() {
	int n, d;
	cin >> n >> d;

	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	sort(all(a));
	
	int res = 0;
	rep(i, 0, n) {
		a[i] -= i * d;
		res += max(0ll, -a[i]);
		a[i] = max(0ll, a[i]);
	}

	vector<Median> s;
	for (int i : a) {
		Median o;
		o.insert(i);
		s.push_back(o);
		while (sz(s) >= 2 and s[sz(s) - 1].median() < s[sz(s) - 2].median()) {
			if (sz(s[sz(s) - 2].l) < sz(s[sz(s) - 1].l)) {
				swap(s[sz(s) - 2], s[sz(s) - 1]);
			}
			for (int i : s[sz(s) - 1].l) {
				s[sz(s) - 2].insert(i);
			}
			s.pop_back();
		}
	}

	for (Median &o : s) {
		int x = o.median();
		for (int i : o.l) {
			res += abs(i - x);
		}
	}
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
