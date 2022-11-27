//task - create a program that uses queue with real-life applications
//LUDO

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct player
{
    char name[60];
    int pos[4];
    int start;
    char s[6][3];
    int score;
    char home[4][3];
};

//Enqueue Dequeue
void enqueue(int a[4],int fr[2],int n)
{
    int front=fr[0];
    int rear=fr[1];
    if(front!=(rear+1)%4)
    {
        if (front==-1)
            fr[0]=0;
        fr[1]=(++rear)%4;
        a[fr[1]]=n;
    }
}

int dequeue(int a[4],int fr[2])
{
    int front=fr[0];
    int rear=fr[1];
    int n;
    if(front==rear==-1)
        return(0);
    n=a[front];
    if (front==rear)
    {
        fr[0]=-1;
        fr[1]=-1;
    }
    else
        fr[0]=(front+1)%4;
    return(n);
}

//displaying game board
void display(struct player p[],char a[52][3])
{
    printf("LUDO!!!\n\n");
    printf("	 __________________________________________________________________________                        format of each piece numbering:\n");
    printf("	|       Player  1       |   %s   |   %s   |   %s   |       Player  2       |                       <player number><piece number>\n",a[10],a[11],a[12]);
    printf("	|   ______     ______   |________|________|________|   ______     ______   |                       <player number>* means 2 pieces\n");
    printf("	|  |      |   |      |  |   %s   |   %s   |   %s   |  |      |   |      |  |                       <player number># means 3 pieces\n",a[9],p[1].s[0],a[13]);
    printf("	|  |  %s  |   |  %s  |  |________|________|________|  |  %s  |   |  %s  |  |                       <player number>$ means 4 pieces\n",p[0].home[0],p[0].home[1],p[1].home[0],p[1].home[1]);
    printf("	|  |______|   |______|  |   %s   |   %s   |   %s   |  |______|   |______|  |\n",a[8],p[1].s[1],a[14]);
    printf("	|                       |________|________|________|                       |                       Player 1: %s\n",p[0].name);
    printf("	|   ______     ______   |   %s   |   %s   |   %s   |   ______     ______   |                       Player 2: %s\n",a[7],p[1].s[2],a[15],p[1].name);
    printf("	|  |      |   |      |  |________|________|________|  |      |   |      |  |                       Player 3: %s\n",p[2].name);
    printf("	|  |  %s  |   |  %s  |  |   %s   |   %s   |   %s   |  |  %s  |   |  %s  |  |                       Player 4: %s\n",p[0].home[2],p[0].home[3],a[6],p[1].s[3],a[16],p[1].home[2],p[1].home[3],p[3].name);
    printf("	|  |______|   |______|  |________|________|________|  |______|   |______|  |\n");
    printf("	|                       |   %s   |   %s   |   %s   |                       |\n",a[5],p[1].s[4],a[17]);
    printf("	|_______________________|________|________|________|_______________________|\n");
    printf("	|   |   |   |   |   |   |        |   %s   |        |   |   |   |   |   |   |\n",p[1].s[5]);
    printf("	|%s |%s |%s |%s |%s |%s |        |________|        |%s |%s |%s |%s |%s |%s |\n",a[51],a[0],a[1],a[2],a[3],a[4],a[18],a[19],a[20],a[21],a[22],a[23]);
    printf("	|___|___|___|___|___|___|____                  ____|___|___|___|___|___|___|\n");
    printf("	|   |   |   |   |   |   |    |                |    |   |   |   |   |   |   |\n");
    printf("	|%s |%s |%s |%s |%s |%s | %s |      LUDO      | %s |%s |%s |%s |%s |%s |%s |\n",a[50],p[0].s[0],p[0].s[1],p[0].s[2],p[0].s[3],p[0].s[4],p[0].s[5],p[2].s[5],p[2].s[4],p[2].s[3],p[2].s[2],p[2].s[1],p[2].s[0],a[24]);
    printf("	|___|___|___|___|___|___|____|                |____|___|___|___|___|___|___|\n");
    printf("	|   |   |   |   |   |   |         ________         |   |   |   |   |   |   |\n");
    printf("	|%s |%s |%s |%s |%s |%s |        |   %s   |        |%s |%s |%s |%s |%s |%s |\n",a[49],a[48],a[47],a[46],a[45],a[44],p[3].s[5],a[30],a[29],a[28],a[27],a[26],a[25]);
    printf("	|___|___|___|___|___|___|________|________|________|___|___|___|___|___|___|\n");
    printf("	|       Player  4       |   %s   |   %s   |   %s   |       Player  3       |\n",a[43],p[3].s[4],a[31]);
    printf("	|   ______     ______   |________|________|________|   ______     ______   |\n");
    printf("	|  |      |   |      |  |   %s   |   %s   |   %s   |  |      |   |      |  |\n",a[42],p[3].s[3],a[32]);
    printf("	|  |  %s  |   |  %s  |  |________|________|________|  |  %s  |   |  %s  |  |\n",p[3].home[0],p[3].home[1],p[2].home[0],p[2].home[1]);
    printf("	|  |______|   |______|  |   %s   |   %s   |   %s   |  |______|   |______|  |\n",a[41],p[3].s[2],a[33]);
    printf("	|                       |________|________|________|                       |\n");
    printf("	|   ______     ______   |   %s   |   %s   |   %s   |   ______     ______   |\n",a[40],p[3].s[1],a[34]);
    printf("	|  |      |   |      |  |________|________|________|  |      |   |      |  |\n");
    printf("	|  |  %s  |   |  %s  |  |   %s   |   %s   |   %s   |  |  %s  |   |  %s  |  |\n",p[3].home[2],p[3].home[3],a[39],p[3].s[0],a[35],p[2].home[2],p[2].home[3]);
    printf("	|  |______|   |______|  |________|________|________|  |______|   |______|  |\n");
    printf("	|                       |   %s   |   %s   |   %s   |                       |\n",a[38],a[37],a[36]);
    printf("	|_______________________|________|________|________|_______________________|\n");
    printf("\n");
}

