#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>	
#include<time.h>
#include <windows.h>

using namespace std;
	
struct stack
{
	int koor1[500];
	int koor2[500];

	int ust = 1;
};

struct queue{
	int kor1[501];
	int kor2[501];
	
	int on=0,son=0;
}q;

struct stack s,s1;
	
int main()
{  	
	initwindow(700,500); // grafik ekraný oluþtur
	
	rectangle(500,400,50,50); 
	setcolor(0);
	setbkcolor(14);
	setfillstyle(9,14);
	rectangle(655,400,505,50);
	outtextxy(545,55,"TITANIC");
	outtextxy(540,95,"YENI OYUN");
	outtextxy(540,115,"CIKIS");
	outtextxy(540,155,"TEKRAR");
	outtextxy(540,175,"OYUN SONU");
	outtextxy(540,215,"PUAN");
	outtextxy(540,235,"...");
	outtextxy(520,95,"->");
	outtextxy(540,255,"DURUM");
	outtextxy(540,275,"...");
	
	rectangle(500,450,50,405);
	outtextxy(202,410," UÐURCAN SORUÇ");
	outtextxy(202,430," 170106206053 ");
	
	int deger=0;
	char sayi[4];	
	
	
	
	int b=1;
	int basla=1;
	int a=0;
	int x=490,y=385;
	int bomxy[300][2];	
	int kontrol = 0;
	int bombakontrol=0;
	int limankonum[5][2];
	int sonuc=1;
	
	while(b==1){
		outtextxy(520,95,"->");
		basla = getch();
		
		cleardevice();
		rectangle(500,400,50,50); 
		setcolor(0);
		setbkcolor(14);
		setfillstyle(9,14);
		rectangle(655,400,505,50);
		outtextxy(545,55,"TITANIC");
		outtextxy(540,95,"YENI OYUN");
		outtextxy(540,115,"CIKIS");
		outtextxy(540,155,"TEKRAR");
		outtextxy(540,175,"OYUN SONU");
		outtextxy(540,215,"PUAN");
		outtextxy(540,235,"...");
		outtextxy(540,255,"DURUM");
		outtextxy(540,275,"...");
		
		
		rectangle(500,450,50,405);
		outtextxy(202,410," UÐURCAN SORUÇ");
		outtextxy(202,430," 170106206053 ");
		
		
		switch(basla){
			case 72:{
				outtextxy(520,95,"->");
				basla=getch();
				if(basla==13){
					sonuc=1;
					kontrol=0;
					deger=0;
					sprintf(sayi,"%d",deger);//puan
					outtextxy(540,235,sayi);
			q.son=0;
			q.on=0;
			s.ust=1;
					
	q.on++;
	q.kor1[q.on]=x;
	q.kor2[q.on]=y;
	s.koor1[s.ust] = x;
	s.koor2[s.ust] = y;
	srand (time(NULL));
	for(int i=0;i<300;i++){  // rastgele bomba;
	bomxy[i][0]=rand()%349+50;
	bomxy[i][1]=rand()%249+50;
	}
	
	
	int limx,limy;
	int rast=rand()%2;
	
	if(rast==0){
		limy=rand() % 300 + 50;
		limx=50;	
	}
	else{
		limx=rand() % 300+50;
		limy=50;
	}
	
	outtextxy(limx,limy,"L");
	
	
	
	
	
	while(a!=1)
	{	
		 
		
		a = getch();
		//bar(500,400,50,50);
		cleardevice();
		rectangle(500,400,50,50); 
		setcolor(0);
		setbkcolor(14);
		setfillstyle(9,14);
		rectangle(655,400,505,50);
		outtextxy(545,55,"TITANIC");
		outtextxy(540,95,"YENI OYUN");
		outtextxy(540,115,"CIKIS");
		outtextxy(540,155,"TEKRAR");
		outtextxy(540,175,"OYUN SONU");
		outtextxy(540,215,"PUAN");
		outtextxy(540,255,"DURUM");
		outtextxy(540,275,"...");
		outtextxy(limx,limy,"L");
		
		rectangle(500,450,50,405);
		outtextxy(202,410," UÐURCAN SORUÇ");
		outtextxy(202,430," 170106206053 ");
			
		switch (a)
		{				
			case 72:
			{
				y-=5;
				if(y+5==50  )y+=5;
					
				
				s.ust++;
				s.koor1[s.ust] = x;
				s.koor2[s.ust] = y;
				
				for(int i=0;i<300;i++){
					if((s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]-1) || (s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]-2) || (s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]-3) || (s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]-4) || (s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]-5) ){
						bombakontrol=1;
						outtextxy(540,295,"HASAR ALDI");
					}
				}
				if(bombakontrol==1){
					Sleep(1000);
					kontrol++;
					if(kontrol==1)
					{
						s.ust -= 3;
						deger-=30;
					}
					else if(kontrol==2)
					{
						s.ust -= 5;
						deger-=70;
					}
					else
					{
						a = 1;
						deger-=200;
					}
					outtextxy(s.koor1[s.ust],s.koor2[s.ust],"x");
					putpixel(s.koor1[s.ust],s.koor2[s.ust],2);
					x = s.koor1[s.ust];
					y = s.koor2[s.ust];
				}
				else{
					outtextxy(s.koor1[s.ust],s.koor2[s.ust],"x");
					putpixel(s.koor1[s.ust],s.koor2[s.ust],2);
					deger+=5;
				}
				bombakontrol=0;
				break;
			}
			case 80:
			{
				
				y+=5;
				s.ust++;
				if(y+5==395  )y-=5;
				s.koor1[s.ust] = x;
				s.koor2[s.ust] = y;
				
				for(int i=0;i<300;i++){
					if((s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]+1) || (s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]+2) || (s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]+3) || (s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]+4) || (s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]+5)){
						bombakontrol=1;
						outtextxy(540,295,"HASAR ALDI");
					}
				}
				if(bombakontrol==1){
					Sleep(1000);
					kontrol++;
					if(kontrol==1)
					{
						s.ust -= 3;
						deger-=30;
					}
					else if(kontrol==2)
					{
						s.ust -= 5;
						deger-=70;
					}
					else
					{
						a = 1;
						deger-=200;
					}
					outtextxy(s.koor1[s.ust],s.koor2[s.ust],"x");
					putpixel(s.koor1[s.ust],s.koor2[s.ust],2);
					x = s.koor1[s.ust];
					y = s.koor2[s.ust];
				}
				else{
					outtextxy(s.koor1[s.ust],s.koor2[s.ust],"x");
					putpixel(s.koor1[s.ust],s.koor2[s.ust],2);
					deger+=5;
				}
				bombakontrol=0;
				break;
			}
			case 75:
			{
				
				x-=5;
				if(x==50)x+=5;
				s.ust++;
				s.koor1[s.ust] = x;
				s.koor2[s.ust] = y;
				
				for(int i=0;i<300;i++){
					if((s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0]-1 && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0]-2 && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0]-3 && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0]-4 && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0]-5 && s.koor2[s.ust]==bomxy[i][1])){
						bombakontrol=1;
						outtextxy(540,295,"HASAR ALDI");
					}
				}
				if(bombakontrol==1){
					Sleep(1000);
					kontrol++;
					if(kontrol==1)
					{
						s.ust -= 3;
						deger-=30;
					}
					else if(kontrol==2)
					{
						s.ust -= 5;
						deger-=70;
					}
					else
					{
						a = 1;
						deger-=200;
					}
					outtextxy(s.koor1[s.ust],s.koor2[s.ust],"x");
					putpixel(s.koor1[s.ust],s.koor2[s.ust],2);
					x = s.koor1[s.ust];
					y = s.koor2[s.ust];
				}
				else{
					outtextxy(s.koor1[s.ust],s.koor2[s.ust],"x");
					putpixel(s.koor1[s.ust],s.koor2[s.ust],2);
					deger+=5;
				}
				bombakontrol=0;
				break;
			}
			case 77:
			{
				x+=5;
				if(x+5==500  )x-=5;
				s.ust++;
				s.koor1[s.ust] = x;
				s.koor2[s.ust] = y;
				
				for(int i=0;i<300;i++){
					if((s.koor1[s.ust]==bomxy[i][0] && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0]+1 && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0]+2 && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0]+3 && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0]+4 && s.koor2[s.ust]==bomxy[i][1]) || (s.koor1[s.ust]==bomxy[i][0]+5 && s.koor2[s.ust]==bomxy[i][1])){
						bombakontrol=1;
						outtextxy(540,295,"HASAR ALDI");
					}
				}
				if(bombakontrol==1){
					Sleep(1000);
					kontrol++;
					if(kontrol==1)
					{
						s.ust -= 3;
						deger-=30;
					}
					else if(kontrol==2)
					{
						s.ust -= 5;
						deger-=70;
					}
					else
					{
						a = 1;
						deger-=200;
					}
					outtextxy(s.koor1[s.ust],s.koor2[s.ust],"x");
					putpixel(s.koor1[s.ust],s.koor2[s.ust],2);
					x = s.koor1[s.ust];
					y = s.koor2[s.ust];
				}
				else{
					outtextxy(s.koor1[s.ust],s.koor2[s.ust],"x");
					putpixel(s.koor1[s.ust],s.koor2[s.ust],2);
					deger+=5;
				}
				bombakontrol=0;
				break;
			}
				default:
				break;
		}
	
	sprintf(sayi,"%d",deger);//puan
	outtextxy(540,235,sayi);
		
	q.on++;
	q.kor1[q.on]=x;
	q.kor2[q.on]=y;
	
	if(rast==0){
		if( (limx+5==x && limy==y) || (limx+5==x && limy+1==y) || (limx+5==x && limy+2==y) || (limx+5==x && limy+3==y) || (limx+5==x && limy+4==y) || (limx+5==x && limy+5==y) ){
			a=1;
			sonuc=0;
		}
	}
	else{
		if( (limx==x && limy+5==y) || (limx+1==x && limy+5==y) || (limx+2==x && limy+5==y) || (limx+3==x && limy+5==y) || (limx+4==x && limy+5==y) || (limx+5==x && limy+5==y) ){
			a=1;
			sonuc=0;
		}
	}
	}
		 	a=0;
		 	x=490;
			y=385;
			if(sonuc==0){
				outtextxy(540,275,"KAZANDINIZ");
			}
			else outtextxy(540,275,"KAYBETTINIZ");
			
			outtextxy(540,155,"->");
			int c=1,basla2;
			while(c!=0){
			cleardevice();
			rectangle(500,400,50,50);
			rectangle(655,400,505,50);
			outtextxy(545,55,"TITANIC");
			outtextxy(540,95,"YENI OYUN");
			outtextxy(540,115,"CIKIS");
			outtextxy(540,155,"TEKRAR");
			outtextxy(540,175,"OYUN SONU");
			outtextxy(540,215,"PUAN");
			outtextxy(540,255,"DURUM");
			outtextxy(540,275,"...");
			outtextxy(540,235,sayi);
			
			rectangle(500,450,50,405);
			outtextxy(202,410," UÐURCAN SORUÇ");
			outtextxy(202,430," 170106206053 ");
		
			if(sonuc==0){
				outtextxy(540,275,"KAZANDIN");
			}
			else outtextxy(540,275,"KAYBETTIN");
			basla2=getch();
			switch(basla2){
				case 72:{
					outtextxy(520,155,"->");
					basla2=getch();
					if(basla2==13){
					while(q.son!=q.on)
					{
					q.son++;
					cleardevice();
					rectangle(500,400,50,50);
					outtextxy(540,235,sayi);
					outtextxy(limx,limy,"L");
					outtextxy(q.kor1[q.son],q.kor2[q.son],"x");
					outtextxy(520,155,"->");
					rectangle(655,400,505,50);
					outtextxy(545,55,"TITANIC");
					outtextxy(540,95,"YENI OYUN");
					outtextxy(540,115,"CIKIS");
					outtextxy(540,155,"TEKRAR");
					outtextxy(540,175,"OYUN SONU");
					outtextxy(540,215,"PUAN");
					outtextxy(540,255,"DURUM");
					outtextxy(540,275,"...");
					
					rectangle(500,450,50,405);
					outtextxy(202,410," UÐURCAN SORUÇ");
					outtextxy(202,430," 170106206053 ");
		
					if(sonuc==0){
					outtextxy(540,275,"KAZANDIN");
					}
					else outtextxy(540,275,"KAYBETTIN");
					Sleep(50);
					}
					q.son=0;
						
					}
					break;
				}
				case 80:{
					outtextxy(520,175,"->");
					basla2=getch();
					if(basla2==13)c=0;
					break;
				}
				default:
			    break;
			}
			
		}		
					
				}
				
				
				break;
			}
			case 80:{
				outtextxy(520,115,"->");
				basla=getch();
				if(basla==13)b=0;  
				break;
			}
			
			default:
				break;
		}
	}
	
	
	
	

getch();
closegraph(); //grafik ekraný kapat 

return 0;  
}
