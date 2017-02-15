#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char buf[100]={0};
    FILE *p=fopen("D:\\temp\\a.txt","r"); //返回文件指针
    while(!feof(p))
    {
        memset(buf,0,sizeof(buf));
       // fgets(buf,sizeof(buf),p);
        fscanf(p,"%s",buf); //以文件作为输入，将空格，回车都当成回车，与scanf用法相似
        printf("%s",buf);
    }
    fclose(p);

    return 0;
}
