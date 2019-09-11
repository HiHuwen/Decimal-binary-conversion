#include"acllib.h" 
//#include<stdio.h>
void setnum(int x,int y,const char *p);
void setword(int x,int y,const char *p);
void setface();
void mouseListener(int x,int y,int button,int event);
void changeface(int x,int y,char *p,int button,int event,int num);
void changeface2(int x,int y,char *p,int button,int event,int num);
void printnum(int num);
void changeD(int num);
void printresult(); 
void printDtoO(double aD);
void printDtoH(double aD);
void printDtoB(double aD);
void number(int place,int y,int num);


//void DtoO(double aD);
//void DtoH(double aD);
//void DtoB(double aD);

int dot=0; 

int Setup()
{
	initWindow("进制运算器",DEFAULT,DEFAULT,360,600);
	//initConsole();
	setface();
	registerMouseEvent(mouseListener);
	 
	return 0;
}
void setface()
{
	beginPaint();
	setPenColor(RGB(192,192,192));
	setPenWidth(2);	
	setnum(0,180," 1 ");
	setnum(120,180," 2 ");
	setnum(240,180," 3 ");
	setnum(0,256," 4 ");
	setnum(120,256," 5 ");
	setnum(240,256," 6 ");
	setnum(0,332," 7 ");
	setnum(120,332," 8 ");
	setnum(240,332," 9 ");
	setnum(120,408," 0 ");	
	setnum(0,408," = ");
	setnum(240,408," . ");	
	setword(0,484," CE ");
	setword(120,484," C ");
	setword(240,484,"DEL");
	endPaint();
}

void mouseListener(int x,int y,int button,int event)
{
	int num;
	if(x>=0&&x<=360&&y>=180&&y<=560){		
		beginPaint();
		setPenColor(RGB(192,192,192));
		setPenWidth(1);
		setnum(0,180," 1 ");
		setnum(120,180," 2 ");
		setnum(240,180," 3 ");
		setnum(0,256," 4 ");
		setnum(120,256," 5 ");
		setnum(240,256," 6 ");
		setnum(0,332," 7 ");
		setnum(120,332," 8 ");
		setnum(240,332," 9 ");
		setnum(120,408," 0 ");	
		setnum(0,408," = ");
		setnum(240,408," . ");	
		setword(0,484," CE ");
		setword(120,484," C ");
		setword(240,484,"DEL");
		if(x>=0&&x<=119&&y>=180&&y<=255){
			x=0;
			y=180;
			num=1;
			changeface(x,y," 1 ",button,event,num);
		}
		if(x>=120&&x<=239&&y>=180&&y<=255){
			x=120;
			y=180;
			num=2;
			changeface(x,y," 2 ",button,event,num);
		}
		if(x>=240&&x<=360&&y>=180&&y<=255){
			x=240;
			y=180;
			num=3;
			changeface(x,y," 3 ",button,event,num);
		}
		if(x>=0&&x<=119&&y>=256&&y<=331){
			x=0;
			y=256;
			num=4;
			changeface(x,y," 4 ",button,event,num);
		}
		if(x>=120&&x<=239&&y>=256&&y<=331){
			x=120;
			y=256;
			num=5;
			changeface(x,y," 5 ",button,event,num);
		}
		if(x>=240&&x<=360&&y>=256&&y<=331){
			x=240;
			y=256;
			num=6;
			changeface(x,y," 6 ",button,event,num);
		}
		if(x>=0&&x<=119&&y>=332&&y<=407){
			x=0;
			y=332;
			num=7;
			changeface(x,y," 7 ",button,event,num);
		}
		if(x>=120&&x<=239&&y>=332&&y<=407){
			x=120;
			y=332;
			num=8;
			changeface(x,y," 8 ",button,event,num);
		}
		if(x>=240&&x<=360&&y>=332&&y<=407){
			x=240;
			y=332;
			num=9;
			changeface(x,y," 9 ",button,event,num);
		}
		if(x>=0&&x<=119&&y>=408&&y<=483){
			x=0;
			y=408;
			num=10;
			changeface(x,y," = ",button,event,num);
		}
		if(x>=120&&x<=239&&y>=408&&y<=483){
			x=120;
			y=408;
			num=0;
			changeface(x,y," 0 ",button,event,num);
		}
		if(x>=240&&x<=360&&y>=408&&y<=483){
			x=240;
			y=408;
			num=11;
			if(dot==0){
				changeface(x,y," . ",button,event,num);
			} else {
				setBrushColor(RGB(70,70,70));
				POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
				polygon(p1,4);	
				setTextColor(RGB(0,0,0));
				setTextBkColor(RGB(70,70,70));
				setTextSize(53);
				paintText(x+18,y+12," . ");
			}
		}
		if(x>=0&&x<=119&&y>=484&&y<=560){
			x=0;
			y=484;
			num=12; 
			changeface2(x,y," CE ",button,event,num);
		}
		if(x>=120&&x<=239&&y>=484&&y<=560){
			x=120;
			y=484;
			num=13;
			changeface2(x,y," C ",button,event,num);
		}
		if(x>=240&&x<=360&&y>=484&&y<=560){
			x=240;
			y=484;
			num=14;
			changeface2(x,y,"DEL",button,event,num);
		}
		
		endPaint();
	} else {
		setface();
	}
}

