#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int flag = 0;
    unordered_map <string, int> mmap;
    for(int i=0; i<n; i++){
        string input;
        cin >> input;
        string copy = input;
        reverse(input.begin(), input.end());
        if(copy != input){
            if(mmap.find(copy)==mmap.end()){
                mmap.insert({input, 1});
            }
            else{
                flag = 1;
            }  
        }
    }
    if(flag==1)
        cout<<"YES"<<endl;
    else       
        cout << "NO"<<endl;
    return 0;    
}