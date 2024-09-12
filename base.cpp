#include "bits/stdc++.h"
using namespace std;

// ================================== Macros ======================================================
#define int long long int
#define uint unsigned long long
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>
#define vp vector<pair<int,int>>
#define pi pair<int,int>>
#define vpi vector<pair<int,int>>
#define PB push_back
#define F first
#define S second
#define el(a,v) for(auto& a : v)
#define fr(i,n) for(int i=0;i<n;i++)
#define rf(i,n) for(int i = (n)-1;i>=0;i++)
#define rep(i,a,n) for(int i=0;i<=(a);i++)
#define sz(v) = (int) v.size()
#define all(v) v.begin(),v.end()
#define rev(v) reverse(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define dbg(var) cout<<#var<<" = "<<var<<nl;
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())))
#define nl "\n"
#define ws " "


const int  MOD=1e9+7; 
const int INF = INT32_MAX;

int modexp(int x , int n){
    if(n==0) return 1%MOD;
    int u = modexp(x,n/2);
    u = (u*u)%MOD;
    if(n&1) u *= x;
    return u%MOD;
}

void modadd(int &a,int b){ a= ( ( (a%MOD) + (b%MOD) ) % MOD );}
void modsub(int &a,int b){ a = ( ( (a%MOD) - (b%MOD) + MOD ) % MOD );}
void modmul(int &a,int b){a = ( ( (a%MOD) * (b%MOD) ) % MOD );}
void moddiv(int &a,int b){ modmul(a , modexp(b,MOD-2 ));}
int modinv(int y){return modexp(y,MOD-2);}

void yes(){cout<<"YES"<<nl;}
void no(){cout<<"NO"<<nl;}

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================



void solve() {
    
}


int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
