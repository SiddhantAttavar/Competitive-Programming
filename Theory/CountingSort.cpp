<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

void countingSort(int a[], int n) {
	unordered_map<int, int> map;
	for (int i = 0; i < n; i++) {
		map[a[i]]++;
	}
	
	int x = 0;
	for (pair<int, int> i: map) {
		for (int j = 0; j < i.second; j++) {
			a[x] = i.first;
			x++;
		}
	}
}

int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	countingSort(a, n);
	for (int i: a) {
		cout << i << " ";
	}			
=======
#include <bits/stdc++.h>
using namespace std;

void countingSort(int a[], int n) {
	unordered_map<int, int> map;
	for (int i = 0; i < n; i++) {
		map[a[i]]++;
	}
	
	int x = 0;
	for (pair<int, int> i: map) {
		for (int j = 0; j < i.second; j++) {
			a[x] = i.first;
			x++;
		}
	}
}

int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	countingSort(a, n);
	for (int i: a) {
		cout << i << " ";
	}			
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}