//task - create a program that uses tree with real-life applications
//PRIME FACTORIZATION TREE

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//REHA

//btnode structure
struct btnode
{
    struct btnode* left;
    int data;
    struct btnode* right;
};

//declaring 'root' in b.tree as global
struct btnode* root;

//function to create node in binary tree
struct btnode* new_node(int input,struct btnode* address)
{
    address->data=input;
    address->right=NULL;
    address->left=NULL;
}

//function to display the prime factor tree
void display()
{
    //declaring and defining variables
    struct btnode* p;
    p=root;
    int c=1;  //used to alternate between left and right sub trees as that is how the tree was created
    //printing the root node if it is not null
    if(p!=NULL)
    {
        printf("\t\t%d\n\t       / \\\n\t      ",p->data);
        //printing the node values until the last leaf node
        while(p->left!=NULL)
        {
            printf("%d   %d\n",p->left->data,p->right->data);
            //going to the right sub-tree
            if(c==1)
            {
                p=p->right;
                c=0;
                printf("\t         / \\\n\t\t");
            }
            //going to the left sub-tree
            else
            {
                p=p->left;
                c=1;
                printf("\t       / \\\n\t      ");
            }
        }
    }
    else
        printf("\nERROR: Can't display an empty tree!!\n");
}

//function to create the prime factors tree
void create(int number)
{
    //declaring and defining required variables
    root=(struct btnode*)malloc(sizeof(struct btnode));
    root->data=number;
    root->left=NULL;
    root->right=NULL;
    struct btnode* p;
    p=root;
    int c=number,i=2,j,x,a=1;
    //creating the nodes in the tree except for the root
    while(i<=sqrt(c))
    {
        //checking if i is a factor of c or not
        if(c%i==0)
        {
            x=1;
            //checking if i is a prime number or not
            for(j=2;j<=sqrt(i);j++)
            {
                if(i%j==0)
                {
                    x=0;
                    break;
                }
            }
            //if i is prime then adding it to appropriate node in tree and updating p to point to the other child node
            if(x==1)
            {
                //adding i to left of p if p is right of it's parent or if it is the main root and c/i to the right
                if(a==1)
                {
                    p->left=(struct btnode*)malloc(sizeof(struct btnode));
                    new_node(i,p->left);
                    p->right=(struct btnode*)malloc(sizeof(struct btnode));
                    new_node(c/i,p->right);
                    p=p->right;
                    c/=i;
                    a=0;
                }
                //adding i to right of p if p is left of it's parent and c/i to the left
                else
                {
                    p->left=(struct btnode*)malloc(sizeof(struct btnode));
                    new_node(c/i,p->left);
                    p->right=(struct btnode*)malloc(sizeof(struct btnode));
                    new_node(i,p->right);
                    p=p->left;
                    c/=i;
                    a=1;
                }
                i=2;   //restarting the loop for new c
            }
            //checking for another i as this one is not prime
            else
                i+=1;
        }
        //checking for another i as this one isn't a factor of c
        else
            i+=1;
    }
}

//VRUNDA

void findHCF(int a[],int b[])
{
    int result=1,i;
    for(int i=0;i<1000;i++)
    {
        if(a[i]==0)
            break;
        for(int j=0;j<1000;j++)
        {
            if(b[j]==0)
                break;
            if(a[i]==b[j])
            {
                result*=a[i];
                b[j]=1;
                break;
            }
        }
    }
    printf("%d",result);
}

//REHA

void findLCM(int ap[],int bp[])
{
    int i,j,lcm=1,n1=0,n2=0;
    for(i=0;i<1000;i++)
    {
        if (ap[i]==0)
            break;
        n1+=1;
    }
    for(i=0;i<1000;i++)
    {
        if (bp[i]==0)
            break;
        n2+=1;
    }
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(ap[i]==bp[j])
            {
                bp[j]=1;
                break;
            }
        }
        lcm*=ap[i];
    }
    for(i=0;i<n2;i++)
    {
        lcm*=bp[i];
    }
    printf("%d",lcm);
}

//KRUPA AND REHA

//globally declaring array to store prime factors
int arr[1000];

//function to find the leafnodes and add them to the array of prime factors
int* leafnode(struct btnode* node)
{
    int i;
    if(node == NULL)
        return arr;
    if(node->left == NULL && node->right==NULL)
    {
        printf("%d, ",node->data);
        for(i=0;i<1000;i++)
        {
            if (arr[i]==0)
            {
                arr[i]=node->data;
                break;
            }
        }
        return arr;
    }
    else
    {
        int *ar = leafnode(node->left);
        int *br = leafnode(node->right);
    }
    return arr;
}

//TANYA

void main()
 {
 	int choice,a,b,c,f=1,i,arp[1000],brp[1000];
 	int *ap,*bp;
 while(f==1)
    {
        for(i=0;i<100;i++)
        {
            arr[i]=0;
            arp[i]=0;
            brp[i]=0;
        }
        printf("Choose one of the following:\n\n1.display prime factorization tree\n2.find LCM\n3.find HCF\n4.Leave application\n\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1)
		{
        	printf("\nEnter a natural number: ");
        	scanf("%d",&a);
        	printf("\nprime factorization tree of %d:\n\n",a);
			create(a);
            display();
        	printf("\nprime factors of %d: ",a);
            ap=leafnode(root);
            for(i=0;i<1000;i++)
            {
                if(arr[i]!=0)
                    arr[i]=0;
                else
                    break;
            }
            printf("\n\n");
        }
        else if(choice==2)
		{
        	printf("\nEnter a: ");
        	scanf("%d",&a);
        	printf("Enter b: ");
        	scanf("%d",&b);
        	printf("\nprime factorization of %d:\n",a);
        	create(a);
        	display();
        	printf("\nprime factors of %d: ",a);
        	ap=leafnode(root);
        	for(i=0;i<1000;i++)
            {
                if(arr[i]!=0)
                {
                    arp[i]=arr[i];
                    arr[i]=0;
                }
                else
                    break;
            }
        	printf("\n\nprime factorization of %d:\n",b);
        	create(b);
        	display();
        	printf("\nprime factors of %d: ",b);
        	bp=leafnode(root);
        	for(i=0;i<1000;i++)
            {
                if(arr[i]!=0)
                {
                    brp[i]=arr[i];
                    arr[i]=0;
                }
                else
                    break;
            }
        	printf("\n\nlcm of given numbers: ");
        	findLCM(arp,brp);
            printf("\n\n");
        }
        else if(choice==3)
		{
        	printf("\nEnter a: ");
        	scanf("%d",&a);
        	printf("Enter b: ");
        	scanf("%d",&b);
        	printf("\nprime factorization of %d:\n",a);
        	create(a);
        	display();
        	printf("\nprime factors of %d: ",a);
        	ap=leafnode(root);
        	for(i=0;i<1000;i++)
            {
                if(arr[i]!=0)
                {
                    arp[i]=arr[i];
                    arr[i]=0;
                }
                else
                    break;
            }
        	printf("\n\nprime factorization of %d:\n",b);
        	create(b);
        	display();
        	printf("\nprime factors of %d: ",b);
        	bp=leafnode(root);
        	for(i=0;i<1000;i++)
            {
                if(arr[i]!=0)
                {
                    brp[i]=arr[i];
                    arr[i]=0;
                }
                else
                    break;
            }
        	printf("\n\nhcf of given numbers: ");
        	findHCF(arp,brp);
            printf("\n\n");
        }
        else if(choice==4)
		{

            printf("\nHope you learned something new.");
            f=0;
            printf("\n\n");
        }
        else
            printf("\ninvalid choice\n\n");
	}
}
