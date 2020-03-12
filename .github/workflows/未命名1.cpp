#include <bits/stdc++.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define random(a,b) rand()%(b-a)+a
using namespace std;
struct Button{
    int x,y,color;
    const char *name;
    int len;
};
void GetPos(POINT &pt){
    HWND hwnd=GetForegroundWindow();
    GetCursorPos(&pt);
    ScreenToClient(hwnd,&pt);
    pt.y=pt.y/16,pt.x=pt.x/16;
}
void color(int a){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);}
void gto(int x,int y)
{
    COORD pos;pos.X=y*2;pos.Y=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

Button NewButton(int x,int y,int color,const char *name){
    Button t;
    t.x=x,t.y=y,t.name=name;
    t.color=color;
    t.len=strlen(name);
    return t;
}
bool Preserve(Button A){
    gto(A.x,A.y),color(A.color),printf("%s",A.name);
    POINT pt;
    GetPos(pt);
    if(pt.y==A.x&&(pt.x>=A.y&&pt.x<=A.y+A.len/2)){
        color(A.color);
		gto(A.x,A.y),printf("%s",A.name);
        if(KEY_DOWN(MOUSE_MOVED)) return 1;
    }
    return 0;
}

POINT Windowpos()
{
    POINT pt;
    GetCursorPos(&pt);
    HWND h=GetForegroundWindow();
    ScreenToClient(h,&pt);
    pt.x/=8;pt.y/=16;
    return pt; 
}
void Go(int x,int y)
{
    COORD coord;
    coord.X=y;
    coord.Y=x;
    HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,coord); 
}
struct node{
	long long many,score;
	bool life;
}player;
int timer()
{
    SYSTEMTIME sys;
    GetLocalTime( &sys );
    printf( "%4d年%02d月%02d日 %02d:%02d:%02d",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond);
}
long long s[7][21]={0,0,0,0,0,0,0,0,0,0,0,-2};
long long jiang[7][21]={0,0,0,0,0,0,0,0,0,0,0,2};
long long lf[7]={0,4,4,10,1,1,1},jian[3]={2,4};
long long tio[7][21];
long long num,i,j,tme,shine;
int map_1(){
	color(14);
	cout<<"           _,,,,_"<<endl;
	cout<<"          //_\\\\\\\\\\"<<endl;
	cout<<"          ;/ \\\\\\\\;"<<endl;
	color(15);
	cout<<"         (  ' 7'  )"<<endl;
	cout<<"          ;  __  ;"<<endl;
	cout<<"           \\ __ /"<<endl;
	color(12),cout<<"        .---";
	color(10),cout<<"'__'";
	color(12),cout<<"---."<<endl;
	color(10),cout<<"       /\\\\________//\\ ";
	color(11),cout<<"  ___"<<endl;
	color(10),cout<<"      ;  '========' ";
	color(11),cout<<"_";
	color(10),cout<<";";	
	color(11),cout<<"__\\ /"<<endl;
	color(13),cout<<" _____";
	color(10),cout<<"|";
	color(13),cout<<"______________";
	color(10),cout<<"|";
	color(13),cout<<"__";
	color(11),cout<<"/_\\";
	color(13);
	cout<<"_____"<<endl;
	cout<<"|                              |"<<endl;
}
int mouse;
bool Pass[5]={0,0,0,0,0};
int main(){
	system("cls");
	system("mode con cols=100 lines=30");
	player.many=1000;
	srand((int)time(0));
	for(num=1;;num++)
	{
		if(num%18==0 && num>=50){
			long long ab=random(0,6);
			s[ab][20]=-1;
			jiang[ab][20]=jian[1];
		}
		if(num%54==0 && jian[1]<=8)jian[1]+=2;
		if(num%32==0 && num>=100){
			long long ab=random(0,6);
			s[ab][20]=-2;
			jiang[ab][20]=jian[2];
		}
		if(num%64==0 && jian[2]<=8)jian[2]+=4;
		color(15);
		cout<<"╔═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╗"<<endl;
		for(i=0;i<=6;i++){
			color(15);
			for(j=0;j<=20;j++){
				color(15);
				cout<<"║";
				if(s[i][j]==0)cout<<"  ";
				if(s[i][j]==1){
					color(10);
					cout<<"♀";
				}
				if(s[i][j]==2){
					color(14);
					cout<<"◎";
				}
				if(s[i][j]==3){
					color(13);
					cout<<"▓";
				}
				if(s[i][j]==4){
					color(15);
					cout<<"※";
				}
				if(s[i][j]==5){
					color(12);
					cout<<"⊕";
				}
				if(s[i][j]==6){
					color(11);
					cout<<"¤";
				}
				if(s[i][j]==-1){
					if(jiang[i][j]<=2)color(6);
					if(jiang[i][j]<=4 && jiang[i][j]>2)color(8);
					if(jiang[i][j]<=6 && jiang[i][j]>4)color(7);
					if(jiang[i][j]<=8 && jiang[i][j]>6)color(5);
					if(jiang[i][j]<=10 && jiang[i][j]>8)color(4);
					if(tme>0)color(11);
					cout<<"Ψ";
				}
				if(s[i][j]==-2){
					if(jiang[i][j]<=4)color(6);
					if(jiang[i][j]<=8 && jiang[i][j]>=4)color(8);
					if(jiang[i][j]<=12 && jiang[i][j]>=8)color(7);
					if(tme>0)color(11);
					cout<<"Ж";
				}
				if(s[i][j]==11){
					color(170);
					cout<<"  ";
				}
				if(s[i][j]==12){
					color(119);
					cout<<"  ";
				}
				if(s[i][j]==13){
					color(204);
					cout<<"  ";
				}
				if(s[i][j]==14){
					color(238);
					cout<<"  ";
				}
			}
			color(15);
			cout<<"║"<<endl;
			if(i==6){
				cout<<"╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝"<<endl;
				continue;
			}
			cout<<"╠═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╣"<<endl;
		}
	    color(15);
	    timer();
	    cout<<endl<<"剩余总和: "<<player.many<<" 枚可种植阳光    "<<endl<<endl;
	    map_1(); /*
		Button x1=NewButton(15,0,10,"出售猫薄荷+0.01");
    	if(Preserve(x1)){
			gto(9,9);
			cout<<"acvdafcvwae"<<endl; 
		} */
        mouse=GetAsyncKeyState(VK_LBUTTON)&0x8000;
        POINT pt=Windowpos();
        if(pt.x>=36&&pt.x<=47&&pt.y>=25&&pt.y<=27){
            color(12);
            Go(25,36);
            printf("┏━━━━┓");
            Go(26,36);
            printf("┃退出游戏┃");
            Go(27,36);
            printf("┗━━━━┛");
            if(mouse){
                int choice=MessageBox(NULL, TEXT("确定退出？"), TEXT("提示"), MB_YESNO);
                if(choice==IDYES){
				    color(15);
					return 0;
				}
            }
        }
        else{
            color(15);
            Go(25,36);
            printf("┏━━━━┓");
            Go(26,36);
            printf("┃退出游戏┃");
            Go(27,36);
            printf("┗━━━━┛");
        }
        if(pt.x>=36&&pt.x<=47&&pt.y>=21&&pt.y<=23){
            color(14);
            Go(21,36);
            printf("┏━━━━┓");
            Go(22,36);
            printf("┃建议反馈┃");
            Go(23,36);
            printf("┗━━━━┛");
            if(mouse){
            	HWND hWnd=FindWindow("ConsoleWindowClass",NULL);
                ShowWindow(hWnd,SW_HIDE);
                system("start https://www.luogu.org/space/show?uid=229378");
                return 0; 
            }
        }
        else{
            color(15);
            Go(21,36);
            printf("┏━━━━┓");
            Go(22,36);
            printf("┃建议反馈┃");
            Go(23,36);
            printf("┗━━━━┛");
        }
        if(pt.x>=36&&pt.x<=47&&pt.y>=17&&pt.y<=19){
            color(10);
            Go(17,36);
            printf("┏━━━━┓");
            Go(18,36);
            printf("┃种植植物┃");
            Go(19,36);
            printf("┗━━━━┛");
            if(mouse){
            	bool king=true;
            	long long xxy,yyx; 
            	while(king!=false){
            		for(i=0;i<=6;i++){
            			for(j=0;j<=20;j++){
            				Button x=NewButton(i*2+1,j*2+1,128,"  ");
            				if(s[i][j]==1){
								x.name="♀";
								x.color=10;
							} 
            				if(s[i][j]==2){
								x.name="◎";
								x.color=14;
							}
            				if(s[i][j]==3){
            					x.name="▓";
            					x.color=13;
            				}
            				if(s[i][j]==4){
								x.name="※";
								x.color=15;
							}
            				if(s[i][j]==5){
								x.name="⊕";
								x.color=12;
							}
            				if(s[i][j]==6){
								x.name="¤";
								x.color=11;
							}
    						if(s[i][j]>=0 && s[i][j]<=6){
    							if(Preserve(x)){
	    							xxy=i,yyx=j;
    								king=false;
    								break;
    							}
							}
						}
					}
				}
				while(king==false){
					long long mouse2=GetAsyncKeyState(VK_LBUTTON)&0x8000;
        			POINT pd=Windowpos();
					if(pd.x>=36&&pd.x<=47&&pd.y>=17&&pd.y<=19){
	     		        color(10);
    	 		        Go(17,36);
    			        printf("┏━━━━┓");
    			        Go(18,36);
    		    	    printf("┃豌豆射手┃");
     		        	Go(19,36);
	     		        printf("┗━━━━┛");
    	      		    if(mouse2){if(player.many<150){
									king=true;
								}
								if(player.many>=150){
									s[xxy][yyx]=1;
									jiang[xxy][yyx]=lf[1];
									king=true;
								}
            				
            				else break;
						}
          			}
        			else{
			            color(15);
            			Go(17,36);
		            	printf("┏━━━━┓");
    	    	    	Go(18,36);
	        		    printf("┃豌豆射手┃");
    		        	Go(19,36);
		    	        printf("┗━━━━┛");
        			}
        			if(pd.x>=36&&pd.x<=47&&pd.y>=21&&pd.y<=23){
            			color(14);
            			Go(21,36);
            			printf("┏━━━━┓");
            			Go(22,36);
            			printf("┃向 日 葵┃");
            			Go(23,36);
            			printf("┗━━━━┛");
            			if(mouse2){if(player.many<100){
									king=true;
								}
								if(player.many>=100){
									s[xxy][yyx]=2;
									jiang[xxy][yyx]=lf[2];
									shine++;
									tio[xxy][yyx]=20;
									king=true;
								}
            		
            				else break;
            			}
        			}
 			       	else{
            			color(15);
            			Go(21,36);
            			printf("┏━━━━┓");
            			Go(22,36);
            			printf("┃向 日 葵┃");
            			Go(23,36);
            			printf("┗━━━━┛");
        			}
        			if(pd.x>=36&&pd.x<=47&&pd.y>=25&&pd.y<=27){
	     		        color(13);
    	 		        Go(25,36);
    			        printf("┏━━━━┓");
    			        Go(26,36);
    		    	    printf("┃ 坚  果 ┃");
     		        	Go(27,36);
	     		        printf("┗━━━━┛");
    	      		    if(mouse2){if(player.many<125){
									king=true;
								}
								if(player.many>=125){
									s[xxy][yyx]=3;
									jiang[xxy][yyx]=lf[3];
									king=true;
								}
            				
            				else break;
						}
          			}
        			else{
			            color(15);
            			Go(25,36);
		            	printf("┏━━━━┓");
    	    	    	Go(26,36);
	        		    printf("┃ 坚  果 ┃");
    		        	Go(27,36);
		    	        printf("┗━━━━┛");
        			}
        			if(pd.x>=53&&pd.x<=64&&pd.y>=25&&pd.y<=27){
	     		        color(7);
    	 		        Go(25,53);
    			        printf("┏━━━━┓");
    			        Go(26,53);
    		    	    printf("┃ 倭  瓜 ┃");
     		        	Go(27,53);
	     		        printf("┗━━━━┛");
    	      		    if(mouse2){if(player.many<100){
									king=true;
								}
								if(player.many>=100){
									s[xxy][yyx]=4;
									jiang[xxy][yyx]=lf[4];
									king=true;
								}
            			
            				else break;
						}
          			}
        			else{
			            color(15);
            			Go(25,53);
		            	printf("┏━━━━┓");
    	    	    	Go(26,53);
	        		    printf("┃ 倭  瓜 ┃");
    		        	Go(27,53);
		    	        printf("┗━━━━┛");
        			}
        			if(pd.x>=53&&pd.x<=64&&pd.y>=21&&pd.y<=23){
            			color(12);
            			Go(21,53);
            			printf("┏━━━━┓");
            			Go(22,53);
            			printf("┃樱桃炸弹┃");
            			Go(23,53);
            			printf("┗━━━━┛");
            			if(mouse2){if(player.many<200){
									king=true;
								}
								if(player.many>=200){
									s[xxy][yyx]=5;
									jiang[xxy][yyx]=lf[5];
									king=true;
								}
            				
            				else break;
            			}
        			}
 			       	else{
            			color(15);
            			Go(21,53);
            			printf("┏━━━━┓");
            			Go(22,53);
            			printf("┃樱桃炸弹┃");
            			Go(23,53);
            			printf("┗━━━━┛");
        			}
        			if(pd.x>=53&&pd.x<=64&&pd.y>=17&&pd.y<=19){
	     		        color(11);
    	 		        Go(17,53);
    			        printf("┏━━━━┓");
    			        Go(18,53);
    		    	    printf("┃寒 冰 菇┃");
     		        	Go(19,53);
	     		        printf("┗━━━━┛");
    	      		    if(mouse2){if(player.many<250){
									king=true;
								}
								if(player.many>=250){
									s[xxy][yyx]=6;
									jiang[xxy][yyx]=lf[6];
									king=true;
								}
            				
            				else break;
						}
          			}
        			else{
			            color(15);
            			Go(17,53);
		            	printf("┏━━━━┓");
    	    	    	Go(18,53);
	        		    printf("┃寒 冰 菇┃");
    		        	Go(19,53);
		    	        printf("┗━━━━┛");
        			}
				}
				system("cls"); 
            }
        }
        else{
            color(15);
            Go(17,36);
            printf("┏━━━━┓");
            Go(18,36);
            printf("┃种植植物┃");
            Go(19,36);
            printf("┗━━━━┛");
        }
        if(num%2==0 && num%5!=0)
		{
			for(i=0;i<=6;i++)
	    	{
		    	for(j=0;j<=20;j++)
			    {
					if(s[i][j]>=10 && s[i][j]!=14)
					{
						s[i][j]=0;
						jiang[i][j]=0;
					}
					if(s[i][j]==14)s[i][j]=2;
				}
			}
		}
        if(num%5==0)
		{
			for(i=0;i<=6;i++)
	    	{
		    	for(j=0;j<=20;j++)
			    {
			    	long long als; 
					if(s[i][j]==1)
					{
						if(jiang[i][j]<=0){
							s[i][j]=0;
							jiang[i][j]=0;
						}
						for(als=j;als<=20;als++)
						{
							long long stepe=jiang[i][als];
							if(s[i][als]==-1)jiang[i][als]--;
					        if(s[i][als]==-2)jiang[i][als]--;
					        if(stepe!=jiang[i][als] && jiang[i][als]<=0){
					        	s[i][als]=11;
					        	jiang[i][als]=0;
					        	break;
							}
							if(stepe!=jiang[i][als] && jiang[i][als]>=0)break;
						}
					}
					if(s[i][j]==2)
					{
						if(jiang[i][j]<=0){
							s[i][j]=0;
							jiang[i][j]=0;
						}
						if(jiang[i][j]>0){
							tio[i][j]--;
							if(tio[i][j]<=0){
								s[i][j]=14;
								tio[i][j]=16;
								player.many+=25;
							}
						}
					}
					if(s[i][j]==3)
					{
						if(jiang[i][j]<=0){
							s[i][j]=0;
							jiang[i][j]=0;
						}
					}
					if(s[i][j]==4 && s[i][j+1]<0)
					{
						if(jiang[i][j]<=0){
							s[i][j]=0;
							jiang[i][j]=0;
						}
						s[i][j+1]=12;
						jiang[i][j+1]=0;
						s[i][j]=0;
						jiang[i][j]=0;
					}
					if(s[i][j]==5)
					{
						if(jiang[i][j]<=0){
							s[i][j]=0;
							jiang[i][j]=0;
						}
						for(long long ii=i-1;ii<=i+1;ii++){
							for(long long jj=j-1;jj<=j+1;jj++){
								if(s[ii][jj]<0){
									jiang[ii][jj]=0;
									s[ii][jj]=13;
								}
							}
						}
						s[i][j]=0;
						jiang[i][j]=0;
					}
					if(s[i][j]==6)
					{
						if(jiang[i][j]<=0){
							s[i][j]=0;
							jiang[i][j]=0;
						}
						s[i][j]=0;
						jiang[i][j]=0;
						tme+=4;
					}
    			}
	    	}
		}
		if(num%6==0 && tme<=0)
		{
			for(i=0;i<=6;i++)
	    	{
		    	for(j=0;j<=20;j++)
			    {
					if(s[i][j]==-1){
						if(s[i][j-1]==0){
							if(j==0){
								system("cls");
								return 0; 
							}
							swap(s[i][j-1],s[i][j]);
							swap(jiang[i][j-1],jiang[i][j]);
						}
						if(s[i][j-1]>=1 && s[i][j-1]<=6)jiang[i][j-1]--;
					}
					if(s[i][j]==-2){
						if(s[i][j-1]==0){
							if(j==0){
								system("cls");
								return 0; 
							}
							swap(s[i][j-1],s[i][j]);
							swap(jiang[i][j-1],jiang[i][j]);
						}
						if(num%18==0){
							if(s[i][j-1]==0 && j>=1){
								s[i][j-1]=-1;
								jiang[i][j-1]=2;
							}
							if(s[i][j+1]==0 && j<=19){
								s[i][j+1]=-1;
								jiang[i][j+1]=2;
							}
							if(s[i-1][j]==0 && i>=1){
								s[i-1][j]=-1;
								jiang[i-1][j]=2;
							}
							if(s[i+1][j]==0 && i<=5){
								s[i+1][j]=-1;
								jiang[i+1][j]=2;
							}
						}
					}
				}
			}
		}
		if(num%6==0 && tme>0)tme--;
        if(num%50==0)player.many+=25; 
		gto(0,0);
    }
}
