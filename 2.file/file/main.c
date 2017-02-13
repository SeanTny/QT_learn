#include <stdio.h>

int main(int argc, char *argv[])
{

    char s[100]={0};
    FILE *p=fopen("D:\\temp\\a.txt","w");//用写的方式打开一个文件
    fputs("hello world!",p);
    fclose(p);

    printf("Hello World tusen 12 !\n");

    //system("pause");
    return 0;
}
