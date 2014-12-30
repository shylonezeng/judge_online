#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <stdlib.h>

#define MAXSIZE 100
#define INF 999999

using namespace std;

typedef pair<int,int> Item_t;
typedef vector<vector<Item_t> > AthBooks_t;

void GetAthBooks(AthBooks_t &athbooks,vector<Item_t> items);
typedef vector<Item_t>::iterator Iterator;
// bool MyCompare(Iterator a, Iterator b){
// 	return (a->first)>(b->second);
// }
float GetPerTime(Iterator iter){
	return (float)iter->first/(float)iter->second;
}
int MinCost(AthBooks_t &ath_books){
	int mcost=0;
	int cur_time=0;
	AthBooks_t::iterator iter_athbooks=ath_books.begin();
	vector<Iterator> p_iters;  
	vector<Iterator> end_iters;
	while(iter_athbooks!=ath_books.end()){
		p_iters.push_back(iter_athbooks->begin());
		end_iters.push_back(iter_athbooks->end());
		iter_athbooks++;
	}

	int end_flag=false;
	while(true){	
		end_flag=true;
		int len=p_iters.size();
		Iterator max_mi_book;
		float max_per_time=0;
		float next_max_per_time=0;
		int max_mi_index;
		/*get the most important book of header ones in each list */
		for(int i=0;i<len;++i){
			if(p_iters[i]==end_iters[i])
				continue;
			float per_time=GetPerTime(p_iters[i]);//(float)(p_iters[i]->first)/(float)(p_iters[i]->second);

			Iterator next_iter=p_iters[i]+1;
			float next_per_time=0;
			if(per_time==max_per_time){

				if(next_iter!=end_iters[i] && (next_per_time=GetPerTime(next_iter))>next_max_per_time ){
					next_max_per_time=next_per_time;

					max_mi_book=p_iters[i];
					max_mi_index=i;
					max_per_time=per_time;
				}
			}
			else if(per_time> max_per_time)
			{

				max_mi_book=p_iters[i];
				max_mi_index=i;
				max_per_time=per_time;

				if(next_iter!=end_iters[i])
					next_per_time=GetPerTime(next_iter);
				next_max_per_time=next_per_time;
			}
			end_flag=false;

		}
		/*calculate the cost of reading and add to sum*/
		if(end_flag)
			break;
		cur_time+=max_mi_book->second;
		mcost+=max_mi_book->first*cur_time;
#ifdef _mydebug
		cout<<"current reading book:"<<max_mi_book->first<<" "<<max_mi_book->second<<endl;
		cout<<"cost:+"<<max_mi_book->first<<"*"<<cur_time<<"=="<<max_mi_book->first*cur_time<<"->"<<mcost<<endl;
#endif

		p_iters[max_mi_index]++;	
	}
	return mcost;
}
int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
#define debug_info "/****read data from file input****/\n"
#else
#define debug_info ""
#endif

	cout<<debug_info;
	int cases;
	cin>>cases;
	for(int icase=0;icase<cases;++icase){
		vector<Item_t> books;
		int book_num;
		cin>>book_num;
#ifdef _mydebug
		cout<<book_num<<endl;
#endif
		/*log books*/
		for(int i=0;i<book_num;++i){
			int wi,ti;
			cin>>wi>>ti;
#ifdef _mydebug
			cout<<wi<<" "<<ti<<endl;
#endif
			books.push_back(make_pair(wi,ti));
		}
		vector<vector<Item_t> > ath_books; //each vector<Item_t> means books of one athhor
		/*allocate books to each researcher according to writor */
		int ath_num;
		cin>>ath_num;
		char bindex[MAXSIZE];
		for(int i=0;i<ath_num;++i)
		{
			vector<Item_t> one_ath_books;
			int one_ath_book_num;
			cin>>one_ath_book_num;
			for(int j=0;j<one_ath_book_num;j++){
				int index;
				cin>>index;
				one_ath_books.push_back(books[index-1]);
			}

			ath_books.push_back(one_ath_books);
		}		
		// 			Getath_books(ath_books,books);	

		int cost=MinCost(ath_books); 	
		cout<<cost<<endl;
	}		
	return 0;
}
void GetAthBooks(AthBooks_t &athbooks,vector<Item_t> items){
}