void changeface(int x,int y,char *p,int button,int event,int num)
{
	if (event==5&&button==5){
		setBrushColor(RGB(141,141,141));
		POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
		polygon(p1,4);	
		setTextColor(RGB(0,0,0));
		setTextBkColor(RGB(141,141,141));
		setTextSize(53);
		paintText(x+18,y+12,p);
	} else if (button==1&&event==0) {
		setBrushColor(RGB(70,70,70));
		POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
		polygon(p1,4);	
		setTextColor(RGB(0,0,0));
		setTextBkColor(RGB(70,70,70));
		setTextSize(53);
		paintText(x+18,y+12,p);
	} else if (button==1&&event==2) {
		setBrushColor(RGB(141,141,141));
		POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
		polygon(p1,4);	
		setTextColor(RGB(0,0,0));
		setTextBkColor(RGB(141,141,141));
		setTextSize(53);
		paintText(x+18,y+12,p);
		printnum(num);
	} else {
		setBrushColor(RGB(141,141,141));
		POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
		polygon(p1,4);	
		setTextColor(RGB(0,0,0));
		setTextBkColor(RGB(141,141,141));
		setTextSize(53);
		paintText(x+18,y+12,p);
	}
}

void changeface2(int x,int y,char *p,int button,int event,int num)
{
	if (event==5&&button==5){
		setBrushColor(RGB(141,141,141));
		POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
		polygon(p1,4);	
		setTextColor(RGB(0,0,0));
		setTextBkColor(RGB(141,141,141));
		setTextSize(38);
		paintText(x+27,y+15,p);
	} else if (button==1&&event==0) {
		setBrushColor(RGB(70,70,70));
		POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
		polygon(p1,4);	
		setTextColor(RGB(0,0,0));
		setTextBkColor(RGB(70,70,70));
		setTextSize(38);
		paintText(x+27,y+15,p);
	} else if (button==1&&event==2) {
		setBrushColor(RGB(141,141,141));
		POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
		polygon(p1,4);	
		setTextColor(RGB(0,0,0));
		setTextBkColor(RGB(141,141,141));
		setTextSize(38);
		paintText(x+27,y+15,p);
		printnum(num);
		
	} else {
		setBrushColor(RGB(141,141,141));
		POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
		polygon(p1,4);	
		setTextColor(RGB(0,0,0));
		setTextBkColor(RGB(141,141,141));
		setTextSize(38);
		paintText(x+27,y+15,p);
	}
}

void setnum(int x,int y,const char *p)
{ 	
	setBrushColor(RGB(192,192,192));
	POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
	polygon(p1,4);	
	setTextColor(RGB(0,0,0));
	setTextBkColor(RGB(192,192,192));
	setTextSize(53);
	paintText(x+18,y+12,p);
}

void setword(int x,int y,const char *p)
{
	setBrushColor(RGB(192,192,192));
	POINT p1[]={{x,y},{x+120,y},{x+120,y+76},{x,y+76}};
	polygon(p1,4);	
	setTextColor(RGB(0,0,0));
	setTextBkColor(RGB(192,192,192));
	setTextSize(38);
	paintText(x+27,y+15,p);
 } 

void printnum(int num)
{
	static int place=-20;
	place=place+20;
	setTextColor(RGB(0,0,0));
	setTextBkColor(RGB(255,255,255));
	setTextSize(40);
	switch (num){
		case 1:
			paintText(place,130,"1");
			break;
		case 2:
			paintText(place,130,"2");
			break;
		case 3:
			paintText(place,130,"3");
			break;
		case 4:
			paintText(place,130,"4");
			break;
		case 5:
			paintText(place,130,"5");
			break;
		case 6:
			paintText(place,130,"6");
			break;
		case 7:
			paintText(place,130,"7");
			break;
		case 8:
			paintText(place,130,"8");
			break;
		case 9:
			paintText(place,130,"9");
			break;
		case 0:
			paintText(place,130,"0");
			break;
		case 11:
			if(dot==0){
				paintText(place,130,".");
			} else {
				place=place-20;
			}
			break;
		case 12:
			place=-20;
			paintText(place,130,"                    ");
			break;
		case 13:
			if(place>0){
				place=place-20;
				paintText(place,130," ");
				place=place-20;
			}
			break;
		case 10:
			setPenColor(WHITE);
			setBrushColor(RGB(255,255,255));
			POINT p2[]={{0,0},{360,0},{360,129},{0,129}};
			polygon(p2,4);		
			place=place-20;
			break;
		case 14:
			setPenColor(WHITE);
			setBrushColor(RGB(255,255,255));
			POINT p1[]={{0,0},{360,0},{360,178},{0,178}};
			polygon(p1,4);
			place=-20;
			break;
		}
	changeD(num);
} 

