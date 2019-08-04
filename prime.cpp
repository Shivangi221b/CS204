#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x;
    cin>>x;
    string arr[x];

    for (int j=0; j<x; j++){
        int flag=0;
        long long int n=0;
        cin >> n;

        long double sr = sqrt(n);

        for(int i=2; i<=sr; i++){
            if (n%i==0){
                arr[j]="Not a Prime";
                flag=1;
            }
        }

        if(flag==0){
            arr[j]="Prime";
        }

    }

    for (int j=0; j<x; j++){
        cout<<arr[j]<<"\n";
    }

    return 0;
}
