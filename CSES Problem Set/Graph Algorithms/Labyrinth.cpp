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

int main() {
	setup();
	
	int n, m;
	input(n);
	input(m);

	//Take input and find start and end
	pair<int, int> s, e;
	bool safe[n][m];

	range(i, 0, n) {
		string str; input(str);
		range(j, 0, m) {
			safe[i][j] = (str[j] != '#');
			if (str[j] == 'A') {
				s.first = i;
				s.second = j;		
			}
			else if (str[j] == 'B') {
				e.first = i;
				e.second = j;
			}
		}
	}

	//BFS to find shortest path
	pair<int, int> prev[n][m];
	queue<pair<int, int>> q;
	q.push(s);
	safe[s.first][s.second] = false;
	bool flag = false;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		int i, j;
		tie(i, j) = p;

		if (i < 0 || i == n || j < 0 || j == m) {
			continue;
		}

		if (p == e) {
			flag = true;
			break;
		}

		if (i > 0 && safe[i - 1][j]) {
			safe[i - 1][j] = false;
			prev[i - 1][j] = p;
			q.push({i - 1, j});
		}
		if (i < (n - 1) && safe[i + 1][j]) {
			safe[i + 1][j] = false;
			prev[i + 1][j] = p;
			q.push({i + 1, j});
		}
		if (j > 0 && safe[i][j - 1]) {
			safe[i][j - 1] = false;
			prev[i][j - 1] = p;
			q.push({i, j - 1});
		}
		if (j < (m - 1) && safe[i][j + 1]) {
			safe[i][j + 1] = false;
			prev[i][j + 1] = p;
			q.push({i, j + 1});
		}
	}

	if (!flag) {
		print("NO");
		return 0;
	}

	print("YES");

	//Retreive the shortest path
	vector<pair<int, int>> path;
	do {
		path.push_back(e);
		e = prev[e.first][e.second];
	} while (e != s);

	print(path.size());
	reverse(path.begin(), path.end());
	
	string res;
	for (pair<int, int> p : path) {
		if (p.first < s.first) {
			res += 'U';
		}
		else if (p.first > s.first) {
			res += 'D';
		}
		else if (p.second < s.second) {
			res += 'L';
		}
		else {
			res += 'R';
		}
		s = p;
	}
 
	print(res);
}