#include<stdio.h>
#include<string.h>
#include<math.h>
char main_data[1000];
char encoded[1000];
int ascii[1000];
int binary[1000];
char for_hamming[1000];
char decoded[1000];
int m_encoded[1000];
int parity[2];
int ham=0;
int d_ascii[1000];
char final_data[1000];
int binarytoascii(int bin)
{
    int rem,i,j;
    rem=j=0;
    int dec=0;

    {
        while(bin>0)
        {
            rem=bin%10;
            dec=dec+rem*(int)pow (2,j);
            bin=bin/10;
            j++;
        }
    }


    return dec;





}
int decryptnrz()
{
    int g;
    int lastbit;
    if(m_encoded[0]==0)
    {
        lastbit=1;
    }
    else
    {
        lastbit=-1;
    }
    for(int i=0; i<strlen(encoded); i++)
    {
        if(m_encoded[i]==0)
        {

            m_encoded[i]=0;
        }
        else
        {
            m_encoded[i]=1;

        }
    }

    return 0;



}

int nrz_I()
{
    int g;
    for(g=0; g<strlen(encoded); g++)
    {
        if(encoded[g]=='0')
        {
            m_encoded[g]=0;
        }
        else
        {
            m_encoded[g]=1;
        }
    }
    int lastbit;
    if(m_encoded[0]==0)
    {
        lastbit=1;
    }
    else
    {
        lastbit=-1;
    }
    for(int i=0; i<strlen(encoded); i++)
    {
        if(m_encoded[i]==0)
        {
            m_encoded[i]=0;
        }
        else
        {
            m_encoded[i]=-lastbit;
            lastbit=-lastbit;
        }
    }
    return g;



}
int even_hamming(int p,int tl)
{
    int i=0;
    int j=0;
    int count=0;
    int a=p-1;
    while(a<tl)
    {
        for(j=a; j<a+p; j++)
        {
            if(encoded[j]=='1')
            {
                count++;
            }


        }

        a=a+2*p;

    }
    if(count%2==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }




}
int convertascii(int number)
{
    char temp[1000];
    int j=0;
    int i=1;
    int f=0;
    int binary_num=0;
    int remainder=0;
    while (number != 0)
    {
        remainder = number % 2;
        if(remainder==0)
        {
            temp[f]='0';
        }
        else
        {
            temp[f]='1';
        }
        number /= 2;
        binary_num += remainder * i;
        i *= 10;
        f++;
    }
    for(int k=f-1; k>=0; k--)
    {
        for_hamming[ham]=temp[k];
        ham++;
    }
    return binary_num;



}
int main()
{
    printf("Enter the main data: ");
    scanf("%s",main_data);
    int i=0;
    int j;
    int p=0;
    while(main_data[i]!='\0')
    {
        main_data[i] =main_data[i]-2;
        ascii[i]=(int)main_data[i];
        i++;

    }
    printf("\nData after stuffing:");
    printf(main_data);
    printf("\nData after Ascii:");
    for(int n=0; n<strlen(main_data); n++)
    {
        printf("%d",ascii[n]);
    }

    for(j=0; j<i; j++)
    {

        binary[j]=convertascii(ascii[j]);


    }
    printf("\nBinary value for hamming:");
    for_hamming[strlen(for_hamming)]='\0';
    int ml=strlen(for_hamming);
    // printf("%d",ml);
    printf(for_hamming);
    int base=1;
    int total_length=ml+2;
    while(ml>(int)pow(base,2)-3)
    {
        base++;
    }

    int d=0;
    int k=0;
    for(int i=0; i<total_length; i++)
    {
        if(i==(int)pow(base,d)-1)
        {
            encoded[i]='0';
            d++;
        }
        else
        {
            encoded[i]=for_hamming[k];
            k++;
        }
    }
    encoded[total_length]='\0';



    for(int p=0; p<2; p++)
    {
        int x=(int)pow(base,p);
        int y=even_hamming(x,total_length);
        parity[p]=y;

        if(y==0)
        {
            encoded[x-1]='0';
        }
        else
        {
            encoded[x-1]='1';
        }
    }

    encoded[total_length]='\0';
    printf("\nData after Hamming parity:");
    printf(encoded);
    printf("\n");

    int len=nrz_I();
    printf("\nData after Hybrid line coding:");
    for(int y=0; y<len; y++)
    {
        printf("%d",m_encoded[y]);
    }
    char op;
    printf("\nAre you to decrypt data: Yes/No:");
    scanf("%s",&op);
    if(op=='y'||op=='Y')
    {
        int v= decryptnrz();
        printf("\nData after Line coding decryption:");
        for(int cm=0; cm<strlen(encoded); cm++)
        {
            printf("%d",m_encoded[cm]);
        }


        for(int q=0; q<2; q++)
        {
            int l=(int)pow(base,q);
            int c=even_hamming(l,total_length);

        }
        int g=0;
        int h=0;

        for(int f=0; f<total_length; f++)
        {
            if(f!=(int)pow(base,g)-1)
            {
                decoded[h]=encoded[f];
                h++;
            }
            else
            {
                g++;
            }
            decoded[total_length]='\0';
        }
        printf("\nData after Hamming decryption:");
        printf(decoded);

        for(int v=0; v<i; v++)
        {
            d_ascii[v] =binarytoascii(binary[v]);
            final_data[v]=d_ascii[v]+2;
        }
        printf("\nFinal Decrypted data:");
        printf(final_data);


    }
    else
    {
        printf("Thank you");
    }

}
