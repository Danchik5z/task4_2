#ifndef MDIWINDOW_H
#define MDIWINDOW_H

#include <QWidget>
#include <QPainter>
#include "graphitem.h"

class MdiWindow : public QWidget
{
public:
    MdiWindow(Graph item, QWidget *parent = nullptr);
    Graph* getItem();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Graph item;
    int IndexOf(vector<int>* vec, int val);
    void drawVertex(float x, float y, int number, QPainter* painter, string name);
};

#endif // MDIWINDOW_H
