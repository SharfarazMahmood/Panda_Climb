#include "iGraphics.h"
#include<stdio.h>
#include<stdlib.h>

bool start=true,highscore=false,option=false,quit=false,back=false,play= false,winner=false;
bool level1=false,level2=false,level3=false,level4=false,level5=false,pandaleft=false,pandaright=true,gameover=false;
int score=00,life=0, bombsmallx,bombsmally,shurikensmallx, shurikensmally, bombx,bomby,shurikenx, shurikeny,pandax=310,panday=0,snakex,snakey;
int resposcounter=0;
char scoreText[100],lasthighscore[100];

void bombsmall();
void bomb();
void shurikensmall();
void shuriken();

void iDraw()
{

	if(start== true)
	{//start menu
		life=0,score=0,bombsmallx=100,bombsmally=410,shurikensmallx=350, shurikensmally=600, pandax=310,panday=0,snakex,snakey;
		gameover=false;
		iClear();
		iShowBMP(0, 0, "images\\main.bmp");
		if(quit == true)
		{//quit
			exit(0);
		}
	}
	if(option== true)
	{//option
		iClear();
		iShowBMP(0, 0, "images\\option.bmp");

		iShowBMP(100, 300, "images\\arrow up.bmp");
		iShowBMP(100, 250, "images\\arrow down.bmp");
		iShowBMP(100, 200, "images\\arrow right.bmp");
		iShowBMP(100, 150, "images\\arrow left.bmp");
	}
	if(highscore == true)
	{//high score
		iClear();
		iShowBMP(0, 0, "images\\high score.bmp");

					FILE *fp;

					fp=fopen("panda climb high scores.txt","r");
					fscanf(fp,"%s",lasthighscore);
					//printf("\n",arr[i]);
					fclose(fp);
					//iText(190,250,"High Score: ",GLUT_BITMAP_HELVETICA_18);
					iText(240,255,lasthighscore,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	         //////main menu done*****
	
	if(play==true)
	{
			iClear();
			iSetColor(0,51,0);
			iShowBMP(0, 0,"images\\bamboo2.bmp");
			iShowBMP(400, 0,"images\\bamboo1.bmp");
			iShowBMP(0, 470,"images\\back.bmp");

			//for showing heart//
				if(life==0 ){
					iShowBMP(110, 470,"images\\heart.bmp");
					iShowBMP(140, 470,"images\\heart.bmp");
					iShowBMP(170, 470,"images\\heart.bmp");	
					iShowBMP(200, 470,"images\\heart.bmp");	
				}
				if(life==1){
					iShowBMP(110, 470,"images\\heart.bmp");
					iShowBMP(140, 470,"images\\heart.bmp");
					iShowBMP(170, 470,"images\\heart.bmp");	
				}
				if(life==2){
					iShowBMP(110, 470,"images\\heart.bmp");
					iShowBMP(140, 470,"images\\heart.bmp");
				}
				if(life==3){
					iShowBMP(110, 470,"images\\heart.bmp");
				}
				if(life==4){
					gameover=true;
				}
			//showing heart ddone//

			//level setting
				if(score>=0 && score<200){
					iShowBMP(210, 0,"images\\level1.bmp");
					level1=true;
					level2=false;
					level3=false;
					level4=false;
				}
				if(score>=200 && score<450){
					iShowBMP(210, 0,"images\\level2.bmp");
					level1=false;
					level2=true;
					level3=false;
					level4=false;
				}
				if(score>=450 && score<750){
					iShowBMP(210, 0,"images\\level3.bmp");
					level1=false;
					level2=false;
					level3=true;
					level4=false;
				}
				if(score>=750 && score<1100){
					iShowBMP(210, 0,"images\\level4.bmp");
					level1=false;
					level2=false;
					level3=false;
					level4=true;
				}   
			//showing score 
				iSetColor(255,255,255);
				iText(310,480,"SCORE:");
				sprintf(scoreText,"%d",score);
				iText(360,480,scoreText);
			//winner
				if(score>=900){
					winner=true;
					if(winner==true)
						iShowBMP(100, 100,"images\\winner.bmp");
				}
			//*******levels setings*******//

//////////////level 1 
				///obstacle////
				if(level1 == true  && level2==false && level3==false && level4==false)
				{
					{	
						if(bombsmally>shurikensmally-100 && bombsmally<shurikensmally){
							bombsmally-=70;
						}
						
						if(bombsmally>=shurikensmally && bombsmally<shurikensmally+100){
							bombsmally+=70;
						}
						
						if(bombsmally<=790 && bombsmally>-5){
							iShowBMP(bombsmallx,bombsmally-=1,"images//bomb small.bmp");
							bombx=bombsmallx,bomby=bombsmally-300;
							iShowBMP(bombx,bomby,"images//bomb small.bmp");
						}
						if(shurikensmally<=600 && shurikensmally>-10){
							 
							iShowBMP(shurikensmallx,shurikensmally-=1,"images//shuriken small.bmp");
							shurikenx=shurikensmallx, shurikeny=shurikensmally-300;
							iShowBMP(shurikenx,shurikeny,"images//shuriken small.bmp");
						}
					}
				}
				////panda climb
				if(pandaleft==true){
					pandax=70;
					iShowBMP(pandax,panday,"images//panda left.bmp");
				}
				else if( pandaright==true)
				{
					pandax=360;
					iShowBMP(pandax,panday,"images//panda right.bmp");
				}

				///score
				if(gameover==false){
					if(bombsmally==0) {
						score += 3;
					}
					if( shurikensmally==0){
						score +=5;
					}
				}


				
//////////////level 2 ***************
				///obstacle////
				if(level1 == false  && level2==true && level3==false && level4==false)
				{
					{	
						if(bombsmally>shurikensmally-100 && bombsmally<shurikensmally){
							bombsmally-=70;
						}
						
						if(bombsmally>=shurikensmally && bombsmally<shurikensmally+100){
							bombsmally+=70;
						}
						
						if(bombsmally<=790 && bombsmally>-5){
							iShowBMP(bombsmallx,bombsmally-=2,"images//bomb small.bmp");
							bombx=bombsmallx,bomby=bombsmally-300;
							iShowBMP(bombx,bomby,"images//bomb small.bmp");
						}
						if(shurikensmally<=600 && shurikensmally>-10){
							 
							iShowBMP(shurikensmallx,shurikensmally-=2,"images//shuriken small.bmp");
							shurikenx=shurikensmallx, shurikeny=shurikensmally-300;
							iShowBMP(shurikenx,shurikeny,"images//shuriken small.bmp");
						}
					}
				}
				////panda climb
				if(pandaleft==true){
					pandax=70;
					iShowBMP(pandax,panday,"images//panda left.bmp");
				}
				else if( pandaright==true)
				{
					pandax=360;
					iShowBMP(pandax,panday,"images//panda right.bmp");
				}

				///score
				if(gameover==false){
					if(bombsmally==0) {
						score += 3;
					}
					if( shurikensmally==0){
						score +=5;
					}
				}


//////////////level 3 ***************
				///obstacle////
				if(level1 == false  && level2==false && level3==true && level4==false)
				{
						if(bombsmally>shurikensmally-100 && bombsmally<shurikensmally){
							bombsmally-=70;
						}
						
						if(bombsmally>=shurikensmally && bombsmally<shurikensmally+100){
							bombsmally+=70;
						}
						
						if(bombsmally<=790 && bombsmally>-5){
							iShowBMP(bombsmallx,bombsmally-=2,"images//bomb small.bmp");
							bombx=bombsmallx,bomby=bombsmally-300;
							iShowBMP(bombx,bomby,"images//bomb small.bmp");
						}
						if(shurikensmally<=600 && shurikensmally>-10){
							 
							iShowBMP(shurikensmallx,shurikensmally-=2,"images//shuriken small.bmp");
							shurikenx=shurikensmallx, shurikeny=shurikensmally-300;
							iShowBMP(shurikenx,shurikeny,"images//shuriken small.bmp");
						}
				}
					
				////panda climb
				if(pandaleft==true){
					pandax=70;
					iShowBMP(pandax,panday,"images//panda left.bmp");
				}
				else if( pandaright==true)
				{
					pandax=360;
					iShowBMP(pandax,panday,"images//panda right.bmp");
				}

				///score
				if(gameover==false){
					if(bombsmally==0) {
						score += 3;
					}
					if( shurikensmally==0){
						score +=5;
					}
				}
//////////////level 4 ***************
				///obstacle////
				if(level1 == false  && level2==false && level3==false && level4==true)
				{
					{	
						if(bombsmally>shurikensmally-100 && bombsmally<shurikensmally){
							bombsmally-=70;
						}
						
						if(bombsmally>=shurikensmally && bombsmally<shurikensmally+100){
							bombsmally+=70;
						}
						
						if(bombsmally<=790 && bombsmally>-5){
							iShowBMP(bombsmallx,bombsmally-=3,"images//bomb small.bmp");
							bombx=bombsmallx,bomby=bombsmally-300;
							iShowBMP(bombx,bomby,"images//bomb small.bmp");
						}
						if(shurikensmally<=600 && shurikensmally>-10){
							 
							iShowBMP(shurikensmallx,shurikensmally-=3,"images//shuriken small.bmp");
							shurikenx=shurikensmallx, shurikeny=shurikensmally-300;
							iShowBMP(shurikenx,shurikeny,"images//shuriken small.bmp");
						}
					}
				}
				////panda climb
				if(pandaleft==true){
					pandax=70;
					iShowBMP(pandax,panday,"images//panda left.bmp");
				}
				else if( pandaright==true)
				{
					pandax=360;
					iShowBMP(pandax,panday,"images//panda right.bmp");
				}

				///score
				if(gameover==false){
					if(bombsmally==0) {
						score += 3;
					}
					if( shurikensmally==0){
						score +=5;
					}
				}		
			//*******levels setings*******//
}
				////life count/////
				if( ( panday+88 == shurikensmally)  )	{
					if (  (pandax+40 == shurikensmallx+10 || pandax+30 == shurikensmallx+40) )
						life++;
				}
				if( ( panday+88 == bombsmally  )  )	{
					if ( (pandax+40 == bombsmallx+10 || pandax+30 == bombsmallx+40) )
						life++;
				}
				if( ( panday+88 == shurikeny)  )	{
					if (  (pandax+40 == shurikenx+10 || pandax+30 == shurikenx+40) )
						life++;
				}
				if( ( panday+88 == bomby  )  )	{
					if ( (pandax+40 == bombx+10 || pandax+30 == bombx+40) )
						life++;
				}
				

	////gameover  + score ////
				if(life>=4 && gameover==true)
				{
					iClear();
					iSetColor(255,255,255);
					iText(0,480,"<<Menu",GLUT_BITMAP_TIMES_ROMAN_24);
					iText(190,300,"Game Over",GLUT_BITMAP_TIMES_ROMAN_24);
					iText(190,250,"Score: ",GLUT_BITMAP_HELVETICA_18);
					iText(250,250,scoreText,GLUT_BITMAP_HELVETICA_18);

					int lastscore,temp;

					FILE *fp;

					fp=fopen("panda climb high scores.txt","r");
					fscanf(fp,"%d",&lastscore);
					//printf("\n",arr[i]);
					fclose(fp);

					if(score >lastscore){
						lastscore=score;
					}
					fp=fopen("panda climb high scores.txt","w");
					fprintf(fp,"%d\n",lastscore);
					fclose(fp);
				}
}

void iMouse(int button, int state, int mx, int my)
{

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		if(mx> 0 && mx< 80 && my>470 && my<500 )
		{//back
			start=true,highscore=false,option=false,play=false;
		}
		if(start == true )
		{
			if( mx>80 && mx<200 && my>90 && my<130)
			{//quit
				quit=true;
			}
			if( mx>80 && mx<200 && my>130 && my<160)
			{//option
				start=false;
				play=false;
				option=true;
				quit=false;
			}
			if( mx>80 && mx<250 && my>160 && my<200)
			{//high score
				start=false;
				play=false;
				highscore=true;
				quit=false;
			}
			if(mx>80 && mx<200 && my>200&& my<235)
			{///game play
				start=false;
				play=true;
				highscore=false;
				option=false;
				quit=false;
			}
		}
	}

	printf("\n\nMouse X=%d\nMouse Y= %d",mx,my);
}
void iSpecialKeyboard(unsigned char key)
{
	//place your codes for other keys here
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	if(key == GLUT_KEY_RIGHT )	
	{
		pandaleft=false;
		pandaright=true;
	}
	if(key == GLUT_KEY_LEFT )
	{
		pandaleft=true;
		pandaright=false;
		
	}
	if(key == GLUT_KEY_UP && panday<=(500-(30+112)))	
	{	
			panday+=15;
	}
	if(key == GLUT_KEY_DOWN && panday>=1)
	{
			panday-=15;
		
	}
}
void bombsmall()
{
	int i;
	i=rand()%99+3;

	if(bombsmally<=00)
		{
			bombsmally=600;

			if(i% 3==0 /*&& bombsmallx != shurikensmallx*/)
			{
				bombsmallx=100;
			}
			else
			{
				bombsmallx=350;
			}
		}
}

void shurikensmall()
{
	int i;
	i=rand()%13;

	if(shurikensmally<=0)
	{
		shurikensmally=580;

		if(i%13==0 )
			{
				shurikensmallx=350;		
			}else
				shurikensmallx=100;
					
	}
}


void iMouseMove(int mx, int my)
{
	//place your codes here
}
void iKeyboard(unsigned char key)
{
	if(key == 's')
		{
			start=false;
			play=true;
	}
	//place your codes here
}
int main()
{
	if(start == true)
    {
	   srand(time(NULL));
	   //PlaySound("option_sound", NULL, SND_LOOP | SND_ASYNC);
    }
	iSetTimer(0,bombsmall);
	iSetTimer(0,shurikensmall);	
	iInitialize(500, 500,"Panda Climb");
	return 0;
}