#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution{
public:
	int maxProfit(vector<int> &prices){
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
#ifdef _mydebug
#define dinfo "read data specified file\n"
	ifstream cin("input");
#else
#define dinfo ""
#endif
	cout<<dinfo;
	
	vector<int> prices;
	int onev;
	while(cin>>onev)
		prices.push_back(onev);
	Solution slt;
// 	int maxp=slt.maxPorofit(prices);
	cout<<slt.maxProfit(prices)<<endl;
	return 0;
}
