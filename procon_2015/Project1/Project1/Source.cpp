#include <iostream>
#include <fstream>
#include <vector>


//ピースを入れる構造体
struct flagstone{
	char block[8][8];
	int zk;
	int flag;
};
std::ifstream ifs("quest1.txt");
typedef std::vector<flagstone> stone;
void select(int);
int total();


//マップを読み込み空いているマスを見る
int total()
{
	int i,
		j,
		max=0;
	char map[46][46];

	
	


	for(i=7;i<39;i++)
	{
		for(j=7;j<39;j++)
		{
			ifs>>map[i][j];
			if(map[i][j]=='0')
				max++;
		}
	}
	

	return max;
	/*for(i=0;i<7;i++)
	{
		for(j=0;j<46;j++)
		{
			map[i][j]='1';
			map[i+39][j]='1';
		}
	}

	
	for(i=7;i<39;i++)
	{
		for(j=0;j<7;j++)
		{
			map[i][j]='1';
			map[i][j+39]='1';
		}
	}
*/
}


//ピースの取得
void select(int max)
{   
	int num,
		i,
		j,
		k,
		total;
	ifs>>num;
	stone piece(num);


	for(k=0;k<num;k++)
	{		
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			ifs>>piece[k].block[i][j];
			if(piece[k].block[i][j]=='1'){
				piece[k].zk++; 
				total++;
			}
			if(total==max)
			break;
			else if(total>max){
				total-=piece[k].zk;
			}

		}
	}


	
}
