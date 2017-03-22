#include "mainframe.h"
#include "ui_mainframe.h"

mainFrame::mainFrame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainFrame)
{
    ui->setupUi(this);


    mass[0] = new procces();
    mass[1] = new procces();
    mass[2] = new procces();
    procCount = mass[0]->globalID;
    //procces *n = mass[0] = new procces();

    for (int i = 0; i < procCount; i++) {
        connect(mass[i]->start, SIGNAL(clicked(bool)), this, SLOT(setActiveProc()));
        ui->verticalLayout->addWidget(mass[i]->forLay);
    }

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(startuem()));
    timer->start(2000);

    ui->statusBar->showMessage("It's good");

}

void mainFrame::startuem()
{
    if (activeProc == 0) return;
    if (activeProc->isDone()) setActiveProc();
    activeProc->execute();
}

void mainFrame::setActiveProc()
{


    int maxPrior = 10;
    int thatProc = -1;
    if (true) // после будет тип выполнения (абсолютный , относительный)
    {
        for (int i = 0; i < procCount; i++) {
            if ((mass[i]->getPriority() < maxPrior) && (mass[i]->getQueue())) {
                maxPrior = mass[i]->getPriority();
                thatProc = i;
            }
        }

        if (thatProc == -1){
            ui->statusBar->showMessage("Sooooo boring!!!");
            return;
        }

        if (ui->radioButton->isChecked()) {
            if (activeProc) {
                if (!activeProc->isDone())
                    activeProc->showStatus(3);
            }

            activeProc = mass[thatProc];
            activeProc->showStatus(2);
        } else {
            if (activeProc) {
                if (activeProc->isDone()) {
                    activeProc = mass[thatProc];
                    activeProc->showStatus(2);
                } else {
                    thatProc = -1;
                }
            } else {
                activeProc = mass[thatProc];
                activeProc->showStatus(2);
            }

        }

        for (int i = 0; i < procCount; i++) {
            if (i == thatProc) continue;
            if (mass[i]->getQueue() && (mass[i]->getStatus() == 0))
                mass[i]->showStatus(1);
        }

    }
    ui->statusBar->showMessage("Executing Process №" + QString::number(thatProc+1));
}

mainFrame::~mainFrame()
{
    delete ui;
}

