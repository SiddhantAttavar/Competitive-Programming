#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i, a, b) for (int i = a; i < b; i++)
const double pi = 3.14159265358979323846;
const double tau = 2 * pi, eps = 1e-9;

double get(double x) {
    if (abs(x) < eps) {
        return 0;
    }
    while (x < 0) {
        x += tau;
    }
    while (x >= tau) {
        x -= tau;
    }
    return x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    double x0, y0, d, t;
    cin >> n >> x0 >> y0 >> d >> t;

    double a = atan2(y0, x0);
    vector<double> v;
    rep(i, 0, n) {
        double x, y;
        cin >> x >> y;

        double f = atan2(y, x), g = asin(d / sqrt(x * x + y * y));
        v.push_back(get(f + g - a));
        v.push_back(get(f - g - a));
    }

    sort(v.begin(), v.end());
    v.push_back(v[0]);
    double l = -1, r = -1;
    rep(i, 0, 2 * n) {
        if (get(v[i + 1] - v[i]) > pi) {
            l = v[i + 1];
            r = v[i];
            break;
        }
    }

    double res = floor(t / tau) * get(r - l);
    t = get(t);
    if (l < r) {
        res += max(0.0L, min(r, t) - l);
    }
    else {
        res += min(r, t) + max(0.0L, t - l);
    }
    cout << fixed << setprecision(12) << res << endl;
}
