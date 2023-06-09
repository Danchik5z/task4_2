#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <logic.h>
#include <QPainter>
#include <QMdiArea>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
     MainWindow(Graph item, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadButton_clicked();

    void on_goButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    Logic logic;
    MainWindow* newWindow;
    int IndexOf(vector<int>* vec, int val);
    Graph* getActiveGraphItem();
};
#endif // MAINWINDOW_H
