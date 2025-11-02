#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define ld double
// #define double long double


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
    double dist() const { return sqrt((double)dist2()); }
    // angle to x=axis in interval [=pi , pi ]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes d i s t ()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated ’a ’ radians ccw around the origin
    P rotate(double a) const {
    return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")"; }
};

const ld eps = 1e-6;

template<class P> bool onSegment(P s, P e, P p) {
    return abs(p.cross(s, e)) < eps && (s - p).dot(e - p) <= eps;
}

bool check(Point<ld> a, Point<ld> b, Point<ld> c, ld lm, ld lg) {
    ld k = max(lm, 2 * lg) * max(lm, 2 * lg);
    if (onSegment(a, b, c) and (a - b).dist2() <= k) {
        return true;
    }

    Point<ld> d = a + (b - a) * (c - a).dot(b - a) / (b - a).dist2();

	lg = lg * lg;
	lm = lm * lm;
    ld x = max((d - a).dist2(), (d - b).dist2());
    ld y = (d - c).dist2();
    if (onSegment(a, b, d)) {
        return x <= lg and y <= lm;
    }
	if (lg > lm) swap(lg, lm);
	if (x > y) swap(x, y);
    return x <= lg and y <= lm;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc; cin >> tc; while (tc--) {
        ld lm, lg;
        cin >> lm >> lg;

		lg += eps;
		lm += eps;

        Point<ld> a, b, c;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;

		// cout << check(a, b, c, lm, lg) << check(a, c, b, lm, lg) << check(b, c, a, lm, lg);
        if (check(a, b, c, lm, lg) or check(a, c, b, lm, lg) or check(b, c, a, lm, lg)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