void changeD(int num)
{
	double Dnum=0;
	static int i=0;
	static int k=0;
	static int ai[18]={};
	static int ak[18]={};
	
	double tenk=1;
	int teni=1;
	int Di=0;
	double Dk=0;
	int cnt;
	int ci;
	int ck;
	if (num==11){
		dot=1;
	}
	
	if(num>=0&&num<=9&&dot==0){
		ai[i]=num;
		i++;
	} else if (num>=0&&num<=9&&dot==1){
		ak[k]=num;
		k++;
	} else if (num==10){
		ci=i;
		while (ci>=0){
			ci--;
			Di=Di+ai[ci]*teni;
			teni=teni*10;
		}
		ci=0;
		for (cnt=0;cnt<k;cnt++){
			tenk=tenk/10;
			Dk=Dk+ak[cnt]*tenk;
		}
		Dnum=Di+Dk;
		
		printresult();
		printDtoO(Dnum);
		printDtoH(Dnum);
		printDtoB(Dnum);
		
//		printf("%f\n",Dnum);
//		DtoO(Dnum);
//		DtoB(Dnum);
//		DtoH(Dnum);
		
	} else if (num==13){
		if (dot==0&&i>0){
			i--;
			ai[i]=0;			
		} else if(dot==1&&k>0){
			k--;
			ak[k]=0;
		} else if (dot==1&&k==0){
			dot=0;
		}
		
	} else if (num==12||num==14) {
		dot=0;
		i=0;
		k=0;
		Dnum=0;
	}
 } 
 
void printresult()
{
	setTextColor(RGB(0,0,0));
	setTextBkColor(RGB(255,255,255));
	setTextSize(25);
	paintText(0,100,"十六进制：");
	paintText(0,70,"八进制：");
	paintText(0,10,"二进制："); 
 } 

