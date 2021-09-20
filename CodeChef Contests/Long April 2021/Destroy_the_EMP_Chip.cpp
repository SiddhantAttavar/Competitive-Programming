#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
typedef long long ll;

string hellfire(ll x, ll y) {
	print(1, x, y);
	string s; input(s);
	return s;
}

string ringOfFire(ll x1, ll y1, ll x2, ll y2) {
	print(2, x1, y1, x2, y2);
	string s; input(s);
	return s;
}

void subTask0() {
	ll lowX = -1e18, highX = 1e18;
	ll lowY = -1e18, highY = 1e18;
	while (lowX <= highX && lowY <= highY) {
		ll midX = (lowX + highX) / 2;
		ll midY = (lowY + highY) / 2;
		
		string res = hellfire(midX, midY);
		if (res == "O") {
			break;
		}
		
		if (res[0] == 'X') {
			lowX = highX = midX;
		}
		else if (res[0] == 'P') {
			highX = midX - 1;
		}
		else {
			lowX = midX + 1;
		}

		if (res[1] == 'Y') {
			lowY = highY = midY;
		}
		else if (res[1] == 'P') {
			highY = midY - 1;
		}
		else {
			lowY = midY + 1;
		}
	}
}

void subTask1() {
	ll lowX = -1e18, highX = 1e18;
	ll lowY = -1e18, highY = 1e18;
	while (lowX <= highX && lowY <= highY) {
		if (highX - lowX <= 1 || highY - lowY <= 1) {
			ringOfFire(lowX, lowY, highX, highY);
			break;
		}

		if (highX - lowX == 2 && highY - lowY == 2) {
			if (ringOfFire(lowX, lowY, highX, highY) != "O") {
				ringOfFire(lowX, lowY, highX, highY);
			}
			break;
		}

		if (highX - lowX == 3) {
			string res = ringOfFire(lowX, lowY, highX - 1, highY);
			if (res == "O") {
				break;
			}
			if (res == "IN") {
				highX--;
			}
			else {
				lowX += 2;
				highX++;
			}
			continue;
		}
		if (highY - lowY == 3) {
			string res = ringOfFire(lowX, lowY, highX, highY - 1);
			if (res == "O") {
				break;
			}
			if (res == "IN") {
				highY--;
			}
			else {
				lowY += 2;
				highY++;
			}
			continue;
		}

		ll midX = (lowX + highX) / 2;
		ll midY = (lowY + highY) / 2;
		
		string res = hellfire(midX, midY);
		if (res == "O") {
			break;
		}
		
		if (res[0] == 'X') {
			lowX = highX = midX;
		}
		else if (res[0] == 'P') {
			highX = midX - 1;
		}
		else {
			lowX = midX + 1;
		}

		if (res[1] == 'Y') {
			lowY = highY = midY;
		}
		else if (res[1] == 'P') {
			highY = midY - 1;
		}
		else {
			lowY = midY + 1;
		}

		lowX--;
		lowY--;
		highX++;
		highY++;
	}
}

int main() {
	int tc, q, d; input(tc, q, d); while (tc--) {
		if (d == 0) {
			subTask0();
		}
		else {
			subTask1();
		}
	}
}