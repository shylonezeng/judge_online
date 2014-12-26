#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cmath>

#define MAXSIZE 1001
using namespace std;

typedef enum ChessType{
	Safe,Danger,Queen,Knight,Pawn
}ChessType;

class Chess{
	public:
	int row;
	int col;
	ChessType type;
	Chess(int r,int c,ChessType t):row(r),col(c),type(t){};

};

typedef struct ChsBoard_t{
	int rows;
	int cols;
	ChessType grid[MAXSIZE][MAXSIZE];
	vector<Chess> chs;
}ChsBoard;

/*task:move once
 *return false: whnen out of boundary or there is one chess 
 * */
bool Move(int *cur_row,int *cur_col,int row_move,int col_move, ChsBoard_t &chs_bd){
	*cur_row+=row_move;
	*cur_col+=col_move;
	if(*cur_row < 1 || *cur_row > chs_bd.rows)
		return false;
	if(*cur_col <1 || *cur_col >chs_bd.cols)
		return false;
	ChessType type=chs_bd.grid[*cur_row][*cur_col];
	if(type==Safe || type==Danger){
		chs_bd.grid[*cur_row][*cur_col]=Danger;	
		return true;
	}
	
	return false;
}
/*get number of safe squars*/
int getSafes(ChsBoard_t &chs_bd){
	int chs_num=chs_bd.chs.size();
	//chesses travel all possible grid space and mark it as unSafe
	for(int i=0;i<chs_num;++i){
		Chess chs=chs_bd.chs[i];
		switch(chs.type){
			case Queen:
				for(int row_move=-1;row_move<=1;row_move++)
					for(int col_move=-1;col_move<=1;++col_move){
						int cur_row=chs.row,cur_col=chs.col;
						while(Move(&cur_row,&cur_col,row_move,col_move,chs_bd));
					}
				break;
			case Knight:
				{
					for(int row_move=-2;row_move<=2;row_move++){
						if(row_move==0)
							continue;
						int col_steps=2;
						int row_steps=abs(row_move);
						if(row_steps==2)
							col_steps=1;	
						//move to left
						int cur_row=chs.row,cur_col=chs.col;
						Move(&cur_row,&cur_col,row_move,-col_steps,chs_bd);
						//move to right
						cur_row=chs.row,cur_col=chs.col;
						Move(&cur_row,&cur_col,row_move,col_steps,chs_bd);
					}
				}
				break;
		}
	}
	//take statistcis of safe squars
	int safe_num=0;
	for(int i=1;i<=chs_bd.rows;++i)
		for(int j=1;j<=chs_bd.cols;++j)
			if(chs_bd.grid[i][j]==Safe)
				safe_num++;
	return safe_num;
			
}
int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
#define debug_info "/****read data from file input****/\n"
#else
#define debug_info ""
#endif
	int bd_item=1;
	int rows,cols;
	while(cin>>rows>>cols){
		if(rows==0 && cols==0)
			return -1;
		int qnum,knum,pnum;
		/*init the chessboard*/
		ChsBoard csb;
		csb.rows=rows;
		csb.cols=cols;
		memset(csb.grid,Safe,sizeof(int)*MAXSIZE*MAXSIZE);

		cin>>qnum;
		for(int i=0;i<qnum;++i){
			int crow,ccol;
			cin>>crow>>ccol;
			csb.grid[crow][ccol]=Queen;			
			csb.chs.push_back(Chess(crow,ccol,Queen));
		}
		cin>>knum;
		for(int i=0;i<knum;++i){
			int crow,ccol;
			cin>>crow>>ccol;
			csb.grid[crow][ccol]=Knight;			
			csb.chs.push_back(Chess(crow,ccol,Knight));

		}
		cin>>pnum;
		for(int i=0;i<pnum;++i){
			int crow,ccol;
			cin>>crow>>ccol;
			csb.grid[crow][ccol]=Pawn;			
			csb.chs.push_back(Chess(crow,ccol,Pawn));
		}

		int num_safe_grid=getSafes(csb);		
		cout<<"Board "<<bd_item<<" has "<<num_safe_grid<<" safe squares."<<endl;
		
		bd_item++;
	}
	return 0;
}
