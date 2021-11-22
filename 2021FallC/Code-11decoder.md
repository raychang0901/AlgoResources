# Final Project
### Steps:
1. given some widths->convert to binary(wide or narrow)  ~~finish
2. find pattern ~~ finish
3. check C&K with formula (TODO!!)

### Code:
((TODO: check C&K))
```cpp
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n = 0;
int wid[151];
int s[151];
double mnGap;


void swap(int& a, int& b){
    int c = b;
    b = a;
    a = c;
    return;
}
void solve(int t){

    /*----------------------------------------------------
    transformation of width to binary
    -------------------------------------------------------*/
    int mxNar = -1, mnWid = INT_MAX;
    memset(wid, 0, sizeof(wid));
    memset(s, 0, sizeof(s));
    for(int i = 0; i<n; ++i){
        scanf("%d", &wid[i]);
        s[i] = wid[i];
    }
    for(int i = 1; i<n; ++i){
        double big = max(wid[i], wid[i-1]);
        double small = min(wid[i], wid[i-1]);
        if(big-small>=(big+small)/2*0.05){
            if(big/small<mnGap){
                printf("Case %d: bad code", t);
                return;
            }
            mxNar = max(mxNar, int(small));
            mnWid = min(mnWid, int(big));
        }
    }
    //cout<< mxNar<<mnWid<<endl;
    for(int i = 0; i<n; ++i){
        if(wid[i]>=mnWid){
            wid[i] = 1;
        }
        else if(wid[i]<=mxNar){
            wid[i] = 0;
        }
    }
    // for(int i = 0; i<n; ++i){
    //     if(i%5==0){cout<< endl;}
    //     cout<< wid[i];
    // }

    /*----------------------------------------------------
    reverse(?
    -------------------------------------------------------*/
    for(int i = 0; i<n/2; ++i){
        swap(wid[i], wid[n-i-1]);
    }
    for(int i = 0; i<n; ++i){
        if(i%6==0){cout<< endl;}
        cout<< wid[i];
    }
    cout<< endl;
    /*----------------------------------------------------
    decode
    {16, 18, 3, 20, 24, 5, 9, 17, 1, 4, 6}
    -------------------------------------------------------*/
    int pattern[25];
    for(int i = 0; i<25; ++i){
        pattern[i] = -1;
    }
    pattern[16] = 0;
    pattern[18] = 1;
    pattern[3] = 2;
    pattern[20] = 3;
    pattern[12] = 4;
    pattern[24] = 5;
    pattern[5] = 6;
    pattern[9] = 7;
    pattern[17] = 8;
    pattern[1] = 9;
    pattern[4] = 10; //dash
    pattern[6] = 11; //stop start

    int curr = 0;
    int currN = 0;
    int buf = 0;
    int good = 1;
    int ans[31];
    int ansN = 0;
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i<n; ++i){
        if(buf){
            if(wid[i]==1){
                good = false;
                break;
            }
            else{
                buf = 0;
                continue;
            }
        }
        curr |= (wid[i]<<(4-currN++));
        if(currN==5){
            // cout<< pattern[curr]<<" "<<curr;
            // cout<< endl;
            ans[ansN++] = pattern[curr];
            curr = 0;
            currN = 0;
            buf = 1;
        }
    }

    for(int i = 0; i<ansN; ++i){
        cout<< ans[i]<<" ";
    }
    
    /*----------------------------------------------------
    TODO:calculate C K
    -------------------------------------------------------*/

}

int main(){
    mnGap = 1.9/1.05;
    scanf("%d", &n);
    int t = 0;
    while(n!=0){
        solve(++t);
        scanf("%d", &n);
    }
}

```
