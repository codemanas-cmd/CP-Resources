#include "bits/stdc++.h"
using namespace std;

#define vi vector<int>
#define pb push_back

//=================================== Binary Search ===========================================================
//for minimum value
int l = ; // l starts from f(l) = 0
int r = ; // r starts from f(r) = 1
while(l+1<r){
    int m = l+(r-l)/2;
    int val = m;
    if(check(val)) r = m;
    else l = m;
}
cout << r << nl;

//for maximum value
int l = ; // l starts from f(l) = 1
int r = ; // r starts from f(r) = 0
while(l+1<r){
    int m = l+(r-l)/2;
    int val = m;
    if(check(val)) l = m;
    else r = m;
}
cout << l << nl;
//=================================== Modular Arithmetic ===========================================================

const int MOD = 1e9+7;


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



//========================================== Combinatorics ============================================================


const int MXN = 2e5+2;
int fact[MXN];
void buildFact(){
    fact[0]=1;
    for(int i=1;i<=MXN;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
}

int choose(int n , int r,int p = MOD ){
    if (n < r)
        return 0;

    if (r == 0 or n==r)
        return 1;
        

    return (fact[n] * modinv(fact[r]) % p * modinv(fact[n - r]) % p) % p;
}


//================================================= Number-Theory =====================================================

bool isPrime(int n){
    for(int x=2;x*x<=n;x++){
        if(n%x==0) return false;
    }
    return true;
}
//check if the number is prime

//prime factorization
vi getFactors(int n){
    vi f;
    for(int x=2;x*x<=n;x++){
        while(n%x==0){
            f.pb(x);
            n /= x;
        }
    }
    if(n>1) f.pb(n);
    return f;
}
int sz = 1e6+5;
bool primeSieve[1000005];

//build sieve
void buildSieve(){
    primeSieve[0]=false;
    primeSieve[1]=false;//1 is neither prime nor composite

    for(int x=2;x*x<=sz;x++){
        if(!primeSieve[x])continue;
        else {
            for(int u=2*x;u<=sz;u+=x){
                primeSieve[u]=false;
            }
        }
    }

}

//find gcd

int GCD (int a,int b){
    if(b==0) return a;
    while(a%b!=0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}






// ==================================== Segment-Tree ===========================================================

vector<int> build(vector<int>&arr,int n){
    vector<int> t(2*n);
    for(int i =0;i<n;i++){
        t[n+i] = arr[i];
    }

    for(int i = n-1;i>=1;i--){
        t[i] = t[2*i]+t[2*i+1];
    }
    return t;
}

void update(vector<int>&t,int n, int idx,int new_val){
    //idx is 0 based index in original array
    int v = idx+n;
    t[v]= new_val;
    v/=2;
    while(v>=1){
        t[v]=t[2*v]+t[2*v+1];
        v/=2;
    }

}

int calc(vector<int>&t,int n, int l , int r){
    // l and r are 0 based indices in og array
    int vl = l+n;
    int vr = r+n;
    int sum = 0;
    while(vl<=vr){
        if((vl&1)) sum+=t[vl++];
        if(!(vr&1)) sum+=t[vr--];

        vl/=2; vr/= 2;
    }
    return sum;
}


//================================================= Binary_Lifting and LCA =====================================================

const int nmax = 2e5;
const int lgmax = 20;
int far[lgmax+1][nmax+1];
int depth[nmax+1];//needed only for finding lca
bool vis[nmax+1];

void dfs(vvi&adj, int u ){
    vis[u] = true;

    for(auto&v:adj[u]){
        if(!vis[v]){
            far[0][v]=u;
            depth[v]=depth[u]+1;//for lca
            dfs(adj,v);
        }
        
    }
}

void pre_process(){
    for(int h=1;h<=lgmax;h++)
        for(int x=1;x<=nmax;x++)
            far[h][x] = far[h-1][far[h-1][x]];
}

int LCA(int x , int y){
    if(depth[x]<depth[y])swap(x,y);
    int diff = depth[x]-depth[y];
    if(diff){
        for(int h = lgmax;h>=0;h--){
            if((1<<h)<=diff){
                x = far[h][x];
                diff-=(1<<h);
            }
        }
    }

    if(x==y)return x;

    for(int h = lgmax;h>=0;h--){
        if(far[h][x]!=far[h][y]){
            x = far[h][x];
            y = far[h][y];
        }
    }
    return far[0][x];
}