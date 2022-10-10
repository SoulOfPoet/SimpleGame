#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    //окончание раунда
    void endOfLoop();
    //запуск игры
    void on_pushButton_start_clicked();
    //остановка игры
    void on_pushButton_stop_clicked();
    //подсветка числа для явной смены
    void flashlight();
    //возврат обычного цвета
    void switchNormalColour();
    //обработка закрытия главного окна
    void closeEvent( QCloseEvent *event );

private:
    Ui::MainWindow *ui;
    QTimer *timer = nullptr;
    int goodAttempts = 0; //количество удачных попыток
    int badAttempts = 0; //количество неудачных попыток
    const int loopLength = 2000; //длина раунда в ms
    const int maxNumber = 5; //верхняя граница диапазона количества кликов
    int counter = 0; //счетчик кликов пользователя
    int currentGoal; //цель текущего раунда
};
#endif // MAINWINDOW_H
