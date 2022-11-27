//task - create a program that uses stack with real-life applications
//SPECIAL VENDING MACHINE

#include<stdio.h>
#include<string.h>

//structure for info on the food options
struct vm //vending machine - vm
{
    char stack[10][10];  //stack of the packets
    char name[60];
    int price;
    char taste[25];
    char category[25];
    int tos; //top of stack - initially 4 i.e. 5 packets
};

//push function - KRUPA
int push(char x[],char array[10][10],int Top)
{
	if(Top==10-1)
	{
		printf("\nOverflow!!");
		return 9;
	}
	Top+=1;
	int i;
	for(i=0;i<strlen(x);i++)
        array[Top][i]=x[i];
    return Top;
}

//pop function - KRUPA
int pop(char array[10][10],int Top)
{
    if(Top==-1)
	{
		printf("\nUnderflow!!");
		return -1;
	}
    return --Top;
}

//function to display according to categories - VRUNDA
void catgy(struct vm food[])
{
    int op = 1, i, k, j, choice;
    char in_cat[50] = "";
    printf("\n1-Lays\n2-Kurkure\n3-Chocolate\n4-Drinks\n5-Namkeen\n6-Khakra\n7-Nachos\n8-Biscuits");
    while (op != 0)
    {
        printf("\n\nIf you want to know about the variety available then press 1(YES) else press 0(NO): ");
        scanf("%d",&op);
        if (op == 1)
        {
            printf("\nPlease choose a number to know about a particular variety:");
            scanf("%d",&choice);
            switch(choice)
            {
                case  1:
                    strcpy(in_cat, "Lays");
                    break;
                case  2:
                    strcpy(in_cat, "Kurkure");
                    break;
                case  3:
                    strcpy(in_cat, "Chocolate");
                    break;
                case  4:
                    strcpy(in_cat, "Drinks");
                    break;
                case  5:
                    strcpy(in_cat, "Namkeen");
                    break;
                case 6:
                    strcpy(in_cat, "Khakra");
                    break;
                case  7:
                    strcpy(in_cat, "Nachos");
                    break;
                case  8:
                    strcpy(in_cat, "Biscuits");
                    break;
                default:
                    break;
            }
            for(i=0; i < 42; i++)
            {
                if (strcmp(food[i].category, in_cat) == 0)
                    printf("\n%d. %s - price: %d, number of available packets: %d",i+1,food[i].name,food[i].price,food[i].tos+1);
            }
            if((choice>8)||(choice<1))
                printf("invalid choice");
        }
        else if(op==0)
            printf("\nWe hope that was informative!\n");
        else
            printf("\nERROR: please enter 1 or 0!!\n");
    }
}

//function to display according to taste - MISARI
void taste(struct vm food[])
{
    int op = 1, i, k, j, choice;
    char in_taste[50] = "";
    printf("\n1-Spicy\n2-Sweet\n3-Chatpata\n4-Mint\n5-Salty\n6-Bitter\n7-Tangy");
    while (op != 0)
        {
        printf("\n\nIf you want to know about the variety available in a particular taste then press 1(YES) else press 0(NO): ");
        scanf("%d",&op);
        if (op == 1)
        {
            printf("\nPlease enter choice for taste category:");
            scanf("%d",&choice);
            switch(choice)
            {
                case  1:
                    strcpy(in_taste, "spicy");
                    break;
                case  2:
                    strcpy(in_taste, "sweet");
                    break;
                case  3:
                    strcpy(in_taste, "chatpata");
                    break;
                case  4:
                    strcpy(in_taste, "mint");
                    break;
                case  5:
                    strcpy(in_taste, "salty");
                    break;
                case 6:
                    strcpy(in_taste, "bitter");
                    break;
                case  7:
                    strcpy(in_taste, "tangy");
                    break;
                default:
                    break;
            }
            for(i=0; i < 42; i++)
            {
                if (strcmp(food[i].taste, in_taste) == 0)
                    printf("\n%d. %s - price: %d, number of available packets: %d",i+1,food[i].name,food[i].price,food[i].tos+1);
            }
            if((choice>7)||(choice<1))
                printf("invalid choice");

        }
        else if(op==0)
            printf("\nWe hope that was informative!\n");
        else
            printf("\nERROR: please enter 1 or 0!!\n");
    }
}

