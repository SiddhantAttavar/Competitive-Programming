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

const int MAX = 1000;

bool query(int x, int y) {
	print("? " << x << " " << y);
	fflush(stdout);
	string s; input(s);
	return s[0] == 'Y';
}

int main() {
	setup();
	
	//First we need to find the length of the square
	//The bottom right corner is of the form {x, 0}
	int squareSide = 0;
	int low = 0;
	int high = MAX;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (query(mid, 0)) {
			squareSide = 2 * (mid - 1);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	//Now we know the length of the side of the square
	//Now we need to find the height of the triangle
	//We can find squareSide + triangleHeight
	//The highest point is of the form {0, y}
	int triangleHeight = 0;
	low = squareSide;
	high = MAX;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (query(0, mid)) {
			triangleHeight = mid - squareSide;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	//We now know the height of the triangle and the 
	//length of the side of the square
	//We need to find the length of the base of the triangle
	//The right end of the triangle is of the form {x, squareSide}
	int triangleBase = 0;
	low = 0;
	high = MAX;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (query(mid, squareSide)) {
			triangleBase = 2 * mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	//We now know the side of the square, the height of the 
	//triangle and the base of the triangle
	//The area of the square is sqaureSide * squareSide
	//The area of the triangle is 1 / 2 * triangleHeight * triangleBase
	int sqaureArea = squareSide * squareSide;
	int triangleArea = triangleHeight * triangleBase / 2;
	print("! " << sqaureArea + triangleArea);
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

const int MAX = 1000;

bool query(int x, int y) {
	print("? " << x << " " << y);
	fflush(stdout);
	string s; input(s);
	return s[0] == 'Y';
}

int main() {
	setup();
	
	//First we need to find the length of the square
	//The bottom right corner is of the form {x, 0}
	int squareSide = 0;
	int low = 0;
	int high = MAX;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (query(mid, 0)) {
			squareSide = 2 * (mid - 1);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	//Now we know the length of the side of the square
	//Now we need to find the height of the triangle
	//We can find squareSide + triangleHeight
	//The highest point is of the form {0, y}
	int triangleHeight = 0;
	low = squareSide;
	high = MAX;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (query(0, mid)) {
			triangleHeight = mid - squareSide;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	//We now know the height of the triangle and the 
	//length of the side of the square
	//We need to find the length of the base of the triangle
	//The right end of the triangle is of the form {x, squareSide}
	int triangleBase = 0;
	low = 0;
	high = MAX;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (query(mid, squareSide)) {
			triangleBase = 2 * mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	//We now know the side of the square, the height of the 
	//triangle and the base of the triangle
	//The area of the square is sqaureSide * squareSide
	//The area of the triangle is 1 / 2 * triangleHeight * triangleBase
	int sqaureArea = squareSide * squareSide;
	int triangleArea = triangleHeight * triangleBase / 2;
	print("! " << sqaureArea + triangleArea);
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}