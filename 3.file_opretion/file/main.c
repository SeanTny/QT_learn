#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>


int main()
{
    FILE *p =fopen("D:\\temp\\a.txt","r");
    while(!feof(p))
    {
        char buf[100]={0};
        fgets(buf,sizeof(buf),p);
        printf("%s",buf);
    }

    fclose(p);
return (0);
}




//big file 超大文件
int  main6()
{
//  srand(time(NULL));
    int i=0;
    FILE *p=fopen("D:\\temp\\a.txt","w");

    for (i=0;i<10000;i++)
    {
        fprintf(p,"%d\n",rand()%256);
    }

    fclose(p);
    printf("end\n");
    return 0;
}



//结构和二进制文件

struct student
{
    char a;
    int age;
};

int main5 ()
{
    struct student st={0};
    FILE *p=fopen("D:\\temp\\a.dat","wb");
    fwrite(&st,sizeof(st),1,p);
    fclose(p);
    printf("%d",sizeof(int));
    return 0;
}





//文件的stat的使用

int main4 ()
{
    struct stat st={0};
    clock_t c1=clock();

    stat("D:\\temp\\a.txt",&st);

    //printf("the stat is %d",st.st_size);

    char * array=malloc(st.st_size);//根据文件的大小，在堆当做动态的分配一块儿内存

    clock_t c2=clock();
    return 0;
}



/***********************************************************************
 *fread 和发write函数书专门对二进制文件进行读写的，
 *其他文件都是针对文本文件的
 *
 ***********************************************************************/
int main2()
{
    char buf[5]={0};
    FILE *p=fopen("D:\\temp\\a.txt","rb");//以二进制只读方式打开文件

    while(!feof(p))
    {
        memset(buf,0,sizeof(buf));
        fread(buf,sizeof(char),sizeof(buf)-1,p);//fread会老老实实的读完你要求的
                                                //其他的是按照一行一行来读取的文件
        printf("%s",buf);
    }


    return 0;
}





int main1(int argc, char *argv[])
{
    char buf[100]={0};
    FILE *p=fopen("D:\\temp\\a.txt","r"); //返回文件指针
    while(!feof(p))
    {
        memset(buf,0,sizeof(buf));
        int a=0;
        int b=0;
        fscanf(p,"%d + %d = ",&a,&b); //以文件作为输入，将空格，回车都当成回车，与scanf用法相似
                                      //scanf 可以以固定格式来读取文件内的内容
        printf("a=%d b=%d\n",a,b);
    }
    fclose(p);

    return 0;
}
