#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void p146() {
    // Problem p146
    while (true) {
        string str;
        cin >> str;
        if (str == "#")
            break;
        if (next_permutation(begin(str), end(str)))
            cout << str << '\n';
        else
            cout << "No  Successor\n";
    }
}

size_t nSwapBubbleSort(vector<size_t> &v) {
    size_t ns{};
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                ns += 1;
            }
        }
    }
    return ns;
}

void p299() {
    size_t n;
    cin >> n;
    for (std::size_t i = 0; i < n; ++i) {
        size_t l{};
        cin >> l;
        vector<size_t> v;
        for (size_t j = 0; j < l; ++j) {
            size_t t;
            cin >> t;
            v.push_back(t);
        }
        cout << "Optimal train swapping takes " << nSwapBubbleSort(v) << " swaps.\n";
    }
}

bool greater_than(const double &a, const double &b) {
    return (a < b);
}

int main() {
    size_t n{};
    string str;
    getline(cin, str);
    stringstream ss(str);
    ss >> n;

    for (size_t i = 0; i < n; ++i) {
        vector<size_t> vn;
        string str{};
        getline(cin, str);
        stringstream iss(str);
        size_t evn;
        while (iss >> evn) {
            vn.push_back(evn);
        }

        vector<double> vd;
        str = "";
        getline(cin, str);
        stringstream jss(str);
        double evd;
        while (jss >> evd) {
            vd.push_back(evn);
        }
        sort(begin(vd), end(vd));
        for (const auto &e: vd) {
            cout << e << '\n';
        }
    }
    return 0;
}
