#include "abc.h"
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

const int MAX_LA = 100000;
const int MAX_LB = 100000;
const int MAX_L = 20000000;

void fatal(const string& msg) {
    cerr << msg << endl;
    exit(1);
}

void ensureImpl(bool condition, const char* conditionStr) {
    if (condition)
        return;
    fatal("Condition does not satisfy: " + string(conditionStr));
}

#define ensure(x...) ensureImpl(x, #x)

template <typename F>
void timed(const string& name, const F& func) {
    cerr << "Running " << name << "..." << endl;
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cerr << name << " took " << fixed << setprecision(6) << (double) duration.count() / 1e9 << " seconds" << endl;
}

int main() {
    freopen("abc.log", "w", stderr);
    // ==================== Read Input ====================
    int n, m;
    cin >> n >> m;
    ensure(0 <= n && n <= 700);
    ensure(0 <= m && m <= 1000);

    auto readUshort = [&]() {
        string s;
        cin >> s;
        stringstream ss(s);
        unsigned short x;
        ss >> x;
        if (s != to_string(x))
            fatal("Invalid input for unsigned short: " + s);
        return x;
    };
    vector<pair<string, unsigned short>> students;
    map<string, unsigned short> studentsMap;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (name.empty())
            fatal("Expected name");
        if (name.size() > 4)
            fatal("Name too long: " + name);
        bool ok = true;
        for (char c : name)
            if (c < 'a' || c > 'z')
                ok = false;
        if (!ok)
            fatal("Invalid name: " + name);
        unsigned short number = readUshort();
        students.emplace_back(name, number);

        if (studentsMap.count(name))
            fatal("Duplicate name: " + name);
        studentsMap[name] = number;
    }

    auto readExistingName = [&] {
        string name;
        cin >> name;
        if (!studentsMap.count(name))
            fatal("Unknown name in Bob's input: " + name);
        return name;
    };
    vector<pair<string, string>> messages;
    for (int i = 0; i < m; i++) {
        string sender = readExistingName();
        string recipient = readExistingName();
        messages.emplace_back(sender, recipient);
    }

    // ==================== Call Alice ====================
    char (*aliceNames)[5] = new char[n][5];
    memset(aliceNames[0], 0, n * 5);
    unsigned short* aliceNumbers = new unsigned short[n];
    bool* aliceOutputs = new bool[MAX_LA];
    memset(aliceOutputs, 0, MAX_LA);
    for (int i = 0; i < n; i++) {
        strcpy(aliceNames[i], students[i].first.c_str());
        aliceNumbers[i] = students[i].second;
    }
    int la;
    timed("Alice", [&]() {
        la = alice(n, aliceNames, aliceNumbers, aliceOutputs);
    });
    cerr << "la = " << la << endl;
    ensure(0 <= la && la <= MAX_LA);

    // ==================== Call Bob ====================
    char (*bobSenders)[5] = new char[m][5];
    memset(bobSenders[0], 0, m * 5);
    char (*bobRecipients)[5] = new char[m][5];
    memset(bobRecipients[0], 0, m * 5);
    bool* bobOutputs = new bool[MAX_LB];
    memset(bobOutputs, 0, MAX_LB);
    for (int i = 0; i < m; i++) {
        strcpy(bobSenders[i], messages[i].first.c_str());
        strcpy(bobRecipients[i], messages[i].second.c_str());
    }
    int lb;
    timed("Bob", [&]() {
        lb = bob(m, bobSenders, bobRecipients, bobOutputs);
    });
    cerr << "lb = " << lb << endl;
    ensure(0 <= lb && lb <= MAX_LB);

    // ==================== Call Circuit ====================
    int* circuitOperations = new int[MAX_L];
    memset(circuitOperations, 0xff, MAX_L * sizeof(int));
    int (*circuitOperands)[2] = new int[MAX_L][2];
    memset(circuitOperands[0], 0xff, MAX_L * 2 * sizeof(int));
    int (*circuitOutputs)[16] = new int[n][16];
    memset(circuitOutputs[0], 0xff, n * 16 * sizeof(int));
    int l;
    timed("Circuit", [&]() {
        l = circuit(la, lb, circuitOperations, circuitOperands, circuitOutputs);
    });
    cerr << "l = " << l << endl;
    ensure(0 <= l && l <= MAX_L);

    bool* values = new bool[l];
    memcpy(values, aliceOutputs, la * sizeof(bool));
    memcpy(values + la, bobOutputs, lb * sizeof(bool));
    for (int i = la + lb; i < l; i++) {
        int op = circuitOperations[i];
        if (op < 0 || op > 15)
            fatal("Invalid operation: " + to_string(op) + " at Circuit index " + to_string(i));
        int a = circuitOperands[i][0];
        int b = circuitOperands[i][1];
        if (a < 0 || a >= i)
            fatal("Invalid operand 0: " + to_string(a) + " at Circuit index " + to_string(i));
        if (b < 0 || b >= i)
            fatal("Invalid operand 1: " + to_string(b) + " at Circuit index " + to_string(i));
        bool x0 = values[a];
        bool x1 = values[b];
        values[i] = op >> (x0 + 2 * x1) & 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 16; j++)
            if (circuitOutputs[i][j] < 0 || circuitOutputs[i][j] >= l)
                fatal("Invalid output: " + to_string(circuitOutputs[i][j]) + " at Circuit index " + to_string(i) + ", " + to_string(j));
    vector<unsigned short> answers;
    for (int i = 0; i < n; i++) {
        unsigned short ans = 0;
        for (int j = 0; j < 16; j++)
            ans |= (unsigned short) values[circuitOutputs[i][j]] << j;
        answers.push_back(ans);
    }

    // ==================== Calculate Reference Answer ====================
    map<string, unsigned short> referenceMap;
    for (int i = 0; i < m; i++)
        referenceMap[messages[i].second] += studentsMap[messages[i].first];
    bool ok = true;
    for (int i = 0; i < n; i++)
        if (answers[i] != referenceMap[students[i].first]) {
            ok = false;
            cerr << "Wrong answer for " << students[i].first << ": expected " << referenceMap[students[i].first] << ", but got " << answers[i] << endl;
        }
    if (ok)
        cerr << "Your answer seems correct" << endl;

    // ==================== Print Answer ====================
    for (int i = 0; i < n; i++)
        cout << answers[i] << '\n';

    return 0;
}
