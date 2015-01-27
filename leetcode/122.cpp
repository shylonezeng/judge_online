#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution{
public:
	int maxProfit(vector<int> &prices){
		int psize=prices.size();
		if(psize<2)
			return 0;
		
		int prf=0;
		int prev=prices[0];
		
		for(int i=1;i<psize;++i){
			if(prices[i]>prev)
				prf+=prices[i]-prev;
			prev=prices[i];
		}
		return prf;
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
