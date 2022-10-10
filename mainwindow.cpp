#include "mainwindow.h"
#include "seeyoulater.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    connect( timer, SIGNAL( timeout() ), this, SLOT( endOfLoop()) );
    this->ui->lcdNumber_good->setStyleSheet( "QLCDNumber {color:green;}" );
    this->ui->lcdNumber_bad->setStyleSheet( "QLCDNumber {color:red;}" );
}

void MainWindow::closeEvent( QCloseEvent *event ){
    SeeYouLater *seeYouLater = new SeeYouLater();
    seeYouLater->setWindowTitle( "Сообщение" );
    seeYouLater->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    counter++;
}

void MainWindow::endOfLoop(){
    //qDebug() << currentGoal << " " << counter; //для отладки

    //в зависимости от результата меняем тот или другой счетчик
    if( currentGoal == counter ){
        goodAttempts++;
        this->ui->lcdNumber_good->display( goodAttempts );
    }else{
        badAttempts++;
        this->ui->lcdNumber_bad->display( badAttempts );
    }

    //генерация и задание цели на следующий раунд
    currentGoal = rand()%(maxNumber+1);
    this->ui->label_goal_number->setNum( currentGoal );

    //сбросить счетчик
    counter = 0;
    flashlight();
}

void MainWindow::on_pushButton_start_clicked()
{
    //генерация и задание первой цели
    currentGoal = rand()%(maxNumber+1);
    this->ui->label_goal_number->setNum( currentGoal );
    //сбросить и выставить начальные значения
    goodAttempts = 0;
    badAttempts = 0;
    this->ui->lcdNumber_good->display( goodAttempts );
    this->ui->lcdNumber_bad->display( badAttempts );
    timer->start( loopLength );
    flashlight();
}

void MainWindow::switchNormalColour(){
    this->ui->label_goal_number->setStyleSheet( "QLabel {color:black;}");
}

void MainWindow::flashlight(){
    this->ui->label_goal_number->setStyleSheet( "QLabel {color:blue;}" );
    QTimer::singleShot( 300, this, SLOT( switchNormalColour() ) );
}

void MainWindow::on_pushButton_stop_clicked()
{
    timer->stop();
}
