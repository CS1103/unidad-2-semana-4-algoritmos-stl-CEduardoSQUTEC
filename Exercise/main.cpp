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

static bool sort_using_greater_than(double u, double v) {
    return u < v;
}

void p482() {
    size_t n{};
    string str{};
    getline(cin, str);
    stringstream ss(str);
    ss >> n;

    for (size_t i = 0; i < n; ++i) {
        str = "";
        getline(cin, str);
        vector<size_t> vn;
        str = "";
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
            vd.push_back(evd);
        }
        std::sort(vd.begin(), vd.end(), sort_using_greater_than);
        for (const auto &e: vn)
            cout << vd[e - 1] << '\n';
    }
}

size_t nInversionSeq(string A, string B) {
    size_t a = 0;
    for (size_t i = 1; A[i] != 0; ++i) {
        a += ((A[i-1] > A[i])? A[i-1] - A[i]: 0);
    }
    size_t b = 0;
    for (size_t i = 1; B[i] != 0; ++i) {
        b += ((B[i-1] > B[i])? B[i-1] - B[i] : 0);
    }
    return a < b;
}

int main() {
    size_t M{}, n{}, m{};
    string in{};
    getline(cin, in);
    stringstream inss1(in);
    inss1 >> M;
    for (size_t i = 0; i < M; ++i) {
        in = "";
        getline(cin, in);

        in = "";
        getline(cin, in);
        stringstream inss2(in);
        inss2 >> n;
        inss2 >> m;

        vector<string> vstr;
        for (size_t j = 0; j < m; ++j) {
            in = "";
            cin >> in;
            vstr.push_back(in);
        }
        sort(vstr.begin(), vstr.end(), nInversionSeq);
        for (const auto &e: vstr)
            cout << e << '\n';
    }
    return 0;
}
