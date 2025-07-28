#include<iostream>
#include<vector>
#include<string>
using namespace std;

long long generate(string s, int base) {
    long long ans = 0;
    long long mul = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        int val;
        if(s[i] >= '0' && s[i] <= '9') {
            val = s[i] - '0';
        } else {
            val = s[i] - 'a' + 10;
        }
        ans += val * mul;
        mul *= base;
    }
    return ans;
}

double solve(vector<pair<int, long long>> pt, int x) {
    double res = 0;
    int n = pt.size();
    for(int i = 0; i < n; i++) {
        double term = pt[i].second;
        for(int j = 0; j < n; j++) {
            if(i != j) {
                term = term * (x - pt[j].first) / (pt[i].first - pt[j].first);
            }
        }
        res += term;
    }
    return res;
}

int main() {
    vector<pair<int, long long>> test1;
    test1.push_back({1, generate("4", 10)});
    test1.push_back({2, generate("111", 2)});
    test1.push_back({3, generate("12", 10)});
    
    vector<pair<int, long long>> test2;
    test2.push_back({1, generate("13444211440455345511", 6)});
    test2.push_back({2, generate("aed7015a346d63", 15)});
    test2.push_back({3, generate("6aeeb69631c227c", 15)});
    test2.push_back({4, generate("e1b5e05623d881f", 16)});
    test2.push_back({5, generate("316034514573652620673", 8)});
    test2.push_back({6, generate("2122212201122002221120200210011020220200", 3)});
    test2.push_back({7, generate("20120221122211000100210021102001201112121", 3)});
    
    long long secret1 = solve(test1, 0);
    long long secret2 = solve(test2, 0);
    
    cout << "Secret 1: " << secret1 << endl;
    cout << "Secret 2: " << secret2 << endl;
    
    return 0;
}
