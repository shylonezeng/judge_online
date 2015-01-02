#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
#include  <vector>
#include <algorithm>
#include <limits>

#define MAXSIZE 100

long int INF=std::numeric_limits<long int>::max();

using namespace std;

class Process {
	public:
		long int start_time;
		long int stop_time;
		int remain_time;
		bool if_completed;
		long int complete_time;
		Process(long int  stime, int rtime){
			start_time=stime;
			stop_time=stime;
			remain_time=rtime;
			if_completed=false;
			complete_time=-1;

		}
};
bool MyCompare(Process a,Process b){
	// 	cout<<"compare:"<<a.stop_time<<" "<<b.stop_time<<endl;
	return a.remain_time>b.remain_time;
}
bool MyCompareByStime(Process a, Process b){
	return a.start_time<b.start_time;
}
template <class L>
void ShowQueue(L list){
	typename L::iterator iter=list.begin();
	while(iter!=list.end()){
		cout<<"start:"<<iter->start_time<<"\t remain:"<<iter->remain_time<<endl;
		iter++;
	}
}
long int MinCost(std::list<Process> v){

	if(v.empty())
		return 0;
	v.sort(MyCompareByStime);
	vector<Process> workv;
	make_heap(workv.begin(),workv.end(),MyCompare);

	long int cur_time=v.begin()->start_time;
	long int next_ready_time;
	long int cost_time=0;
	list<Process>::iterator front;	
	/*push first few ready processes to ready list*/
// 	front=v.begin();
// 	while(front!=v.end()){
// 		if(front->start_time>cur_time){
// 			next_ready_time=front->start_time;
// 			break;
// 		}
// 		workv.push_back(*front);
// 		push_heap(workv.begin(),workv.end(),MyCompare);
// 
// 		v.erase(front);
// 		front=v.begin();		
// 	}	// 	list<Process>::iterator =v.begin();

// #ifdef _mydebug
// 	cout<<"current time:"<<cur_time<<"\t next_time:"<<next_ready_time<<"\t work queue size:"<<workv.size()<<endl;
// #endif 
	while(!workv.empty() || !v.empty()){
		/*push ready processes in wait list to work ready list*/
		front=v.begin();
		while(front!=v.end()){
			if(front->start_time>cur_time){
				next_ready_time=front->start_time;
				break;
			}
			workv.push_back(*front);
			push_heap(workv.begin(),workv.end(),MyCompare);

			v.erase(front);
			front=v.begin();		
		}
		if(front==v.end())
			next_ready_time=INF;
#ifdef _mydebug
// 		cout<<"wait queue size:"<<v.size()<<"\t first start_time:"<<v.begin()->start_time<<endl;
#endif
#ifdef _mydebug
		cout<<"---------------------"<<endl;
		cout<<"- wait queue:"<<endl;
		ShowQueue<list<Process> >(v);
		
		cout<<"-work queue:"<<endl;
		ShowQueue<vector<Process> > (workv);
			cout<<"current time:"<<cur_time<<"\t next adding time:"<<next_ready_time<<"\t work queue size:"<<workv.size()<<endl;
#endif
		
		/*choose one process to process*/
		if(!workv.empty()){
			// 			Process *pwork=&workv.front();
			vector<Process>::iterator ppv=workv.begin();	
			if(cur_time+ppv->remain_time>next_ready_time){
				ppv->remain_time-=next_ready_time-cur_time;
				//go to next time state
				cur_time=next_ready_time;
			}
			else{
				cur_time=cur_time+ppv->remain_time;
				cost_time+=cur_time;/*one process finished*/
#ifdef _mydebug
				cout<<"+"<<cur_time<<"="<<cost_time<<endl;
#endif

				pop_heap(workv.begin(),workv.end(),MyCompare);
				workv.pop_back();
			}


		}
		else {
			cur_time=next_ready_time;
		}

	}
	return cost_time;
}

int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
#define debug_info "/****read data from file input****/\n"
#else
#define debug_info ""
#endif

	cout<<debug_info;
	int ps;
	while(cin>>ps){
		if(ps<=0)
			continue;
		list<Process> prs;
		for(int i=0;i<ps;++i)
		{
			long int start_time;
			int prs_time;
			cin>>start_time>>prs_time;
			prs.push_back(Process(start_time,prs_time));
		}

		long int cost=MinCost(prs);
		cout<<cost<<endl;
	}
	return 0;
}