void number(int place,int y,int num)
{
	switch (num){
		case 1:
			paintText(place,y,"1");
			break;
		case 2:
			paintText(place,y,"2");
			break;
		case 3:
			paintText(place,y,"3");
			break;
		case 4:
			paintText(place,y,"4");
			break;
		case 5:
			paintText(place,y,"5");
			break;
		case 6:
			paintText(place,y,"6");
			break;
		case 7:
			paintText(place,y,"7");
			break;
		case 8:
			paintText(place,y,"8");
			break;
		case 9:
			paintText(place,y,"9");
			break;
		case 0:
			paintText(place,y,"0");
			break;
		case 10:
			paintText(place,y,"A");
			break;
		case 11:
			paintText(place,y,"B");
			break;
		case 12:
			paintText(place,y,"C");
			break;
		case 13:
			paintText(place,y,"D");
			break;
		case 14:
			paintText(place,y,"E");
			break;
		case 15:
			paintText(place,y,"F");
			break;
		}
}
 
 void printDtoO(double aD)
{
	int place=90;
	setTextColor(RGB(0,0,0));
	setTextBkColor(RGB(255,255,255));
	setTextSize(25);
	
	int aiD;
	double adD;
	int printa=0;
	int i=0;
	int pra[100]={};
	double dk;
	int ik;
	aiD=(int)aD;
	adD=aD-aiD;
	do{
		i++;
		printa=aiD%8;
		aiD=aiD/8;
			pra[i]=printa;
	}while(aiD);
	 
	for (;i;i--){
		number(place,70,pra[i]);
		place=place+14;
	} 
	if(adD!=0){
		paintText(place,70,".");
		place=place+14;
		i=0;
		do{
			i++;
			dk=adD*8;
			ik=(int)dk;
			
			number(place,70,ik);
			place=place+14;
			adD=dk-ik; 
		}while (adD&&i<8);
	}
}
 
 void printDtoH(double aD)
{
	int place=115;
	setTextColor(RGB(0,0,0));
	setTextBkColor(RGB(255,255,255));
	setTextSize(25);
	
	
	int aiD;
	double adD;
	int printa=0;
	int i=0;
	int pra[100]={};
	double dk;
	int ik;
	aiD=(int)aD;
	adD=aD-aiD;
	do{
		i++;
		printa=aiD%16;
		aiD=aiD/16;
			pra[i]=printa;
	}while(aiD);
	for (;i;i--){
			number(place,100,pra[i]);
			place=place+14;
		}
	 
	if(adD!=0){
		paintText(place,100,".");
		place=place+14;
		i=0;
		do{
			i++;
			dk=adD*16;
			ik=(int)dk;
			
			number(place,100,ik);
			place=place+14;			
			adD=dk-ik; 
		}while (adD&&i<8);
	}

}
 
 void printDtoB(double aD)
{
	int place=90;
	setTextColor(RGB(0,0,0));
	setTextBkColor(RGB(255,255,255));
	setTextSize(25);
	
	int aiD;
	double adD;
	int printa=0;
	int i=0;
	int pra[100]={};
	double dk;
	int ik;

	aiD=(int)aD;
	adD=aD-aiD;
	do{
		i++;
		printa=aiD%2;
		aiD=aiD/2;
		if (printa){
			pra[i]=1;
		} else {
			pra[i]=0;
		}
	}while(aiD); 
	for (;i;i--){
		if(place<=(18*14+90)){
			number(place,10,pra[i]);
			place=place+14;
		} else {
			number(place-(19*14),40,pra[i]);
			place=place+14;
		}
	} 
	if(adD!=0){
		if(place<=(18*14+90)){
			paintText(place,10,".");
			place=place+14;
		} else {
			paintText(place-(19*14),40,".");
			place=place+14;
		}
		i=0;
		do{
			i++;
			dk=adD*2;
			ik=(int)dk;
			if(ik){
				if(place<=(18*14+90)){
					paintText(place,10,"1");
					place=place+14;
				} else {
					paintText(place-(19*14),40,"1");
					place=place+14;
				}
			} else {
				if(place<=(18*14+90)){
					paintText(place,10,"0");
					place=place+14;
				} else {
					paintText(place-(19*14),40,"0");
					place=place+14;
				}
			}
			adD=dk-ik; 
		}while (adD&&i<8);
	}
 } 
 
 /*
 void DtoO(double aD)
{
	int aiD;
	double adD;
	int printa=0;
	int i=0;
	int pra[100]={};
	double dk;
	int ik;
	aiD=(int)aD;
	adD=aD-aiD;
	do{
		i++;
		printa=aiD%8;
		aiD=aiD/8;
			pra[i]=printa;
	}while(aiD);
	printf("八进制数为："); 
	for (;i;i--){
		printf("%d",pra[i]);
	} 
	if(adD!=0){
		printf(".");
		i=0;
		do{
			i++;
			dk=adD*8;
			ik=(int)dk;
			printf("%d",ik);
			adD=dk-ik; 
		}while (adD&&i<8);
	}
	printf("\n");
}

void DtoH(double aD)
{
	//double aD;
	int aiD;
	double adD;
	int printa=0;
	int i=0;
	int pra[100]={};
	double dk;
	int ik;
	//printf("输入一个十进制的正数："); 
	//scanf("%lf",&aD);
	aiD=(int)aD;
	adD=aD-aiD;
	do{
		i++;
		printa=aiD%16;
		aiD=aiD/16;
			pra[i]=printa;
	}while(aiD);
	printf("十六进制数为："); 
	for (;i;i--){
		if (pra[i]<10) {
			printf("%d",pra[i]);
		} else {
			switch (pra[i]){
				case 10:printf("A");break;
				case 11:printf("B");break;
				case 12:printf("C");break;
				case 13:printf("D");break;
				case 14:printf("E");break;
				case 15:printf("F");break;
			}
		}
	} 
	if(adD!=0){
		printf(".");
		i=0;
		do{
			i++;
			dk=adD*16;
			ik=(int)dk;
			if (ik<10) {
				printf("%d",ik);
			} else {
				switch (ik){
					case 10:printf("A");break;
					case 11:printf("B");break;
					case 12:printf("C");break;
					case 13:printf("D");break;
					case 14:printf("E");break;
					case 15:printf("F");break;
				}
			}
			adD=dk-ik; 
		}while (adD&&i<8);
	}
	printf("\n");
}

void DtoB(double aD)
{
	//double aD;
	int aiD;
	double adD;
	int printa=0;
	int i=0;
	int pra[100]={};
	double dk;
	int ik;
	//printf("输入一个十进制的正数："); 
	//scanf("%lf",&aD);
	aiD=(int)aD;
	adD=aD-aiD;
	do{
		i++;
		printa=aiD%2;
		aiD=aiD/2;
		if (printa){
			pra[i]=1;
		} else {
			pra[i]=0;
		}
	}while(aiD);
	printf("二进制数为："); 
	for (;i;i--){
		printf("%d",pra[i]);
	} 
	if(adD!=0){
		printf(".");
		i=0;
		do{
			i++;
			dk=adD*2;
			ik=(int)dk;
			if(ik){
				printf("1");
			} else {
				printf("0");
			}
			adD=dk-ik; 
		}while (adD&&i<8);
	}
	printf("\n");
 } 
*/
