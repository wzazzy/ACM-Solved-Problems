////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-24 17:10:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int y,m,d,x;
    while(~scanf("%d/%d/%d",&y,&m,&d))
    {
		x=0;
		switch(m)
		{
			case 1:x=d;break;
			case 2:x=31+d;break;
			case 3:x=59+d;break;
			case 4:x=90+d;break;
			case 5:x=120+d;break;
			case 6:x=151+d;break;
			case 7:x=181+d;break;
			case 8:x=212+d;break;
			case 9:x=243+d;break;
			case 10:x=273+d;break;
			case 11:x=304+d;break;
			case 12:x=334+d;break;
		}
		if((y%4==0&&y%100!=0)||(y%400==0))
		{
			if(m>2)
			x=x+1;
		}
		printf("%d\n",x);
	}
    return 0;
}