//function to display according to price - TANYA
void price(struct vm t[])
{
 	int d=1,p,i;
	while(d==1)
	{
		printf("\nAvailable price ranges:\n");
		printf("1.1-10\n2.11-20\n3.21-30\n4.31-40\n5.41-50\n6.51-60\n");
		printf("\nEnter Choice: ");
		scanf("%d",&p);
		if (p==1)
	    {
			for(i=0;i<42;i++)
			{
				if((t[i].price>=1)&&(t[i].price<=10))
					printf("\n%d. %s - price: %d, number of available packets: %d",i+1,t[i].name,t[i].price,t[i].tos+1);
		    }
		}
		else if(p==2)
		{
			for(i=0;i<42;i++)
			{
				if((t[i].price>=11)&&(t[i].price<=20))
                    printf("\n%d. %s - price: %d, number of available packets: %d",i+1,t[i].name,t[i].price,t[i].tos+1);
			}
		}
		else if (p==3)
		{
			for(i=0;i<42;i++)
			{
				if((t[i].price>=21)&&(t[i].price<=30))
                    printf("\n%d. %s - price: %d, number of available packets: %d",i+1,t[i].name,t[i].price,t[i].tos+1);
			}

		}
		else if (p==4)
		{
			for(i=0;i<42;i++)
			{
				if((t[i].price>=31)&&(t[i].price<=40))
                    printf("\n%d. %s - price: %d, number of available packets: %d",i+1,t[i].name,t[i].price,t[i].tos+1);
			}
		}
		else if (p==5)
		{
			for(i=0;i<42;i++)
			{
				if((t[i].price>=41)&&(t[i].price<=50))
                    printf("\n%d. %s - price: %d, number of available packets: %d",i+1,t[i].name,t[i].price,t[i].tos+1);
			}
		}
		else if (p==6)
		{
			for(i=0;i<42;i++)
			{
				if((t[i].price>=51)&&(t[i].price<=60))
                    printf("\n%d. %s - price: %d, number of available packets: %d",i+1,t[i].name,t[i].price,t[i].tos+1);
			}
		}
		else
            printf("that choice is not available!!");
		printf("\n\nDo you want to see more price ranges? If yes enter 1 else enter any integer: ");
		scanf("%d",&d);
	}
}