void main()
{
    //player structure object for 4 players
    struct player p[4]={{.name="-",.pos={-1,-1,-1,-1},.start=-1,.s={"  ","  ","  ","  ","  ","  "},.score=0,.home={"11","12","13","14"}},
    {.name="-",.pos={-1,-1,-1,-1},.start=12,.s={"  ","  ","  ","  ","  ","  "},.score=0,.home={"21","22","23","24"}},
    {.name="-",.pos={-1,-1,-1,-1},.start=25,.s={"  ","  ","  ","  ","  ","  "},.score=0,.home={"31","32","33","34"}},
    {.name="-",.pos={-1,-1,-1,-1},.start=38,.s={"  ","  ","  ","  ","  ","  "},.score=0,.home={"41","42","43","44"}}};
    printf("LUDO!!!\n\n");
    //declaring variables
    int i,n,queue[4]={0,0,0,0},win=0,fr[2]={-1,-1},cur_p,g,roll,piece,end[4]={0,0,0,0},efr[2]={-1,-1},pos,start;
    char element[3]="  ",a[52][3]={"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},name[60];
    //input for number of players
    do
    {
    printf("Enter the number of players(2 or 3 or 4): ");
    scanf("%d",&n);}while((n<2)||(n>4));
    //enqueue players
    for(i=0;i<n;i++)
    {
        printf("Enter the name of player %d:",i+1);
        scanf("%s",name);
        strcpy(p[i].name,name);
        enqueue(queue,fr,i+1);
    }
    //game
    srand(time(NULL));
    while(win<n-1)
    {
        //dequeuing current player
        cur_p=dequeue(queue,fr);
        element[0]=(char)(cur_p+48);
        g=1;
        //loop to ensure that if a player rolls a six or kills another players piece then they get another turn
        while(g==1)
        {
            printf("press any key to continue.");
            getch();
            system("cls");
            display(p,a);
            //dice roll
            printf("%s's turn, press any key to roll the dice\n",p[cur_p-1].name);
            getch();
            roll=(rand()%6)+1;
            printf("you rolled a %d\n",roll);
            //if all pieces in home and roll is not 6
            if(((p[cur_p-1].pos[0]==-1)||(p[cur_p-1].pos[0]==57))&&((p[cur_p-1].pos[1]==-1)||(p[cur_p-1].pos[1]==57))&&((p[cur_p-1].pos[2]==-1)||(p[cur_p-1].pos[2]==57))&&((p[cur_p-1].pos[3]==-1)||(p[cur_p-1].pos[3]==57))&&(roll!=6))
            {
                printf("no move\n");
                break;
            }
            //input for which piece to move
            do{
            printf("which piece do you want to move(please enter 1/2/3/4 and the piece should not be\nin your home if you did not roll a six): ");
            scanf("%d",&piece);}while(((piece<1)||(piece>4))||((p[cur_p-1].pos[(piece-1)%4]==-1)&&(roll!=6)));
            //if roll is more than piece can move
            if(roll+p[cur_p-1].pos[piece-1]>57)
                break;
            //discontinuing loop if roll is not 6
            if(roll!=6)
                g=0;
            //assigning new position to piece according to it's current state and clearing old position of that piece's number
            if(p[cur_p-1].pos[piece-1]==-1)
            {
                p[cur_p-1].pos[piece-1]=1;
                strcpy(p[cur_p-1].home[piece-1],"  ");
            }
            else
            {
                if(p[cur_p-1].pos[piece-1]<52)
                {
                    if(a[(p[cur_p-1].pos[piece-1]+p[cur_p-1].start)%52][1]==(char)(piece+48))
                        strcpy(a[(p[cur_p-1].pos[piece-1]+p[cur_p-1].start)%52],"  ");
                    else if(a[(p[cur_p-1].pos[piece-1]+p[cur_p-1].start)%52][1]=='*')
                        for(i=0;i<4;i++)
                        {
                            if((i!=piece-1)&&(p[cur_p-1].pos[piece-1]==p[cur_p-1].pos[i]))
                            {
                                a[(p[cur_p-1].pos[piece-1]+p[cur_p-1].start)%52][1]=(char)(i+49);
                                break;
                            }
                        }
                    else if(a[(p[cur_p-1].pos[piece-1]+p[cur_p-1].start)%52][1]=='#')
                        a[(p[cur_p-1].pos[piece-1]+p[cur_p-1].start)%52][1]='*';
                    else if(a[(p[cur_p-1].pos[piece-1]+p[cur_p-1].start)%52][1]=='$')
                        a[(p[cur_p-1].pos[piece-1]+p[cur_p-1].start)%52][1]='#';
                }
                else if(p[cur_p-1].pos[piece-1]<57)
                {
                    if(p[cur_p-1].s[p[cur_p-1].pos[piece-1]%52][1]==(char)(piece+48))
                        strcpy(p[cur_p-1].s[p[cur_p-1].pos[piece-1]%52],"  ");
                    else if(p[cur_p-1].s[p[cur_p-1].pos[piece-1]%52][1]=='*')
                        for(i=0;i<4;i++)
                        {
                            if((i!=piece-1)&&(p[cur_p-1].pos[piece-1]==p[cur_p-1].pos[i]))
                            {
                                p[cur_p-1].s[p[cur_p-1].pos[piece-1]%52][1]=(char)(i+49);
                                break;
                            }
                        }
                    else if(p[cur_p-1].s[p[cur_p-1].pos[piece-1]%52][1]=='#')
                        p[cur_p-1].s[p[cur_p-1].pos[piece-1]%52][1]='*';
                    else if(p[cur_p-1].s[p[cur_p-1].pos[piece-1]%52][1]=='$')
                        p[cur_p-1].s[p[cur_p-1].pos[piece-1]%52][1]='#';
                }
                p[cur_p-1].pos[piece-1]+=roll;
            }
            pos=p[cur_p-1].pos[piece-1];
            element[1]=(char)(piece+48);
            //updating special positions of particular player if the piece enters that queue
            if(pos>=52)
            {
                if(p[cur_p-1].s[pos%52][0]==' ')
                    strcpy(p[cur_p-1].s[pos%52],element);
                else if(p[cur_p-1].s[pos%52][1]=='*')
                    p[cur_p-1].s[pos%52][1]='#';
                else if(p[cur_p-1].s[pos%52][1]=='#')
                    p[cur_p-1].s[pos%52][1]='$';
                else
                    p[cur_p-1].s[pos%52][1]='*';
                if(pos==57)
                {
                    p[cur_p-1].score+=1;
                    if(p[cur_p-1].score==4)
                        g=0;
                }
            }
            //updating the common positions queue
            else
            {
                start=p[cur_p-1].start;
                if(a[(pos+start)%52][0]==' ')
                    strcpy(a[(pos+start)%52],element);
                //if a piece of same player is there in new place
                else if(a[(pos+start)%52][0]==element[0])
                {
                    if(a[(pos+start)%52][1]=='*')
                        a[(pos+start)%52][1]='#';
                    else if(a[(pos+start)%52][1]=='#')
                        a[(pos+start)%52][1]='$';
                    else
                        a[(pos+start)%52][1]='*';
                }
                //if a piece of another player is there in new place
                else
                {
                    g=1;
                    if(a[(pos+start)%52][1]=='*')
                    {
                        for(i=0;i<4;i++)
                        {
                            if((pos+start)%52==(p[(int)a[(pos+start)%52][0]-49].pos[i]+p[(int)a[(pos+start)%52][0]-49].start)%52)
                            {
                                p[(int)a[(pos+start)%52][0]-49].home[i][0]=a[(pos+start)%52][0];
                                p[(int)a[(pos+start)%52][0]-49].home[i][1]=(char)(i+49);
                                p[(int)a[(pos+start)%52][0]-49].pos[i]=-1;
                            }
                        }
                    }
                    else if(a[(pos+start)%52][1]=='#')
                    {
                        for(i=0;i<4;i++)
                        {
                            if((pos+start)%52==(p[(int)a[(pos+start)%52][0]-49].pos[i]+p[(int)a[(pos+start)%52][0]-49].start)%52)
                            {
                                p[(int)a[(pos+start)%52][0]-49].home[i][0]=a[(pos+start)%52][0];
                                p[(int)a[(pos+start)%52][0]-49].home[i][1]=(char)(i+49);
                                p[(int)a[(pos+start)%52][0]-49].pos[i]=-1;
                            }
                        }
                    }
                    else if(a[(pos+start)%52][1]=='$')
                    {
                        for(i=0;i<4;i++)
                        {
                            p[(int)a[(pos+start)%52][0]-49].home[i][0]=a[(pos+start)%52][0];
                            p[(int)a[(pos+start)%52][0]-49].home[i][1]=(char)(i+49);
                            p[(int)a[(pos+start)%52][0]-49].pos[i]=-1;
                        }
                    }
                    else
                    {
                        strcpy(p[(int)a[(pos+start)%52][0]-49].home[(int)a[(pos+start)%52][1]-49],a[(pos+start)%52]);
                        p[(int)a[(pos+start)%52][0]-49].pos[(int)a[(pos+start)%52][1]-49]=-1;
                    }
                    strcpy(a[(pos+start)%52],element);
                }
            }
        }
        //updating end queue if player has pieces at end or else enqueueing the player
        if(p[cur_p-1].score==4)
        {
            win++;
            enqueue(end,efr,cur_p);
        }
        else
            enqueue(queue,fr,cur_p);
    }
    //end of game.
    printf("Winners:\n");
    for(i=0;i<n-1;i++)
        printf("%d: %s\n",i+1,p[end[i]-1].name);
}
