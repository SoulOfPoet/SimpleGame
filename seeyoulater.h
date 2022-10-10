#ifndef SEEYOULATER_H
#define SEEYOULATER_H

#include <QDialog>

namespace Ui {
class SeeYouLater;
}

class SeeYouLater : public QDialog
{
    Q_OBJECT

public:
    explicit SeeYouLater(QWidget *parent = nullptr);
    ~SeeYouLater();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SeeYouLater *ui;
};

#endif // SEEYOULATER_H
