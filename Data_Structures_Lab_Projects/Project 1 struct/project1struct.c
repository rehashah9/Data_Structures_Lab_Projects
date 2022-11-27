//task - create a structure with real-life applications
//PERIODIC TABLE APPLICATION

#include<stdio.h>
#include<math.h>
#include<string.h>

//structure for periodic table elements information
struct ptable
{
    char symbol[4]; //element symbol
    char name[20]; //element name
    int ano; //atomic number
    float am; //atomic mass
    char type[40]; //type of element
    char block; //block of periodic table
    int orbits; //number of orbits in ground state on atom
    char state; //state of element at room temperature
};

//main code
void main()
{
    printf("LET'S LEARN ABOUT THE PERIODIC TABLE !!\n");
    //structure object initiation for all 118 elements
    struct ptable elements[118] = {{.symbol="H" ,.name="Hydrogen" , .ano=1 ,.am=1.00 ,.type="Non-Metal" , .block='s' ,.orbits=1 ,.state='g' },
    {.symbol="He",.name="Helium" ,   .ano=2 ,.am=4.00 ,.type="Noble Gas" , .block='p' ,.orbits=1 ,.state='g' },
    {.symbol="Li",.name="Lithium" ,  .ano=3 ,.am=7.00,.type="Alkali Metal" ,.block='s' ,.orbits=2 ,.state='s' },
    {.symbol="Be",.name="Beryllium" ,.ano=4 ,.am=9.01 ,.type="Alkaline Earth Metal" ,.block='s',.orbits=2 ,.state='s' },
    {.symbol="B",.name="Boron" , .ano=5 ,.am=10.81 ,.type="Metalloid" ,  .block='p' ,.orbits=2 ,.state='s' },
    {.symbol="C",.name="Carbon" , .ano=6 ,.am=12.01 ,.type="Non-Metal" ,  .block='p' ,.orbits=2 ,.state='s' },
    {.symbol="N",.name="Nitrogen" , .ano=7 ,.am=14.00 ,.type="Non-Metal" ,  .block='p' ,.orbits=2 ,.state='g' },
    {.symbol="O",.name="Oxygen" , .ano=8 ,.am=15.99 ,.type="Non-Metal" ,  .block='p' ,.orbits=2 ,.state='g'},
    {.symbol="F",.name="Fluorine" , .ano=9 ,.am=18.99 ,.type="Halogen" ,   .block='p',.orbits=2 ,.state='g' },
    {.symbol="Ne",.name="Neon" , .ano=10 ,.am=20.17 ,.type="Noble Gas" ,.block='p' ,.orbits=2,.state='g' },
    {.symbol="Na" ,.name="Sodium" , .ano=11 ,.am=22.98 ,.type="Alkali Metal" ,.block='s' ,.orbits=3 ,.state='s' },
    {.symbol="Mg" ,.name="Magnesium" , .ano=12 ,.am=24.30 ,.type="Alkaline Earth Metal" ,.block='s',.orbits=3 ,.state='s' },
    {.symbol="Al" ,.name="Aluminum" , .ano=13 ,.am=26.98 ,.type="Post Transition Metal" ,.block='p' ,.orbits=3 ,.state='s'},
    {.symbol="Si" ,.name="Silicon" , .ano=14 ,.am=28.08 ,.type="Metalloid" , .block='p' ,.orbits=3 ,.state='s' },
    {.symbol="P" ,.name="Phosphorus" , .ano=15 ,.am=30.97 ,.type="Non-Metal" , .block='p' ,.orbits=3 ,.state='s' },
    {.symbol="S" ,.name="Sulfur" , .ano=16 ,.am=32.06 ,.type="Non-Metal" , .block='p' ,.orbits=3 ,.state='s' },
    {.symbol="Cl" ,.name="Chlorine" , .ano=17 ,.am=35.45 ,.type="Halogen" ,  .block='p' ,.orbits=3 ,.state='g'},
    {.symbol="Ar" ,.name="Argon" , .ano=18 ,.am=39.94 ,.type="Noble Gas" ,.block='p' ,.orbits=3 ,.state='g' },
    {.symbol="K" ,.name="Potassium" , .ano=19 ,.am=39.09 ,.type="Alkali Metal" ,.block='s' ,.orbits=4 ,.state='s' },
    {.symbol="Ca" ,.name="Calcium" , .ano=20 ,.am=40.07 ,.type="Alkaline Earth Metal" ,.block='s' ,.orbits=4 ,.state='s'},
    {.symbol="Sc" ,.name="Scandium" , .ano=21 ,.am=44.95 ,.type="Transition Metal" ,.block='d',.orbits=4 ,.state='s' },
    {.symbol="Ti" ,.name="Titanium" , .ano=22 ,.am=47.86 ,.type="Transition Metal" ,.block='d',.orbits=4 ,.state='s' },
    {.symbol="V" ,.name="Vanadium" , .ano=23 ,.am=50.94,.type="Transition Metal" , .block='d' ,.orbits=4 ,.state='s'},
    {.symbol="Cr" ,.name="Chromium" , .ano=24 ,.am=51.99 ,.type="Transition Metal" ,.block='d' ,.orbits=4 ,.state='s' },
    {.symbol = "Mn" ,.name = "Manganese" ,.ano = 25 ,.am =54 ,.type ="Transition Metal" ,.block ='d' ,.orbits =4 ,.state ='solid' },
    {.symbol = "Fe" ,.name = "Iron" ,.ano = 26,.am =55 ,.type ="Transition Metal" ,.block ='d' ,.orbits =4 ,.state ='solid' },
    {.symbol = "Co" ,.name = "Cobalt" ,.ano = 27 ,.am =58 ,.type ="Transition Metal" ,.block ='d' ,.orbits =4 ,.state ='solid' },
    {.symbol = "Ni" ,.name = "Nickel" ,.ano =28 , .am =58 ,.type ="Transition Metal" ,.block ='d' ,.orbits =4 ,.state ='solid' },
    {.symbol = "Cu" ,.name = "Copper" ,.ano =29 , .am =63 ,.type ="Transition Metal" ,.block ='d' ,.orbits =4 ,.state ='solid' },
    {.symbol = "Zn",.name = "Zinc" ,.ano =30 , .am =65 ,.type ="Transition Metal" ,.block ='d' ,.orbits =4 ,.state = 'solid' },
    {.symbol = "Ga" ,.name = "Gallium" ,.ano =31 ,.am =69 ,.type ="Post-Transition Metal" ,.block ='d' ,.orbits =4 ,.state ='solid' },
    {.symbol = "Ge" ,.name = "Germanium" ,.ano =32 ,.am =72 ,.type ="Mettaloid" ,.block ='p' ,.orbits =4 ,.state = 'solid' },
    {.symbol = "As" ,.name = "Arsenic" ,.ano =33 ,.am =74 ,.type ="Mettaloid" ,.block ='p' ,.orbits =4 ,.state = 'solid' },
    {.symbol = "Se" ,.name = "Selenium" ,.ano =34 ,.am =79 ,.type ="Non-Metal" ,.block ='p' ,.orbits =4 ,.state ='solid' },
    {.symbol = "Br" ,.name = "Bromine" ,.ano =35 ,.am =80 ,.type ="Halogen" ,.block ='p' ,.orbits =4 ,.state ='liquid' },
    {.symbol = "Kr" ,.name = "Krypton" ,.ano =36 ,.am =83 ,.type ="Noble Gas" ,.block ='p' ,.orbits =4 ,.state ='gas' },
    {.symbol = "Rb" ,.name = "Rubidium" ,.ano =37 ,.am =85 ,.type ="Alkali Metal" ,.block ='s' ,.orbits =5 ,.state ='solid'},
    {.symbol = "Sr" ,.name = "Stronium" ,.ano =38 ,.am =87 ,.type ="Alkaline Earth Metal" ,.block ='s' ,.orbits =5 ,.state ='solid'},
    {.symbol = "Y" ,.name =  "Yttrium" ,.ano =39 ,.am =39 ,.type ="Transition Metal" ,.block ='d' ,.orbits =5 ,.state ='solid'},
    {.symbol = "Zr" ,.name = "Zirconium" ,.ano =40 ,.am =91 ,.type ="Transition Metal" ,.block ='d' ,.orbits =5 ,.state ='solid'},
    {.symbol = "Nb" ,.name = "Nibodium ",.ano =41 ,.am =92 ,.type ="Transition Metal" ,.block ='d' ,.orbits =5 ,.state ='solid'},
    {.symbol = "Mo" ,.name = "Molybdenum" ,.ano =42 ,.am =96 ,.type ="Transition Metal" ,.block ='d' ,.orbits =5 ,.state ='solid'},
    {.symbol = "Tc" ,.name = "Technetium",.ano =43 ,.am =98 ,.type ="Transition Metal" ,.block ='d' ,.orbits =5 ,.state ='solid'},
    {.symbol = "Ru" ,.name = "Ruthenium" ,.ano =44 ,.am =101 ,.type ="Transition Metal" ,.block ='d' ,.orbits =5 ,.state ='solid' },
    {.symbol = "Rh" ,.name = "Rhodium" ,.ano =45 ,.am =102 ,.type ="Transition Metal" ,.block ='d' ,.orbits =5 ,.state ='solid' },
    {.symbol = "Pd" ,.name = "Palladium" ,.ano =46 ,.am =106 ,.type ="Transition Metal" ,.block ='d' ,.orbits =5 ,.state ='solid' },
    {.symbol = "Ag" ,.name = "Silver" ,.ano =47 ,.am =107 ,.type ="Transition Metal" ,.block ='d' ,.orbits =5 ,.state ='solid' },
    {.symbol = "Cd" ,.name = "Cadmium" ,.ano =48 ,.am =112 ,.type ="Transition Metal" ,.block ='d' ,.orbits =5 ,.state ='solid' },
    {.symbol = "Cd", .name = "Cadmium", .ano =48 , .am =112.41, .type = "Post-Transition Metal", .block = 'd', .orbits = 5, .state = 's'},
    {.symbol = "In", .name = "Indium",  .ano =49 , .am =114.81 , .type = "Post-Transition Metal", .block = 'p', .orbits = 5, .state = 's'},
    {.symbol = "Sn", .name = "Tin", .ano =50 , .am =118.71 , .type = "Post-Transition Metal", .block = 'p', .orbits = 5, .state = 's'},
    {.symbol = "Sb", .name = "Antimony", .ano = 52, .am =121.76 , .type = "Metalloid", .block = 'p', .orbits = 5, .state = 's'},
    {.symbol = "Te", .name = "Tellurium", .ano = 53, .am =127.60 , .type = "Metalloid", .block = 'p', .orbits = 5, .state = 's'},
    {.symbol = "I", .name = "Iodine", .ano = 54, .am =126.90 , .type = "Halogen", .block = 'p', .orbits = 5, .state = 's'},
    {.symbol = "Xe", .name = "Xenon", .ano = 55 , .am =131.29 , .type = "Noble Gas", .block = 'p', .orbits = 5, .state = 's'},
    {.symbol = "Cs", .name = "Caesium", .ano = 56 , .am =132.90 , .type = "Alkali Metal", .block = 's', .orbits = 6, .state = 's'},
    {.symbol = "Ba", .name = "Barium", .ano = 57, .am =137.32 , .type = "Alkaline Earth Metal", .block = 's', .orbits = 6, .state = 's'},
    {.symbol = "La", .name = "Lanthanum", .ano = 58 , .am =138.90 , .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Ce", .name = "Cerium", .ano = 59, .am =140.11 , .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Pr", .name = "Prasmodymium", .ano = 60, .am =140.90 , .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Nd", .name = "Neodymium", .ano = 61, .am = 144.24, .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Pm", .name = "Promethium", .ano = 62, .am =145 , .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Sm", .name = "Samarium", .ano = 63, .am =150.36 , .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Eu", .name = "Europium", .ano = 64, .am =151.96 , .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Gd", .name = "Gadolinium", .ano = 65, .am =157.25 , .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Tb", .name = "Terbium", .ano = 66, .am = 152.92, .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Dy", .name = "Dysprosium", .ano = 67, .am =162.50 , .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Ho", .name = "Holmium", .ano = 68, .am =164.93 , .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Er", .name = "Erbium", .ano = 69, .am = 167.25, .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Tm", .name = "Thulium", .ano = 70, .am = 168.93, .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Yb", .name = "Ytterbium", .ano =71, .am = 173.04, .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Lu", .name = "Lutetium", .ano = 72, .am =174.96 , .type = "Lanthanide", .block = 'f', .orbits = 6, .state = 's'},
    {.symbol = "Ta", .name = "Tantalum", .ano = 73, .am = 180.95, .type = "Transition Metal", .block = 'd', .orbits = 6, .state = 's'},
    {.symbol = "W", .name = "Tungesten", .ano = 74, .am = 183.84, .type = "Transition Metal", .block = 'd', .orbits = 6, .state = 's'},
    {.symbol = "Re", .name = "Rhenium", .ano = 75, .am = 186.21, .type = "Transition Metal", .block = 'd', .orbits = 6, .state = 's'},
    {.symbol = "Os", .name = "Osmium", .ano = 76, .am = 190.23, .type = "Transition Metal", .block = 'd', .orbits = 6, .state = 's'},
    {.symbol = "Ir", .name = "Iridium", .ano = 77, .am = 192.22, .type = "Transition Metal", .block = 'd', .orbits = 6, .state = 's'},
    {.symbol = "Pt", .name = "Platinum", .ano = 78, .am = 195.08, .type = "Transition Metal", .block = 'd', .orbits = 6, .state = 's'},
    {.symbol = "Au", .name = "Gold", .ano = 79, .am = 196.97, .type = "Transition Metal", .block = 'd', .orbits = 6, .state = 's'},
    {.symbol = "Hg", .name = "Mercury", .ano = 80, .am = 200.59, .type = "Post-Transition Metal", .block = 'd', .orbits = 6, .state = 'l'},
    {.symbol = "Tl", .name = "Thallium", .ano = 81, .am = 204.38, .type = "Post-Transition Metal", .block = 'p', .orbits = 6, .state = 's'},
    {.symbol = "Pb", .name = "Lead", .ano = 82, .am = 207.2, .type = "Post-Transition Metal", .block = 'p', .orbits = 6, .state = 's'},
    {.symbol = "Bi", .name = "Bismuth", .ano = 83, .am = 208.98, .type = "Post-Transition Metal", .block = 'p', .orbits = 6, .state = 's'},
    {.symbol = "Po", .name = "Polonium", .ano = 84, .am = 209, .type = "Post-Transition Metal", .block = 'p', .orbits = 6, .state = 's'},
    {.symbol = "At", .name = "Astatine", .ano = 85, .am = 210, .type = "Halogen", .block = 'p', .orbits = 6, .state = 's'},
    {.symbol = "Rn", .name = "Radon", .ano = 86, .am = 222, .type = "Noble Gas", .block = 'p', .orbits = 6, .state = 'g'},
    {.symbol = "Fr", .name = "Francium", .ano = 87, .am = 223, .type = "Alkali Metal", .block = 's', .orbits = 7, .state = 's'},
    {.symbol = "Ra", .name = "Radium", .ano = 88, .am = 226, .type = "Alkaline Earth Metal", .block = 's', .orbits = 7, .state = 's'},
    {.symbol = "Ac", .name = "Actinium", .ano = 89, .am = 227, .type = "Actinide", .block = 'd', .orbits = 7, .state = 's'},
    {.symbol = "Th", .name = "Thorium", .ano = 90, .am = 232.04, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Pa", .name = "Protactinium", .ano = 91, .am = 231.04, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "U", .name = "Uranium", .ano = 92, .am = 238.03, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Np", .name = "Neptunium", .ano = 93, .am = 237, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Pu", .name = "Plutonium", .ano = 94, .am = 244, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Am", .name = "Americium", .ano = 95, .am = 243, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Cm", .name = "Curium", .ano = 96, .am = 247, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Bk", .name = "Berkelium", .ano = 97, .am = 247, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Cf", .name = "Californium", .ano = 98, .am = 251, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Es", .name = "Einsteinium", .ano = 99, .am = 252, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Fm", .name = "Fermium", .ano = 100, .am = 257, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Md", .name = "Mendelevium", .ano = 101, .am = 258, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "No", .name = "Nobelium", .ano = 102, .am = 259, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Lr", .name = "Lawrencium", .ano = 103, .am = 266, .type = "Actinide", .block = 'f', .orbits = 7, .state = 's'},
    {.symbol = "Rf", .name = "Rutherfordium", .ano = 104, .am = 267, .type = "Transition Metal", .block = 'd', .orbits = 7, .state = 's'},
    {.symbol = "Db", .name = "Dubnium", .ano = 105, .am = 268, .type = "Transition Metal", .block = 'd', .orbits = 7, .state = 's'},
    {.symbol = "Sg", .name = "Seaborgium", .ano = 106, .am = 269, .type = "Transition Metal", .block = 'd', .orbits = 7, .state = 's'},
    {.symbol = "Bh", .name = "Bohrium", .ano = 107, .am = 270, .type = "Transition Metal", .block = 'd', .orbits = 7, .state = 's'},
    {.symbol = "Hs", .name = "Hassium", .ano = 108, .am = 277, .type = "Transition Metal", .block = 'd', .orbits = 7, .state = 's'},
    {.symbol = "Mt", .name = "Meithnerium", .ano = 109, .am = 278, .type = "Transition Metal", .block = 'd', .orbits = 7, .state = 's'},
    {.symbol = "Ds", .name = "Darmstadtium", .ano = 110, .am = 281, .type = "Transition Metal", .block = 'd', .orbits = 7, .state = 's'},
    {.symbol = "Rg", .name = "Roentgenium", .ano = 111, .am = 282, .type = "Transition Metal", .block = 'd', .orbits = 7, .state = 's'},
    {.symbol = "Cn", .name = "Copernicium", .ano = 112, .am = 285, .type = "Transition Metal", .block = 'd', .orbits = 7, .state = 'g'},
    {.symbol = "Nh", .name = "Nihonium", .ano = 113, .am = 286, .type = "Post-Transition Metal", .block = 'p', .orbits = 7, .state = 's'},
    {.symbol = "Fl", .name = "Flerovium", .ano = 114, .am = 289, .type = "Post-Transition Metal", .block = 'p', .orbits = 7, .state = 'g'},
    {.symbol = "Mc", .name = "Moscovium", .ano = 115, .am = 290, .type = "Post-Transition Metal", .block = 'p', .orbits = 7, .state = 's'},
    {.symbol = "Lv", .name = "Livermorium", .ano = 116, .am = 293, .type = "Post-Transition Metal", .block = 'p', .orbits = 7, .state = 's'},
    {.symbol = "Ts", .name = "Tennessine", .ano = 117, .am = 294, .type = "Halogen", .block = 'p', .orbits = 7, .state = 's'},
    {.symbol = "Og", .name = "Oganesson", .ano = 118, .am = 294, .type = "Nobel Gas", .block = 'p', .orbits = 7, .state = 's'}};
    //declaring all the variables
    char in[3];
    int d=1,i,j,k,y,exist,opt,f,n;
    float radius,velocity,force,density;
    struct ptable *p;
    //main menu
    while(d==1)
    {
    printf("\nChoose one of the following:\n1.Know about a particular element\n2.Alkali Metals\n3.Alkaline Earth Metals\n4.Transition Metals\n5.Post-Transition Metals\n6.Metalloids\n7.Non-Metals(except for halogens)\n8.Halogens\n9.Noble Gases\n10.Lanthanides\n11.Actinindes\n12.Elements in s block\n13.Elements in p block\n14.Elements in d block\n15.Elements in f block\n16.Elements that are solid at room temperature\n17.Elements that are liquid at room temperature\n18.Elements that are gaseous at room temperature\n");
    printf("\nEnter choice: ");
    y=0;
    scanf("%d",&y);
    //about particular element
    if(y==1)
    {
    while(y==1)
    {
        printf("\nEnter name of element: ");
        scanf("%s",in);
        exist=0;
        //pointer initiation for particular element's structure
        for(i=0;i<=117;i++)
        {
            k=1;
            if(strlen(in)==strlen(elements[i].symbol))
            {
            for(j=0;j<strlen(in);j++)
            {
                if(tolower(in[j])!=tolower(elements[i].symbol[j]))
                {
                    k=0;
                    break;
                }
            }
            //assigning address to pointer for specific element
            if(k==1)
            {
                p=&elements[i];
                exist=1;
                break;
            }
            }
        }
        //functionalities
        if(exist==1)
        {
            printf("\nAbout the element:\nSymbol: %s\nName: %s\nAtomic number: %d\nAtomic Mass: %f\nType: %s\nBlock: %c\nNumber of orbits: %d\nState at room temperature: %c\n",p->symbol,p->name,p->ano,p->am,p->type,p->block,p->orbits,p->state);
            printf("\nChoose a property that you want to see (according to Bohr's formulas):\n1.Nuclei Radius\n2.Orbital Radius\n3.Electron Velocity\n4.Force needed to remove electron from atom\n5.Density of atom\n6.Density of nucleus\n");
        }
        else
            printf("This element does not exist.\n");
        opt=0;
        f=1;
        //properties
        while((f==1)&&(exist==1))
        {
            printf("\nenter choice: ");
            scanf("%d",&opt);
            //nucleus radius
            if(opt==1)
            {
                radius = (pow((p->am),0.33))*1.2;
                printf("Nuclei Radius of %s is: %fx10^-15 metres\n",p->name,radius);
            }
            //orbit radius
            else if(opt==2)
            {
                int n;
                printf("enter orbit number: ");
                scanf("%d",&n);
                if((0<n)&&(n<=p->orbits))
                {
                    radius = 0.529*n/(p->ano)/(p->ano);
                    printf("Orbital radius of orbit number %d of the element %s is: %f Armstrong\n",n,p->name,radius);
                }
                else
                {
                    printf("%s does not have this orbit in its ground state\n",p->name);
                }
            }
            //electron velocity
            else if(opt==3)
            {
                int n;
                printf("enter orbit number in which the electron is: ");
                scanf("%d",&n);
                if((0<n)&&(n<=p->orbits))
                {
                    velocity = 2.18*pow(10,6)*(p->ano)/n;
                    printf("Velocity of an electron in the orbit %d of the element %s is: %f metres/second\n",n,p->name,velocity);
                }
                else
                {
                    printf("%s does not have this orbit in its ground state\n",p->name);
                }
            }
            //electrostatic force
            else if(opt==4)
            {
                printf("enter orbit number in which the electron is: ");
                scanf("%d",&n);
                if((0<n)&&(n<=p->orbits))
                {
                    force = 9*1.6*1.6*pow(p->ano,3)/pow(0.529*n,2);
                    printf("Force needed to remove a electron in the orbit %d from an atom of the element %s is: %fx10^-9 Newton\n",n,p->name,force);
                }
                else
                {
                    printf("%s does not have this orbit in its ground state\n",p->name);
                }
            }
            //atomic density
            else if(opt==5)
            {
                density = (p->am)*1.66/(4*3.14*pow((0.529*(p->orbits)/(p->ano)/(p->ano)),3)/3);
                printf("Density of %s is: %fx10^3 kilogram/cubic metre\n",p->name,density);
            }
            //nucleus density
            else if(opt==6)
            {
                density = 1.66/(4*3.14*pow(1.2,3)/3);
                printf("Density of the nucleus is: %fx10^18 kilogram/cubic metre\nNOTE: This value is same for all the atoms.\n",density);
            }
            //invalid choice
            else
            {
                printf("That choice is not available.");
            }
            //to see other properties
            printf("\nDo you want to explore the properties more? Please enter 1(yes) or 0(no): ");
            scanf("%d",&f);
        }
        printf("We hope the element was interesting enough for you !!\n");
        //to repeat for another element
        printf("\nDo you want to know about some other element? Please enter 1(yes) or 0(no): ");
        scanf("%d",&y);
    }
    printf("If you want to know any more about elements please GOOGLE..\n");
    }
    //alkali metals
    else if(y==2)
    {
        printf("Alkali Metals:\n");
        char a[14]="Alkali Metal";
        for(i=0;i<118;i++)
        {
            k=1;
            for(j=0;j<13;j++)
            {
                if(a[j]!=elements[i].type[j])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //alkaline earth metals
    else if(y==3)
    {
        printf("Alkaline Earth Metals:\n");
        char a[22]="Alkaline Earth Metal";
        for(i=0;i<118;i++)
        {
            k=1;
            for(j=0;j<21;j++)
            {
                if(a[j]!=elements[i].type[j])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //transition metals
    else if(y==4)
    {
        printf("Transition Metals:\n");
        char a[17]="Transition Metal";
        for(i=0;i<118;i++)
        {
            k=1;
            for(j=0;j<15;j++)
            {
                if(a[j]!=elements[i].type[j])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //post-transition metals
    else if(y==5)
    {
        printf("Post-Transition Metals:\n");
        char a[22]="Post-Transition Metal";
        for(i=0;i<118;i++)
        {
            k=1;
            for(j=0;j<21;j++)
            {
                if(a[j]!=elements[i].type[j])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //metalloids
    else if(y==6)
    {
        printf("Mettalloids:\n");
        char a[10]="Metalloid";
        for(i=0;i<118;i++)
        {
            k=1;
            for(j=0;j<9;j++)
            {
                if(a[j]!=elements[i].type[j])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //non-metals
    else if(y==7)
    {
        printf("Non-Metals (except halogens):\n");
        char a[10]="Non-Metal";
        for(i=0;i<118;i++)
        {
            k=1;
            for(j=0;j<9;j++)
            {
                if(a[j]!=elements[i].type[j])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //halogens
    else if(y==8)
    {
        printf("Halogens:\n");
        char a[8]="Halogen";
        for(i=0;i<118;i++)
        {
            k=1;
            for(j=0;j<7;j++)
            {
                if(a[j]!=elements[i].type[j])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //noble gases
    else if(y==9)
    {
        printf("Noble Gases:\n");
        char a[10]="Noble Gas";
        for(i=0;i<118;i++)
        {
            k=1;
            for(j=0;j<9;j++)
            {
                if(a[j]!=elements[i].type[j])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //lanthanides
    else if(y==10)
    {
        printf("Lanthanides:\n");
        char a[11]="Lanthanide";
        for(i=0;i<118;i++)
        {
            k=1;
            for(j=0;j<10;j++)
            {
                if(a[j]!=elements[i].type[j])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //actinides
    else if(y==11)
    {
        printf("Actinides:\n");
        char a[9]="Actinide";
        for(i=0;i<118;i++)
        {
            k=1;
            for(j=0;j<8;j++)
            {
                if(a[j]!=elements[i].type[j])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //s block
    else if(y==12)
    {
        printf("S Block Elements:\n");
        for(i=0;i<118;i++)
        {
            if(elements[i].block=='s')
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //p block
    else if(y==13)
    {
        printf("P Block Elements:\n");
        for(i=0;i<118;i++)
        {
            if(elements[i].block=='p')
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //d block
    else if(y==14)
    {
        printf("D Block Elements:\n");
        for(i=0;i<118;i++)
        {
            if(elements[i].block=='d')
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //f block
    else if(y==15)
    {
        printf("F Block Elements:\n");
        for(i=0;i<118;i++)
        {
            if(elements[i].block=='f')
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //solid
    else if(y==16)
    {
        printf("Elements that are solid at room temperature:\n");
        for(i=0;i<118;i++)
        {
            if(elements[i].state=='s')
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //liquid
    else if(y==17)
    {
        printf("Elements that are liquid at room temperature:\n");
        for(i=0;i<118;i++)
        {
            if(elements[i].state=='l')
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //gaseous
    else if(y==18)
    {
        printf("Elements that are gaseous at room temperature:\n");
        for(i=0;i<118;i++)
        {
            if(elements[i].state=='g')
            {
                printf("%s\n",elements[i].name);
            }
        }
    }
    //invalid choice
    else
    {
        printf("This choice is not available.\n");
    }
    //to go back to the start menu if the user want to try more options
    printf("\nDo you want to explore more in the periodic table? Please enter 1(yes) or 0(no): ");
    scanf("%d",&d);
    }
    printf("We hope you had fun !!!\n");
}
