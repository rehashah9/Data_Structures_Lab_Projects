//task - create a linked list real-life applications
//MULTI GAMES - CHECKERS, TICTACTOE, SNAKES AND LADDERS, TREASURE HUNT

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

//structure to store player data
struct player
{
    int p_no;
    char name[40];
    int points;
};

//linked list-node structure
struct node
{
    struct player data;
    struct node* link;
};

//declaring some global variables
struct node* start;
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

//REHA

//function to create new node
struct node* new_node(char name[],int p)
{
    struct node* t;
    t=start;
    if(t!=NULL)
    {
        while(t->link!=NULL)
            t=t->link;
        t->link=(struct node*)malloc(sizeof(struct node));
        t->link->data=(struct player){.p_no=(t->data.p_no+1),.name=" ",.points=p};
        strcpy(t->link->data.name,name);
        t->link->link=NULL;
        t=t->link;
    }
    else
    {
        start=(struct node*)malloc(sizeof(struct node));
        start->data=(struct player){.p_no=1,.name=" ",.points=p};
        strcpy(start->data.name,name);
        start->link=NULL;
        t=start;
    }
    return t;
}

void ch_display(char a[8][8])
{
    printf("    y^ x-> 1   2   3   4   5   6   7   8\n");
    printf("     |   _________________________________                            If you want to end the game or the game ends:\n");
    printf("	1| %c | %c | %c | %c | %c | %c | %c | %c |                              Enter x or y or both as 0.\n",a[0][0],a[0][1],a[0][2],a[0][3],a[0][4],a[0][5],a[0][6],a[0][7]);
    printf("	 |___|___|___|___|___|___|___|___|\n");
    printf("	2| %c | %c | %c | %c | %c | %c | %c | %c |\n",a[1][0],a[1][1],a[1][2],a[1][3],a[1][4],a[1][5],a[1][6],a[1][7]);
    printf("	 |___|___|___|___|___|___|___|___|\n");
    printf("	3| %c | %c | %c | %c | %c | %c | %c | %c |\n",a[2][0],a[2][1],a[2][2],a[2][3],a[2][4],a[2][5],a[2][6],a[2][7]);
    printf("	 |___|___|___|___|___|___|___|___|\n");
    printf("	4| %c | %c | %c | %c | %c | %c | %c | %c |\n",a[3][0],a[3][1],a[3][2],a[3][3],a[3][4],a[3][5],a[3][6],a[3][7]);
    printf("	 |___|___|___|___|___|___|___|___|                                Points:\n");
    printf("	5| %c | %c | %c | %c | %c | %c | %c | %c |                        Winner: +20\n",a[4][0],a[4][1],a[4][2],a[4][3],a[4][4],a[4][5],a[4][6],a[4][7]);
    printf("	 |___|___|___|___|___|___|___|___|                                Loser: -5\n");
    printf("	6| %c | %c | %c | %c | %c | %c | %c | %c |\n",a[5][0],a[5][1],a[5][2],a[5][3],a[5][4],a[5][5],a[5][6],a[5][7]);
    printf("	 |___|___|___|___|___|___|___|___|\n");
    printf("	7| %c | %c | %c | %c | %c | %c | %c | %c |\n",a[6][0],a[6][1],a[6][2],a[6][3],a[6][4],a[6][5],a[6][6],a[6][7]);
    printf("	 |___|___|___|___|___|___|___|___|\n");
    printf("	8| %c | %c | %c | %c | %c | %c | %c | %c |\n",a[7][0],a[7][1],a[7][2],a[7][3],a[7][4],a[7][5],a[7][6],a[7][7]);
    printf("	 |___|___|___|___|___|___|___|___|\n");
}

struct node* checkp(char nm[])
{
    struct node* t;
    t=start;
    if(t==NULL)
        return t;
    while(strcmp(t->data.name,nm)!=0)
    {
        t=t->link;
        if(t==NULL)
            return t;
    }
    return t;
}

