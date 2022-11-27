//task - create a linked list, queue, stack and structure real-life applications
//HOSPITAL PATIENT INFORMATION DATABASE
//queues-patients for today-new ones dequeued into main database at the end of the day and for old ones data is updated-maximum limit 100
//different queue for different departments of the hospital-according to the patients current illness
//stack-patient health portfolio-old first, new last
//linked list-stores data from database

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to store data in stack
struct data_s
{
    char symptoms[400];
    char diagnosis[100];
    char type[50];
    char treatment[500];
};

//structure for stack
struct node_s
{
    struct data_s data;
    struct node_s* link;
};

//structure to store patient info
struct patient
{
    struct node_s* start;
    int p_no;
    char name[60];
    char sex[10];
    int age;
    long int phone;
};

//structure for linked list node
struct node
{
    struct patient data;
    struct node* link;
};

//declaring some global variables
struct node* start;
int qp[10],qn[10],qc[10],qg[10],qy[10],fp=-1,rp=-1,fn=-1,rn=-1,fc=-1,rc=-1,fg=-1,rg=-1,fy=-1,ry=-1;

//declaring functons
struct node_s* pop(struct node*);
struct node* new_node(struct node_s*,int,char[],char[],int,long int);
struct node* traverse(int);
void new_patient();
void p_data();
void p_change();
void r_upd();
void push(struct node*,char[],char[],char[],char[]);
void add_record();
void see_queue();
void enqueue(int,int[],int*,int*);
void dequeue(int[],int*,int*);
void display(int[],int,int);
void add_queue();
void out_queue();
void see_stack();

//REHA

//main function
void main()
{
    int f=1,c;
    //accessing file where user data is stored and putting it in the linked list
    FILE* fr;
    fr=fopen("C:/Users/Admin/Documents/PDEU/Academics/Semester 3/Data Structures/Lab/Patient Data","r");
    start=(struct node*)malloc(sizeof(struct node));
    struct node* p;
    struct node* q;
    p=start;
    q=p;
    struct node_s* t;
    struct node_s* v;
    while(fscanf(fr,"%d %d %s %s %d %ld\n",&p->data.start,&p->data.p_no,p->data.name,p->data.sex,&p->data.age,&p->data.phone)!=EOF)
    {
        p->data.start=(struct node_s*)malloc(sizeof(struct node_s));
        t=p->data.start;
        do
        {
            t->link=(struct node_s*)malloc(sizeof(struct node_s));
            fscanf(fr,"%s %s %s %s\n",t->data.symptoms,t->data.diagnosis,t->data.type,t->data.treatment);
            v=t;
            t=t->link;
        }while(!((strcmp(v->data.symptoms,"0"))||(strcmp(v->data.diagnosis,"0"))||(strcmp(v->data.type,"0"))||(strcmp(v->data.treatment,"0"))));
        t=NULL;
        p->link=(struct node*)malloc(sizeof(struct node));
        q=p;
        p=p->link;
    }
    if(p==start)
        start=NULL;
    q->link=NULL;
    free(p);
    p=NULL;
    while(f)
    {
        printf("\nDAY START AT XYZ HOSPITAL\n\n");
        printf("Choose one of the following options to access the patient database:\n1.Create new patient record\n2.Add new entry in patient's file\n3.Add patient to queue\n4.See patient's file record\n5.See available patient information\n6.Update patient information details\n7.Update latest entry in patient file\n8.Dequeue patient\n9.See current queue for specific department\n10.Leave application\nenter choice: ");
        scanf("%d",&c);
        if(c==1)
            new_patient();
        else if(c==2)
            add_record();
        else if(c==3)
            add_queue();
        else if(c==4)
            see_stack();
        else if(c==5)
            p_data();
        else if(c==6)
            p_change();
        else if(c==7)
            r_upd();
        else if(c==8)
            out_queue();
        else if(c==9)
            see_queue();
        else if(c==10)
            f=0;
        else
            printf("invalid choice");
    }
    printf("\nUser Data in system currently:\n\n");
    FILE* fw;
    fw=fopen("C:/Users/Admin/Documents/PDEU/Academics/Semester 3/Data Structures/Lab/Patient Data","w");
    p=start;
    while(p!=NULL)
    {
        fprintf(fw,"%d %d %s %s %d %ld\n",p->data.start,p->data.p_no,p->data.name,p->data.sex,p->data.age,p->data.phone);
        printf("%d %d %s %s %d %ld\n",p->data.start,p->data.p_no,p->data.name,p->data.sex,p->data.age,p->data.phone);
        t=p->data.start;
        while(t!=NULL)
        {
            fprintf(fw,"%s %s %s %s\n",t->data.symptoms,t->data.diagnosis,t->data.type,t->data.treatment);
            printf("%s %s %s %s\n",t->data.symptoms,t->data.diagnosis,t->data.type,t->data.treatment);
            t=t->link;
        }
        char stz[2]="0";
        fprintf(fw,"%s %s %s %s\n",stz,stz,stz,stz);
        printf("%s %s %s %s\n",stz,stz,stz,stz);
        p=p->link;
    }
    fclose(fr);
    fclose(fw);
    printf("DAY ENDS AT XYZ HOSPITAL");
}