//main code -REHA
void main()
{
    printf("SPECIAL VENDING MACHINE\n\n");
    printf("Copyright ABCD 2022 and 1234567890\n\n");
    printf("--------------------------------------------------------------------\n");
    //structure array for vm
    struct vm food[42]={{.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Lays - Indian Magic Masala",.price=30,.taste="chatpata",.category="Lays",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Lays - Hot n Sweet Chilli",.price=20,.taste="spicy",.category="Lays",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Lays - American Style Cream And Onion",.price=25,.taste="chatpata",.category="Lays",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Lays - Spanish Tomato Tango",.price=40,.taste="spicy",.category="Lays",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Lays - Chile Limon",.price=20,.taste="tangy",.category="Lays",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Lays - Classic Salted",.price=40,.taste="salty",.category="Lays",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Kurkure - Masala Munch",.price=20,.taste="chatpata",.category="Kurkure",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Kurkure - Puff Corn",.price=20,.taste="chatpata",.category="Kurkure",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Kurkure - Triangles",.price=20,.taste="salty",.category="Kurkure",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Kurkure - Solid Masti",.price=20,.taste="chatpata",.category="Kurkure",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Kurkure - Chataka Pataka",.price=20,.taste="chatpata",.category="Kurkure",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Kurkure - Chili Chataka",.price=20,.taste="spicy",.category="Kurkure",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Nachos - Peri Peri",.price=30,.taste="spicy",.category="Nachos",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Nachos - Barbeque",.price=30,.taste="sweet",.category="Nachos",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Nachos - Sizzlin Jalapeno",.price=30,.taste="spicy",.category="Nachos",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Nachos - Tomato Mexican",.price=30,.taste="sweet-sour",.category="Nachos",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Nachos - Tikka Masala",.price=30,.taste="spicy",.category="Nachos",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Biscuits - Parle-G",.price=20,.taste="sweet",.category="Biscuits",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Biscuits - Bourbon",.price=30,.taste="sweet",.category="Biscuits",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Biscuits - Monaco",.price=10,.taste="salty",.category="Biscuits",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Biscuits - Jim Jam",.price=40,.taste="sweet",.category="Biscuits",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Biscuits - Good Day",.price=30,.taste="sweet",.category="Biscuits",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Khakra - Methi",.price=40,.taste="bitter",.category="Khakra",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Khakra - Masala",.price=50,.taste="spicy",.category="Khakra",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Khakra -Plain",.price=60,.taste="salty",.category="Khakra",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Khakra - Jeera",.price=30,.taste="salty",.category="Khakra",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Khakra - Chili",.price=55,.taste="spicy",.category="Khakra",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Chocolate - Dairy Milk",.price=10,.taste="sweet",.category="Chocolate",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Chocolate - KitKat",.price=25,.taste="sweet",.category="Chocolate",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Chocolate - Munch",.price=10,.taste="sweet",.category="Chocolate",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Chocolate - 5Star",.price=20,.taste="sweet",.category="Chocolate",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Chocolate - Amul Dark Chocolate",.price=80,.taste="bitter",.category="Chocolate",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Drinks - Thumbs-up",.price=40,.taste="tangy",.category="Drinks",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Drinks - Fanta",.price=40,.taste="sweet",.category="Drinks",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Drinks - Sprite",.price=40,.taste="tangy",.category="Drinks",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Drinks - Coca-cola",.price=40,.taste="tangy",.category="Drinks",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Drinks - Limca",.price=40,.taste="mint",.category="Drinks",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Namkeen - Bhakharvadi",.price=65,.taste="spicy",.category="Namkeen",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Namkeen - Aloo bhujiya",.price=35,.taste="chatpata",.category="Namkeen",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Namkeen - Lite mixture",.price=35,.taste="spicy",.category="Namkeen",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Namkeen - Salted peanuts",.price=50,.taste="chatpata",.category="Namkeen",.tos=4},
    {.stack={"packet","packet","packet","packet","packet"," "," "," "," "," "},.name="Namkeen - Kachori",.price=60,.taste="spicy",.category="Namkeen",.tos=4},
    };
    //declaring all the variables
    int f=1,p,opt,key,n,q,d,g,i,z;
    //customer or manager
    while(f==1)
    {
        printf("\nAre you a:\n1.Customer\n2.Manager\n3.Or do you want to Leave application\n");
        printf("\nenter choice: ");
        scanf("%d",&p);
        //customer
        if(p==1)
        {
            z=1;
            g=1;
            while(g==1)
            {
                printf("\nchoose one of the following options to see available products:\n1.whole menu\n2.categorically filter\n3.filter on the basis of taste\n4.filter on the basis of the price range\n5.directly order\n6.don't want to order\n");
                printf("\nenter choice: ");
                scanf("%d",&opt);
                //whole menu
                if(opt==1)
                {
                    printf("WHOLE MENU:\n)");
                    for(i=0;i<42;i++)
                        printf("\n%d. %s - price: %d, number of available packets: %d",i+1,food[i].name,food[i].price,food[i].tos+1);
                }
                //categories
                else if(opt==2)
                    catgy(food);
                //tastes
                else if(opt==3)
                    taste(food);
                //price range
                else if(opt==4)
                    price(food);
                //directly order
                else if(opt==5)
                    break;
                //leave customer page
                else if(opt==6)
                {
                    z=0;
                    break;
                }
                //invalid
                else
                    printf("choice is invalid.\n\n");
                //want to continue loop?
                printf("\nAre you ready to order - if not - enter 1 else enter any integer: ");
                scanf("%d",&g);
            }
            g=1;
            while((g==1)&&(z==1))
            {
                //item input
                d=1;
                while(d==1)
                {
                    printf("\nEnter item number: ");
                    scanf("%d",&n);
                    if((n>0)&&(n<43))
                        break;
                    printf("invalid number, do you want to try again? press 1 if yes else enter any integer: ");
                    scanf("%d",&d);
                }
                //input amount of product
                while(d==1)
                {
                    printf("enter quantity of packets: ");
                    scanf("%d",&q);
                    if(q<=(food[n-1].tos+1))
                        break;
                    printf("we don't have that much quantity, do you want to enter a smaller value? (press 1 if yes, else press any integer): ");
                    scanf("%d",&d);
                }
                //giving the products
                if(d==1)
                {
                    for(i=0;i<q;i++)
                        food[n-1].tos=pop(food[n-1].stack,food[n-1].tos);
                    printf("please pay %d rupees and collect your purchase(s): %d %s.\n",(food[n-1].price)*q,q,food[n-1].name);
                }
                //want to continue loop?
                printf("\nDo you want to purchase more? if yes, enter 1 else enter any integer: ");
                scanf("%d",&g);
            }
            printf("\nThank You for shopping with us!\nGood food brings good health :)\n");
        }
        //manager
        else if(p==2)
        {
            //admin key input
            g=1;
            while(g==1)
            {
                printf("\nenter admin pin: ");
                scanf("%d",&key);
                if(key==12624)
                    break;
                printf("invalid key!!\nDo you want to enter again? press 1 if yes else any other integer: ");
                scanf("%d",&g);
            }
            //correct key
            while(g==1)
            {
                //item input
                d=1;
                while(d==1)
                {
                    printf("\nEnter item number: ");
                    scanf("%d",&n);
                    if((n>0)&&(n<43))
                        break;
                    printf("invalid number, do you want to try again? press 1 if yes else enter any integer: ");
                    scanf("%d",&d);
                }
                //input amount of product
                while(d==1)
                {
                    printf("enter quantity of packets you are adding: ");
                    scanf("%d",&q);
                    if(q<=(9-food[n-1].tos))
                       break;
                    printf("we don't have that much capacity, do you want to enter a smaller value? (press 1 if yes, else press any integer): ");
                    scanf("%d",&d);
                }
                //adding the packets
                if(d==1)
                {
                    for(i=0;i<q;i++)
                    {
                        food[n-1].tos=push("packet",food[n-1].stack,food[n-1].tos);
                    }
                    printf("\nSuccessfully added the packets!!\nUpdated number of packets of %s: %d\n",food[n-1].name,food[n-1].tos+1);
                }
                //want to continue loop?
                printf("\nDo you want to add more packets? if yes, enter 1 else enter any integer: ");
                scanf("%d",&g);
            }
        }
        //leave
        else if(p==3)
        {
            printf("\nVENDING MACHINE SHUTDOWN.\n");
            f=0;
        }
        //invalid
        else
            printf("invalid choice\n");
    }
}