void checkers()
{
    system("cls");
    printf("WELCOME TO CHECKERS!\n");
    char name1[40],name2[40];
    char a[8][8] = {{' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ','1','2',' ',' ',' '},
    {' ',' ',' ','2','1',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '}};
    int yt=1,turn=49,x,y,co,co1,i,j,po1=0,po2=0;
    //getting name of player 1 and creating/accessing node that stores that users info
    printf("\nEnter name of player 1 (only first 39 characters considered): ");
    scanf("%39s",name1);
    struct node* p1;
    p1=checkp(name1);
    if(p1!=NULL)
        printf("Welcome back %s, your current point score is: %d\n",name1,p1->data.points);
    else
    {
        p1=new_node(name1,0);
        printf("Welcome!! You are our newest member and you start with 0 points!\n");
    }
    //getting name of player 2 and creating/accessing node that stores that users info
    printf("\nEnter name of player 2 (only first 39 characters considered): ");
    scanf("%39s",name2);
    struct node* p2;
    p2=checkp(name2);
    if(p2!=NULL)
        printf("Welcome back %s, your current point score is: %d\n",name2,p2->data.points);
    else
    {
        p2=new_node(name2,0);
        printf("Welcome!! You are our newest member and you start with 0 points!\n");
    }
    printf("\nPress any key to start the game.");
    getch();
    //actual game code
    while(yt)
    {
        system("cls");
        printf("CHECKERS GAME\n\n");
        printf("Player 1: %s\nPlayer 2: %s\n\n",name1,name2);
        ch_display(a);
        printf("\nturn of player %d: \n",turn-48);
        //input for position to put next piece
        do
        {
            //taking input until the position exists and is empty
            do
            {
                printf("enter x and y for box you want:\nx(1-8): ");
                scanf("%d",&x);
                printf("\ny(1-8): ");
                scanf("%d",&y);
                if((x==0)||(y==0))
                {
                    yt=0;
                    break;
                }
            }while((x>8)||(x<=0)||(y>8)||(y<=0)||(a[(y-1)%9][(x-1)%9]!=' '));
            //game ends if x or y are 0
            if(yt==0)
                break;
            //checking if any conversions happen with that place and if yes, doing those conversions
            co1=0;
            if(y!=1)
            {
                if(a[y-2][x-1]==(((turn-48)%2)+49))
                {
                    co=0;
                    for(i=y-3;i>=0;i--)
                    {
                        if(a[i][x-1]==(char)turn)
                        {
                            co=1;
                            co1=1;
                            break;
                        }
                    }
                    if(co==1)
                    {
                        for(i;i<=y-2;i++)
                            a[i][x-1]=(char)turn;
                    }
                }
            }
            if(y!=8)
            {
                if(a[y][x-1]==(char)(((turn-48)%2)+49))
                {
                    co=0;
                    for(i=y+1;i<=7;i++)
                    {
                        if(a[i][x-1]==(char)turn)
                        {
                            co=1;
                            co1=1;
                            break;
                        }
                    }
                    if(co==1)
                    {
                        for(i;i>=y;i--)
                            a[i][x-1]=(char)turn;
                    }
                }
            }
            if(x!=1)
            {
                if(a[y-1][x-2]==(char)(((turn-48)%2)+49))
                {
                    co=0;
                    for(i=x-3;i>=0;i--)
                    {
                        if(a[y-1][i]==(char)turn)
                        {
                            co=1;
                            co1=1;
                            break;
                        }
                    }
                    if(co==1)
                    {
                        for(i;i<=x-2;i++)
                            a[y-1][i]=(char)turn;
                    }
                }
            }
            if(x!=8)
            {
                if(a[y-1][x]==(char)(((turn-48)%2)+49))
                {
                    co=0;
                    for(i=x+1;i<=7;i++)
                    {
                        if(a[y-1][i]==(char)turn)
                        {
                            co=1;
                            co1=1;
                            break;
                        }
                    }
                    if(co==1)
                    {
                        for(i;i>=x;i--)
                            a[y-1][i]=(char)turn;
                    }
                }
            }
        }while(co1==0);
        a[y-1][x-1]=(char)turn;
        turn=((turn-48)%2)+49;
    }
    system("cls");
    printf("CHECKERS GAME\n\n");
    printf("Player 1: %s\nPlayer 2: %s\n\n",name1,name2);
    ch_display(a);
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(a[i][j]=='1')
                po1+=1;
            else if(a[i][j]=='2')
                po2+=1;
        }
    }
    if(po1>po2)
    {
        p1->data.points+=20;
        p2->data.points-=5;
        printf("\n%s won!!\n%s gets 20 more points and %s loses 5 points..\nSo, now, points:\n%s: %d\n%s: %d",name1,name1,name2,name1,p1->data.points,name2,p2->data.points);
    }
    else if(po2>po1)
    {
        p1->data.points-=5;
        p2->data.points+=20;
        printf("\n%s won!!\n%s gets 20 more points and %s loses 5 points..\nSo, now, points:\n%s: %d\n%s: %d",name2,name2,name1,name2,p2->data.points,name1,p1->data.points);
    }
    else
        printf("Its a draw!!\nSo, no change in score of either player:\n%s: %d\n%s: %d",name1,p1->data.name,name2,p2->data.name);
    printf("\n\npress any key to go back to main page.");
    getch();
    system("cls");
}


