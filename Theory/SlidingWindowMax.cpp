<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    input(int, n);
    input(int, k);
    arrput(int, a, n);

    map<int, int, greater<int>> sortedMap;
    range(i, 0, k) {
        if (sortedMap.find(a[i]) == sortedMap.end()) {
            sortedMap.insert(make_pair(a[i], 1));
        }
        else {
            sortedMap.emplace(a[i], sortedMap.at(a[i]) + 1);
        }
    }
    printf("%d ", sortedMap.begin()->first);

    range(i, k, n) {
        if (sortedMap.at(a[i - k]) > 1) {
            sortedMap.emplace(a[i - k], sortedMap.at(a[i - k]) - 1);
        }
        else {
            sortedMap.erase(a[i - k]);
        }

        if (sortedMap.find(a[i]) == sortedMap.end()) {
            sortedMap.emplace(make_pair(a[i], 1));
        }
        else {
            sortedMap.emplace(a[i], sortedMap.at(a[i]) + 1);
        }
        printf("%d ", sortedMap.begin()->first);
    }
=======
#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    input(int, n);
    input(int, k);
    arrput(int, a, n);

    map<int, int, greater<int>> sortedMap;
    range(i, 0, k) {
        if (sortedMap.find(a[i]) == sortedMap.end()) {
            sortedMap.insert(make_pair(a[i], 1));
        }
        else {
            sortedMap.emplace(a[i], sortedMap.at(a[i]) + 1);
        }
    }
    printf("%d ", sortedMap.begin()->first);

    range(i, k, n) {
        if (sortedMap.at(a[i - k]) > 1) {
            sortedMap.emplace(a[i - k], sortedMap.at(a[i - k]) - 1);
        }
        else {
            sortedMap.erase(a[i - k]);
        }

        if (sortedMap.find(a[i]) == sortedMap.end()) {
            sortedMap.emplace(make_pair(a[i], 1));
        }
        else {
            sortedMap.emplace(a[i], sortedMap.at(a[i]) + 1);
        }
        printf("%d ", sortedMap.begin()->first);
    }
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}