#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>


#define MAXSIZE 100

using namespace std;


typedef struct Node{
	char data;
	int left;
	int right;
}Node_t;

vector<Node_t> t;
int pre_index;
/*create tree*/
int  getTree(string pre_order, string in_order, int in_begin,int in_end){
	if(pre_index>pre_order.size()-1)
		return -1;
	if(in_begin>=in_end)
		return -1;

	char root_data=pre_order[pre_index++];	//get data of position pre_index and pre_index plus one
	int fp=in_begin;
	while(fp<in_end){
		if(in_order[fp]==root_data)
			break;	
		fp++;
	}
	if(fp==in_end){
		cout<<"fp out of index"<<endl;
		return -2;
	}
	Node_t node;
	node.data=root_data;
	node.left=getTree(pre_order,in_order,in_begin,fp);
	node.right=getTree(pre_order,in_order,fp+1,in_end);
	
	t.push_back(node);
	return t.size()-1;
}

void BFS(vector<Node_t> &t,int theader){
	queue<Node_t> q;
	q.push(t[theader]);
	while(!q.empty()){
		Node_t &front =q.front();
		cout<<front.data;
		q.pop();
		
		if(front.left!=-1)
			q.push(t[front.left]);
		if(front.right!=-1)
			q.push(t[front.right]);
	}
	cout<<endl;
}

int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
	#define debug_info "/****read data from file input****/\n"
#else
	#define debug_info ""
#endif
	cout<<debug_info;
	
	int ins;
	while(cin>>ins){
		for(int i=0;i<ins;++i){
			string pre_order,in_order;
			cin>>pre_order>>in_order;
			//
			pre_index=0;
			int theader=getTree(pre_order,in_order,0,in_order.size());
			BFS(t,theader);
			t.clear();
		}	
	}
	return 0;
}
