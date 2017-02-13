#include <stdio.h>
#include <string.h>


int main()//读文件的操作
{
    char s[1024]={0};
    FILE *p=fopen("D:\\temp\\a.txt","r");//用写的方式打开一个文件

    //feof(p);//可以判断文件是否到达最末尾，
    while(!feof(p))
    {
        memset(s,0,sizeof(s));
        fgets(s,sizeof(s),p); //内存buffer 内存的大小，文件指针
        printf("%s",s);
    }
    fclose(p);

    return 0;
}



int main0(int argc, char *argv[]) //写文件的代码
{

    char s[100]={0};
    FILE *p=fopen("D:\\temp\\a.txt","w");//用写的方式打开一个文件
                                         //"w":代表如果文件不存在就建立一个，如果文件存在就覆盖
    while(1)
    {
        memset(s,0,sizeof(s));
        //scanf("%s",s);
        gets(s);
        if(strcmp(s,"exit")==0)
        {
            break;
        }

        int len=strlen(s);
        s[len]='\n';

        fputs(s,p);
    }

    fclose(p);
    printf("Hello World tusen 12 !\n");
    printf("this is file opretion !\n");
    return 0;
}
