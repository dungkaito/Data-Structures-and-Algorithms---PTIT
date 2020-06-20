#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define heso first
#define somu second

vector <ii> donThucs;

bool cmp(ii x, ii y) {
    return x.somu > y.somu;
}

int stringToNum(string s) {
    int tmp = 0, n = s.length();
    for (int i=0; i<n; i++)
        tmp = tmp * 10 + s[i] - '0';
    return tmp;
}

void merge(string s) {
    int n = s.length();
    string tmp;
    ii p;
    for (int i=0; i<n; i++) {
        if (isdigit(s[i]))
            tmp += s[i];
        if (s[i] == '*') {
            p.heso = stringToNum(tmp);
            tmp = "";
        }
        if (s[i] == '+' || i == n-1) {
            p.somu = stringToNum(tmp);
            tmp = "";
            donThucs.push_back(p);
        }
    }
}

int main() {
    int t; cin >> t; cin.ignore();
    string daThuc1, daThuc2;
    while (t--) {
        getline(cin, daThuc1);
        getline(cin, daThuc2);

        donThucs.clear();
        merge(daThuc1);
        merge(daThuc2);
        sort(donThucs.begin(), donThucs.end(), cmp);

        //output
        int n = donThucs.size();
        for (int i=0; i<n; i++) {
            if (donThucs[i].somu == donThucs[i+1].somu) {
                cout << donThucs[i].heso + donThucs[i+1].heso << "*x^" << donThucs[i].somu;
                i++;
            }
            else cout << donThucs[i].heso << "*x^" << donThucs[i].somu;
            if (i != n - 1) cout << " + ";
        }
        cout << endl;
    }
}