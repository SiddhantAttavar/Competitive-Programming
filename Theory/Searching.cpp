#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    input(int, n);
    input(int, k);
    arrput(int, a, n);

    //Linear Search
    bool flag = true;
    range(i, 0, n) {
        if (a[i] == k) {
            println("Linear Search: %d found at %d", k, i);
            flag = false;
            break;
        }
    }
    if (flag) {
        println("Linear Search: %d not found", k);
    }

    pair<int, int> x[n];
    range(i, 0, n) {
        x[i] = make_pair(a[i], i);
    }
    sort(x, x + n, compare);
    for (pair<int, int> )

    //Binary Search
    int low = 0;
    int high = len(a) - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x[mid].first == k) {
            println("Binary Search: %d found at %d", k, x[mid].second);
            break;
        }
        else if (x[mid].first > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if (low > high) {
        println("Binary Search: %d not found", k);
    }
}