//function to create new node
struct node* new_node(struct node_s* starts,int p_no,char name[60],char sex[10],int age,long int phone)
{
    struct node* t;
    t=start;
    if(t!=NULL)
    {
        while(t->link!=NULL)
            t=t->link;
        t->link=(struct node*)malloc(sizeof(struct node));
        t->link->data=(struct patient){.start=starts,.p_no=p_no,.name=" ",.sex=" ",.age=age,.phone=phone};
        strcpy(t->link->data.name,name);
        strcpy(t->link->data.sex,sex);
        t->link->link=NULL;
        t=t->link;
    }
    else
    {
        start=(struct node*)malloc(sizeof(struct node));
        start->data=(struct patient){.start=starts,.p_no=p_no,.name=" ",.sex=" ",.age=age,.phone=phone};
        strcpy(start->data.name,name);
        strcpy(start->data.sex,sex);
        start->link=NULL;
        t=start;
    }
    return t;
}

//function to find particular patient record using the patient number
struct node* traverse(int number)
{
    struct node* t;
    t=start;
    while(t!=NULL)
    {
        if(t->data.p_no==number)
            return t;
        t=t->link;
    }
    return NULL;
}

//function to add new patient in linked list
void new_patient()
{
    char n[60],s[10];
    int r,pn,a;
    printf("\nenter the following details to create a new account for the patient: \n");
    printf("name: ");
    scanf("%s",n);
    printf("age: ");
    scanf("%d",&a);
    printf("sex: ");
    scanf("%s",s);
    printf("phone number: ");
    scanf("%ld",&pn);
    struct node* t;
    t=start;
    if(t==NULL)
        r=1;
    else
    {
        while(t->link!=NULL)
        {
            t=t->link;
        }
        r=t->data.p_no+1;
    }
    struct node_s* stack;
    stack=NULL;
    t=new_node(stack,r,n,s,a,pn);
    printf("\nnew patient entry has been created and the patient number for %s with id %d.\n\n",t->data.name,t->data.p_no);
}

//function to see patient info stored in linked list
void p_data()
{
    int n;
    printf("enter patient number: ");
    scanf("%d",&n);
    struct node* p;
    p=traverse(n);
    if(p!=NULL)
    {
        printf("\nPatient data:\nName: %s\nAge: %d\nSex: %s\nPhone Number: %ld\n",p->data.name,p->data.age,p->data.sex,p->data.phone);
    }
    else
        printf("patient number is incorrect.\n");
}

