#include "seeyoulater.h"
#include "ui_seeyoulater.h"

SeeYouLater::SeeYouLater(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeeYouLater)
{
    ui->setupUi(this);
}

SeeYouLater::~SeeYouLater()
{
    delete ui;
}

void SeeYouLater::on_pushButton_clicked()
{
    this->close();
}
