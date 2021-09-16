<<<<<<< HEAD
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
    unordered_map<int, char> hashMap;
    range(i, 10) {
        hashMap.insert(pair<int, char>(i, char(i + 65)));
    }

    println("Size: %d", hashMap.size());
    for (pair<int, char> iterator: hashMap) {
        println("%d: %c", iterator.first, iterator.second);
    }

    println("The value for 7: %c", hashMap.at(7));
=======
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
    unordered_map<int, char> hashMap;
    range(i, 10) {
        hashMap.insert(pair<int, char>(i, char(i + 65)));
    }

    println("Size: %d", hashMap.size());
    for (pair<int, char> iterator: hashMap) {
        println("%d: %c", iterator.first, iterator.second);
    }

    println("The value for 7: %c", hashMap.at(7));
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}