//task - create a program that uses graphs with real-life applications
//TRANSPORTATION MAPPING AND BEST ROUTE RECOMMENDATION SYSTEM

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//REHA

//structure for edge nodes (each edge represents a flight)
struct edge
{
    float length;
    int time;
    int price;
    float av;
    int dest_code;
    int source_code;
    struct edge* link;
};

//method declaration
int add_loc(char[100][60], int);
int del_loc(char[100][60],int,struct edge*[]);
void upd_edge(char[100][60],int,struct edge*[]);
void add_edge(char[100][60],int,struct edge*[]);
void del_edge(char[100][60],int,struct edge*[]);
void readfile(char[100][60],int,struct edge*[]);
void writefile(char[100][60],int,struct edge*[]);
void allavail(int,int,char[100][60],int,struct edge*[]);
void shortestd(int,int,char[100][60],int,struct edge*[]);
void shortestt(int,int,char[100][60],int,struct edge*[]);
void shortestp(int,int,char[100][60],int,struct edge*[]);
void shortesta(int,int,char[100][60],int,struct edge*[]);


void main()
{
    int user,w=1,v,choice,source,destination,p_no=0,i;  //p_no is total places/locations
    char p_code[100][60]={"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
    struct edge* arr[100];
    readfile(p_code,p_no,arr);
    printf("Welcome to Airline Flight Database!!\n");
    while(w)
    {
        printf("\nInformation you require before proceeding:\nLocations and associated codes:\n");
        for(i=0;i<100;i++)
        {
            if(strcmp(p_code[i],""))
                printf("%d - %s\n",i+1,p_code[i]);
        }
        printf("\nChoose:\n1.Authorized personnel (to edit the information\n2.Customer (to see available flight details)\n3.Leave Application\nEnter your choice: ");
        scanf("%d",&user);
        if(user==1)
        {
            v=1;
            while(v)
            {
                printf("\nDo you want to:\n1.Add a location\n2.Delete a location\n3.Add a flight\n4.Delete a flight\n5.Edit details of a flight\n6.Go back to home page\nEnter choice: ");
                scanf("%d",&choice);
                if(choice==1)
                {
                    p_no=add_loc(p_code,p_no);
                }
                else if(choice==2)
                {
                    p_no=del_loc(p_code,p_no,arr);
                }
                else if(choice==3)
                {
                    add_edge(p_code,p_no,arr);
                }
                else if(choice==4)
                {
                    del_edge(p_code,p_no,arr);
                }
                else if(choice==5)
                {
                    upd_edge(p_code,p_no,arr);
                }
                else if(choice==6)
                {
                    v=0;
                }
                else
                    printf("\nChoice not available! Please try again with another choice.\n");
            }
        }
        else if(user==2)
        {
            v=1;
            while(v)
            {
                printf("\nEnter source place code: ");
                scanf("%d",&source);
                printf("\nEnter destination place code: ");
                scanf("%d",&destination);
                if((source>=1)&&(source<=100)&&(destination>=1)&&(destination<=100))
                {
                    if((strcmp(p_code[source-1],""))&&(strcmp(p_code[destination-1],"")))
                    {
                        printf("\nChoose the option you want to see:\n1.All flights available\n2.Shortest route available\n3.Cheapest route available\n4.Fastest route available\n5.Aggregated best rout available\n6.Go back to home page\nEnter choice: ");
                        scanf("%d",&choice);
                        if(choice==1)
                        {
                            allavail(source,destination,p_code,p_no,arr);
                        }
                        else if(choice==2)
                        {
                            shortestd(source,destination,p_code,p_no,arr);
                        }
                        else if(choice==3)
                        {
                            shortestp(source,destination,p_code,p_no,arr);
                        }
                        else if(choice==4)
                        {
                            shortestt(source,destination,p_code,p_no,arr);
                        }
                        else if(choice==5)
                        {
                            shortesta(source,destination,p_code,p_no,arr);
                        }
                        else if(choice==6)
                        {
                            v=0;
                        }
                        else
                            printf("\nChoice not available! Please try again with another choice.\n");
                    }
                    else
                    {
                        printf("\nProvided code(s) do(es) not exist!\n");
                        v=0;
                    }
                }
                else
                {
                    printf("\nProvided code(s) do(es) not exist!\n");
                    v=0;
                }
            }
        }
        else if(user=3)
        {
            w=0;
        }
        else
        {
            printf("\nChoice not available! Please try again with another choice.\n");
        }
    }
    writefile(p_code,p_no,arr);
}

//function to add a place/location
int add_loc(char p_code[100][60],int p_no)
{
    if(p_no==100)
    {
        printf("\nThe database cannot contain more than 100 locations at a time. Sorry.\n");
        return(p_no);
    }
    char name[60];
    printf("\nEnter name of new location(max. 60 characters): ");
    scanf("%s",name);
    int i=0;
    while(strcmp(p_code[i],""))
        i++;
    strcpy(p_code[i],name);
    printf("\n%s has been added successfully and its location code will be: %d\n",name,i+1);
    return(p_no+1);
}

//function to delete a location and all its associates flights
int del_loc(char p_code[100][60],int p_no,struct edge* arr[])
{
    if(p_no==0)
    {
        printf("\nSystem contains 0 locations so we cannot delete anything!\n");
        return(p_no);
    }
    int code;
    printf("\nenter location code of location to be deleted: ");
    scanf("%d",&code);
    if((code>=1)&&(code<=100))
    {
        if(strcmp(p_code[code-1],""))
        {
            arr[code-1]=NULL;
            int i;
            struct edge* p;
            for(i=0;i<100;i++)
            {
                p=arr[i];
                if(p==NULL)
                    continue;
                if(p->dest_code==code)
                    arr[i]=p->link;
                while(p->link!=NULL)
                {
                    if(p->link->dest_code==code)
                        p->link=p->link->link;
                    p=p->link;
                }
            }
            printf("\nThe location %s and all the flights coming and going from it have been successfully deleted from the database.\n",p_code[code-1]);
            strcpy(p_code[code-1],"");
            return(p_no-1);
        }
        else
        {
            printf("\nNo location is associated with this code, so cannot delete!\n");
            return(p_no);
        }
    }
    else
    {
        printf("\nThis location code does not exist!\n");
        return(p_no);
    }
}

//function to change details of particular flight
void upd_edge(char p_code[100][60],int p_no,struct edge* arr[100])
{
    int source,dest,ch;
    printf("\nEnter location code of source of flight: ");
    scanf("%d",&source);
    printf("\nEnter location code of destination of flight: ");
    scanf("%d",&dest);
    if((source>=1)&&(source<=100)&&(dest>=1)&&(dest<=100))
    {
        if((strcmp(p_code[source-1],""))&&(strcmp(p_code[dest-1],"")))
        {
            struct edge* p;
            p=arr[source-1];
            while(p!=NULL)
            {
                if(p->dest_code==dest)
                    break;
                p=p->link;
            }
            if(p!=NULL)
            {
                printf("\nChoose the detail you want to change:\n1.Distance covered\n2.Price\n3.Time taken\n4.Go back to admin home page\nEnter choice: ");
                scanf("%d",&ch);
                if(ch==1)
                {
                    float d;
                    printf("\nenter new value (in kilometres): ");
                    scanf("%f",&d);
                    p->av+=0.2*(d-(p->length));
                    p->length=d;
                }
                else if(ch==2)
                {
                    int pr;
                    printf("\nenter new price value (in ruppees): ");
                    scanf("%d",&pr);
                    p->av+=0.4*(pr-(p->price));
                    p->price=pr;
                }
                else if(ch==3)
                {
                    int t;
                    printf("\nenter new time taken value (format: hhmm, example: 2017 is 20 hours and 17 minutes): ");
                    scanf("%d",&t);
                    p->av+=0.4*(t-(p->time));
                    p->time=t;
                }
                else if(ch==4){}
                else
                    printf("\nChoice not available!.\n");
            }
            else
                printf("\nNo flight exists from %s(%d) to %s(%d).\n",p_code[source-1],source,p_code[dest-1],dest);
        }
         else
            printf("\nProvided code(s) do(es) not exist!\n");
    }
     else
        printf("\nProvided code(s) do(es) not exist!\n");
}

void readfile(char p_code[100][60],int p_no,struct edge* arr[100])
{
    FILE* f;
    f=fopen("AirlineLocations.txt","r");
    int n,s,d,t,p,i=0;
    float l,a;
    char st[60];
    while(fscanf(f,"%s %d\n",st,&n)!=EOF)
    {
        strcpy(p_code[n-1],st);
        p_no+=1;
    }
    for(i=0;i<100;i++)
        arr[i]=NULL;
    fclose(f);
    f=fopen("FlightDetails.txt","r");
    while(fscanf(f,"%d %d %f %d %d %f\n",&s,&d,&l,&t,&p,&a)!=EOF)
    {
        struct edge* ed;
        ed=(struct edge*)malloc(sizeof(struct edge));
        ed->av=a;
        ed->dest_code=d;
        ed->length=l;
        ed->price=p;
        ed->source_code=s;
        ed->time=t;
        ed->link=arr[s-1];
        arr[s-1]=ed;
    }
    fclose(f);
}

void writefile(char p_code[100][60],int p_no,struct edge* arr[100])
{
    int i;
    FILE* f;
    f=fopen("AirlineLocations.txt","w");
    for(i=0;i<100;i++)
    {
        if(strcmp(p_code[i],""))
            fprintf(f,"%s %d\n",p_code[i],i+1);
    }
    fclose(f);
    f=fopen("FlightDetails.txt","w");
    struct edge* p;
    for(i=0;i<100;i++)
    {
        p=arr[i];
        while(p!=NULL)
        {
            fprintf(f,"%d %d %f %d %d %f\n",p->source_code,p->dest_code,p->length,p->time,p->price,p->av);
            p=p->link;
            printf("123");
        }
    }
    fclose(f);
}

void allavail(int source,int dest,char p_code[100][60],int p_no,struct edge* arr[100])
{
    struct edge* p;
    int i=1;
    p=arr[source-1];
    while(p!=NULL)
    {
        if(p->dest_code==dest)
        {
            printf("\nFlight %d:\nPath length: %f\nCost: %d\nTime taken: %d\n",i,p->length,p->price,p->time);
            i++;
        }
        p=p->link;
    }
}

//TANYA

void add_edge(char p_code[100][60],int p_no,struct edge* arr[100])
{
	int p,t,d,s;
	float dist,avg;
	struct edge*ptr;
	printf("\nEnter location code of source: ");
	scanf("%d" ,&s);
	printf("Enter location code of destination: ");
	scanf("%d",&d);
	if((s>=1)&&(s<=100)&&(d>=1)&&(d<=100))
    {
        if((strcmp(p_code[s-1],""))&&(strcmp(p_code[d-1],"")))
		{
        	printf("Enter distance covered by flight: ");
        	scanf("%f",&dist);
        	printf("Enter price: ");
        	scanf("%d",&p);
        	printf("Enter time taken(format: hhmm, example: 2017 is 20 hours and 17 minutes): ");
        	scanf("%d",&t);
        	avg=(t*0.4+d*0.2+p*0.4);
        	ptr=(struct edge*)malloc(sizeof(struct edge));
        	ptr->source_code=s;
        	ptr->length=dist;
    		ptr->time=t;
   			ptr->price=p;
    		ptr->av=avg;
    		ptr->dest_code=d;
    		ptr->source_code=s;
            ptr->link=arr[s-1];
            arr[s-1]=ptr;
        	printf("\nSuccessfully added the flight!\n");
		}
	}
}

void del_edge(char p_code[100][60],int p_no,struct edge* arr[100])
{
	int p,t,d,s;
	float dist,avg;
	printf("\nEnter location code of source: ");
	scanf("%d",&s);
	printf("Enter location code of destination: ");
	scanf("%d",&d);
	printf("Enter distance covered by flight: ");
   	scanf("%f",&dist);
	printf("Enter price: ");
    scanf("%d",&p);
    printf("Enter time taken(format: hhmm, example: 2017 is 20 hours and 17 minutes): ");
    scanf("%d",&t);
	if((s>=1)&&(s<=100)&&(d>=1)&&(d<=100))
    {
    	if((strcmp(p_code[s-1],""))&&(strcmp(p_code[d-1],"")))
		{
       		struct edge* ed;
        	ed=arr[s-1];
        	if(ed==NULL)
        		printf("\nNo flight starts at given location!\n");
			else
			{
			    int x=0;
        		while(ed->link!=NULL)
        		{
        			if((ed->link->dest_code==d)&&(ed->link->price==p)&&(ed->link->length==dist)&&(ed->link->time==t))
					{
        				ed->link==ed->link->link;
        				printf("\nIt has been deleted successfully.\n");
        				x=1;
        				break;
					}
					ed=ed->link;
				}
				if(x==0)
					printf("Such a flight doesn't exist!\n");
        	}
		}
		else
            printf("\nProvided code(s) do(es) not exist!\n");
	}
	else
        printf("\nProvided code(s) do(es) not exist!\n");
}


//KRUPA AND MISARI

//void readfile(char p_code[100][60],int p_no,struct edge* arr[100]){}

//void writefile(char p_code[100][60],int p_no,struct edge* arr[100]){}

//VRUNDA (WITH REHA)

void shortestd(int s,int d,char p_code[100][60],int p_no,struct edge* arr[100])
{
    int i,j,k,s1,d1;
    struct edge* p;
    float mat[p_no][p_no];
    for(i=0;i<p_no;i++)
    {
        for(j=0;j<p_no;j++)
            mat[i][j]=0;
    }
    j=0;
    for(i=0;i<100;i++)
    {
        if(strcmp(p_code[i],""))
        {
            p=arr[i];
            while(p!=NULL)
            {
                if((mat[j][p->dest_code-1]==0)||(mat[j][p->dest_code-1]>p->length))
                    mat[j][p->dest_code-1]=p->length;
                p=p->link;
            }
            if(i==s-1)
                s1=j;
            if(i==d-1)
                d1=j;
            j++;
        }
    }
    float mat1[p_no][p_no];
    for(i=0;i<p_no;i++)
    {
        for(j=0;j<p_no;j++)
        {
            for(k=0;k<p_no;k++)
            {
                mat1[j][k]=mat[j][k];
                if((mat[j][i]!=0)&&(mat[i][k]!=0))
                {
                    if((mat[j][k]==0)||(mat[j][k]>(mat[j][i]+mat[i][k])))
                        mat1[j][k]=mat[j][i]+mat[i][k];
                }
            }
        }
        for(j=0;i<p_no;i++)
        {
            for(k=0;j<100;j++)
                mat[j][k]=mat1[j][k];
        }
    }
    printf("%f",mat[s1][d1]);
    if(mat[s1][d1]==0)
        printf("\nNo path available from %s(%d) to %s(%d).\n",p_code[s-1],s,p_code[d-1],d);
    else
        printf("\nShortest distance path from %s(%d) to %s(%d): %f\n",p_code[s-1],s,p_code[d-1],d,mat[s1][d1]);
}

void shortestt(int s,int d,char p_code[100][60],int p_no,struct edge* arr[100])
{
    int i,j,k,s1,d1;
    struct edge* p;
    int mat[p_no][p_no];
    for(i=0;i<p_no;i++)
    {
        for(j=0;j<p_no;j++)
            mat[i][j]=0;
    }
    j=0;
    for(i=0;i<100;i++)
    {
        if(strcmp(p_code[i],""))
        {
            p=arr[i];
            while(p!=NULL)
            {
                if((mat[j][p->dest_code-1]==0)||(mat[j][p->dest_code-1]>p->time))
                    mat[j][p->dest_code-1]=p->time;
                p=p->link;
            }
            if(i==s-1)
                s1=j;
            if(i==d-1)
                d1=j;
            j++;
        }
    }
    int mat1[p_no][p_no];
    for(i=0;i<p_no;i++)
    {
        for(j=0;j<p_no;j++)
        {
            for(k=0;k<p_no;k++)
            {
                mat1[j][k]=mat[j][k];
                if((mat[j][i]!=0)&&(mat[i][k]!=0))
                {
                    if((mat[j][k]==0)||(mat[j][k]>(mat[j][i]+mat[i][k])))
                        mat1[j][k]=mat[j][i]+mat[i][k];
                }
            }
        }
        for(j=0;i<p_no;i++)
        {
            for(k=0;j<100;j++)
                mat[j][k]=mat1[j][k];
        }
    }
    if(mat[s1][d1]==0)
        printf("\nNo path available from %s(%d) to %s(%d).\n",p_code[s-1],s,p_code[d-1],d);
    else
        printf("\nFastest path time from %s(%d) to %s(%d): %d\n",p_code[s-1],s,p_code[d-1],d,mat[s1][d1]);
}

void shortestp(int s,int d,char p_code[100][60],int p_no,struct edge* arr[100])
{
    int i,j,k,s1,d1;
    struct edge* p;
    int mat[p_no][p_no];
    for(i=0;i<p_no;i++)
    {
        for(j=0;j<p_no;j++)
            mat[i][j]=0;
    }
    j=0;
    for(i=0;i<100;i++)
    {
        if(strcmp(p_code[i],""))
        {
            p=arr[i];
            while(p!=NULL)
            {
                if((mat[j][p->dest_code-1]==0)||(mat[j][p->dest_code-1]>p->price))
                    mat[j][p->dest_code-1]=p->price;
                p=p->link;
            }
            if(i==s-1)
                s1=j;
            if(i==d-1)
                d1=j;
            j++;
        }
    }
    int mat1[p_no][p_no];
    for(i=0;i<p_no;i++)
    {
        for(j=0;j<p_no;j++)
        {
            for(k=0;k<p_no;k++)
            {
                mat1[j][k]=mat[j][k];
                if((mat[j][i]!=0)&&(mat[i][k]!=0))
                {
                    if((mat[j][k]==0)||(mat[j][k]>(mat[j][i]+mat[i][k])))
                        mat1[j][k]=mat[j][i]+mat[i][k];
                }
            }
        }
        for(j=0;i<p_no;i++)
        {
            for(k=0;j<100;j++)
                mat[j][k]=mat1[j][k];
        }
    }
    if(mat[s1][d1]==0)
        printf("\nNo path available from %s(%d) to %s(%d).\n",p_code[s-1],s,p_code[d-1],d);
    else
        printf("\nCheapest path price from %s(%d) to %s(%d): %d\n",p_code[s-1],s,p_code[d-1],d,mat[s1][d1]);
}

void shortesta(int s,int d,char p_code[100][60],int p_no,struct edge* arr[100])
{
    int i,j,k,s1,d1;
    struct edge* p;
    float mat[p_no][p_no];
    for(i=0;i<p_no;i++)
    {
        for(j=0;j<p_no;j++)
            mat[i][j]=0;
    }
    j=0;
    for(i=0;i<100;i++)
    {
        if(strcmp(p_code[i],""))
        {
            p=arr[i];
            while(p!=NULL)
            {
                if((mat[j][p->dest_code-1]==0)||(mat[j][p->dest_code-1]>p->av))
                    mat[j][p->dest_code-1]=p->av;
                p=p->link;
            }
            if(i==s-1)
                s1=j;
            if(i==d-1)
                d1=j;
            j++;
        }
    }
    float mat1[p_no][p_no];
    for(i=0;i<p_no;i++)
    {
        for(j=0;j<p_no;j++)
        {
            for(k=0;k<p_no;k++)
            {
                mat1[j][k]=mat[j][k];
                if((mat[j][i]!=0)&&(mat[i][k]!=0))
                {
                    if((mat[j][k]==0)||(mat[j][k]>(mat[j][i]+mat[i][k])))
                        mat1[j][k]=mat[j][i]+mat[i][k];
                }
            }
        }
        for(j=0;i<p_no;i++)
        {
            for(k=0;j<100;j++)
                mat[j][k]=mat1[j][k];
        }
    }
    printf("%f",mat[s1][d1]);
    if(mat[s1][d1]!=0)
        printf("\nNo path available from %s(%d) to %s(%d).\n",p_code[s-1],s,p_code[d-1],d);
    else
        printf("\nBest path (acc. to aggregated formula) value from %s(%d) to %s(%d): %f\n",p_code[s-1],s,p_code[d-1],d,mat[s1][d1]);
}
