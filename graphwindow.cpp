#include "graphwindow.h"

graphWindow::graphWindow(QWidget *parent) : QMdiArea(parent)
{

}

void graphWindow::paintEvent(QPaintEvent *event)
{
    QMdiArea::paintEvent(event);

    QPainter painter(viewport());

    // Calculate the logo position - the bottom right corner of the mdi area.
//    int x = width() - m_pixmap.width();/*
//    int y = height() - m_pixmap.height();
//    painter.drawPixmap(x, y, m_pixmap);*/
}
