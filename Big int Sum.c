/* Find out the summation of Big integers
I created a function named sum */
#include<stdio.h>
#include<string.h>
int num1[100],num2[100],rslt[100];
int i,j,m,len1,len2,s,carry;
void sum(char str1[],char str2[])
{
    len1=strlen(str1);
    len2=strlen(str2);
    for(i=0;i<100;i++){
        num1[i]=0;
        num2[i]=0;
        rslt[i]=0;
    }
    m=0;
    for(i=len1-1;i>=0;i--)
        num1[m++]=str1[i]-48;

    m=0;
    for(i=len2-1;i>=0;i--)
        num2[m++]=str2[i]-48;
    carry=0;
    for(i=0;i<100;i++){
        s=num1[i]+num2[i]+carry;
        if(s<10){
            rslt[i]=s;
            carry=0;
        }
        else{
            rslt[i]=s%10;
            carry=s/10;
        }
    }
}
int main()
{
    char str1[101],str2[101];
    int start;
    while(gets(str1)&&gets(str2)){
    sum(str1,str2);
    for(i=99;i>=0;i--){
        if(rslt[i]!=0){
            start=i;
            break;
        }
    }
    for(i=start;i>=0;i--){
        printf("%d",rslt[i]);
}
printf("\n");
}
return 0;
}
