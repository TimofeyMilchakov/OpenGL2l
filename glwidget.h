#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGL>
#include <vector>
#include "mylines.h"
using namespace std;


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void addNewLines();
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    vector<myLines> myVe;
vector<myLines> myVeNew;
bool qw;



};

#endif // GLWIDGET_H
