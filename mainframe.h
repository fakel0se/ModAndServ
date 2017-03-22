#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QMainWindow>
#include <procces.h>
#include <QTimer>

namespace Ui {
class mainFrame;
}

class mainFrame : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainFrame(QWidget *parent = 0);
    ~mainFrame();

private:
    QTimer *timer;
    int procCount;
    procces *mass[3];
    Ui::mainFrame *ui;
    procces *activeProc = 0;
public slots:
    void startuem();
    void setActiveProc();
};


#endif // MAINFRAME_H

