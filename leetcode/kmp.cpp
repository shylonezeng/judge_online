#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;


int  *getNext(string pattern);


const vector<int> kmp(string S,string P){
	int slen=S.length();
	int plen=P.length();
	vector<int> mv;
	//get next list
	int *next=getNext(P);

	int pi=0;
	for(int i=0;i<slen;++i){
		while(pi>0 && S[i]!=P[pi])
			pi=next[pi];
		if (S[i]==P[pi])
			pi++;
		if(pi==plen)
		{
			mv.push_back(i-plen+1);
			//cout<<i<<" ";
			pi=next[pi];   //匹配到后回到
		}

	}

	return mv;
}


/*compute prefix function*/
int  *getNext(string pattern){
	int plen=pattern.length();
	int *next=new int[plen+1];
	next[0]=next[1]=0;
	int pi=0;
	for(int i=1;i<plen;++i){
		while(pi>0 && pattern[i]!= pattern[pi])
			pi=next[pi];
		if(pattern[i]==pattern[pi])
			pi++;
		next[i+1]=pi;
	}
	return next;
}

int main(void){
	//for debug things
	ifstream cin("input");

	string t,p;
	while(cin>>t>>p){
		vector<int> posv=kmp(t,p);
		copy(posv.begin(),posv.end(),ostream_iterator<int>(cout," "));

		cout<<endl;
	}
	system("pause");
	
	return 0;
}
