#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long
#define vt vector
#define pb push_back
#define iipair pair<int, int>
#define llpair pair<ll, ll>
#define fir first
#define sec second
#define mp make_pair
#define endl '\n'

using namespace std;
unordered_map<ll, long double> logF;
int main() {
    ll v;
    logF[1] = 0;
    for(int i = 2; i<1e7; ++i){
        logF[i] = log2l(i)+logF[i-1];
    }
    cin>>v;
    ll x = pow(2, (v-1900)/10+2);
    ll L = 1, R = 1e7;
    while(L<=R){
        ll mid = (L+R)/2;
        //cout<< mid<<" ";
        if(logF[mid]<x){
            L = mid+1;
        }
        else{
            R = mid-1;
        }
    }
    cout<< R<<endl;
}