void main()
{
    //declaring variables
    int f=1,choice;
    //accessing file where user data is stored and putting it in the linked list
    FILE* fr;
    fr=fopen("C:/Users/Admin/Documents/PDEU/Academics/Semester 3/Data Structures/Lab/User Data","r");
    start=(struct node*)malloc(sizeof(struct node));
    struct node* p;
    struct node* q;
    p=start;
    q=p;
    while(fscanf(fr,"%d %s %d\n",&p->data.p_no,p->data.name,&p->data.points)!=EOF)
    {
        p->link=(struct node*)malloc(sizeof(struct node));
        q=p;
        p=p->link;
    }
    if(p==start)
        start=NULL;
    q->link=NULL;
    free(p);
    p=NULL;
    //actual application
    while(f==1)
    {
        printf("Welcome to MANY GAMES !!\n");
        printf("\nChoose any one of these games:\n1.Treasure Hunt\n2.Checkers\n3.Snakes and Ladders\n4.Tic Tac Toe\n5.leave application\n\nNOTE: Point system and User data storage system not available in treasure hunt currently.\n\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1)
            treasure_hunt();
        else if(choice==2)
            checkers();
        else if(choice==3)
            snake();
        else if(choice==4)
            tictactoe();
        else if(choice==5)
            f=0;
        else
            printf("invalid choice\n");
    }
    printf("\nUser Data in system currently:\n\n");
    FILE* fw;
    fw=fopen("C:/Users/Admin/Documents/PDEU/Academics/Semester 3/Data Structures/Lab/User Data","w");
    p=start;
    while(p!=NULL)
    {
        fprintf(fw,"%d %s %d\n",p->data.p_no,p->data.name,p->data.points);
        printf("%d %s %d\n",p->data.p_no,p->data.name,p->data.points);
        p=p->link;
    }
    fclose(fr);
    fclose(fw);
    printf("\nHOPE YOU HAD FUN!!\n");
}

//KRUPA AND MISARI

//function to roll dice
int rd()
{
	int rem;
	A:rem=rand()%7;
	if(rem==0)
		goto A;
	else
		return rem;
}

//function to display board
void displaychart(int curp,char player[4],struct node* p1,struct node* p2)
{	int i,j,t,c,sft=0,diceres,pos1,pos2,f=1;
		if(curp==100)
		{
			printf("Congratulations!!!!!! \n\nPlayer %s wins\n",player);
			if(player=='1')
            {
                p1->data.points+=20;
                p2->data.points-=5;
                printf("\n%s gets 20 more points and %s loses 5 points..\nSo, now, points:\n%s: %d\n%s: %d",p1->data.name,p2->data.name,p1->data.name,p1->data.points,p2->data.name,p2->data.points);
            }
            else
            {
                p2->data.points+=20;
                p1->data.points-=5;
                printf("\n%s gets 20 more points and %s loses 5 points..\nSo, now, points:\n%s: %d\n%s: %d",p2->data.name,p1->data.name,p2->data.name,p2->data.points,p1->data.name,p1->data.points);
            }
            scanf("%*s");
            f=0;
        }
    if(f==1)
    {
	for(i=10;i>0;i--)
	{
		t=i-1;
		if((sft%2)==0)
		{
			c=0;
			for(j=10;j>=1;j--)
			{
				diceres=(i*j)+(t*c++);
				if(curp==diceres)
					printf("%s\t",player);
				else
				printf("%d\t",diceres);
			}
			sft++;
		}
		else
		{
			c=9;
			for(j=1;j<=10;j++)
			{
				diceres=(i*j)+(t*c--);
				if(curp==diceres)
					printf("%s\t",player);
				else
					printf("%d\t",diceres);
			}
			sft++;
		}
		printf("\n\n");
	}
        printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    }
}


//snakes and ladders game
void snake()
{
    system("cls");
    char mark,name1[40],name2[40];
    //getting name of player 1 and creating/accessing node that stores that users info
    printf("\nEnter name of player 1 (only first 39 characters considered): ");
    scanf("%39s",name1);
    struct node* p1;
    p1=checkp(name1);
    if(p1!=NULL)
        printf("Welcome back %s, your current point score is: %d\n",name1,p1->data.points);
    else
    {
        p1=new_node(name1,0);
        printf("Welcome!! You are our newest member and you start with 0 points!\n");
    }
    //getting name of player 2 and creating/accessing node that stores that users info
    printf("\nEnter name of player 2 (only first 39 characters considered): ");
    scanf("%39s",name2);
    struct node* p2;
    p2=checkp(name2);
    if(p2!=NULL)
        printf("Welcome back %s, your current point score is: %d\n",name2,p2->data.points);
    else
    {
        p2=new_node(name2,0);
        printf("Welcome!! You are our newest member and you start with 0 points!\n");
    }
    printf("\nPress any key to start the game.");
    getch();
    system("cls");
	int i,dice,cpos1=0,cpos2=0,l=1;
	char ch;
	while(l)
	{
		printf("Snakes: | 25 to 9  | 65 to 40 | 99 to 1  |\nLadder: | 13 to 42 | 60 to 83 | 70 to 93 |\n\n");
		printf("Choose your option\n");
		printf("[1] Player 1 plays\n");
		printf("[2] Player 2 plays\n");
		printf("[3] Exit\n");
		scanf("%s",&ch);

		switch(ch)
		{

			case '1':dice=rd();
                    system("cls");
                    printf("\n\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
                    printf("\t\t\t    Snakes And Ladders\n");
                    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
					cpos1=dice+cpos1;
					if(cpos1<101){
						if(cpos1==99)
                            displaychart(1,"-P1-",p1,p2);//snake
						if(cpos1==65)
                            displaychart(40,"-P1-",p1,p2);//snake
						if(cpos1==25)
                            displaychart(9,"-P1-",p1,p2);//snake
						if(cpos1==70)
                            displaychart(93,"-P1-",p1,p2);//ladder
						if(cpos1==60)
                            displaychart(83,"-P1-",p1,p2);//ladder
						if(cpos1==13)
                            displaychart(42,"-P1-",p1,p2);//ladder
						else
							displaychart(cpos1,"-P1-",p1,p2);
                        printf("\t\t\t\tDice = %d\n",dice);
                        printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
					}
					else{
						cpos1=cpos1-dice;
						printf("Range exceeded of Player 1.\n");
						displaychart(cpos1,"-P1-",p1,p2);
					}
					printf("P2 is at %d\n\n",cpos2);

				break;
			case '2':dice=rd();
                    system("cls");
                    printf("\n\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
                    printf("\t\t\t    Snakes And Ladders\n");
                    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
					cpos2=dice+cpos2;
					if(cpos2<101){
						if(cpos2==99)	//snake
                            displaychart(1,"-P2-",p1,p2);
						if(cpos2==65)	//snake
                            displaychart(40,"-P2-",p1,p2);
						if(cpos2==25)	//snake
                            displaychart(9,"-P2-",p1,p2);
						if(cpos2==70)	//ladder
                            displaychart(93,"-P2-",p1,p2);
						if(cpos2==60)	//ladder
                            displaychart(83,"-P2-",p1,p2);
						if(cpos2==13) 	//ladder
                            displaychart(42,"-P2-",p1,p2);
						else
							displaychart(cpos2,"-P2-",p1,p2);
						printf("\t\t\t\tDice = %d\n",dice);
						printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
					}

					else{
						cpos2=cpos2-dice;
						printf("Range exceeded of Player 2.\n");
						displaychart(cpos2,"-P2-",p1,p2);
					}
					printf("P 1 is at %d\n\n",cpos1);
				break;
			case '3':l=0;
				break;

			default:printf("Choice is incorrect, Please Try Again:)\n");

		}

	}
}

//TANYA

//main code for treasure hunt
void treasure_hunt()
{
    system("cls");
    printf("Welcome to the hunt!\n");
    printf("Just follow the hints and collect your exciting treats.\n");
    struct nodes
    {
        char data[200];
        struct nodes* next;
    };
    /* Initialize nodes */
    struct nodes *head;
    struct nodes *one = NULL;
    struct nodes *two = NULL;
    struct nodes *three = NULL;
    struct nodes *four=NULL;
    struct nodes *five=NULL;
    struct nodes *six= NULL;
    /* Allocate memory */
    one =  malloc(sizeof(struct nodes));
    two = malloc(sizeof(struct nodes));
    three = malloc(sizeof(struct nodes));
    four= malloc(sizeof(struct nodes));
    five=malloc(sizeof(struct nodes));
    six=malloc(sizeof(struct nodes));
    /* Assign data values */
    strcpy(one->data , "if you are in a hungry mood,go herefirst and find some food");
    strcpy(two->data ," Now you are on your second clue,these go on before your shoes");
    strcpy(three->data, "If you want your teeth to shine,pick this up and spend some time");
    strcpy(four->data, "If you want to learn and grow, turn the page,get in the know");
    strcpy(five->data,"Add some colour to your days!Pick these up,you are on the way");
    strcpy(six->data, "Take a walk and step outside,this is where you go to ride");
    //displaying clues
	printf("First hint is: %s\n", (one->data));
	printf("Second hint is: %s\n", (two->data));
	printf("Third hint is: %s\n", (three->data));
	printf("Fourth hint is: %s\n", (four->data));
	printf("Fifth hint is: %s\n", (five->data));
	printf("Sixth hint is: %s\n", (six->data));
	printf("\n\npress any key to exit.");
	getch();
	system("cls");
}

//VRUNDA

//main part of code of tictactoe
void tictactoe()
{
    system("cls");
    //declaring most variables
    int player = 1, i, choice;
    char mark,name1[40],name2[40];;
    //getting name of player 1 and creating/accessing node that stores that users info
    printf("\nEnter name of player 1 (only first 39 characters considered): ");
    scanf("%39s",name1);
    struct node* p1;
    p1=checkp(name1);
    if(p1!=NULL)
        printf("Welcome back %s, your current point score is: %d\n",name1,p1->data.points);
    else
    {
        p1=new_node(name1,0);
        printf("Welcome!! You are our newest member and you start with 0 points!\n");
    }
    //getting name of player 2 and creating/accessing node that stores that users info
    printf("\nEnter name of player 2 (only first 39 characters considered): ");
    scanf("%39s",name2);
    struct node* p2;
    p2=checkp(name2);
    if(p2!=NULL)
        printf("Welcome back %s, your current point score is: %d\n",name2,p2->data.points);
    else
    {
        p2=new_node(name2,0);
        printf("Welcome!! You are our newest member and you start with 0 points!\n");
    }
    printf("\nPress any key to start the game.");
    getch();
    //actual game code
    do
    {
        board();
        printf("Information:\nPlayer 1 (X): %s\nPlayer 2 (O): %s\n\nPoint distribution:\nWinner: +20\nLoser: -5\nDraw: +0 for both\n\n",name1,name2);
        player = (player % 2) ? 1 : 2;
        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("Invalid move. Please press ant key!!");

            player--;player = (player % 2) ? 1 : 2;
            getch();
        }
        i = checkwin();
        player++;
    }while (i ==  - 1);
    board();
    if (i == 1)
    {
        printf("==>\aPlayer %d win\n", --player);
        if(player==1)
        {
            p1->data.points+=20;
            p2->data.points-=5;
            printf("\n%s gets 20 more points and %s loses 5 points..\nSo, now, points:\n%s: %d\n%s: %d",name1,name2,name1,p1->data.points,name2,p2->data.points);
        }
        else
        {
            p2->data.points+=20;
            p1->data.points-=5;
            printf("\n%s gets 20 more points and %s loses 5 points..\nSo, now, points:\n%s: %d\n%s: %d",name2,name1,name2,p2->data.points,name1,p1->data.points);
        }
    }
    else
    {
        printf("==>\aGame draw\n");
        printf("\nSo, no change in score of either player:\n%s: %d\n%s: %d",name1,p1->data.name,name2,p2->data.name);
    }
    printf("\n\nPress any key to go back to home page.");
    getch();
    system("cls");
}

//function to check who won
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;   //1 FOR GAME IS OVER WITH RESULT

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;                                                    //O GAME IS OVER AND NO RESULT
    else
        return  - 1;                                                 //-1 FOR GAME IS IN PROGRESS
}

//function to print board
void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("     |     |     \n\n");
}
