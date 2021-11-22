## implement
```cpp
#include "bits/stdc++.h"
using namespace std;

class trie{
public:
    trie* next[26];
    trie(){
        for(auto& i:next){
            i = nullptr;
        }
    }
    bool isEnd = false;
};
void insert(string ss, trie* root){
    trie* curr = root;
    for(auto c:ss){
        if(curr->next[c-'a']){
            curr = curr->next[c-'a'];
        }
        else{
            trie* new_trie = new trie();
            curr->next[c-'a'] = new_trie;
            curr = curr->next[c-'a'];
        }
    }
    curr->isEnd = true;
}
void print_trie(string pre, trie* root){
    if(root->isEnd){
        cout<< pre<<endl;
    }
    for(int i = 0; i<26; ++i){
        if(root->next[i]){
            pre+=(i+'a');
            print_trie(pre, root->next[i]);
            pre.pop_back();
        }
    }
}
void find_prefix(string ss, trie* root){
    trie* curr = root;
    for(auto c:ss){
        if(curr->next[c-'a']){
            curr = curr->next[c-'a'];
        }
        else{
            cout<<"Nothing found"<<endl;
            return;
        }
    }
    print_trie(ss, curr);
}

int main(){
    trie* root = new trie();
    insert("hello", root);
    insert("heavy", root);
    insert("happy", root);
    insert("he", root);
    insert("height", root);
    insert("heaven", root);
    insert("healthy", root);
    find_prefix("hea", root);
    //print_trie("", root);
}

```
---------------------
#### Functions:
* insert: insert a word in trie
* find_prefix: find all words that have same prefix ss
