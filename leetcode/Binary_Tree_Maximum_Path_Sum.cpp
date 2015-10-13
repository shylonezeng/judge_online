//head files
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <fstream>
#include <cassert>
using namespace std;



static bool global_debug=false;

typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int _val):val(_val),left(NULL),right(NULL){};
	
}TreeNode;

class Solution {

        public:

                Solution(){
                        env_init();
                }
                void env_init(){
					if_debug=false;
                }


				
				/*creat binary tree: 输入的节点权值只能是个位数的非负整数*/
				void createBT(TreeNode **pp_root, vector<char> bnodes ){
					int blen=bnodes.size();
					if(NULL==pp_root|| blen<=0)
						return;

					stack<TreeNode*> p_st;
					TreeNode *p;	
				
					int bn_index=0;
					char val=bnodes[bn_index++];
					*pp_root=new TreeNode(val-'0');
					

					TreeNode *curNode_p=*pp_root;
					p_st.push(curNode_p);
					while(!p_st.empty()){
						curNode_p=p_st.top();
						p_st.pop();

						if(bn_index>blen-1)
							break;
						char lval=bnodes[bn_index++];
						if('#'!=lval){
							curNode_p->left=new TreeNode(lval-'0');
							p_st.push(curNode_p->left);
						}

						if(bn_index>blen-1)
							break;
						char rval=bnodes[bn_index++];
						if('#'!=rval){
							curNode_p->right=new TreeNode(rval-'0');
							p_st.push(curNode_p->right);
						}
					}

				}
	

				int subSum(TreeNode * root){
					if(NULL== root)
						return 0;
					
					int lsum=subSum(root->left),
					rsum=subSum(root->right);
					int better_sum=lsum>rsum?lsum:rsum;
					
					//check if exist better path with lager path sum
					int temp_sum=lsum+rsum+root->val;
					if(temp_sum>max_sum)
						max_sum=temp_sum;
					if(if_debug)
						cout<<"cur max sum:"<<max_sum<<endl;
					
					//接连子树的路径
					int temp_path_sum=root->val;
					if(better_sum>0)
						temp_path_sum+=better_sum;
					if(temp_path_sum>max_sum)
						max_sum=temp_path_sum;
					return temp_path_sum;
				}

				int maxPathSum(TreeNode* root) {
					assert(root!=NULL);
					
					max_sum=root->val;
					subSum(root);
					return max_sum;
				}
private:
	int max_sum;
	bool if_debug;

			/*
                vector<int> inorderTraversal(TreeNode *root){
                        vector<int> result;
                        stack<TreeNode*> st;
                        TreeNode* cur_ptr=root;
                        while( !st.empty() || NULL != cur_ptr){
                                while( NULL!= cur_ptr){
                                        st.push(cur_ptr);
                                        cur_ptr=cur_ptr->left;
                                }
				TreeNode * temp_ptr = st.top();
				st.pop();
				int value = temp_ptr - > val;
				result.push_back(temp_ptr - > val);
				//cout<<"visiting:"<<temp_ptr->val<<endl;
				
				cur_ptr = temp_ptr - > right;
				
				//cout<<"temp_ptr:"<<temp_ptr<<endl;
				
				}
				
				return result;
				} */
};

//main entry
int main(void) {
	//fordebug
	ifstream cin("input");

	string line;
	while (getline(cin, line)) {
		if (global_debug)
			cout << line << endl;

		stringstream ss(line);
		vector < char > cs;
		char c;
		while (ss >> c) {
			if (' ' == c) {
				//cout<<"blank space"<<endl;
				continue;
			}
			cs.push_back(c);
		}

		TreeNode * root_p = NULL; //=new TreeNode;
		Solution slt;
		slt.createBT( & root_p, cs);
		cout << slt.maxPathSum(root_p) << endl;

		//deallocate resouce which is in storage of the tree

	}

	//fordebug
	system("pause");

}