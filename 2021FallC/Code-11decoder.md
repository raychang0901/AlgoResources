# Final Project
### Steps:
1. given some widths->convert to binary(wide or narrow)
2. find pattern ~~ finish
3. check C&K with formula

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
void solve(int t);
int C(int *a,int n);
int K(int *a,int n);
int reverse(int* wid, int n);
void swap(int& a, int& b);
FILE* fptr;
int main(){
    if((fptr = fopen("code.txt", "r"))==NULL){
      puts("File could not be opened");
    }
    fscanf(fptr, "%d", &n);
    int t = 0;
    while(n!=0){
        solve(++t);
        fscanf(fptr, "%d", &n);
    }
}
void solve(int t){
    /*----------------------------------------------------
    transformation of width to binary
    -------------------------------------------------------*/
    double mxNar = -1, mnNar = INT_MAX, mxWid = -1, mnWid = INT_MAX;
    double first_nar, narC, widC;
    memset(wid, 0, sizeof(wid));
    for(int i = 0; i<n; ++i){
        fscanf(fptr, "%d", &wid[i]);
    }
    if((n+1)%6!=0){
      printf("Case %d: bad code\n", t);
      return;
    }
    first_nar = mxNar = mnNar = wid[0];
    wid[0] = 0;
    for(int i = 1; i<n; ++i){
      if(wid[i]>1.1*first_nar||wid[i]<0.9*first_nar){
        mxWid = max(int(mxWid), wid[i]);
        mnWid = min(int(mnWid), wid[i]);
        wid[i] = 1;
      }
      else{
        mxNar = max(int(mxNar), wid[i]);
        mnNar = min(int(mnNar), wid[i]);
        wid[i] = 0;
      }
    }
    //cout<< mxNar<<" "<<mnNar<<" "<<mxWid<<" "<<mnWid<<endl;
    narC = (mxNar+mnNar)/2;
    widC = (mxWid+mnWid)/2;
    // cout<< mxNar<<" "<<narC<<" "<<mnNar<<endl;
    // cout<< mxWid<<" "<<widC<<" "<<mnWid<<endl;
    if(mxNar>1.05*narC||mnNar<0.95*narC||mxWid>1.05*widC||mnWid<0.95*widC){
      printf("Case %d: bad code\n", t);
      return;
    }
    double mnGap = (2*0.95)/(1*1.05);
    if(mxWid/mnNar<mnGap){
      printf("Case %d: bad code\n", t);
      return;
    }
    // cout<< endl;
    // cout<< widC<<" "<<narC<<endl;
    // for(int i = 0; i<n; ++i){
    //     if(i%5==0){cout<< endl;}
    //     cout<< wid[i];
    // }

    /*----------------------------------------------------
    Check directions ->reverse(?
    -------------------------------------------------------*/
    int reverse_pattern[5]{0, 1, 1, 0, 0};
    bool isReverse = true;
    for(int i = 0; i<5; ++i){
      if(wid[i]!=reverse_pattern[i]){isReverse = false;break;}
    }
    if(isReverse){
      reverse(wid, n);
    }
    for(int i = 0; i<n; ++i){
        //if(i%6==0){cout<< endl;}
        //cout<< wid[i]<<" ";
    }
    //cout<< endl;
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
    int good = 1;
    int curr = 0;
    int currN = 0;
    int buf = 0;
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
    if(ans[0]!=11||ans[ansN-1]!=11){printf("Case %d: bad code\n", t);return;}
    for(int i = 0; i<ansN; ++i){
        //cout<< ans[i]<<" ";
        if(ans[i]==-1){
          printf("Case %d: bad code\n", t);
          return;
        }
    }
    int c = C(ans, ansN);
    int k = K(ans, ansN);
    if(c!=ans[ansN-3]){
      printf("Case %d: bad C\n", t);
      return;
    }
    if(k!=ans[ansN-2]){
      printf("Case %d: bad K\n", t);
      return;
    }

    printf("Case %d: ", t);
    for(int i = 1; i<ansN-3; ++i){
      if(ans[i]==10){
        printf("%s", "-");
      }
      else{
        printf("%d", ans[i]);
      }
    }
    printf("\n");
    return;
}

int C(int *a,int n){
    int sum=0;
    int N = n-3;
    for(int i=1;i<N;++i){
      sum+=((N-i-1)%10+1)*a[i];
    }
    return sum%11;
}
int K(int *a,int n){
    int sum=0;
    int N = n-2;
    for(int i=1;i<N;++i){
        sum+=((N-i-1)%9+1)*a[i];
    }
    return sum%11;
}
int reverse(int* wid, int n){
  for(int i = 0; i<n/2; ++i){
      swap(wid[i], wid[n-i-1]);
  }
}
void swap(int& a, int& b){
    int c = b;
    b = a;
    a = c;
    return;
}

```
