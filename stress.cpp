#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...) 8
#endif
#define int long long
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
const int mod = 1e9+7;
const int inf  = 1e18;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<int> generateArray (int n, int l, int r) {
    uniform_int_distribution<long long> dist(l, r);
    vector<int>a(n);
    for(int i=0; i<n; i++)
        a[i] = dist(RNG);
    return a;
}
string generateStringLowercase(int n) {
    
    uniform_int_distribution<int> dist('a', 'z');

    string result;
    for (int i = 0; i < n; i++) {
        result += static_cast<char>(dist(RNG));
    }
    return result;
}

vector<string> generateGrid(int n, int m, char space, char block) {
    uniform_int_distribution<int> dist(0, 1); 

    vector<string> grid(n, string(m, space)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = (dist(RNG) ? block : space);
        }
    }
    return grid;
}

int brute (int n, vector<int> a) {
    
}

int mine (int n, vector<int> a) {
    
}

void run (int ITR) {
    while(ITR--){
        int n = 10;
        int l = 1;
        int r = 100;
        vector<int>a = generateArray(n,l, r);
        int correct = brute(n,a);
        int my = mine(n,a);
        if(correct != my){
            cout << "TESTCASE : \n";
            for(auto&x:a)cout << x << " ";
            cout <<endl;
            cout << "CORRECT : "<<correct <<endl;
            cout << "YOURS : " <<my <<endl;
            return;
        }
    }
    cout << "RAN SUCCESSFULLY" <<endl;
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    run(1000);
    
}