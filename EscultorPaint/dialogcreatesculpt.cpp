#include "dialogcreatesculpt.h"
#include "ui_dialogcreatesculpt.h"

DialogCreateSculpt::DialogCreateSculpt(int nx, int ny, int nz, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreateSculpt)
{
    ui->setupUi(this);
    current_nx = nx;
    current_ny = ny;
    current_nz = nz;
}

DialogCreateSculpt::~DialogCreateSculpt()
{
    delete ui;
}

void DialogCreateSculpt::on_nxSpinBox_valueChanged(int arg1)
{
    current_nx = arg1;
    emit n_changed(current_nx, current_ny, current_nz);
}


void DialogCreateSculpt::on_nySpinBox_valueChanged(int arg1)
{
    current_ny = arg1;
    emit n_changed(current_nx, current_ny, current_nz);
}

void DialogCreateSculpt::on_nzSpinBox_valueChanged(int arg1)
{
    current_nz = arg1;
    emit n_changed(current_nx, current_ny, current_nz);
}
