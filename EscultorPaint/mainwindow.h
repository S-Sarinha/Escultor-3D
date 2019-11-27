#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <dialogcreatesculpt.h>
#include "sculptor.h"
#include "figurageometrica.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();

    void set_boxes_limits();
    void clear_boxes_limits();
    void disable_all_shape_group_boxes();
    void enable_valid_shape_group_box();
    void disable_all_locations();
    void update_preview_color();
private slots:
    void create_sculpt(int finished);
    void update_dim(int nx,int ny, int nz);
    void update_positions(int x,int y, int z, int row, int col, bool sculptUpdated);


    void on_setPlaneXY_released();

    void on_setPlaneYZ_released();

    void on_setPlaneXZ_released();


    void on_createNewVoxel_released();

    void on_cutVoxel_released();

    void on_createNewBox_released();

    void on_cutBox_released();

    void on_createNewSphere_released();

    void on_cutSphere_released();

    void on_createNewEllipsoid_released();

    void on_cutEllipsoid_released();

    void on_spinBox_13_valueChanged(int arg1);

    void on_horizontalSlider_13_valueChanged(int value);

    void on_spinBox_12_valueChanged(int arg1);

    void on_horizontalSlider_12_valueChanged(int value);

    void on_spinBox_11_valueChanged(int arg1);

    void on_horizontalSlider_11_valueChanged(int value);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_pushButton_15_pressed();

    void on_createNewSculptor_released();

    void on_createOutputFile_released();


private:
    Ui::MainWindow *ui;
    DialogCreateSculpt *dialogForm;
    Sculptor* sculptor;
    int _nx, _ny, _nz;
    int x_coord, y_coord, z_coord, row_coord,  col_coord;
    int current_plane;
    int r,g,b,a;
    // 0 - putvoxel
    // 1 - cutvoxel
    // 2 - putBox
    // 3 - cutBox
    // 4 - putSphere
    // 5 - cutSphere
    // 6 - putEllipse
    // 7 - cutEllipse
    int current_drawing_option;
    vector<FiguraGeometrica *> fgs;
};

#endif // MAINWINDOW_H
