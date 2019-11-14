#include<bits/stdc++.h>
using namespace std;
#define lli long long
lli n;


lli hashfunc(string s)
{
    lli r=0;
    for(int i=0;i<s.length();i++)
    {
        r=(r+s[i]*(i+1))%n;
    }
    return r;
}

class hashtable{

    public:

    void insert(string x)
    {
        this->a[hashfunc(x)].push_front(x);
    }

    int search(string x)
    {
        int index = hashfunc(x); 
        list <string> :: iterator i; 
        for (i = a[index].begin(); i != a[index].end(); i++) { 
        	if (*i == x) 
        	{	
            	return 1;
        	}
        }
        return 0;
    }

    void deletehash(string x)
    {
        int index = hashfunc(x); 
        list <string> :: iterator i; 
        for (i = a[index].begin(); i != a[index].end(); i++) { 
        if (*i == x) 
        {
            a[index].erase(i);
            cout<<"Deleted "<<x<<endl;
            return;
        }
        }
        cout<<x<<" not found"<<endl;
    }

    hashtable(lli m)
    { 
        
        a = new list<string>[m];
    }
    
    private:
		list<string> *a;
};

int main()
{
    string s,str;
    cin>>n;
    short flag=0;
    hashtable Hash(n);
    for(lli i=0;i<n;i++)
    {
        cin>>s;
        str=s;
        reverse(str.begin(), str.end()); 
        if(Hash.search(str)&&s!=str)
        	flag=1;
        Hash.insert(s);
    }

    if(flag)
    	cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    	return 0;
}