#include <bits/stdc++.h>
#include <cmath>
using namespace std;

string singleMultiply(string s1, int n){
    int l= s1.length();
     reverse(s1.begin(), s1.end());
     int carry=0;
     string str="";
     for(int i=0; i<l; i++){
        int m= ((s1[i]-'0')*n)+carry;
        int d= m%10;
        carry= m/10;
        str.push_back(d+'0');
     }
     reverse(str.begin(), str.end());
     return str;
}

string add(string s1, string s2){

    int n1= s1.length();
    int n2= s2.length();

    int carry=0;
    string sum="";

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    if(n2>=n1){
        for(int i=0; i<n1; i++){
            int s= (s1[i]-'0')+(s2[i]-'0')+carry;
            int d= s%10;
            carry= s/10;
            sum.push_back(d+'0');
        }

        for(int i=n1; i<n2; i++){
            int s= (s2[i]-'0')+carry;
            int d= s%10;
            carry= s/10;
            sum.push_back(d+'0');
        }

        if(carry!=0){
            sum.push_back(carry+'0');
        }
    }

    if(n1>n2){
        for(int i=0; i<n2; i++){
            int s= (s2[i]-'0')+(s1[i]-'0')+carry;
            int d= s%10;
            carry= s/10;
            sum.push_back(d+'0');
        }

        for(int i=n2; i<n1; i++){
            int s= (s1[i]-'0')+carry;
            int d= s%10;
            carry= s/10;
            sum.push_back(d+'0');
        }

        if(carry!=0){
            sum.push_back(carry+'0');
        }
    }

    reverse(sum.begin(), sum.end());
    return sum;
}

string multiply(string s1, string s2){

    reverse(s2.begin(), s2.end());

    int n1= s1.length();
    int n2= s2.length();
    int carry=0;
    string str1="", str2="", sum="";

    if(n2%2!=0)
        s2.append("0");

    for(int i=0; i<n2; i=i+2){
        int x= (s2[i]-'0');
        int y= (s2[i+1]-'0');
        str1= singleMultiply(s1,x);
        str2= singleMultiply(s1,y);

        for(int j=0; j<i; j++)
            str1.append("0");

        for(int k=0; k<=i; k++)
            str2.append("0");

        sum= add(sum, add(str1,str2));
    }

    return sum;
}
int main(){
    string s1, s2;
    int n;
    cin>>n;
    string arr[n];
    for(int i=0; i<n; i++){
        cin >> s1;
        cin >> s2;
        arr[i]= multiply(s1,s2);
    }
    for(int j=0; j<n; j++){
        cout<<arr[j]<<"\n";
    }
}
