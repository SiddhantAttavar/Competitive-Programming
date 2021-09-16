#include <bits/stdc++.h>
using namespace std;
#define print(x) printf("%d\n", x);
#define printd(x) printf("%f\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) (*(&a + 1) - a)

int main() {
    map<int, char> map;
    range(i, 10) {
        map.insert(pair<int, char>(i, char(i + 65)));
    }

    println("Map elements");
    for (pair<int, char> iterator: map) {
        println("%d: %c", iterator.first, iterator.second);
    }

    map.erase(5);
    map.erase(map.begin(), map.find(3));
    println("Updated map elements");
    for (pair<int, char> iterator: map) {
        println("%d: %c", iterator.first, iterator.second);
    }

    println("Key = 7: Value = %c", map.at(7));

    println("Size: %d", map.size());
    map.clear();
    println("Updated size: %d", map.size());
}