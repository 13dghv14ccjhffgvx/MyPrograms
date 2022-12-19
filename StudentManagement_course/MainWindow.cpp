#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QKeyEvent>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadData("D:\\MyCode\\QtCode\\StudentManagement_course\\images\\student.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        ui->stackedWidget->setCurrentWidget(ui->menuPage);
    }
}

void MainWindow::loadData(const QString &filename)
{
    QFile file(filename);
    //打开文件
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo()<<"open file failed";
        return;
    }
    //读取数据
    QTextStream stream(&file);
    //读取表头
    m_fields = stream.readLine().split("\t",QString::SplitBehavior::SkipEmptyParts);

    //读取数据 C++98  C++11 C++17 C++20
    while(!stream.atEnd())
    {
        auto lineData = stream.readLine().split("\t",QString::SplitBehavior::SkipEmptyParts);

        auto s = new Student;
        s->number       = lineData[0];
        s->name         = lineData[1];
        s->classname    = lineData[2];
        s->math         = lineData[3].toDouble();
        s->chinese      = lineData[4].toDouble();
        s->english      = lineData[5].toDouble();
        m_students.push_back(s);
    }
}

void MainWindow::saveData(const QString &filename)
{
    //流操作  <<  >>
    //通过文件操作学生的数据？ 不太好..处理麻烦，格式要有规则
    //数据库存储
    //学生表 成绩表 班级表 选课表 ....
    //大数据分析 大数据处理...数据库 8G   2G C语言操作  QQ账号和密码 8000万

    //学！！
    //一步一步，C语言  C++ 数据结构与算法
    //Qt  MFC win32  企业级开发框架
    //数据库 网络编程 多线程

    //十六期班级，马上就要开班了
    //自学。。。  疑难杂症  找一个老师

    //8-10个月，课后练习，巩固，吸收...
    //线下培训: 25000+ 6个月脱产学习
    //跟着咱们:8280  在读书，工作...每天两个小时来学习即可

    //1，学好，学会...
    //2,C语言 C++


    //初中 高中...
    //自律：

}



void MainWindow::on_lookBtn_released()
{
    //切换到查看页面
    ui->stackedWidget->setCurrentWidget(ui->lookPage);
    //把list中的数据显示到表格中
    ui->lookTableWidget->setColumnCount(m_fields.size());
    ui->lookTableWidget->setHorizontalHeaderLabels(m_fields);

    for(auto s : m_students)
    {
        //获取数量（也就是将要添加的新行的行号）
        int row = ui->lookTableWidget->rowCount();
        //1，添加一个空行
        ui->lookTableWidget->insertRow(row);
        //2，把数据设置到空行中
        ui->lookTableWidget->setItem(row,0,new QTableWidgetItem(s->number));
        ui->lookTableWidget->setItem(row,1,new QTableWidgetItem(s->name));
        ui->lookTableWidget->setItem(row,2,new QTableWidgetItem(s->classname));

        ui->lookTableWidget->setItem(row,3,new QTableWidgetItem(QString::number(s->math)));
        ui->lookTableWidget->setItem(row,4,new QTableWidgetItem(QString::number(s->chinese)));
        ui->lookTableWidget->setItem(row,5,new QTableWidgetItem(QString::number(s->english)));

    }
}

void MainWindow::on_statBtn_released()
{
    //切换到统计页面
    ui->stackedWidget->setCurrentWidget(ui->statPage);
}

void MainWindow::on_quitBtn_released()
{
    close();    //关闭窗口
}

void MainWindow::on_addBtn_released()
{
    //添加一个新行，再最下面
    ui->lookTableWidget->insertRow(ui->lookTableWidget->rowCount());
    //跳转到最下面
    ui->lookTableWidget->scrollToBottom();
    //创建一个学生（稍后填充数据）
    m_students.push_back(new Student);

}

void MainWindow::on_saveBtn_released()
{
    for(int i = 0;i<ui->lookTableWidget->rowCount();i++)
    {
        m_students[i]->number   = ui->lookTableWidget->item(i,0)->text();
        m_students[i]->name     = ui->lookTableWidget->item(i,1)->text();
        m_students[i]->classname = ui->lookTableWidget->item(i,2)->text();
        m_students[i]->math     = ui->lookTableWidget->item(i,3)->text().toDouble();
        m_students[i]->chinese  = ui->lookTableWidget->item(i,4)->text().toDouble();
        m_students[i]->english  = ui->lookTableWidget->item(i,5)->text().toDouble();
    }
    QMessageBox::information(this,"保存提示","保存成功");
}
