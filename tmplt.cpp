#include "bits/stdc++.h"

#define ll long long
#define vt vector
#define pb push_back
#define iipair pair<int, int>
#define llpair pair<ll, ll>
#define fir first
#define sec second
#define mp make_pair

using namespace std;


ll pow(ll x, ll y, ll p) {
 if (y==0) return 1;
 if (y & 1) return (pow(x, y-1,p)*x)%p;
 // otherwise y is even
 ll t=pow(x, y/2, p);
 return (t*t)%p;
}

ll gcd(ll a, ll b){
    if(b==0){return a;}
    return gcd(b, a%b);
}
//support functions
//cout vt<vt<T>>
template<class T>
ostream& operator<<(ostream& os, vt<vt<T>> arr){
    for(auto& i:arr){
        for(auto& j:i){
            os<< j<<" ";
        }
        os<<"\n";
    }
    return os;
}
// cout<< vector<pair<T, T>>;
template<class T>
ostream& operator<<(ostream& os, vt<pair<T, T>> arr){
  for(auto& ele:arr)
    os<< "{"<<ele.first<<","<<ele.second<<"} ";
  os<<endl;
  return os;
}
//cout<< vector<T>;
template<class T>
ostream& operator<<(ostream& os,vector<T> arr){
  for(auto& ele:arr){
    os<< ele<<" ";
  }
  os<< endl;
  return os;
}

//cout<< map;
template<class T>
ostream& operator<<(ostream& os,unordered_map<T, int> mp){
  for(auto& ele:mp){
    os<< "{"<<ele.first<<" : "<<ele.second<<"} ";
  }
  os<< endl;
  return os;
}
//build feq map
template<class T>
unordered_map<T, int> count(vector<T> arr){
  unordered_map<T, int> feq;
  for(auto& ele:arr){
    if(!feq.count(ele)){
      feq[ele] = 1;
    }
    else{
      feq[ele]++;
    }
  }
  return feq;
}
//build prefix sum array
template<class T>
vector<T> PRE(vector<T> arr){
  int n = arr.size();
  vector<T> pre(n+1, 0);
  for(int i = 1; i<=n; ++i){
    pre[i] = pre[i-1]+arr[i-1];
  }
  return pre;
}

//solution
void solve(){
}
int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  //solve();

}
