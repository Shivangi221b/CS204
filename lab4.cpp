#include <bits/stdc++.h>
using namespace std;
#include<cmath>

int isOperator(char c){
	if(c=='+' || c=='*' || c=='/' || c=='^' || c=='-')
		return 1;
	else 
		return 0;
}

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 


string infixToPostfix(string s) 
{ 
    stack<char> st; 
    st.push('X'); 
    string pf=""; 
    for(int i = 0; i < s.length(); i++) 
    { 
         
        if(isOperator(s[i])==0 && s[i]!='(' && s[i]!=')') 
        pf+=s[i]; 
  
        
        else if(s[i] == '(') 
          st.push('('); 
          
        
        else if(s[i] == ')') 
        { 
            while(st.top() != 'X' && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
                pf += c; 
            } 

            if(st.top() == '(')  
                st.pop(); 
        } 
          
        
        else
        { 
        	pf+=' ';

            while(st.top() != 'X' && prec(s[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                pf += c; 
            } 
            st.push(s[i]); 
        } 
  
    } 
     
    while(st.top() != 'X') 
    { 
        char c = st.top(); 
        st.pop(); 
        pf += c; 
    } 
      
   return pf;
  
}



struct et 
{ 
    string value; 
    et* left, *right; 
};

et* newNode(string val) 
{ 
    et *new_Node = new et; 
    new_Node->left = NULL;
    new_Node->right = NULL; 
    new_Node->value = val; 
    return new_Node; 
};

et * createTree(string pf){
	stack<et *> st;
	et *t, *t1, *t2;
	string x="";

	for(int i=0; i<pf.length(); i++)
	{

		if (pf[i]!=' ' && pf[i]!='+' && pf[i]!='-' && pf[i]!='*' && pf[i]!='/' && pf[i]!='^')
		{
			x=x+pf[i];
			
		}

		if(pf[i]==' ' || pf[i]=='+' || pf[i]=='-' || pf[i]=='*' || pf[i]=='/' || pf[i]=='^' /*&& pf[i-1]!='+' && pf[i-1]!='-' && pf[i-1]!='*' && pf[i-1]!='/' && pf[i-1]!='^' && pf[i-1]!=' '*/)
		{
			if(i==0)
			{
				t=newNode(x); 
               
           		st.push(t);
           		x="";
           	}
           	else if(pf[i-1]!='+' && pf[i-1]!='-' && pf[i-1]!='*' && pf[i-1]!='/' && pf[i-1]!='^' && pf[i-1]!=' ')
           	{
           		t=newNode(x); 

           		st.push(t);
           		x="";
           	}
		}

		if(isOperator(pf[i])==1)
		{
			string k="";
			k.push_back(pf[i]);
			t= newNode(k);

			t1=st.top();
			st.pop();
			t->right=t1;

			t2=st.top();
			st.pop();
			t->left=t2;

			st.push(t);
		}

	}

	t=st.top();
	st.pop();

	return t;
}

int sToInt(string s){
	int num=0;

	for(int i=0; i<s.length(); i++)
		num= num*10+(int(s[i])-48);

return num;
	

}

int evaluate(et * root)
{
	if (root==NULL)  
        return 0;

    if(root->left==NULL && root->right==NULL)
    	return sToInt(root->value);

    int l = evaluate(root->left);
    int r = evaluate(root->right);

    if (root->value=="+")  
        return l+r;  
  
    if (root->value=="-")  
        return l-r;  
  
    if (root->value=="*")  
        return l*r;
    if (root->value=="/")  
        return (int)l/r;
    if (root->value=="^")
    	return (int)pow(l,r);
}

int main(){
	int n, d;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>d;
		for(int j=0; j<d; j++){
			string str;
			cin>> str;
			cout<<evaluate(createTree(infixToPostfix(str)));
		}
	}
	
	return 0;
}
