<<<<<<< HEAD
#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

bool flag = false;
int finP, finQ;
int n, m;
ll finScore = 1e12;
pair<int, int> x = {-1, 0};
pair<int, int> y = {1e6 + 1, 1e6};

ll cost(pair<int, int> x, pair<int, int> y) {
	return ((ll) abs(x.first - y.first)) * abs(x.first - y.first) + ((ll) abs(x.second - y.second)) * abs(x.second - y.second);
}

void solve(pair<int, int> a[], pair<int, int> b[]) {
	int p = 0, q = 1;
	ll score1 = cost(x, b[0]) + cost(y, a[1]);
	ll score2 = cost(x, b[1]) + cost(y, a[0]);
	
	ll currScore = score1;
	if (score2 < score1) {
		p = 1;
		q = 0;
		currScore = score2;
	}

	range(i, 2, m) {
		score1 = cost(x, b[i]) + cost(y, a[q]);
		score2 = cost(x, b[p]) + cost(y, a[i]);
		if (score1 < score2 && score1 < currScore) {
			p = i;
			currScore = score1;
		}
		else if (score2 < currScore) {
			q = i;
			currScore = score2;
		}
	}

	if (currScore < finScore) {
		if (finScore != 1e12) {
			flag = true;
		}
		finScore = currScore;
		finP = p;
		finQ = q;
	}
}

int main() {
	setup();
	input(n);
	input(m);

	range(i, 0, n) {
		int x, y; input(x); input(y);
	}

	pair<int, int> a[m], b[m];
	range(i, 0, m) {
		cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
		
		if (a[i].first > b[i].first) {
			swap(a[i], b[i]);
		}
	}

	solve(a, b);
	
	/*x = {0, -1};
	y = {1e6, 1e6 + 1};
	pair<int, int> c[m], d[m];
	range(i, 0, m) {
		c[i] = a[i];
		d[i] = b[i];
		if (c[i].second > d[i].second) {
			swap(c[i], d[i]);
		}
	}
	solve(c, d);*/

	print(finP);

	range(i, 0, m) {
		if (i == finP) {
			if (flag) {

			}
			else {
				print(-(b[i].first + 1) << " " << -b[i].second);
			}
		}
		else if (i == finQ) {
			if (flag) {

			}
			else {
				print((1e6 + 1 - a[i].first) << " " << (1e6 - a[i].second));
			}
		}
		else {
			print("0 0");
		}
	}
=======
#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

bool flag = false;
int finP, finQ;
int n, m;
ll finScore = 1e12;
pair<int, int> x = {-1, 0};
pair<int, int> y = {1e6 + 1, 1e6};

ll cost(pair<int, int> x, pair<int, int> y) {
	return ((ll) abs(x.first - y.first)) * abs(x.first - y.first) + ((ll) abs(x.second - y.second)) * abs(x.second - y.second);
}

void solve(pair<int, int> a[], pair<int, int> b[]) {
	int p = 0, q = 1;
	ll score1 = cost(x, b[0]) + cost(y, a[1]);
	ll score2 = cost(x, b[1]) + cost(y, a[0]);
	
	ll currScore = score1;
	if (score2 < score1) {
		p = 1;
		q = 0;
		currScore = score2;
	}

	range(i, 2, m) {
		score1 = cost(x, b[i]) + cost(y, a[q]);
		score2 = cost(x, b[p]) + cost(y, a[i]);
		if (score1 < score2 && score1 < currScore) {
			p = i;
			currScore = score1;
		}
		else if (score2 < currScore) {
			q = i;
			currScore = score2;
		}
	}

	if (currScore < finScore) {
		if (finScore != 1e12) {
			flag = true;
		}
		finScore = currScore;
		finP = p;
		finQ = q;
	}
}

int main() {
	setup();
	input(n);
	input(m);

	range(i, 0, n) {
		int x, y; input(x); input(y);
	}

	pair<int, int> a[m], b[m];
	range(i, 0, m) {
		cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
		
		if (a[i].first > b[i].first) {
			swap(a[i], b[i]);
		}
	}

	solve(a, b);
	
	/*x = {0, -1};
	y = {1e6, 1e6 + 1};
	pair<int, int> c[m], d[m];
	range(i, 0, m) {
		c[i] = a[i];
		d[i] = b[i];
		if (c[i].second > d[i].second) {
			swap(c[i], d[i]);
		}
	}
	solve(c, d);*/

	print(finP);

	range(i, 0, m) {
		if (i == finP) {
			if (flag) {

			}
			else {
				print(-(b[i].first + 1) << " " << -b[i].second);
			}
		}
		else if (i == finQ) {
			if (flag) {

			}
			else {
				print((1e6 + 1 - a[i].first) << " " << (1e6 - a[i].second));
			}
		}
		else {
			print("0 0");
		}
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}