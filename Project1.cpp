#include <stdio.h>
#include<string.h>
int ab=0;
void display()
{
    printf("------------------------------------------------ \n");
    printf("	CAR BRAND 	MODEL   RENT PER DAY(Inr)  \n");
    printf("------------------------------------------------\n");
    printf(" 	HYUNDAI   	Creta    	250      	\n");
    printf(" 	SUZUKI     	800     	250        	\n");
    printf("  	HONDA    	City     	250      	\n");
    printf(" 	TOYOTA   	Innova    	250      	\n");
    printf("   	BMW   	5 Series   	250      	\n");
    printf("  	TATA    	Indigo    	250      	\n");
    printf("	MERCEDES   	E-Class  	250      	\n");
    printf("  	AUDI     	Q3       	250       	\n");
    printf(" 	DATSUN    	Go       	250      	\n");
    printf("---------------------------------------------- \n");
}
struct car   //c,ca[10],cr[10],cn={0},,,,,                     	basically c is the input from user
{           //c.carrented is the brand of car you wanna rent...... ca[i] is pre existing repository of cars that have already been rented
	char customername[50];
	char customerId[13];
	char carrented[20];
	int n,rent,days;
	int dr,mr,yr,dret,mret,yret;  	//dr, mr, yr is date on which you will take the car
	//dret mret yret is date to return the car
};
char carbrand[10][20]={"HYUNDAI","SUZUKI","HONDA","TOYOTA","BMW","TATA","MERCEDES","AUDI","DATSUN"};
char carmodel[10][20]={"Creta","800","City","Innova","5 Series","Indigo","E-Class","Q3","Go"};
int carseat[10]={4,4,4,8,4,4,4,8,8,0};
int carrentperday[10]={250,250,250,250,250,250,250,250,250,0};
int carrentpermontly[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int z=0,u=0;
struct car c,ca[10],cr[10],cn={0};//
int date(int y1,int y2,int m1,int m2,int d1,int d2)
{
	int i,days1=0,days2=0,days3=0 ;
        for(i=0;i<=m1;i++)
            days1+=carrentpermontly[i];
        for(i=0;i<=m2;i++)
            days2+=carrentpermontly[i];
        days1+=d1;
        days2+=d2;
        return(days2-days1);
}
void car_rent()
{
	int i,f;
	int t,days1=0,days2=0,days3=0;
	char ch;
	int j,x;
    printf("Welcome! \n");
	display();
    printf("ENTER THE BRAND OF CAR YOU WANT TO RENT: ");
    scanf("%s",c.carrented);
    printf("ENTER DATE ON WHICH YOU WILL TAKE THE CAR(dd mm yyyy): ");
    scanf("%d%d%d",&c.dr,&c.mr,&c.yr);
    printf("ENTER THE DATE ON WHICH YOU WILL RETURN THE CAR(dd mm yyyy): ");
    scanf("%d%d%d",&c.dret,&c.mret,&c.yret);
    printf("LETS CHECK WHETHER THE CAR IS AVAILABLE OR NOT\n");
  
       for(i=0;i<10;i++)
   	{
        if(strcmp(ca[i].carrented,c.carrented)==0)	//if strings are equal then return 0
    	{
            for(t=0;t<=ca[i].mr;t++){
                days1+=carrentpermontly[t];    //days1 is stored value of the previous users rent date and days2 is the return date
        	}
            for(t=0;t<=ca[i].mret;t++){
                days2+=carrentpermontly[t];
        	}
            for(t=0;t<=c.mr;t++){
                days3+=carrentpermontly[t];  //here days3 is for counting the number of days the user has inputted that he is going to rent the car
        	}
            days1+=ca[i].dr;
            days2+=ca[i].dret;
            days3+=c.dr;
            if((days3-days1)*(days2-days3)>=0)
                f=1;
        	else
        	f=0;
               if(f==1)
           	{
                 printf("Car not available.Are you interested in trying another car?\nIf yes enter Y else enter N\n");
                 getchar();
                 scanf("%c",&ch);
                 if(ch=='y'||ch=='Y')
                    car_rent();
                 else
                 {
                     printf("Thank You \n\n\n");
                     break;
                 }
           	}
    	}
    	else if(strcmp(ca[i].carrented,c.carrented)!=0 ||f==0) //output is non zero hence strings are not equal
    	{
            printf("CAR AVAILABLE!! \n");
        	
            strcpy(ca[u].carrented,c.carrented);//int u=0 was declared before and input from user to rent the car has been stored in the repository containing all the cars that have been rented
            ca[u].dr=c.dr;
            ca[u].mr=c.mr;
            ca[u].yr=c.yr;
            ca[u].dret=c.dret;
            ca[u].mret=c.mret;
            ca[u].yret=c.yret;
 
            printf("ENTER YOUR NAME: ");
            scanf("%s",c.customername);
            printf("ENTER YOUR ID NUMBER: ");
            scanf("%s",c.customerId);
            c.n=date(c.yr,c.yret,c.mr,c.mret,c.dr,c.dret);
            for(j=0;j<10;j++)
        	{
                x=strcmp(c.carrented,carbrand[j]);
                if(x==0)
                    break;
        	}
            c.rent=c.n*carrentperday[j];
            printf("WARNING: If any damage is done to the car then you are entirely responsible. The car has to be returned in its initial condition.\n");
            printf("Details:\n");
            printf("NAME:\t%s\nID:\t%s\nCAR RENTED:\t%s\nNUMBER OF DAYS:\t%d\nRENT:\t%d\n",c.customername,c.customerId,c.carrented,c.n,c.rent);
            strcpy(cr[z].customername,c.customername);
            strcpy(cr[z].customerId,c.customerId);
            strcpy(cr[z].carrented,c.carrented);
            cr[z].n=c.n;
            cr[z].rent=c.rent;
        	z++;
	        ab++;
            break;
    	}
	}
}
 
void car_return()
{
	char id[13];
	int dd,mm,yy,d,m,y,flag=0,i,j;
    printf("Welcome back dear customer \n");
    printf("Please enter your id\n");
    scanf("%s",id);
    for(i=0;i<10;i++)
	{
        if(strcmp(cr[i].customerId,id)==0)
    	{
            flag=1;
            printf("HELLO %s\n",cr[i].customername);
            printf("For confirmation please enter the date on which you took the car and the date on which you are returning the date in(dd mm yyyy)format.\n");
            scanf("%d%d%d",&dd,&mm,&yy);
            scanf("%d%d%d",&d,&m,&y);
            cr[i].days=date(yy,y,mm,m,dd,d);
            if(cr[i].days>cr[i].n)
        	{
                    cr[i].rent+=50*(cr[i].days-cr[i].n);
        	}
            printf("FINAL AMOUNT:%d \n",cr[i].rent);
            printf("\n\n");
            break;
    	}
	}
	if(flag==0)
       	{
             printf("Customer not found\n");
       	}
    	else
    	{
            for(j=0;j<10;j++)
        	{
                if(j==i){
                   
                printf("%s\n",cr[j].carrented);}
        	}
    	}
}
 
int main()
{
	z=0;
	ab=0;
	int q,p=0,g,h;
    for(g=1;g<=365;g++)
	{
        for(h=1;h<=10;h++)
    	{
            printf("\nEnter 1 to rent/ return a car. \nEnter 0 to view the history of transactions. \n");
            scanf("%d",&p);
            if(p==1)
        	{
                label:
                printf("\a1.RENT A CAR.\n 2.RETURN THE CAR.\n");
                scanf("%d",&q);
                switch(q)
                {
                    case 1:{car_rent();u++;z;
                    break;}
                    case 2:car_return();
                    break;
                    default:{printf("Wrong choice!! Try again.\n");
                    goto label;}
                }
        	}
            if(p==0){
                 for(int z=0;z<ab;z=z+1){
                 printf("Details:\n");
            printf("NAME:\t%s\nID:\t%s\nCAR RENTED:\t%s\nNUMBER OF DAYS:\t%d\nRENT:\t%d\n",cr[z].customername,cr[z].customerId,cr[z].carrented,cr[z].n,cr[z].rent);
        	
        	}
        	}
    	}
        printf("\n\n\nThank you for using the app!\a\n\n\n");
	}
}
 














#include<bits/stdc++.h>
using namespace std;

class info{
    friend class user;
    friend class admin;
    vector<string>brand;
    vector<string>model;
    vector<string>rent;
    public:
    void add(string b,string m, string r){
        brand.push_back(b);
        model.push_back(m);
        rent.push_back(r);
    }   
    void disp(){
        for(int i=0;i<brand.size();i++){
            cout<<i+1<<" "<<brand[i]<<" "<<model[i]<<" "<<rent[i]<<" "<<endl;
        }
    }
    void rem(int in){
        brand.erase(brand.begin()+in-1);
        model.erase(model.begin()+in-1);
        rent.erase(rent.begin()+in-1);
    }
    
    
};
class user:public info{
    public:
    
};
class admin:public info{
    public:
    void add(string b,string m, string r,info&){
        brand.push_back(b);
        model.push_back(m);
        rent.push_back(r);
    }

    
    
};




int main(){
    info inf;
    inf.add("hyundai","creta","250");
    inf.add("suzuki","800","200");
    inf.add("honda","city","300");
    inf.add("toyota","fortuner","300");
    inf.add("bmw","5 series","400");
    inf.add("tata","safari","230");
    inf.add("mercedes","s class","330");
    inf.add("audi","a4","430");
    inf.add("datsun","go","200");
    admin admin1;
    for(int i=1;i<100;i++){
        cout<<"1: Display inventory"<<endl;
        cout<<"2: Add car to inventory"<<endl;
        cout<<"3: Remove car from inventory"<<endl;
        cout<<"4: Rent a car"<<endl;
        cout<<"5: Return a car"<<endl;
        int x;
        cin>>x;
        string br,cr,rt;
        int ind;
        switch(x){
            case 1:
            inf.disp();
            break;
            case 2:
            cout<<endl<<"Enter Brand name: "<<endl;cin>>br;
            cout<<endl<<"Enter Car name: "<<endl;cin>>cr;
            cout<<endl<<"Enter Rent: "<<endl;cin>>rt;
            inf.add(br,cr,rt);
            break;
            case 3:
            cout<<endl<<"Enter the index number of car to be removed: "<<endl;
            cin>>ind;
            inf.rem(ind);
            break;
            case 4:
            cout<<endl<<"Enter index number of car to be rented: "endl;
            cin>>ind;
            
            break;
            case 5:
            break;
            default:
            cout<<endl<<"enter a valid number"<<endl;
        }
        
    }
    return 0;
}
