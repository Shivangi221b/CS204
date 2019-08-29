#include <bits/stdc++.h>
using namespace std;
#include<cmath>
#include <vector>

std::map<string, string> m;

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
    int l=s.length();
    for(int j=0; j<l; j++)
    {
        if(s[j]=='-' && isOperator(s[j-1])==1)
        {
            s.insert(j,"(");
            s.insert(j+3,")");
            l=l+2;
        }

    }
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

            if(s[i]=='-' && i!=0 && s[i-1]=='(')
            {

                pf+='?';
            }

        	else
            {
                if(s[i]=='^' && st.top()=='^')
                    st.push(s[i]);
                else
                {
                    while(st.top() != 'X' && prec(s[i]) <= prec(st.top()))
                    {
                        char c = st.top();
                        st.pop();
                        pf += c;
                    }

                    st.push(s[i]);
                }


            }
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
	int c=0;
	int o=0;

	for(int j=0; j< pf.length(); j++)
	{
		if(isOperator(pf[j])==0)
		{
			if(pf[j]=='?')
			{
				c++;
				o=j;
			}

			if(j==pf.length()-1)
			{
				string k="";
				if(c>0)
				{
				    k.push_back('-');
					for(int h=o+1; h<pf.length(); h++)
					{
						k.push_back(pf[h]);
					}
				}
				else
				{
					for(int h=0; h<pf.length(); h++)
					{
						k.push_back(pf[h]);
					}
				}
				t= newNode(k);
				return t;
			}
		}

		else
			break;
	}

	for(int i=0; i<pf.length(); i++)
	{

		if (pf[i]!=' ' && pf[i]!='+' && pf[i]!='-' && pf[i]!='*' && pf[i]!='/' && pf[i]!='^' && pf[i]!='?')
		{
            if(i!=0 && pf[i-1]=='?')
            {
                x=x+'-';
                x=x+pf[i];
            }

            else
            {
                x=x+pf[i];
            }

		}


		if(pf[i]==' ' || pf[i]=='+' || pf[i]=='-' || pf[i]=='*' || pf[i]=='/' || pf[i]=='^')
		{

			if(i==0 && pf[i]!=' ')
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

    if(s[0]!='-')
    {
        for (int i=0; i<s.length(); i++)
            num = num*10 + (int(s[i])-48);
    }

    else
    {
        for(int i=1; i<s.length(); i++)
            num= num*10+(int(s[i])-48);
        num = num*-1;
    }


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

int isExpression(string s)
{
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]=='=')
        {
            for(int j=i+1; j<s.length(); j++)
            {
                if((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z'))
                    return 0;
            }

            return 1;
        }
    }

    return -1;
}

string replacement(string str)
{
    string t="";
    for(int i=0; i<=str.length(); i++)
    {

        if (isOperator(str[i])==0 && i!=str.length())
        {
            t.push_back(str[i]);
            continue;
        }

        if((t[0]>='a' && t[0]<='z') || (t[0]>='A' && t[0]<='Z'))
        {
            int l= t.length();
            if(m.find(t) == m.end())
            {
            	//cout<< "CAN'T BE EVALUATED" << "\n";
            	return "CAN'T BE EVALUATED";
            }	

            else 
            	str.replace(i-l, l, m[t]);

            t="";
            i=i-l+1;
        }
    }
    return str;
}

int main(){
	int n, d;


	cin>>n;
	for(int i=0; i<n; i++)
    {
		cin>>d;
		for(int j=0; j<d; j++)
        {
            string str;
            cin>> str;
            if(isExpression(str)==1)
            {
                size_t q= str.find('=');
                string key= str.substr(0, q);
                string value= str.substr(q+1, str.length());
                m[key]=value;

            }

            else if (isExpression(str)==0)
            {

                size_t w= str.find('=');
                string key= str.substr(0, w);
                string s= str.substr(w+1,str.length());
                //m["xyz"]="2";
                string t= replacement(s);
                if (t=="CAN'T BE EVALUATED")
                {
                	cout<< "CAN'T BE EVALUATED" << "\n";
                	return 0;
                }	

                int val= evaluate(createTree(infixToPostfix(t)));
                string value= to_string(val);
                m[key]=value;

            }

            else if(isExpression(str)==-1)
            {
            	string t=replacement(str);
            	if (t=="CAN'T BE EVALUATED")
                {
                	cout<< "CAN'T BE EVALUATED" << "\n";
                	return 0;
                }
                cout<<evaluate(createTree(infixToPostfix(t)))<<"\n";
            }

		}
	}
	return 0;
}

