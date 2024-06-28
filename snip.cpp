#include "bits/stdc++.h"
using namespace std;

#define vi vector<int>
#define pb push_back


//=================================== Modular Arithmetic ===========================================================

const int MOD = 1e9+7;


int modexp(int x , int n){
  if(n==0) return 1%MOD;

  int u = modexp(x,n/2);
  u = (u*u)%MOD;
  if(n&1) u *= x;
  return u%MOD;
}

int modadd(int a,int b){ return ( ( (a%MOD) + (b%MOD) ) % MOD );}
int modsub(int a,int b){ return ( ( (a%MOD) - (b%MOD) + MOD ) % MOD );}
int modmul(int a,int b){return ( ( (a%MOD) * (b%MOD) ) % MOD );}
int moddiv(int a,int b){ return ( modmul(a , modexp(b,MOD-2 )));}
int modinv(int y){return modexp(y,MOD-2);}



//========================================== Combinatorics ============================================================

const int MAXN=100;
int c[MAXN+1][MAXN+1]; 

void buildComb(){
    
    for(int i = 1;i<=MAXN;i++){
        //nc0=1 and ncn=1
        c[i][0] = 1;
        c[i][i]=1;
    }

    for(int i = 1;i<=MAXN;i++){
        for(int j = 1;j<=min(MAXN,i);j++){
            if(i==j)continue;
            // nck = n-1 c k-1 + n-1 c k
            c[i][j]= modadd(c[i-1][j-1],c[i-1][j]);

        }
    }
}

// find factorial of numbers in o(n)
int fact [MAXN+1];
void buildFact(){
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=MAXN;i++){
        fact[i]= modmul(i,fact[i-1]);
    }
}

int comb(int n , int r ){
    if(r==0 or n-r==0) return 1;
    if(r==1 or n-r==1)return n;
    if( n < r ) return 0;

    // ncr = n! / (r! * n-r!)
    int u =  (modmul(fact[n],modinv(fact[n-r])));
    return (modmul(u,modinv(fact[r])));
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
    //idx is index in og array
    int v = idx+n;
    t[v]= new_val;
    v/=2;
    while(v>=1){
        t[v]=t[2*v]+t[2*v+1];
        v/=2;
    }

}

int calc(vector<int>&t,int n, int l , int r){
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

