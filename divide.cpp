#include <bits/stdc++.h>
using namespace std;

int compare(string str, string s2){
    int n2= s2.length();
    int n3= str.length();

    if(n2>n3){
        reverse(str.begin(), str.end());
        for (int i=0; i<(n2-n3); i++){
            str.append("0");
        }
        reverse(str.begin(), str.end());
    }

    if(n3>n2){
        reverse(s2.begin(), s2.end());
        for (int i=0; i<(n3-n2); i++){
            s2.append("0");
        }
        reverse(s2.begin(), s2.end());
    }

    n2= s2.length();
    n3= str.length();


    for(int i=0; i<n2; i++){
        if(str[i]>s2[i]){
            return 0;
        }

        else if(str[i]< s2[i]){
            return 1;
        }

        else if (str[i]==s2[i] && i==n2-1)
            return 0;

        else
            continue;
        }

}

string subtract(string str, string s2){
    int n2= s2.length();
    int n3= str.length();

	int diff=0;
	string s="";

	reverse(s2.begin(), s2.end());
    reverse(str.begin(), str.end());

    for(int i=n2; i<n3;i++){
        s2.append("0");
    }

    for (int i=0; i<n3; i++){

        if(str[i]>=s2[i]){
            diff=(str[i]-'0')-(s2[i]-'0');
            s.push_back(diff+'0');
        }

        if(str[i]<s2[i]){
            diff=(str[i]-'0')-(s2[i]-'0')+10;
            if(str[i+1]==0)
                str[i+1]=9;
            else
                str[i+1]= str[i+1]-1;
            s.push_back(diff+'0');
        }
    }

    reverse(s.begin(), s.end());
	return s;
}

string quotient(string s1, string s2){
    string str="";
    string quo="";
    int n1= s1.length();
    int n2= s2.length();


    for(int i=0; i<n2; i++)
        str.push_back(s1[i]);

    if(compare(str,s2)==1)
        str.push_back(s1[n2]);

    int n3= str.length();
    int q=0;

    for(int j=n3; j<=n1; j++){

        q=0;

        while(compare(str,s2)==0)
        {
            str= subtract(str, s2);
            q++;
        }

        quo.push_back(q +'0');

        if (j!= n1)
            str.push_back(s1[j]);
    }

    return quo;
}

string rem(string s1, string s2){
    string str="";
    string quo="";
    int n1= s1.length();
    int n2= s2.length();


    for(int i=0; i<n2; i++)
        str.push_back(s1[i]);

    if(compare(str,s2)==1)
        str.push_back(s1[n2]);

    int n3= str.length();
    int q=0;

    for(int j=n3; j<=n1; j++){

        q=0;

        while(compare(str,s2)==0)
        {
            str= subtract(str, s2);
            q++;
        }

        quo.push_back(q +'0');

        if (j!= n1)
            str.push_back(s1[j]);
    }

    return str;
}

int main(){
    string s1, s2;
    int n;
    cin >> n;
    string arr[n][2];

    for (int j=0; j<n; j++){
        cin >> s1;
        cin >> s2;
        int n2= s2.length();
        int flag=0;

        for(int i=0; i<n2; i++){

            if(s2[i]!='0'){
                flag=1;
                break;
            }

            else if(s2[i]=='0' && i==n2-1)
            {
                cout<<"Can't divide by zero";
                return 0;
            }

            else
                continue;
        }

            arr[j][0]=quotient(s1, s2);
            arr[j][1]=rem(s1, s2);
    }

    for (int j=0; j<2*n; j++){
        cout<<arr[j][0]<<"\n"<<arr[j][1]<<"\n";

    }

    return 0;
}
