#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct list
{
    char name[30];
    char comp[30];
    float rate;
    int shelves;
    int quan;

};
int bal=0;
struct list data[1000];
int i=0;
//FILE *shop;
int check()
{
    printf("Enter medicine name: ");
    char m[100];
    scanf("%s",m);
    int r=search(m);
    if(r==0)
    {
        add(m);
    }
    else if(r==1)
    {
        system("cls");
        printf("\n         Medicine already in stock.\n               Just Update data\n");
        update(m);

    }
}
int add(char c[])
{
    if(i<1000)
    {
        system("cls");
        printf("Medicine name:%s\n",c);
        fflush(stdin);
        strcpy(data[i].name,c);
        printf("\nEnter Company name: ");
        fflush(stdin);
        gets(data[i].comp);
        printf("\nEnter rate: ");
        fflush(stdin);
        scanf("%f",&data[i].rate);
        printf("\nEnter shelves number: ");
        fflush(stdin);
        scanf("%d",&data[i].shelves);
        printf("\nEnter quantity in packet:");
        fflush(stdin);
        scanf("%d",&data[i].quan);
        printf("\nData saved succesfully\n");
    }
    i++;

    printf("\nPress 1 to add more medicine and 0 to go main menu: ");
    int x;
    scanf("%d",&x);
    if(x==1)
    {
        check();
    }
    else if(x==0)
    {
        dashboard();


    }
}
void display()
{
    system("cls");
    int x;
    int z,k,p;
    struct list temp;

    for(z=0; z<i; z++)
    {
        for(k=0; k<i-1-z; k++)
        {
            if(strcmp(data[k].name,data[k+1].name)>0)
            {
                temp=data[k];
                data[k]=data[k+1];
                data[k+1]=temp;
            }
        }
    }


    printf("                      <===Available Medicine====> \n\n");
    printf("%-10s \t %-20s \t %-20s \t %10s \t %10s \n\n","Medicine Name","Company Name","Rate","Shelf number","Quantity(in packet)");
    for(x=0; x<i; x++)
    {



        printf("%-10s \t %-20s \t %-20.2f \t %-10d \t %-10d\n",data[x].name,data[x].comp,data[x].rate,data[x].shelves,data[x].quan);


    }


    printf("Press 0 to go main menu: ");
    int y;
    scanf("%d",&y);
    if(y==0)
    {
        dashboard();


    }
}
int sell()
{
    system("cls");

    printf("Enter the Medicine name\n");

    char m[100];
    scanf("%s",m);
    int v=search(m);
    if(v==1)
    {
        int r,y;
        printf("\nHow many packets going to sell:");
        scanf("%d",&r);

        for(y=0; y<=i; y++)
        {
            if(strcmp(data[y].name,m)==0)
            {
                if(data[y].quan<r)
                    {
                    printf("\nInsufficient quantity\n");
                    printf("\n0 to go main menu: ");
                    }
                else{


                bal=bal+(data[y].rate*r);
                data[y].quan=data[y].quan-r;
                printf("\nSale successful\n");
                printf("\nPress 1 to sale more medicine and 0 to go main menu: ");
                break;
                }
            }
        }



    }
    else
    {
        printf("\nMedicine is not available.\nPress 0 to go main menu:");
    }


    int x;
    scanf("%d",&x);
    if(x==1)
    {
        sell();
    }
    else if(x==0)
    {
        dashboard();


    }


}
int dashboard()
{
    system("cls");
    printf("<====Welcome to your Pharmacy management system====>\n\n\n");
    printf("<=========Please Enter your choice=========>\n\n\n");
    printf("1.Add new medicine\n");
    printf("2.Sell Medicine\n");
    printf("3.Update \n");
    printf("4.Balance\n");
    printf("5.View all medicine\n");
    printf("6.Search\n");
    int SN;
    scanf("%d",&SN);
    if(SN==1)
    {
        check();
    }
    else if(SN==2)
    {
        sell();
    }

    else if(SN==3)
    {
        printf("Enter medicine name: ");
        char m[100];
        scanf("%s",m);
        int v=search(m);
        if(v==1)
        {
            update(m);
        }
        else
        {
            printf("Medicine is not available.\n");
            printf("\n0 to go main menu: ");
        }

        int x;
        scanf("%d",&x);

        if(x==0)
        {
            dashboard();


        }
    }
    else if(SN==4)
    {
        printf("\nYour total sale is:%d",bal);
        int x;
        printf("\nEnter 0 to go main menu:");
        scanf("%d",&x);
        if(x==0)
        {
            dashboard();


        }
    }
    else if(SN==5)
    {
        display();
    }
    else if(SN==6)
    {
        find();
    }

    else
    {
        printf("Wrong input");

    }
}
int find()
{
    printf("\nPlease enter the name of medicine(use alphabetical case):");
    char s[100];
    scanf("%s",s);
    int e=search(s);
    if(e==0)
    {
        printf("\nNot found or Wrong input\n");
        printf("\nPress 1 to search again.");
        printf("Press 0 to go main menu: ");
    }
    else
    {
        printf("\nPress 1 to search again.");
        printf("Press 0 to go main menu: ");
    }

    int y;
    scanf("%d",&y);
    if(y==1)
    {
        find();

    }
    if(y==0)
    {
        dashboard();
    }



}
int update(char m[])
{


    printf("\nWhat type of data you want to update?\nRate or Quantity:");
    int r,y;
    printf("\nEnter 0 for rate and 1 for quantity:");
    scanf("%d",&r);
    if(r==0)
    {
        for(y=0; y<=i; y++)
        {
            if(strcmp(data[y].name,m)==0)
            {
                printf("\nEnter new rate:");

                int n;
                scanf("%d",&n);

                data[y].rate=n;

                break;
            }
        }

    }

    else if(r==1)
    {
        for(y=0; y<=i; y++)
        {
            if(strcmp(data[y].name,m)==0)
            {
                printf("\nEnter new quantity:");
                int n;
                scanf("%d",&n);
                data[y].quan=data[y].quan+n;

                break;
            }
        }

    }
    printf("Update successful\n");
    printf("Press 0 to go main menu: ");
    int p;
    scanf("%d",&p);
    if(p==0)
    {
        dashboard();


    }

}

