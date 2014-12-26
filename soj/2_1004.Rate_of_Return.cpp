#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cmath>

#define MAXSIZE 100

using namespace std;

typedef vector<pair<int,double> > Items_t;
/*get total value at the rate of insterast p_rate*/
double Value(Items_t items,pair<int,double> last_item,double p_rate){
	Items_t::iterator iter=items.begin();
	double sum_value=0;
	while(iter!=items.end()){
		double part_value=iter->second;
		int rmonths=last_item.first-iter->first+1;
		for(int i=0;i<rmonths;++i)
			part_value*=1+p_rate;	

		sum_value+=part_value;
		iter++;
	}
	return sum_value;	
}
int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
	#define debug_info "/****read data from file input****/\n"
#else
	#define debug_info ""
#endif
	
	cout<<debug_info;
	int invst_num;
// 	bool if_fcase=true;
	int icase=1;
	while(cin>>invst_num){
		if(invst_num==-1)	
			return -1;
		Items_t items;
		for(int i=0;i<invst_num;++i){
			int month; double invst;
			cin>>month>>invst;
			items.push_back(make_pair(month,invst));	
		}
		int lmonth; double value;
		cin>>lmonth>>value;
		pair<int,double> last_item(lmonth,value);
			
		/*get interest rate*/
		double base=0.1;
		int pricision=5;
		double rate=0;
		for(int i=0;i<pricision+1;++i){
			
			int base_num=1;
			double p_rate=rate+base;
			while(base_num<10 && Value(items,last_item,p_rate)<=last_item.second){
				base_num++;
				p_rate+=base;
			}

			rate+=base*(base_num-1);	
// 			cout<<"rate:"<<rate<<endl;
			base*=0.1;
		}
		/*round result value to nearest pricision value*/
// 		double new_rate=( (int)(rate*pow(10,pricision)) )*pow(10,-pricision);
// 		cout<<"new_rate:"<<new_rate<<endl;
// 		double carry_mid=pow(10,-pricision-1)*5;
// 		if(rate-new_rate>carry_mid)
// 			rate+=pow(10,-pricision);
	
		if(icase!=1)
			cout<<endl;
		printf("Case %d: %.5lf\n",icase++,rate);
	}

	return 0;
}
