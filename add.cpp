#include<bits/stdc++.h>
using namespace std;

string add(string str1, string str2)
{
    string str = "";
    int carry = 0;

    int n1=str1.length();
    int n2=str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    if (n1>=n2){
        for (int i=0; i<n1; i++)
        {
            int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }

        for (int i=n1; i<n2; i++)
        {
            int sum = ((str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }

        if (carry)
            str.push_back(carry+'0');
    }

    if (n2> n1){
        for (int i=0; i<n2; i++)
        {
            int sum = ((str2[i]-'0')+(str1[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }

        for (int i=n2; i<n1; i++)
        {
            int sum = ((str1[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }

        if (carry)
            str.push_back(carry+'0');
    }

    reverse(str.begin(), str.end());

    return str;
}

int main()
{
    int n;
    cin>>n;
    string arr[n];

    for(int i=0; i<n; i++){
        string s1, s2;
        cin>>s1;
        cin>>s2;
        arr[i]= add(s1,s2);
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\n";
    }

    return 0;
}
