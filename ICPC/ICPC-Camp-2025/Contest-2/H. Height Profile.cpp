#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const double EPS = 1e-9;

#define sz(x) (int) x.size()

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		b++;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> h(n + 1);
	rep(i, 0, n + 1) {
		cin >> h[i];
	}

	cout << fixed << setprecision(10);
	while (k--) {
		double q;
		cin >> q;
		int g = round(q * 10);

		vector<int> x(n + 1);
		rep(i, 0, n + 1) {
			x[i] = h[i] - i * g;
		}

		RMQ rmq(x);
		int z = 0;
		rep(i, 0, n + 1) {
			int l = 0, r = i - 1, j = i;
			while (l <= r) {
				int m = (l + r) / 2;
				if (rmq.query(0, m) <= x[i]) {
					j = m;
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
			z = max(z, i - j);
		}

		double res = z;
		rep(i, z + 1, n + 1) {
			int p = -z * g + h[i] - h[i - z];
			int q = h[i - z - 1] - h[i - z] + g;
			double a = ((double) p) / q;
			if (a >= 0 and abs(p) < abs(q)) {
				res = max(res, z + a);
			}
		}

		rep(i, 0, n - z) {
			int p = -z * g - h[i] + h[i + z];
			int q = h[i + z] - h[i + z + 1] + g;
			double a = ((double) p) / q;
			if (a >= 0 and abs(p) < abs(q)) {
				res = max(res, z + a);
			}
		}

		if (res == 0) {
			cout << "-1\n";
		}
		else {
			cout << res << endl;
		}
	}
}
