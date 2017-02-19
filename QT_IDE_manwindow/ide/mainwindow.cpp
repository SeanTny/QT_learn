#include "mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) //构造函数
{
    //*******************编辑框**********************************************
    text1=new QTextEdit;
    QFont f;
    f.setPixelSize(20);
    text1->setFont(f); //设置text1的字体大小为30
    /*  QColor c;
    c.setRgb(255,100,100);
    text1->setTextColor(c);//设置颜色rgb  */
    this->setCentralWidget(text1);//将这个texteditfang放到中间


    //*******************菜单栏********************************************
    file=this->menuBar()->addMenu("文件");//在菜单栏加入一个菜单项
    edit=this->menuBar()->addMenu("编辑");
    build=this->menuBar()->addMenu("构建");
    help=this->menuBar()->addMenu("帮助");



    //********************文件菜单********************************************
    file_open=new QAction("打开",this);//建立一个action
    file->addAction(file_open);//将file_open这个cation加入到file菜单下面
    file_open->setShortcut(tr("Ctrl+O"));//将open菜单的快捷键设置为Ctrl+O


    file->addSeparator();//加入一个分隔符

    file_save= new QAction("保存",this);
    file->addAction(file_save);
    file_save->setShortcut(tr("Ctrl+S"));

    file->addSeparator();//加入一个分隔符

    file_exit=new QAction("退出",this);
    file->addAction(file_exit);
    file_exit->setShortcut(tr("Ctrl+D"));


    //*********************编辑菜单*******************************************
    edit_copy =new QAction("复制",this);
    edit->addAction(edit_copy);
    edit_copy->setShortcut(tr("Ctrl+C"));

    edit->addSeparator();//加入一个分隔符

    edit_paste =new QAction("粘贴",this);
    edit->addAction(edit_paste);
    edit_paste->setShortcut(tr("Ctrl+V"));

    edit->addSeparator();//加入一个分隔符

    edit_cut=new QAction("剪切",this);
    edit->addAction(edit_cut);
    edit_cut->setShortcut(tr("Ctrl+X"));

    edit->addSeparator();//加入一个分隔符

    edit_selectAll=new QAction("全选",this);
    edit->addAction(edit_selectAll);
    edit_selectAll->setShortcut(tr("Ctrl+A"));


    //********************构建菜单***********************************************
    build_compile=new QAction("编译",this);
    build->addAction(build_compile);
    build_compile->setShortcut(tr("F5"));

    build->addSeparator();//加入一个分隔符

    build_run=new QAction("运行",this);
    build->addAction(build_run);



    //*********************帮助菜单**********************************************
    help_about=new QAction("关于",this);
    help->addAction(help_about);
    help_about->setShortcut(tr("Ctrl+H"));



    //**********************QT的信号与槽******************************************
    //QT的消息与槽机制
    //第一个参数：触发这个事件的控件，
    //第二个参数：对于action来讲，是QT里面的固定写法 SIGNAL(triggered())
    //第三个参数固定写this
    //第四个参数指定点击action会执行哪个函数。
    connect(file_open,SIGNAL(triggered()),this,SLOT(on_open()));
    connect(file_save,SIGNAL(triggered()),this,SLOT(on_save()));
    connect(file_exit,SIGNAL(triggered()),this,SLOT(on_exit()));

    connect(edit_copy,SIGNAL(triggered()),this,SLOT(on_copy()));
    connect(edit_paste,SIGNAL(triggered()),this,SLOT(on_paste()));
    connect(edit_cut,SIGNAL(triggered()),this,SLOT(on_cut()));
    connect(edit_selectAll,SIGNAL(triggered()),this,SLOT(on_edit_selectAll()));

    connect(build_compile,SIGNAL(triggered()),this,SLOT(on_compile()));
    connect(build_run,SIGNAL(triggered()),this,SLOT(on_run()));

    connect(help_about,SIGNAL(triggered()),this,SLOT(on_about()));


}

MainWindow::~MainWindow() //析构函数
{
    delete text1;
}

void MainWindow::on_open()
{
    filename=QFileDialog::getOpenFileName(); //打开一个标准的文件对话框，返回值是用户选择的文件名。
    //QMessageBox::information(this,"提示",Filename);
    //return;
    if(filename.isEmpty())//没有选择任何文件
        return;

    QString content;        //QT定义的一个字符串类.
    FILE *p=fopen(filename.toStdString().data(),"r");//将Qstring类转换成标准字符串。
    if(p==NULL)
    {
        QMessageBox::information(this,"错误","打开文件失败");
    }
    else
    {
        char buf[1024]={0};
        while(!feof(p))
        {
            memset(buf,0,sizeof(buf)); //也可是使用生命周期的做法
            fgets(buf,sizeof(buf),p);
            content +=buf; //将buf内的字符串追加到content的后面。
        }
        fclose(p);
        text1->setText(content);//将Qstring里面的字符放入text1里面
    }

}

void MainWindow::on_save()
{
    filename =QFileDialog::getSaveFileName();
    if(filename.isEmpty())
        return;
    FILE *p=fopen(filename.toStdString().data(),"w");
    if(p==NULL)
    {
        QMessageBox::information(this,"提示","打开文件失败");
    }else
    {
        //text1->toPlainText().toStdString().data();//将用户在text1控件中输入的字符串转化为const char * 类型
        fputs(text1->toPlainText().toStdString().data(),p);
        fclose(p);
    }

}


void MainWindow::on_about()
{
    QMessageBox::information(this,"关于","涂森：版权所有\n2016-2025");
}


void MainWindow::on_exit()
{
    exit(0);
}

void MainWindow::on_copy()
{
    text1->copy();
}

void MainWindow::on_paste()
{
    text1->paste();
}

void MainWindow::on_cut()
{
    text1->paste();
}

void MainWindow::on_edit_selectAll()
{
    text1->selectAll();
}

void MainWindow::on_compile()
{
    QString destname=filename;
    destname.replace(".c",".exe");//将filename中的.c替换成.exe
    QString command="gcc -o "+ destname + " " + filename;

    //QMessageBox::information(this,"提示",command);
    system(command.toStdString().data());

}

void MainWindow::on_run()
{
   // QMessageBox::information(this,"提示","run");
    QString destname=filename;
    destname.replace(".c",".exe");//将filename中的.c替换成.exe
    QMessageBox::information(this,"提示","run"+destname);
    system(destname.toStdString().data());
}