//function to update patient information
void p_change()
{
    int n,ch;
    printf("enter patient number: ");
    scanf("%d",&n);
    struct node* p;
    p=traverse(n);
    if(p!=NULL)
    {
        printf("\nWhich value do you want to update:\n1.Name\n2.Age\n3.Sex\n4.Phone Number\n\nenter choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nenter updated name: ");
            scanf("%s",p->data.name);
        }
        else if(ch==2)
        {
            printf("\nenter updated age: ");
            scanf("%d",&p->data.age);
        }
        else if(ch==3)
        {
            printf("\nenter updated sex: ");
            scanf("%s",p->data.sex);
        }
        else if(ch==4)
        {
            printf("\nenter updated phone number: ");
            scanf("%ld",&p->data.phone);
        }
        else
            printf("\ninvalid choice.\n");
    }
    else
        printf("patient number is incorrect.\n");
}

//function to update latest stack record in patient file
void r_upd()
{
    int n,ch,d;
    printf("enter patient number: ");
    scanf("%d",&n);
    struct node* p;
    p=traverse(n);
    if(p!=NULL)
    {
        char s[400],g[100],t[50],r[500];
        struct node_s* k;
        k=pop(p);
        if(k!=NULL)
        {
        printf("\nWhich value do you want to update:\n1.Symptoms\n2.Diagnosis\n3.Hospital Department\n4.Treatment Suggested\n\nenter choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nenter updated symptoms: ");
            scanf("%s",k->data.symptoms);
        }
        else if(ch==2)
        {
            printf("\nenter updated diagnosis: ");
            scanf("%s",k->data.diagnosis);
        }
        else if(ch==3)
        {
            printf("\nchoose updated department: \n1.Pediatric\n2.Neurology\n3.Cardiology\n4.General Physician\n5.Gynecology\nenter choice: ");
            scanf("%d",&d);
            if(d==1)
                strcpy(k->data.type,"Pediatrician");
            else if(d==2)
                strcpy(k->data.type,"Neurology");
            else if(d==3)
                strcpy(k->data.type,"Cardiology");
            else if(d==4)
                strcpy(k->data.type,"General Physician");
            else if(d==5)
                strcpy(k->data.type,"Gynecology");
            else
                printf("invalid choice\n");
        }
        else if(ch==4)
        {
            printf("\nenter updated treatment: ");
            scanf("%s",k->data.treatment);
        }
        else
            printf("\ninvalid choice.\n");
        push(p,k->data.symptoms,k->data.diagnosis,k->data.type,k->data.treatment);
    }
    else
        printf("file is empty.\n");
    }
    else
        printf("patient number is incorrect.\n");
}

//TANYA

//function to push onto the stack
void push(struct node* p,char symptoms[400],char diagnosis[100],char type[50],char treatment[500])
{
	struct node_s* n=(struct node_s*)malloc(sizeof(struct node_s));
    strcpy(n->data.symptoms,symptoms);
    strcpy(n->data.diagnosis,diagnosis);
    strcpy(n->data.type,type);
    strcpy(n->data.treatment,treatment);
	n->link=p->data.start;
	p->data.start=n;
}

//function to add an entry to the patient file stack
void add_record()
{
    int num,c;
  	printf("Enter patient no.: ");
  	scanf("%d",&num);
  	struct node* p;
  	p=traverse(num);
  	if(p!=NULL)
    {
  		char s[400],d[100],t[50]="none",tr[500];
  		printf("Enter these details to add new record:\n");
  		printf("symptoms: ");
  		scanf("%s",s);
  		printf("diagnosis: ");
  		scanf("%s",d);
  		printf("choose department: \n1.Pediatric\n2.Neurology\n3.Cardiology\n4.General Physician\n5.Gynecology\nenter choice: ");
        scanf("%d",&c);
        if(c==1)
            strcpy(t,"Pediatrician");
        else if(c==2)
            strcpy(t,"Neurology");
        else if(c==3)
            strcpy(t,"Cardiology");
        else if(c==4)
            strcpy(t,"General Physician");
        else if(c==5)
            strcpy(t,"Gynecology");
        else
            printf("invalid choice\n");
        printf("treatment: ");
  		scanf("%s",tr);
  		printf("\n");
  		push(p,s,d,t,tr);
    }
    else
        printf("patient number is incorrect.\n\n");
}

