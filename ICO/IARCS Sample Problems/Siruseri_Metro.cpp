#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, m;
int colTrains[50];
int rowTrains[50];
char trains[3] = {'S', 'O', 'F'};
int a, b, c, d, e;

int main() {
	setup();

	//Input
	cin >> n >> m;
	range(i, 0, m) {
		input(char, c);
		colTrains[i] = find(trains, trains + 3, c) - trains;
	}
	range(i, 0, n) {
		input(char, c);
		rowTrains[i] = find(trains, trains + 3, c) - trains;
	}

	cin >> a >> b >> c >> d >> e;

	queue<pair<int, int>> q;
	q.push({a, b});
	
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();


	}
}