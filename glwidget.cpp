#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    myLines l = myLines(-0.999,-0.999,0.999,-0.999);

    myVe.push_back(l);
    myVe.push_back(myLines(0.999,-0.999,0.999,0.999));
    myVe.push_back( myLines(0.999,0.999,-0.999,0.999));
    myVe.push_back( myLines(-0.999,0.999,-0.999,-0.999));
    qw=false;
}

void GLWidget::initializeGL(){
    glClearColor(0.2,0.2,0.2,0.7);

}


void GLWidget::addNewLines()
{
    myVeNew.clear();

      if(qw)
      {
          for(int i=0;i<myVe.size();i++)
          {
              myVeNew.push_back(myVe[i].getLine1());
              myVeNew.push_back(myVe[i].getLine2());
              myVeNew.push_back(myVe[i].getLine3());
              myVeNew.push_back(myVe[i].getLine4());
          }
      }
      else
      {
          for(int i = 0; i<myVe.size();i++)
          {
              myVeNew.push_back(myVe[i].getLine1());
              myVeNew.push_back(myVe[i].getLine2());
              if(myVe[i].x1==myVe[i].x2)
              {
                  if(myVe[i].x1>0)
                  {
                    myVeNew.push_back(myVe[i].getLine4());
                  }
                  else
                  {
                      myVeNew.push_back(myVe[i].getLine3());
                  }
              }
              if(myVe[i].y1==myVe[i].y2)
              {
                  if(myVe[i].y1>0)
                  {
                    myVeNew.push_back(myVe[i].getLine4());
                  }
                  else
                  {
                      myVeNew.push_back(myVe[i].getLine3());
                  }
              }

          }
          qw=true;
      }
      myVe.clear();
      myVe=myVeNew;
}

void GLWidget::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1);
    glBegin(GL_LINES);

    for(int i=0;i<myVe.size();i++)
    {
        switch(i%3)
        {
        case(0):  glColor3f(1.0, 0.0, 0.0);
            break;
        case(1):  glColor3f(0, 1.0, 0.0);
            break;
        case(2):  glColor3f(0, 0.0, 1.0);
            break;
        }

        glVertex2f(myVe[i].x1,myVe[i].y1);
        glVertex2f(myVe[i].x2,myVe[i].y2);
    }



    glEnd();

}



void GLWidget::resizeGL(int w, int h)
{
 glViewport(0,0,w,h);


}
