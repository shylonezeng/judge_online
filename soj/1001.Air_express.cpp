#include <iostream>
#include <fstream>
#include <limits>

#include <vector>

#define MAXSIZE 100

using namespace std;
int MAX_INT=std::numeric_limits<int>::max();
typedef pair<int,int> Item_t;

int BestPrice(vector<Item_t> &items,int cw){
	bool nearest=true;
	int 
		lweight_item=0,
		sum_cost=0,
	    add_weight=0;
	
	int lst_sum_cost=MAX_INT;
	int add_weight_best=0;
		
	vector<Item_t>::iterator iter=items.begin();
	while(iter!=items.end()){
		int item_maxw=iter->first;
		if( item_maxw>=cw){
			if(nearest)
			{	sum_cost=cw*(iter->second);
				nearest=false;
			}
			else{
				add_weight=lweight_item-cw;
				sum_cost=lweight_item*(iter->second);
			}

			if(sum_cost<lst_sum_cost){
				lst_sum_cost=sum_cost;
				add_weight_best=add_weight;
			}
			
		}
		lweight_item=item_maxw+1;
		iter++;
	}
	cout<<"Weight ("<<cw<<") has best price $"<<lst_sum_cost<<" (add "<<add_weight_best<<" pounds)"<<endl;
}

int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
	#define debug_info "read data from file input\n"
#else
	#define debug_info ""
#endif
	
	cout<<debug_info;
	int weight,cost;
	int item_num=1;

	while(cin>>weight>>cost){
		vector<Item_t> items;
		cout<<"Set number "<<item_num<<":"<<endl;
		items.push_back(Item_t(weight,cost));
		for(int i=0;i<2;++i){
			cin>>weight>>cost;
			items.push_back(Item_t(weight,cost));
		}
		cin>>cost;
		weight=1000;
		items.push_back(Item_t(weight,cost));
		
		/*begin customer's weight*/
		int cus_weight;
		while(cin>>cus_weight){
			if(cus_weight<=0)
				break;
			BestPrice(items,cus_weight);
		}
		cout<<endl;
		item_num++;
	}
	return 0;
}
