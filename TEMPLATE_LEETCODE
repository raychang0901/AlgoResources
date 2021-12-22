```cpp
#define ll long long
#define vt vector
#define pb push_back
#define iipair pair<int, int>
#define cipair pair<char, int>
#define icpair pair<int, char>
#define ispair pair<int, string>
#define sipair pair<string, int>
#define llpair pair<ll, ll>
#define MOD 1e9+7
#define iMat vector<vector<int>>
#define cMat vector<vector<char>>
#define mp make_pair

using namespace std;

//support functions

// cout<< vector<pair<T, T>>;
template<class T>
ostream& operator<<(ostream& os, vt<pair<T, T>> arr){
  for(auto& ele:arr)
    os<< "{"<<ele.first<<","<<ele.second<<"} ";
  os<<endl;
  return os;
}
// sum of 2 interger vector
vt<int> operator+(vt<int>v1, vt<int>v2){
  int m = v1.size(), n = v2.size();
  int mxSize = max(m, n);
  vt<int> ans(mxSize, 0);
  for(int i = 0; i<mxSize; ++i){
    if(i<m&&i<n){
      ans[i] = v1[i]+v2[i];
    }
    else if(i<m){
      ans[i] = v1[i];
    }
    else{
      ans[i] = v2[i];
    }
  }
  return ans;
}
// difference of 2 interger vector
vt<int> operator-(vt<int>v1, vt<int>v2){
  int m = v1.size(), n = v2.size();
  int mxSize = max(m, n);
  vt<int> ans(mxSize, 0);
  for(int i = 0; i<mxSize; ++i){
    if(i<m&&i<n){
      ans[i] = v1[i]-v2[i];
    }
    else if(i<m){
      ans[i] = v1[i];
    }
    else{
      ans[i] = -v2[i];
    }
  }
  return ans;
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
```
