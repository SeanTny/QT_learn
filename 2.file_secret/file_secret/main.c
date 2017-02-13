#include <stdio.h>
#include <string.h>


void code (char * s )
{
    while(*s)
    {
        (*s)++;
        s++;
    }
}


int main()//读文件的操作
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



