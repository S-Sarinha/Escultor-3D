#ifndef DIALOGCREATESCULPT_H
#define DIALOGCREATESCULPT_H

#include <QDialog>

namespace Ui {
class DialogCreateSculpt;
}

class DialogCreateSculpt : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateSculpt(int nx, int ny, int nz, QWidget *parent = nullptr);
    ~DialogCreateSculpt();

private slots:
    void on_nxSpinBox_valueChanged(int arg1);

    void on_nySpinBox_valueChanged(int arg1);

    void on_nzSpinBox_valueChanged(int arg1);

signals:
    void n_changed(int _nx, int _ny, int _nz);

private:
    Ui::DialogCreateSculpt *ui;
    int current_nx;
    int current_ny;
    int current_nz;
};

#endif // DIALOGCREATESCULPT_H