//to display queue of particular department
void see_queue(){
	int c;
	printf("\nchoose  department: \n1.Pediatric\n2.Neurology\n3.Cardiology\n4.General Physician\n5.Gynecology\nenter choice: ");
    scanf("%d",&c);
    if(c==1)
        display(qp,fp,rp);
    else if(c==2)
        display(qn,fn,rn);
    else if(c==3)
        display(qc,fc,rc);
    else if(c==4)
        display(qg,fg,rg);
    else if(c==5)
        display(qy,fy,ry);
    else
        printf("invalid choice\n");
}

//KRUPA AND MISARI

void enqueue(int element,int q[],int* front,int* rear)
{
    if (*rear == 9)
        printf("Queue Overflow\n");
    else
    {
        if (*front == - 1)
            *front = 0;
        *rear=*rear+1;
        q[*rear] = element;
        printf("%d %d",*front,*rear);
    }
}

void dequeue(int q[],int* front,int* rear)
{
    if((*front==-1)||(*front>*rear))
        printf("Queue Underflow \n");
    else
    {
        printf("This patient has been removed from the queue successfully: %d\n", q[*front]);
        *front=*front+1;
    }
}

void display(int q[],int front,int rear)
{
    int i;
    if (front == - 1)
        printf("Queue underflow\n");
    else
    {
        printf("The elements of the queue are:\n");
        for (i = front; i <= rear; i++)
            printf("%d\n",q[i]);
    }
}

void add_queue()
{
    int num;
 	printf("Enter patient no.: ");
  	scanf("%d",&num);
  	struct node* p;
  	p=traverse(num);
  	if(p!=NULL)
    {
        int c;
        printf("\nchoose  department:\n1.Pediatric\n2.Neurology\n3.Cardiology\n4.General Physician\n5.Gynecology\nenter choice: ");
        scanf("%d",&c);
        if(c==1)
            enqueue(p->data.p_no,qp,&fp,&rp);
        else if(c==2)
            enqueue(p->data.p_no,qn,&fn,&rn);
        else if(c==3)
            enqueue(p->data.p_no,qc,&fc,&rc);
        else if(c==4)
            enqueue(p->data.p_no,qg,&fg,&rg);
        else if(c==5)
            enqueue(p->data.p_no,qy,&fy,&ry);
        else
            printf("invalid choice\n");
    }
    else
        printf("patient number is incorrect.\n\n");
}

void out_queue(){
 	int num;
 	printf("Enter patient no.: ");
  	scanf("%d",&num);
  	struct node* p;
  	p=traverse(num);
  	if(p!=NULL)
    {
        int c;
        printf("\nchoose  department: \n1.Pediatric\n2.Neurology\n3.Cardiology\n4.General Physician\n5.Gynecology\nenter choice: ");
        scanf("%d",&c);
        if(c==1)
            dequeue(qp,&fp,&rp);
        else if(c==2)
            dequeue(qn,&fn,&rn);
        else if(c==3)
            dequeue(qc,&fc,&rc);
        else if(c==4)
            dequeue(qg,&fg,&rg);
        else if(c==5)
            dequeue(qy,&fy,&ry);
        else
            printf("invalid choice\n");
  	}
}

//VRUNDA

//function to display file stack
void see_stack()
{
    int num,c;
  	printf("Enter patient no.: ");
  	scanf("%d",&num);
  	struct node* p;
  	p=traverse(num);
  	if(p!=NULL)
    {
        struct node_s* top1;
        top1 = p->data.start;
        while (top1 != NULL)
        {
            printf("symptoms: %s\ndiagnosis: %s\ndepartment: %s\ntreatment: %s\n\n",top1->data.symptoms,top1->data.diagnosis,top1->data.type,top1->data.treatment);
            top1 = top1->link;
        }
    }
    else
        printf("patient number is incorrect.\n\n");
}

//function to pop entry from stack
struct node_s* pop(struct node* p1)
{
   if (p1->data.start == NULL)
      return p1->data.start;
    struct node_s* q;
    q=p1->data.start;
    p1->data.start = p1->data.start->link;
    return q;
}
