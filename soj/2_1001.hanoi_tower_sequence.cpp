#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <vector>

#define MAXSIZE 100

using namespace std;

	static bool first_flag=true;
// void hanoi(int n,int spos,int dpos){
// 	if(n==1){
// 		if(!first_flag)
// 			cout<<",";
// 		else
// 			first_flag=false;
// 		cout<<1;
// 		return ;
// 	}
// 
// 	hanoi(n-1,spos,6-spos-dpos);
// 	if(!first_flag)
// 		cout<<",";
// 	else 
// 		first_flag=false;
// 	cout<<n;
// 	hanoi(n-1,spos,dpos);
// }
//
typedef vector<int> BigInt_t;

BigInt_t SToBigint(string &s){	
	BigInt_t bt;
	int len=s.size();
	for(int i=0;i<len;++i){
		bt.push_back((int)(s[i]-'0'));
	}
	return bt;
}
bool Zero(BigInt_t bt){
	bool if_zero=true;
	int len=bt.size();
	for(int i=0;i<len;++i){
		if(bt[i]>0)
		{
			if_zero=false;
			break;
		}
	}
	return if_zero;
}
int Mode2(BigInt_t &bt){
	BigInt_t temp; 
	int mod=0;
	int len=bt.size();
	int i=0;
	int first_notzero=false;
	while(i<len){
		mod=mod*10+bt[i];
		int bit_res=mod/2;
		mod=mod%2;
		if(!first_notzero){
			if(bit_res!=0){
				temp.push_back(bit_res);
				first_notzero=true;
			}
		}
		else {
			temp.push_back(bit_res);			
		}
		i++;
	}
	bt.clear();
	BigInt_t::iterator iter=temp.begin();
	while(iter!=temp.end()){
		bt.push_back(*iter);
		iter++;
	}
	return mod;
}
int Nth(BigInt_t nth){
	int mod=0,count=0;
	while(!Zero(nth)){
		//mod 2
		int mod=Mode2(nth);
		if(mod==0)
			count++;
		else
			break;
			
	}
	return count+1;	
// 	if(nth<=0)
// 		return -1;
// 	double 	exp=log2(nth);
// // 	cout<<"exp:"<<exp<<endl;
// 	int iexp=(int)exp;
// 	if( exp-iexp==(double)0)
// 		return iexp+1;
// 
// 	Nth(nth-pow(2,iexp));
}

int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
	#define debug_info "/****read data from file input****/\n"
#else
	#define debug_info ""
#endif
	
	cout<<debug_info;
	int cases=-1;
	while(cin>>cases){
		for(int i=0;i<cases;++i){
			string nth;
			if(!(cin>>nth))
				break;
			BigInt_t  snth=SToBigint(nth);
			cout<<"Case "<<i+1<<": "<<Nth(snth)<<endl;
			if(i!=cases-1)
				cout<<endl;
		}
	}
	return 0;
}
