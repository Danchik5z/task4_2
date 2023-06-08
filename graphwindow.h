#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H
#include <QMdiArea>

class graphWindow : public QWidget
{
public:
    graphWindow(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

private:
    // Store the logo image.
};

#endif // GRAPHWINDOW_H
