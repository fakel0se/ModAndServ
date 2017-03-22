#ifndef PROCCES_H
#define PROCCES_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QHBoxLayout>

class procces : public QWidget
{
    Q_OBJECT
public:
    explicit procces(QWidget *parent = 0, int t1 = 333, int t2 = 10);

    static int globalID;
    QWidget *forLay;
    QPushButton* start;

    QString getProc();
    int getID();
    int getStatus();
    int getPriority();
    bool isDone();
    bool getQueue();


    void showStatus(int i);
    void execute();
    void pause();
    void waiting();
    void startProcess();

private:
    QLabel *status;
    QLabel *proc;
    QProgressBar *done;
    QLineEdit *priority;
    QHBoxLayout *layout;

    bool waitP = false;
    short running = 0; //executing status: 0 - not running, 1 - in queue, 2 - running, 3 - waiting, 4 - done
    int executingTime = 0;
    int nessTime;
    int dueTime;
    int procID = 0;


signals:

public slots:
    void inQueue();
};

#endif // PROCCES_H
