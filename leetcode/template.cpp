#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int maxProfix(vector<int> &prices){
		if(prices.size()<2)
			return 2;
		int mina=prices[0];
		int maxp=0;
		for(int prc:prices){
			int prf=prc-mina;
			if(prf>maxp)
				maxp=prf;
			if(prc<mina)
				mina=prc;
		}
		return maxp;
	}
};


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void){
        char s[]="123456789";
        char d[]="123";
        cout<<"address of s:"<<(void*)s<<",address of d:"<<(void*)d<<endl;
        strcpy(d,s);
        printf("%s,\n%s",d,s);

}

