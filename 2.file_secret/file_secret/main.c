#include <stdio.h>
#include <string.h>


int main( )
{
    FILE *p=fopen("D:\\temp\\a.txt","a");//以追加的方式打开文件，不要求文件必须存在

    if(p==NULL)
    {
        printf("file open fail \n");
    }else
    {
        printf("file open success\n");
        fputs("hello tusen welcom to QT for C",p);
        fclose(p);
    }

    printf("hello world!\n");
    return 0;
}



int main2( )
{
    FILE *p=fopen("D:\\temp\\a.txt","r");//以只读的方式打开文件，要求文件必须存在
    //FILE *p=fopen("D:\\temp\\a.txt","r+");//以可读可写的方式打开文件，要求文件必须存在

    if(p==NULL)
    {
        printf("file open fail \n");
    }else
    {
        printf("file open success\n");
        fclose(p);
    }

    printf("hello world!\n");
    return 0;
}











void code (char * s )
{
    while(*s)
    {
        (*s)++;
        s++;
    }
}


int main1()//文件加密的操作
{
    char s[1024]={0};
    FILE *p=fopen("D:\\temp\\a.txt","r");//用读的方式打开一个文件
    FILE *p1=fopen("D:\\temp\\b.txt","w");//用写的方式打开一个文件

    //feof(p);//可以判断文件是否到达最末尾，
    while(!feof(p))
    {
        memset(s,0,sizeof(s));
        fgets(s,sizeof(s),p); //内存buffer 内存的大小，文件指针
        code(s);
        fputs(s,p1);
    }
    fclose(p);
    fclose(p1);

    return 0;
}



