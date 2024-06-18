#include "bits/stdc++.h"
using namespace std;

#define vi vector<int>
#define pb push_back


//===================== Number-Theory ========================================

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
