#include <stdio.h>  
#include <conio.h>  
#include <stdlib.h>  
#include <time.h>  
#include <stdlib.h>  
#include <windows.h>  
 
// 由于棋盘格与逻辑雷区格有一定差别，所以为了坐标能够相互映射，设置宏I,J，分别映射逻辑表的i,j。
#define I (i+2)
#define J (2*(j+1)+1)
 
/*字体颜色处理函数*/  
  
void SetColor(unsigned short ForeColor,unsigned short BackGroundColor){  
    HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));  
}  
  
/*游戏主程序*/  
  
void showmine();        //显示所有地雷  
void setmine(int x);  //布雷  
void printmine();       //打印所有地雷  
void countmine(int rowno, int colno);    //数雷算法  
//////////////////////////////////////////////////////构建棋盘////////////////////////////////  
char row[16][80]={  
    {"----------Platform---------------------"},  
    {"------------------------------------------------------------------------"},  
    {"01|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"02|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"03|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"04|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"05|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"06|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"07|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"08|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"09|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"10|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"11|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"12|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"13|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
    {"14|\x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02 \x02"},  
};  
////////////////////////////////////////////////构建雷区//////////////////////////////////////////////////  
int mines[14][14]={             //雷区模拟图(01二值化，标记地雷)  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
};  
////////////////////////////////////////////////////////////////////////////////////////////  
  
int mines_demo[14][14]={          //雷数统计图(用于显示周围雷总数)  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
};  
  
//////////////////////////////////////////////////////////////////////////////  
  
int countstep=0;  //已挖坑数目（计数器），用于判定玩家获胜
int n=5;  //布雷数（待输入）
/////////////////////////////////主函数开始///////////////////////////////////////////  
int main()  
{  
    int i=0,j=0;  
    int flag=1;  
    int temp=0;  
    char ch1;  
    SetColor(3,0);  
    printf("欢乐扫雷\n\n");  
    printf("w-上 s-下 a-左 d-右 q-挖雷\n\n");  
    SetColor(7,0);  
    getch();  
    system("cls");  
    printf("你想要布几颗雷？（1< mines <196）");  
    scanf("%d",&n);    
	system("cls");
    setmine(n);  
    row[I][J]='\x01';  
    system("cls");  
    showmine();  
	printf("\n\n");
	//按键消息处理核心代码
    while(flag)  
    {  
        ch1=getch();  
        if(ch1=='w'){  
            if(i==0){  
                system("cls");  
                showmine();  
                continue;  
            }else{  
                system("cls");  
                if(row[I][J]<'9' && row[I][J]>='0'){  //确认移动前的位置属于已被挖雷（在上一次光标移动时已经恢复数字，只是还没有showmine()而已）
                    i--;  //光标移动
                    if(row[I][J]<'9' && row[I][J]>='0'){  //确认移动后的位置已被挖雷
                        temp=row[I][J];  //用temp记录该位置原数字
                        row[I][J]='\x01';  //将该位置标记为选中
                        showmine();  //显示雷区图
                        row[I][J]=temp;  //将选中位置改回原数字
                        continue;  
                    }  
                    row[I][J]='\x01'; //如果不会被覆盖，则直接选中即可  
                    showmine();  //显示雷区图
                    continue;    
                }  
				//移动前的位置未被挖雷情况
                row[I][J]='\x02';  
                i--;  
                if(row[I][J]<'9' && row[I][J]>='0'){  
                    temp=row[I][J];  
                    row[I][J]='\x01';  
                    showmine();  
                    row[I][J]=temp;  
                    continue;  
                }  
                row[I][J]='\x01';  
                showmine();  
            }  
        }else if(ch1=='s'){  
            if(i==13){  
                system("cls");  
                showmine();  
                continue;  
            }else{  
                system("cls");  
                if(row[I][J]<'9' && row[I][J]>='0'){//防止当前位数字覆盖  
                    i++;  
                    if(row[I][J]<'9' && row[I][J]>='0'){ //防止下一位数字覆盖  
                        temp=row[I][J];  
                        row[I][J]='\x01';  
                        showmine();  
                        row[I][J]=temp;  
                        continue;  
                    }  
                    row[I][J]='\x01';  
                    showmine();  
                    continue;  
                }  
                row[I][J]='\x02';  
                i++;  
                if(row[I][J]<'9' && row[I][J]>='0'){  
                    temp=row[I][J];  
                    row[I][J]='\x01';  
                    showmine();  
                    row[I][J]=temp;  
                    continue;  
                }  
                row[I][J]='\x01';  
                showmine();  
            }  
        }else if (ch1=='a'){  
            if(j==0){  
                system("cls");
				if(row[I][J]<'9' && row[I][J]>='0'){  
					temp=row[I][J];  
					row[I][J]='\x01';  
					showmine();  
					row[I][J]=temp;  
					continue;  
                } 
                showmine();  
                continue;  
            }else{  
                system("cls");  
                if(row[I][J]<'9' && row[I][J]>='0'){  
                    j--;  
                    if(row[I][J]<'9' && row[I][J]>='0'){  
                        temp=row[I][J];  
                        row[I][J]='\x01';  
                        showmine();  
                        row[I][J]=temp;  
                        continue;  
                    }  
                    row[I][J]='\x01';  
                    showmine();  
                    continue;  
                }  
                row[I][J]='\x02';  
                j--;  
                if(row[I][J]<'9' && row[I][J]>='0'){  
                    temp=row[I][J];  
                    row[I][J]='\x01';  
                    showmine();  
                    row[I][J]=temp;  
                    continue;  
                }  
                row[I][J]='\x01';  
                showmine();  
            }  
        }else if (ch1=='d'){  
            if(j==13){  
                system("cls");  
                showmine();  
                continue;  
            }else{  
                system("cls");  
                if(row[I][J]<'9' && row[I][J]>='0'){  
                    j++;  
                    if(row[I][J]<'9' && row[I][J]>='0'){  
                        temp=row[I][J];  
                        row[I][J]='\x01';  
                        showmine();  
                        row[I][J]=temp;  
                        continue;  
                    }  
                    row[I][J]='\x01';  
                    showmine();  
                    continue;  
                }  
                row[I][J]='\x02';  
                j++;  
                if(row[I][J]<'9' && row[I][J]>='0'){  
                    temp=row[I][J];  
                    row[I][J]='\x01';  
                    showmine();  
                    row[I][J]=temp;  
                    continue;  
                }  
                row[I][J]='\x01';  
                showmine();  
            }  
        }else if(ch1=='q'){ //挖雷消息识别&处理  
            system("cls");  
            if (mines[i][j]==1)  //如果踩雷
            {  
                printmine();  //打印全图雷区，游戏结束...
                printf("\n BOOM!\n\n");  
                flag=0;  
                getch();  
                fflush(stdin);  
                break; 
            }else{  
				//如果没有踩雷...标示本位地雷数目（从雷数统计图读取）
                if(i>0 && j>0 && row[I][J]=='\x01'){  
                    row[I][J]=(char)(mines_demo[i][j]+48);  
					countstep++;
                }else if(i==0 && j>0 && row[I][J]=='\x01'){  
                    row[I][J]=(char)(mines_demo[i][j]+48); 
					countstep++;
                }else if(i>0 && j==0 && row[I][J]=='\x01'){  
                    row[I][J]=(char)(mines_demo[i][j]+48); 
					countstep++;
                }else if(i==0 && j==0 && row[I][J]=='\x01'){  
                    row[I][J]=(char)(mines_demo[i][j]+48);  
					countstep++;
                }  
                if(mines_demo[i][j]==0 && i>0 && j>0 && i<13 && j<13){      //无雷地区自动展开  
                    if(mines_demo[i+1][j]==0 && row[I+1][J]=='\x02'){  
                        row[I+1][J]=(char)(mines_demo[i+1][j]+48);  
						countstep++;
                    }  
                    if(mines_demo[i-1][j]==0 && row[I-1][J]=='\x02'){  
                        row[I-1][J]=(char)(mines_demo[i-1][j]+48);  
						countstep++;
                    }  
                    if(mines_demo[i][j+1]==0 && row[I][2*(j+1+1)+1]=='\x02'){  
                        row[I][2*(j+1+1)+1]=(char)(mines_demo[i][j+1]+48);  
						countstep++;
                    }  
                    if(mines_demo[i][j-1]==0 && row[I][2*(j-1+1)+1]=='\x02'){  
                        row[I][2*(j-1+1)+1]=(char)(mines_demo[i][j+1]+48);  
						countstep++;
                    }  
                    if(mines_demo[i+1][j+1]==0 && row[I+1][2*(j+1+1)+1]=='\x02'){  
                        row[I+1][2*(j+1+1)+1]=(char)(mines_demo[i+1][j+1]+48);  
						countstep++;
                    }  
                    if(mines_demo[i+1][j-1]==0 && row[I+1][2*(j-1+1)+1]=='\x02'){  
                        row[I+1][2*(j-1+1)+1]=(char)(mines_demo[i+1][j+1]+48);  
						countstep++;
                    }  
                    if(mines_demo[i-1][j+1]==0 && row[I-1][2*(j+1+1)+1]=='\x02'){  
                        row[I-1][2*(j+1+1)+1]=(char)(mines_demo[i-1][j+1]+48);  
						countstep++;
                    }  
                    if(mines_demo[i-1][j-1]==0 && row[I-1][2*(j-1+1)+1]=='\x02'){  
                        row[I-1][2*(j-1+1)+1]=(char)(mines_demo[i-1][j+1]+48);  
						countstep++;
                    }  
                }  
                system("cls");  
                showmine();  
                if(countstep==196-n)  
                {  
                    printf("\nYou Win!\n\n");  
                    getch();  
                    flag=0;  
                    break;  
                }  
            }  
        }  
    }  
}  
  
////////////////////////////////////////////主函数结束/////////////////////////////////////////////////  
  
//////////////////////////////////////////数雷算法开始//////////////////////////////////////////  
void countmine(int rowno, int colno)  
{  
    int count;  
    int i,j;  
    i=rowno;  
    j=colno;  
    mines_demo[i][j]=mines[i-1][j]+mines[i+1][j]+mines[i][j-1]+mines[i][j+1]+mines[i-1][j-1]+mines[i-1][j+1]+mines[i+1][j-1]+mines[i+1][j+1];    
    return;  
}  
/////////////////////////////////////数雷算法结束////////////////////////////////////////////  
void DebugMines()
{
	int i=0 , j=0;
	printf("\n\n");
	for (i = 0 ; i < 14 ; i++)
	{
		for (j=0;j<14;j++)
		{
			printf("%d ",mines[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	for (i = 0 ; i < 14 ; i++)
	{
		for (j=0;j<14;j++)
		{
			printf("%d ",mines_demo[i][j]);
		}
		printf("\n");
	}
}
///////////////////////////////////////棋盘显示///////////////////////////////////////////////  
void showmine(){  
    int i=0,j=0;  
    for(i=0;i<16;i++){  
        for(j=0;j<30;j++){  
            if(row[i][j]=='\xf'){  
                SetColor(4,0);  
                printf("%c",row[i][j]);  
                SetColor(7,0);  
                continue;  
            }else if(row[i][j]<='8' && row[i][j]>='0' && j>2){  
                SetColor(2,0);  
                printf("%c",row[i][j]);  
                SetColor(7,0);  
                continue;  
            }  
            printf("%c",row[i][j]);  
        }  
        printf("\n");  
    }
 
}  
  
/////////////////////////////////////////随机布雷///////////////////////////////////////  
void setmine(int x){  
    int i,j,k;  
    //初始化棋盘  
    for(i=0;i<14;i++){  
        for(j=0;j<14;j++){  
            mines[i][j]=0;  
        }  
    }  
    //设置随机种子  
    srand(time(0));  
    //随机布雷开始  
    for(k=1;k<=x;){  
        i=rand()%14;  
        j=rand()%14;  
        if(mines[i][j]!=1){  
            mines[i][j]=1;  
            k++;  
        }else{  
            continue;  
        }  
    }  
	//方格雷数计算开始
    for(i=0;i<14;i++){  
        for(j=0;j<14;j++){  
            if(i>0 && j>0 && i<13 && j<13){  
                countmine(i,j);  
            }else{ //预置方格雷数计算 
                //if(mines[i][j]!=1){  
                    if(i==0 && j!=0 && j!=13){  
                        mines_demo[0][j]=mines[0][j-1]+mines[1][j]+mines[0][j+1]+mines[1][j-1]+mines[1][j+1];  
                    }else if(j==0 && i!=0 && i!=13){  
                        mines_demo[i][0]=mines[i-1][0]+mines[i+1][0]+mines[i-1][1]+mines[i+1][1]+mines[i][1];  
                    }else if(i==0 && j==0){  
                        mines_demo[0][0]=mines[0][1]+mines[1][1]+mines[1][0];  
                    }else if(i==13 && j==13){  
                        mines_demo[13][13]=mines[12][13]+mines[12][12]+mines[13][12];  
                    }else if(i==0 && j==13){  
                        mines_demo[0][13]=mines[0][12]+mines[1][12]+mines[1][13];  
                    }else if(i==13 && j==0){  
                        mines_demo[13][0]=mines[12][0]+mines[12][1]+mines[13][1];  
                    }else if(i==13 && j!=0 && j!=13){
						mines_demo[i][j] = mines[i][j-1]+mines[i][j+1]+mines[i-1][j-1]+mines[i-1][j]+mines[i-1][j+1];
					}else if (j==13 && i!=0 && i!=13)
					{
						mines_demo[i][j] = mines[i+1][j]+mines[i-1][j]+mines[i-1][j-1]+mines[i][j-1]+mines[i+1][j-1];
					}
                //}  
            }  
        }  
    }  
    return;  
}  
  
/////////////////////////////打印雷区（失败时）///////////////////////////////  
void printmine()  
{  
    int i,j;  
    system("cls");  
    for(i=0;i<14;i++)  
    {  
        for(j=0;j<14;j++){  
            if( mines[i][j]==1){  
                row[I][J]='\xf';  
            }else{  
                row[I][J]='\x02';  
            }  
        }  
  
    }  
    showmine();  
    return;  
}
