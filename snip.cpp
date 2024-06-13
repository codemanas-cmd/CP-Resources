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
