#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// ����ѧ���ṹ������
struct student
{
    int iNo;
    QString strName;
    int score;
};
Q_DECLARE_METATYPE(student)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
