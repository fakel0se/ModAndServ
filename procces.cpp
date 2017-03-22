#include "procces.h"

procces::procces(QWidget *parent, int t1, int t2) : QWidget(parent)
{
    nessTime = t1;
    dueTime = t2;
    globalID++;
    procID = globalID;
    running = 0;


    forLay = new QWidget();
    layout = new QHBoxLayout();
    proc = new QLabel();
    start = new QPushButton("Start");
    priority = new QLineEdit(QString::number(procID));
    status = new QLabel("<font color=red>Don't start</font>");
    done = new QProgressBar();

    status->setFixedSize(100, 20);
    start->setFixedSize(55, 20);
    proc->setFixedSize(80, 20);
    priority->setFixedSize(51,20);
    done->setFixedSize(100, 20);

    proc->setText("Process " + QString::number(procID));
    layout->addWidget(proc);
    layout->addWidget(done);
    layout->addWidget(status);
    layout->addWidget(priority);
    layout->addWidget(start);

    forLay->setLayout(layout);
    connect(start, SIGNAL(clicked(bool)), this, SLOT(inQueue()));


}

void procces::showStatus(int st) {
    switch(st) {
        case 0:
        case 1:  status->setText("<font color=black>In queue</font>");
                 running = 1;
                 break;
        case 2:  status->setText("<font color=green>Running</font>");
                 running = 2;
                 break;
        case 3:  status->setText("<font color=blue>Waiting</font>");
                 running = 3;
                 break;
        case 4:  status->setText("Done!"); break;
        default: break;
    }
}

void procces::inQueue()
{
    waitP = true;
    //status->setText("<font color=black>In queue</font>");
}

void procces::waiting()
{
    running = 1;
    //status->setText("<font color=black>In queue</font>");
}

void procces::startProcess()
{
    running = 2;
    //status->setText("<font color=green>Running</font>");
    done->setMinimum(0);
    done->setMaximum(nessTime);
}

void procces::pause()
{
    running = 3;
    //status->setText("<font color=yellow>Waiting</font>");

}

void procces::execute()
{    
    executingTime += dueTime;
    if (executingTime < nessTime) {
        done->setValue(executingTime*100/nessTime);
    } else {
        running = 4;
        waitP = false;
        status->setText("Done!");
        done->setValue(100);
    }
}


int procces::getID() {return procID;}
int procces::getStatus() {return running;}
QString procces::getProc() {return proc->text();}
int procces::getPriority() {return (priority->text().toInt());}
bool procces::isDone() {return running == 4;}
bool procces::getQueue() {return waitP;}

int procces::globalID = 0;
