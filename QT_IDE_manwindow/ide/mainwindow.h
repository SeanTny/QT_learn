#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>   //QT已经帮我们写好了的一个控件
#include <QMenu>
#include <QMenuBar>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QString filename;
    QTextEdit *text1;

    QMenu *file;
    QMenu *edit;
    QMenu *build;
    QMenu *help;

    QAction *file_open;
    QAction *file_save;
    QAction *file_exit;

    QAction *edit_copy;
    QAction *edit_paste;
    QAction *edit_cut;
    QAction *edit_selectAll;

    QAction *build_compile;
    QAction *build_run;

    QAction *help_about;


public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_open();
    void on_save();
    void on_about();
    void on_exit();
    void on_copy();
    void on_paste();
    void on_cut();
    void on_edit_selectAll();
    void on_compile();
    void on_run();


};

#endif // MAINWINDOW_H
