#include "mdiwindow.h"
#include <cmath>


MdiWindow::MdiWindow(Graph item, QWidget *parent): QWidget(parent)
{
    this->item = item;
}

Graph* MdiWindow::getItem()
{
    return &item;
}

void MdiWindow::paintEvent(QPaintEvent *event)
{
    vector<int>* vertexes = item.getVertexes();
    int nVert = vertexes->size();
    vector<vector<int>>* connections = item.getConnection();
    vector<string>* names = item.getNames();
    float midlX = 120.;
    float midlY = 120.;
    float R = 100.;
    QPainter painter;
    painter.begin(this);
    vector<float> X;
    vector<float> Y;
    for(int i = 0; i < nVert; i++){
        float x = (cos(2 * 3.14 * i / nVert) * R + 0.5) + midlX;
        X.push_back(x);
        float y = (sin(2 * 3.14 * i / nVert) * R + 0.5) + midlY;
        Y.push_back(y);
        drawVertex(x, y, item.getVertexes()->at(i), &painter, names->at(i));
    }
    QPen pen;
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    for(int i = 0; i < connections->size(); i++){
        for(int j = 0; j < connections->at(i).size(); j++){
            painter.drawLine(X[i], Y[i], X[IndexOf(vertexes, connections->at(i).at(j))], Y[IndexOf(vertexes, connections->at(i).at(j))]);
        }
    }
    painter.end();
}

int MdiWindow::IndexOf(vector<int> *vec, int val)
{
    for(int i = 0; i < vec->size(); i++)
            if(vec->at(i) == val)
                return i;
        return -1;
}

void MdiWindow::drawVertex(float x, float y, int number, QPainter *painter, string name)
{
    QFont font = painter->font();
    font.setPixelSize(18);
    painter->setFont(font);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(3);
    painter->setPen(pen);

    const QRect rectangle = QRect(x - 10, y - 10, x + 15,y + 25);
    painter->drawText(rectangle, 0, QString::fromStdString(to_string(number) + name));
    painter->drawEllipse(x - 15, y - 15, 30, 30);
}

