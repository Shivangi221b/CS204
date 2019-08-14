#include<bits/stdc++.h>
using namespace std;

int checkBalanced(string str){
	stack<char> s;
	int l= str.length();
	char c;

	for(int i=0; i<l; i++){

		if (str[i]=='(' || str[i]=='{' || str[i]=='[' || str[i]=='<'){
			s.push(str[i]);
			continue;
		}

		if(str[i]=='|'){
			if (s.empty()){
				s.push(str[i]);
				continue;
			}

			else if (s.top()=='(' || s.top()=='{' || s.top()=='[' || s.top()=='<'){
				s.push(str[i]);
				continue;
			}
		}

		if (s.empty()) 
           return 0; 

		switch(str[i]){
			case ')':
				c=s.top();
				if(c=='('){
					s.pop();
					break;
				}
				else 
					return 0;

			case '}':
				c=s.top();
				if(c=='{'){
					s.pop();
					break;
				}
				else 
					return 0;
				break;

			case ']':
				c=s.top();
				if(c=='['){
					s.pop();
					break;
				}
				else 
					return 0;
				break;

			case '>':
				c=s.top();
				if(c=='<'){
					s.pop();
					break;
				}
				else 
					return 0;
				break;

			case '|':
				c=s.top();
				if(c=='|'){
					s.pop();
					break;
				}
				else 
					return 0;
				break;
		}
	}

	return (s.empty());
}

int main(){
	int n;
	string str;
	cin >> n;
	for (int i=0; i<n; i++){
		cin>>str;
		if (checkBalanced(str)==1)
			cout<<"YES";
		else 
			cout<<"NO";
	}
	return 0;
}
