#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <QObject>
#include <QWidget>

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QMouseEvent>
#include "sculptor.h"

class DrawManager : public QWidget
{
    Q_OBJECT
public:
    explicit DrawManager(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void drawBackGround();
    void drawGrid();
    void updateGridInfo();
    void updateSculptInfo(Sculptor* sculpt, int current_x, int current_y, int current_z, int current_plane);
    void setCurrent_x(int value);

    void setCurrent_y(int value);

    void setCurrent_z(int value);

    void setCurrent_plane(int value);
protected:
    Sculptor* sculpt;
    QPen pen;
    QBrush brush;
    int square_size;
    int margin_size_hor;
    int margin_size_ver;
    int n_ver;
    int n_hor;
    bool vertical_grid;
    int current_x;
    int current_y;
    int current_z;
    int current_plane;
    int click_min_valid_hor;
    int click_max_valid_hor;
    int click_min_valid_ver;
    int click_max_valid_ver;
    int click_x_fixed;
    int click_y_fixed;
    int selected_square_row;
    int selected_square_col;

signals:
    void positions(int x, int y, int z, int selected_row, int selected_col, bool sculptUpdated);

public slots:
};

#endif // DRAWMANAGER_H
