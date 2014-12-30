#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
#include <algorithm>

#define MAXSIZE 100

using namespace std;

class Process {
	public:
	int start_time;
	int stop_time;
	int remain_time;
	bool if_completed;
	int complete_time;
	Process(int  stime, int rtime){
		start_time=stime;
		stop_time=stime;
		remain_time=rtime;
		if_completed=false;
		complete_time=-1;

	}
};
bool MyCompare(Process a,Process b){
// 	cout<<"compare:"<<a.stop_time<<" "<<b.stop_time<<endl;
	return a.stop_time<b.stop_time;
}
int MinCost(std::list<Process> v){
	v.sort(MyCompare);

	int cost_time=0;
	while(!v.empty()){
		list<Process>::iterator iter=v.begin();
		int cur_time=iter->stop_time;
		
// 		int pre_stop_time;
		/*find shortest job and next different stop_time*/
		list<Process>::iterator shortest_prs=v.begin();
		int shortest_time=shortest_prs->remain_time;

		list<Process>::iterator next=iter;
		int next_time=cur_time;
		while(next!=v.end()){
			next_time=next->stop_time;
			if(next_time!=cur_time){
					break;
			}

			if(next->remain_time<shortest_time){
				shortest_prs=next;
				shortest_time=next->remain_time;
			}
			next++;	
		}
		/*delay all process which stop time is equal to cur_time*/
		int finished_time=cur_time+shortest_prs->remain_time;
		int new_time=finished_time;
		if(next_time!= cur_time)
		{//
		
			if(new_time>next_time)
				new_time=next_time;
		
		}
		next=iter;
		while(next!=v.end()){
			int stime=next->stop_time;
			if(stime==cur_time)
				next->stop_time=new_time;
			else
				break;
			next++;
		}
		/*end delay*/
		
		/*deal with current selected process*/
		if(next_time==cur_time ||  finished_time<=next_time){
			v.erase(shortest_prs);
			cost_time+=new_time;
#ifdef _mydebug
		cout<<"current time:"<<cur_time<<"\t finished time:"<<new_time<<"\t| new_time:"<<new_time<<endl;
#endif
		}
		else{
			shortest_prs->remain_time-=new_time-cur_time;
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
			int start_time,prs_time;
			cin>>start_time>>prs_time;
			prs.push_back(Process(start_time,prs_time));
		}

		int cost=MinCost(prs);
		cout<<cost<<endl;
	}
	return 0;
}
