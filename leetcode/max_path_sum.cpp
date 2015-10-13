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
using namespace std;




typedef struct TreeNode{
	int val;
	TreeNode *lchild;
	TreeNode *rchild;
	TreeNode(int _val):val(_val),lchild(NULL),rchild(NULL){};
	
}TreeNode;

class Solution {
        public:
                bool if_debug;
				
        public:

                Solution(){
                        env_init();
                }
                void env_init(){
                        if_debug=false;
                }


				/*creat binary tree*/
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
						char lval=bnodes[bn_index++];
						if('#'!=lval){
							curNode_p->lchild=new TreeNode(lval-'0');
							p_st.push(curNode_p->lchild);
						}

						char rval=bnodes[bn_index++];
						if('#'!=rval){
							curNode_p->rchild=new TreeNode(rval-'0');
							p_st.push(curNode_p->rchild);
						}
					}

				}
	

				int subSum(TreeNode * root){
					if(NULL== root)
						return 0;
					if( NULL == root->lchild && NULL == root->rchild)
						return root->val;
					
					int lsum=subSum(root->lchild),
					rsum=subSum(root->rchild);
					int max_sum=lsum>rsum?lsum:rsum;
					
					//check if exist better path with lager path sum
					int temp_sum=lsum+rsum+root->val;
					if(temp_sum>max_sum)
						max_sum=temp_sum;

					return max_sum+root->val;
				}

				int maxPathSum(TreeNode* root) {
					max_sum=0;
					subSum(root);
					return max_sum;
				}
private:
	int max_sum;

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

                                TreeNode* temp_ptr=st.top();
                                st.pop();
                                int value=temp_ptr->val;
                                result.push_back(temp_ptr->val);
                                //cout<<"visiting:"<<temp_ptr->val<<endl;

                                cur_ptr=temp_ptr->right;

                                //cout<<"temp_ptr:"<<temp_ptr<<endl;

                        }

                        return result;
                }
				*/
};

//main entry
int main(void){
	ifstream cin("input");
	string line;
	while(getline(cin,line)){
		stringstream ss;
		vector<char> cs;
		char c;
		while(ss>>c){
			if(' '== c){
				cout<<"blank space"<<endl;
				continue;
			}
			cout<<c;
			cs.push_back(c);
		}

		TreeNode * root_p;
		Solution slt;
		slt.createBT(&root_p,cs);
		cout<<slt.maxPathSum(root_p)<<endl;

	}
	
	system("pasue");

}