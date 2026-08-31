#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ld long double

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	ld dist() const { return sqrt((ld)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	ld angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(ld a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a))s.insert(a);
	if (onSegment(c, d, b))s.insert(b);
	if (onSegment(a, b, c))s.insert(c);
	if (onSegment(a, b, d))s.insert(d);
	return {all(s)};
}

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) {
	int cnt = 0, n = sz(p);
	rep(i,0,n) {
		P q = p[(i + 1) % n];
		if (onSegment(p[i], q, a)) return !strict;
		//or: if (segDist(p[i], q, a) <= eps) return !strict;
		cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
	}
	return cnt;
}

void solve() {
    int v;
    cin >> v;

    vector<Point<int>> a(v);
    rep(i, 0, v) {
        cin >> a[i].x >> a[i].y;
    }

    int k;
    cin >> k;
    vector<Point<int>> c(k);
    rep(i, 0, k) {
        cin >> c[i].x >> c[i].y;
    }
    
    Point<int> s, t;
    cin >> s.x >> s.y;
    cin >> t.x >> t.y;
    
    int n = v + k + 2;
    vector<Point<int>> b = a;
    b.insert(b.end(), all(c));
    b.push_back(s);
    b.push_back(t);

    vector<Point<int>> d = a;
    rep(i, 0, v) {
        d[i] = d[i] * 2;
    }

    vector<vector<ld>> graph(n, vector<ld>(n, 1e18));
    rep(i, 0, n) {
        graph[i][i] = 0;
    }
    rep(i, 0, n) {
        rep(j, 0, i) {
            if (!inPolygon(d, b[i] + b[j], false)) {
                continue;
            }
            bool flag = true;
            rep(k, 0, v) {
                vector<Point<int>> z = segInter(b[i], b[j], a[k], a[(k + 1) % v]);
                if (sz(z) == 1 and !(z[0] == b[i] or z[0] == b[j])) {
                    flag = false;
                    break;
                }
            }
            ld d = (b[i] - b[j]).dist();
            if (flag) {
                // cout << i << ' ' << j << ' ' << d << endl;
                graph[i][j] = d;
                graph[j][i] = d;
            }
        }
    }
    
    rep(k, 0, n) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    c.push_back(s);
    c.push_back(t);
    k += 2;

    vector<vector<ld>> dp(1 << k, vector<ld>(k, 1e18));
    dp[1 << (k - 2)][k - 2] = 0;
    rep(i, 0, 1 << k) {
        rep(p, 0, k) {
            if (!(i >> p & 1)) {
                continue;
            }
            rep(q, 0, k) {
                if (i >> q & 1) {
                    dp[i][p] = min(
                        dp[i][p],
                        dp[i ^ (1 << p)][q] + graph[q + v][p + v]
                    );
                }
            }
        }
    }

    cout << fixed << setprecision(15) << dp.back()[k - 1] << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
