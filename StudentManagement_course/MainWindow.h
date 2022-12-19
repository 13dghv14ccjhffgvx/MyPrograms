#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include"Student.h"
#include<QStringList>
#include<QList>
#include<QTableWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //键盘操作
    void keyPressEvent(QKeyEvent *event) override;
    //加载数据(从文件中读取数据)
    void loadData(const QString& filename);
    void saveData(const QString&filename);

private slots:

    void on_lookBtn_released();

    void on_statBtn_released();

    void on_quitBtn_released();

    void on_addBtn_released();

    void on_saveBtn_released();

private:
    Ui::MainWindow *ui;

    QStringList m_fields;   //表头字段
    QList<Student*> m_students;
};
#endif // MAINWINDOW_H
