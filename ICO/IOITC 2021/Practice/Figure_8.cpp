#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
#define int ll

struct Point {
	int x, y;
	bool operator<(const Point& b) const {
		if (x == b.x) {
			return y < b.y;
		}
		return x < b.x;
	}
};

Point mid;

int quadrant(Point p) {
	if (p.x >= 0 && p.y >= 0) {
		return 1;
	}
	if (p.x < 0 && p.y >= 0) {
		return 2;
	}
	if (p.x < 0 && p.y < 0) {
		return 3;
	}
	return 4;
}

int orientiation(Point a, Point b, Point c) {
	int res = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
	if (res == 0) {
		return 0;
	}
	if (res > 0) {
		return 1;
	}
	return -1;
}

bool compare(Point p, Point q) {
	Point x = {p.x - mid.x, p.y - mid.y};
	Point y = {q.x - mid.x, q.y - mid.y};

	int one = quadrant(x);
	int two = quadrant(y);

	if (one != two) {
		return one < two;
	}
	return (x.y * y.x < x.x * y.y);
}

vector<Point> merge(vector<Point> a, vector<Point> b) {
	int n = a.size(), m = b.size();

	int u = 0, v = 0;
	range(i, 1, n) {
		if (a[i].x < a[u].x) {
			u = i;
		}
	}
	range(i, 1, m) {
		if (b[i].x < b[v].x) {
			v = i;
		}
	}

	int indA = u, indB = v;
	bool done = false;
	while (!done) {
		done = true;
		while (orientiation(b[indB], a[indA], a[(indA + 1) % n]) >= 0) {
			indA = (indA + 1) % n;
		}
		while (orientiation(a[indA], b[indB], b[(indB - 1 + m) % m]) >= 0) {
			indB = (indB - 1 + m) % m;
			done = false;
		}
	}

	int upperA = indA, upperB = indB;
	indA = u, indB = v;
	done = false;
	int g = 0;
	while (!done) {
		done = true;
		while (orientiation(a[indA], b[indB], b[(indB + 1) % m]) >= 0) {
			indB = (indB + 1) % m;
		}
		while (orientiation(b[indB], a[indA], a[(indA - 1 + n) % n]) >= 0) {
			indA = (indA - 1 + n) % n;
			done = false;
		}
	}

	int lowerA = indA, lowerB = indB;
	vector<Point> res;
	
	int ind = upperA;
	res.push_back(a[upperA]);
	while (ind != lowerA) {
		ind = (ind + 1) % n;
		res.push_back(a[ind]);
	}

	ind = lowerB;
	res.push_back(b[lowerB]);
	while (ind != upperB) {
		ind = (ind + 1) % m;
		res.push_back(b[ind]);
	}

	return res;
}

vector<Point> bruteHull(vector<Point> a) {
	set<Point> s;
	range(i, 0, a.size()) {
		range(j, i + 1, a.size()) {
			int a1 = a[i].y - a[j].y;
			int b1 = a[j].x - a[i].x;
			int c1 = a[i].x * a[j].y - a[i].y * a[j].x;
			int pos = 0, neg = 0;
			range(k, 0, a.size()) {
				int x = a1 * a[k].x + b1 * a[k].y + c1;
				if (x <= 0) {
					neg++;
				}
				if (x >= 0) {
					pos++;
				}
			}
			if (pos == a.size() || neg == a.size()) {
				s.insert(a[i]);
				s.insert(a[j]);
			}
		}
	}

	vector<Point> res;
	for (Point p : s) {
		res.push_back(p);
	}

	mid = {0, 0};
	int n = res.size();
	range(i, 0, n) {
		mid.x += res[i].x;
		mid.y += res[i].y;
		res[i] = {res[i].x * n, res[i].y * n};
	}
	sort(res.begin(), res.end(), compare);
	range(i, 0, n) {
		res[i] = {res[i].x / n, res[i].y / n};
	}

	return res;
}

vector<Point> convexHull(vector<Point> a) {
	if (a.size() <= 5) {
		return bruteHull(a);
	}

	vector<Point> left, right;
	range(i, 0, a.size() / 2) {
		left.push_back(a[i]);
	}
	range(i, a.size() / 2, a.size()) {
		right.push_back(a[i]);
	}

	return merge(convexHull(left), convexHull(right));
}

bool isAbove(Point a, Point b, Point k) {
	if (a.x == b.x) {
		return k.x < a.x;
	}
	double slope = (1.0 * (b.y - a.y)) / (b.x - a.x);
	double c = a.y - slope * a.x;
	double lineY = k.x * slope + c;
	return k.y > lineY;
}

signed main() {
	setup(); int tc; input(tc); while (tc--) {
		int n; input(n);
		Point a[n];
		range(i, 0, n) {
			input(a[i].x, a[i].y);
		}

		int res = 0;
		range(i, 0, n) {
			range(j, i + 1, n) {
				int u = i, v = j;
				if (a[i].x > a[i].y) {
					swap(u, v);
				}

				vector<Point> above = {a[u], a[v]}, below = {a[u], a[v]};
				range(k, 0, n) {
					if (k == u || k == v) {
						continue;	
					}

					if (isAbove(a[u], a[v], a[k])) {
						above.push_back(a[k]);
					}
					else {
						below.push_back(a[k]);
					}
				}

				sort(above.begin(), above.end());
				sort(below.begin(), below.end());

				res = max(res, (int) (convexHull(above).size() + convexHull(below).size()) - 2);
			}
		}

		print(res);
	}
}