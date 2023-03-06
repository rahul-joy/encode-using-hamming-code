#include<stdio.h>
#include<math.h>
int code[100];
int hamming_bit(int pos,int len)
{
    int count=0,i=pos;

    while(i<=len)
    {
        for(int j=i;j<i+pos;j++)
        {
            if(code[j]==1)
            count++;
        }
        i=i+pos*2;
    }

    if(count%2==0)
        return 0;
    else
        return 1;
}
void solver(int arr[], int n)
{
    //calculate redantdunt bits
    int r=0;
    while (n>((int) pow(2,r)-(r+1)))
        r++;
        //code size after encoding
    int codelen=r+n;
    //maessage and redantdunt bits assiging
    int p=0,j=0;
    for(int i=1;i<=codelen;i++)
    {
        if(i==(int) pow(2,p))
        {
            code[i]=0;
            p++;
        }
        else
            code[i]=arr[j++];
    }
    //Updating redandunt bits
    p=0;
    while(p<r)
    {
        int pos=(int)pow(2,p);
        int value=hamming_bit(pos,codelen);
        code[pos]=value;
        p++;
    }
    //Display massage after encoding
     for(int i=1;i<=codelen;i++)
    {
        printf("%d ",code[i]);
    }
}
int main()
{
    int input[]={1,0,0,1,1,0,1};

    int N=sizeof(input)/sizeof(input[0]);
    solver(input,N);
    return 0;
}
