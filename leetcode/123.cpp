/*
 * status:wrong answer 
 * failed case:
 *
 * Input:	[1,2]
 * Output:	0
 * Expected:	1
 *
 * 
 * */
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;



class Solution{
	public:
		int maxProfit(vector<int> &prices){
			int psize=prices.size();
			if(psize<2)
				return 0;
			vector<int> l(psize);
			vector<int> r(psize);

			/*solve by DP*/	
			l[0]=0;
			r[psize-1]=0;

			int lminv=prices[0];
			int rmaxv=prices[psize-1];
			for(int j=1;j<psize;++j){
				//subfunction get best profit by once
				// [front,tail]

				//left part solution
				if(prices[j]<lminv){
					lminv=prices[j];
					l[j]=l[j-1];
				}
				else{
					int tprt=prices[j]-lminv;
					if(tprt<=l[j-1])
						l[j]=l[j-1];
					else
						l[j]=tprt;
				}
				//right part solution	
				int rfront=psize-1-j;	
				if(prices[rfront]>rmaxv){
					rmaxv=prices[rfront];
					r[rfront]=r[rfront+1];
				}
				else{
					int tprt=rmaxv-prices[rfront];
					if(tprt<=r[rfront])
						r[rfront]=r[rfront+1];
					else
						r[rfront]=tprt;
				}	
			}
			int bstprt=0;
			for(int i=0;i<psize;++i){
				bstprt=max(bstprt,l[i]+r[i+1]);
			}

			return bstprt;
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

	int count;
	while(cin>>count){
		vector<int> prices;
		int onev;
		for(int i=0;i<count;++i){
			cin>>onev;
			prices.push_back(onev);
		}
		Solution slt;
		// 	int maxp=slt.maxPorofit(prices);
		cout<<slt.maxProfit(prices)<<endl;
		cout<<"----------------------"<<endl;
	}
	return 0;
}
