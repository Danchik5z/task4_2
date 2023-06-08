#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include <QDebug>
#include "loggingcategories.h"
#include <QColor>
#include <cmath>
#include <QtGui>
#include <QInputDialog>
#include "mdiwindow.h"
#include <QMdiSubWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(Graph item, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::IndexOf(vector<int> *vec, int val)
{
    for(int i = 0; i < vec->size(); i++)
            if(vec->at(i) == val)
                return i;
    return -1;
}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Text files (*.txt)"));
    Graph item = logic.readFileItem(fileName.toStdString());

    QWidget *widget = new MdiWindow(item, ui->mdiArea);
    ui->mdiArea->addSubWindow(widget);
    widget->setWindowTitle(fileName);
    widget->show();

    qInfo(logInfo()) << "loaded from file";
}

void MainWindow::on_goButton_clicked()
{
    if(!ui->mdiArea->isActiveWindow()){
        qInfo(logWarning()) << "no active window";
        return;
    }

    bool ok;
    int vertex = QInputDialog::getInt(this, QString::fromUtf8("Input vertex"),
                             QString::fromUtf8("Vertex:"), 0, 0, 10000, 1, &ok);
    if (!ok){
        qInfo(logWarning()) << "invalid input";
        return;
    }

    vector<Graph> items = logic.splitGraph(vertex, getActiveGraphItem());
    for(int i = 0; i < items.size(); i++){
        QWidget *widget = new MdiWindow(items[i], ui->mdiArea);
        ui->mdiArea->addSubWindow(widget);
        widget->setWindowTitle(QString::fromStdString("layer" + to_string(i)));
        widget->show();

    }
    qInfo(logInfo()) << "graph splited from " + QString::fromStdString(to_string(vertex));
}

void MainWindow::on_saveButton_clicked()
{
    Graph* item = getActiveGraphItem();

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Text files (*.txt)"));
    logic.writeFile(fileName.toStdString(), item);
    qInfo(logInfo()) << "saved graph to file";
}

Graph *MainWindow::getActiveGraphItem()
{
    QMdiSubWindow* subWindow = ui->mdiArea->activeSubWindow();
    MdiWindow* widget = static_cast<MdiWindow*>(subWindow->widget());
    return widget->getItem();
}

