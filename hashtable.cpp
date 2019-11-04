#include <bits/stdc++.h>
using namespace std;
/*IMPLEMENTATION OF HASH TABLE
TO FIND THE FREQUENCY OF EACH CHARACTER IN A GIVEN STRING*/

int frequency[26];
int hashfunc(char key){
	return(key-'a');
}

void countFreq(string s){
	for(int i=0; i<s.length(); i++){
		int index= hashfunc(s[i]);
		frequency[index]++;
	}

	for(int i=0; i<26; i++)
		if(frequency[i]!=0)
        	cout<<(char)(i+'a')<<' '<<frequency[i]<<endl;
}

int main(){
	string s="abgkahihcnhccmiiicoihg";
	countFreq(s);
}