int search(char s[])
{
    int z,k,p;
    struct list temp;

    for(z=0; z<i; z++)
    {
        for(k=0; k<i-1-z; k++)
        {
            if(strcmp(data[k].name,data[k+1].name)>0)
            {
                temp=data[k];
                data[k]=data[k+1];
                data[k+1]=temp;
            }
        }
    }


    int low=0,high=i-1;
    int mid;
    int flag=0;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(strcmp(data[mid].name,s)==0)
        {
            printf("\n                            ===========>>Medicine found<<=============                              \n");
            printf("%-10s \t %-20s \t %-20s \t %10s \t %10s \n\n","Medicine Name","Company Name","Rate","Shelf number","Quantity(in packet)");
            // while(fread(&data,sizeof(struct list),1,shop)==1)
            {
                printf("%-10s \t %-20s \t %-20.2f \t %-10d \t %-10d\n",data[mid].name,data[mid].comp,data[mid].rate,data[mid].shelves,data[mid].quan);
                flag++;
                return 1;
                break;
            }

        }
        else if(strcmp(data[mid].name,s)<0)
        {
            low=mid+1;
        }
        else if(strcmp(data[mid].name,s)>0)
        {
            high=mid-1;
        }
    }



    if(flag==0)
    {

        return 0;
    }
}



int main()
{
    system("cls");
    int pass=1245;
    char user[50]="Mahfuz";
    char n[50];
    int y;
    printf("Please enter your user id and password:\n");
    printf("User Id: ");
    scanf("%s",n);
    printf("\nPassword:");
    scanf("%d",&y);
    if(strcmp(user,n)==0&&y==pass)
    {
        dashboard();
    }
    else
    {
        printf("Wrong user or password,Please try again\n");
        int r;
        printf("Enter to 0 to return main menu");
        scanf("%d",&r);
        if(r==0)
        {
            return main();

        }
    }
}

