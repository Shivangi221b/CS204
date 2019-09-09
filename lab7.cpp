#include <bits/stdc++.h>
using namespace std; 

int Compare(string a, string b) 
{ 
    string ab = a.append(b);  
    string ba = b.append(a);    
    return ab.compare(ba) > 0 ? 1: 0; 
} 

void swap(string* x, string* y) 
{ 
    string t = *x; 
    *x = *y; 
    *y = t; 
} 

long long int part(string arr[], long long int start, long long int end) 
{ 
    string pivot = arr[end];    
    long long int i = start-1; 
  
    for (long long int j=start; j<=end-1; j++) 
    { 
        if (Compare(arr[j], pivot)) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i+1], &arr[end]); 
    return (i+1); 
} 
  
void qSort(string arr[], long long int start, long long int end) 
{ 
    if (start < end) 
    { 
        long long int p = part(arr, start, end); 
  
        qSort(arr, start, p-1); 
        qSort(arr, p+1, end); 
    } 
}

void print(string arr[], long long int size) 
{ 
    for (long long int k=0; k < size; k++) 
    	cout<<arr[k];
} 

int main() 
{ 
    long long int c;    
    cin>> c; // no of test Cases
    for(long long int i=0; i<c; i++)
    {
    	long long int t;
    	cin>>t; // 
    	string arr[t];
    	for(long long int j=0; j<t; j++)
    	{
    		string d;
    		cin>>d;
    		arr[j]=d;
    	}
    	qSort(arr, 0, t-1);
    	print(arr, t);
    	cout<<"\n";
    }
    return 0; 
} 