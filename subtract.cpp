#include<bits/stdc++.h>
using namespace std;

int isBigger(string s1, string s2){
    int n1= s1.length();
    int n2=s2.length();

    if(n1=n2){
        for(int i=0; i<n1; i++){
            if(s1[i]>s2[i])
                return 0;
            else if(s2[i]>s1[i])
                return 1;
        }
    }

}

string sub(string s1, string s2){
	int n1=s1.length();
	int n2=s2.length();

	int diff=0;
	string str="";
	int carry=0;

	if(n1>n2 || isBigger(s1,s2)==0){

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

		for(int i=n2; i<n1;i++){
			s2.append("0");
		}

		for (int i=0; i<n1; i++){

			if(s1[i]>=s2[i]){
				diff=(s1[i]-'0')-(s2[i]-'0');
				str.push_back(diff+'0');
			}

			if(s1[i]<s2[i]){
				diff=(s1[i]-'0')-(s2[i]-'0')+10;
				if(s1[i+1]==0)
					s1[i+1]=9;
				else
					s1[i+1]= s1[i+1]-1;
				str.push_back(diff+'0');
			}
		}
	}

	if(n2>n1 || isBigger(s1,s2)==1){

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

		for(int i=n1; i<n2;i++){
			s1.append("0");
		}

		for (int i=0; i<n2; i++){

			if(s2[i]>=s1[i]){
				diff=(s2[i]-'0')-(s1[i]-'0');
				str.push_back(diff+'0');
			}

			if(s2[i]<s1[i]){
				diff=(s2[i]-'0')-(s1[i]-'0')+10;
				if(s2[i+1]==0)
					s2[i+1]=9;
				else
					s2[i+1]= s2[i+1]-1;
				str.push_back(diff+'0');
			}
		}
		str.append("-");
	}

    reverse(str.begin(), str.end());
	return str;
}

int main(){
    int n;
    string s1,s2;
    cin>>n;
    string arr[n];

    for(int i=0; i<n; i++){
        cin >> s1;
        cin >> s2;
        arr[i]=sub(s1,s2);
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\n";
    }


}
