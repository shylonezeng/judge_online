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


/*function main to debug*/
int main(int argc,char **argv){
	return 0;
}
