/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "drawmanager.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *createNewSculptor;
    QPushButton *createNewVoxel;
    QPushButton *cutVoxel;
    QPushButton *createNewBox;
    QPushButton *cutBox;
    QPushButton *createNewSphere;
    QPushButton *cutSphere;
    QPushButton *createNewEllipsoid;
    QPushButton *cutEllipsoid;
    QPushButton *setPlaneXY;
    QPushButton *setPlaneXZ;
    QPushButton *setPlaneYZ;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QSpinBox *spinBox_5;
    QLabel *label_7;
    QSpinBox *spinBox_6;
    QLabel *label_8;
    QSpinBox *spinBox_7;
    QGroupBox *groupBox;
    QLabel *label_2;
    QSpinBox *spinBox;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QLabel *label_4;
    QSpinBox *spinBox_3;
    QLabel *label_5;
    QSpinBox *spinBox_4;
    QGroupBox *groupBox_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label;
    QPushButton *pushButton_15;
    QGroupBox *groupBox_6;
    QLabel *label_12;
    QSlider *horizontalSlider_11;
    QSpinBox *spinBox_11;
    QLabel *label_13;
    QSlider *horizontalSlider_12;
    QSpinBox *spinBox_12;
    QLabel *label_14;
    QSlider *horizontalSlider_13;
    QSpinBox *spinBox_13;
    DrawManager *plainTextEdit;
    QPushButton *createOutputFile;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        createNewSculptor = new QPushButton(centralWidget);
        createNewSculptor->setObjectName(QStringLiteral("createNewSculptor"));
        createNewSculptor->setGeometry(QRect(10, 10, 60, 60));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/new_item.png"), QSize(), QIcon::Normal, QIcon::Off);
        createNewSculptor->setIcon(icon);
        createNewSculptor->setIconSize(QSize(32, 32));
        createNewVoxel = new QPushButton(centralWidget);
        createNewVoxel->setObjectName(QStringLiteral("createNewVoxel"));
        createNewVoxel->setGeometry(QRect(80, 10, 60, 60));
        QIcon icon1;
        icon1.addFile(QStringLiteral("icons/color_cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        createNewVoxel->setIcon(icon1);
        createNewVoxel->setIconSize(QSize(32, 32));
        cutVoxel = new QPushButton(centralWidget);
        cutVoxel->setObjectName(QStringLiteral("cutVoxel"));
        cutVoxel->setGeometry(QRect(150, 10, 60, 60));
        QIcon icon2;
        icon2.addFile(QStringLiteral("icons/empty_cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutVoxel->setIcon(icon2);
        cutVoxel->setIconSize(QSize(32, 32));
        createNewBox = new QPushButton(centralWidget);
        createNewBox->setObjectName(QStringLiteral("createNewBox"));
        createNewBox->setGeometry(QRect(220, 10, 60, 60));
        QIcon icon3;
        icon3.addFile(QStringLiteral("icons/colour_rubik.png"), QSize(), QIcon::Normal, QIcon::Off);
        createNewBox->setIcon(icon3);
        createNewBox->setIconSize(QSize(32, 32));
        cutBox = new QPushButton(centralWidget);
        cutBox->setObjectName(QStringLiteral("cutBox"));
        cutBox->setGeometry(QRect(290, 10, 60, 60));
        QIcon icon4;
        icon4.addFile(QStringLiteral("icons/empty_rubik.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutBox->setIcon(icon4);
        cutBox->setIconSize(QSize(32, 32));
        createNewSphere = new QPushButton(centralWidget);
        createNewSphere->setObjectName(QStringLiteral("createNewSphere"));
        createNewSphere->setGeometry(QRect(360, 10, 60, 60));
        QIcon icon5;
        icon5.addFile(QStringLiteral("icons/colour_globe.png"), QSize(), QIcon::Normal, QIcon::Off);
        createNewSphere->setIcon(icon5);
        createNewSphere->setIconSize(QSize(32, 32));
        cutSphere = new QPushButton(centralWidget);
        cutSphere->setObjectName(QStringLiteral("cutSphere"));
        cutSphere->setGeometry(QRect(430, 10, 60, 60));
        QIcon icon6;
        icon6.addFile(QStringLiteral("icons/empty_globe.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutSphere->setIcon(icon6);
        cutSphere->setIconSize(QSize(32, 32));
        createNewEllipsoid = new QPushButton(centralWidget);
        createNewEllipsoid->setObjectName(QStringLiteral("createNewEllipsoid"));
        createNewEllipsoid->setGeometry(QRect(500, 10, 60, 60));
        QIcon icon7;
        icon7.addFile(QStringLiteral("icons/colour_ellipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        createNewEllipsoid->setIcon(icon7);
        createNewEllipsoid->setIconSize(QSize(32, 32));
        cutEllipsoid = new QPushButton(centralWidget);
        cutEllipsoid->setObjectName(QStringLiteral("cutEllipsoid"));
        cutEllipsoid->setGeometry(QRect(570, 10, 60, 60));
        QIcon icon8;
        icon8.addFile(QStringLiteral("icons/empty_ellipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutEllipsoid->setIcon(icon8);
        cutEllipsoid->setIconSize(QSize(32, 32));
        setPlaneXY = new QPushButton(centralWidget);
        setPlaneXY->setObjectName(QStringLiteral("setPlaneXY"));
        setPlaneXY->setGeometry(QRect(640, 10, 60, 60));
        QIcon icon9;
        icon9.addFile(QStringLiteral("icons/xy.png"), QSize(), QIcon::Normal, QIcon::Off);
        setPlaneXY->setIcon(icon9);
        setPlaneXY->setIconSize(QSize(48, 48));
        setPlaneXZ = new QPushButton(centralWidget);
        setPlaneXZ->setObjectName(QStringLiteral("setPlaneXZ"));
        setPlaneXZ->setGeometry(QRect(780, 10, 60, 60));
        QIcon icon10;
        icon10.addFile(QStringLiteral("icons/zx.png"), QSize(), QIcon::Normal, QIcon::Off);
        setPlaneXZ->setIcon(icon10);
        setPlaneXZ->setIconSize(QSize(48, 48));
        setPlaneYZ = new QPushButton(centralWidget);
        setPlaneYZ->setObjectName(QStringLiteral("setPlaneYZ"));
        setPlaneYZ->setGeometry(QRect(710, 10, 60, 60));
        QIcon icon11;
        icon11.addFile(QStringLiteral("icons/yz.png"), QSize(), QIcon::Normal, QIcon::Off);
        setPlaneYZ->setIcon(icon11);
        setPlaneYZ->setIconSize(QSize(48, 48));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(720, 80, 291, 621));
        groupBox_4->setStyleSheet(QStringLiteral("background-color: rgb(220, 220, 220);"));
        groupBox_3 = new QGroupBox(groupBox_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 30, 270, 120));
        groupBox_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 30, 41, 17));
        spinBox_5 = new QSpinBox(groupBox_3);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setGeometry(QRect(130, 30, 48, 26));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 60, 41, 17));
        spinBox_6 = new QSpinBox(groupBox_3);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setGeometry(QRect(130, 60, 48, 26));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(70, 90, 41, 17));
        spinBox_7 = new QSpinBox(groupBox_3);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setGeometry(QRect(130, 90, 48, 26));
        groupBox = new QGroupBox(groupBox_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 160, 270, 101));
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 50, 41, 17));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(130, 50, 71, 26));
        groupBox_2 = new QGroupBox(groupBox_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 270, 270, 120));
        groupBox_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 30, 21, 17));
        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(97, 30, 71, 26));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 60, 21, 17));
        spinBox_3 = new QSpinBox(groupBox_2);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(97, 60, 71, 26));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 90, 21, 17));
        spinBox_4 = new QSpinBox(groupBox_2);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(97, 90, 71, 26));
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 400, 270, 151));
        groupBox_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(170, 30, 21, 17));
        label_9->setStyleSheet(QStringLiteral(""));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(170, 60, 21, 17));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(170, 90, 16, 17));
        doubleSpinBox = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(190, 25, 61, 26));
        doubleSpinBox->setStyleSheet(QStringLiteral(""));
        doubleSpinBox->setDecimals(3);
        doubleSpinBox->setMaximum(1);
        doubleSpinBox->setSingleStep(0.004);
        doubleSpinBox->setValue(1);
        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(190, 55, 61, 26));
        doubleSpinBox_2->setDecimals(3);
        doubleSpinBox_2->setMaximum(1);
        doubleSpinBox_2->setSingleStep(0.004);
        doubleSpinBox_2->setValue(1);
        doubleSpinBox_3 = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(190, 85, 61, 26));
        doubleSpinBox_3->setDecimals(3);
        doubleSpinBox_3->setMaximum(1);
        doubleSpinBox_3->setSingleStep(0.004);
        doubleSpinBox_3->setValue(1);
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(170, 120, 21, 17));
        label_15->setStyleSheet(QStringLiteral(""));
        doubleSpinBox_4 = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(190, 120, 61, 26));
        doubleSpinBox_4->setDecimals(3);
        doubleSpinBox_4->setMaximum(1);
        doubleSpinBox_4->setSingleStep(0.004);
        doubleSpinBox_4->setValue(1);
        label = new QLabel(groupBox_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 111, 91));
        label->setStyleSheet(QStringLiteral(""));
        pushButton_15 = new QPushButton(groupBox_4);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(48, 560, 191, 41));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 540, 700, 161));
        groupBox_6->setLayoutDirection(Qt::LeftToRight);
        groupBox_6->setStyleSheet(QStringLiteral("background-color: rgb(220, 220, 220);"));
        groupBox_6->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 40, 67, 17));
        horizontalSlider_11 = new QSlider(groupBox_6);
        horizontalSlider_11->setObjectName(QStringLiteral("horizontalSlider_11"));
        horizontalSlider_11->setGeometry(QRect(30, 40, 531, 16));
        horizontalSlider_11->setOrientation(Qt::Horizontal);
        spinBox_11 = new QSpinBox(groupBox_6);
        spinBox_11->setObjectName(QStringLiteral("spinBox_11"));
        spinBox_11->setGeometry(QRect(570, 40, 101, 26));
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 80, 67, 17));
        horizontalSlider_12 = new QSlider(groupBox_6);
        horizontalSlider_12->setObjectName(QStringLiteral("horizontalSlider_12"));
        horizontalSlider_12->setGeometry(QRect(30, 80, 531, 16));
        horizontalSlider_12->setOrientation(Qt::Horizontal);
        spinBox_12 = new QSpinBox(groupBox_6);
        spinBox_12->setObjectName(QStringLiteral("spinBox_12"));
        spinBox_12->setGeometry(QRect(570, 75, 101, 26));
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 120, 67, 17));
        horizontalSlider_13 = new QSlider(groupBox_6);
        horizontalSlider_13->setObjectName(QStringLiteral("horizontalSlider_13"));
        horizontalSlider_13->setGeometry(QRect(30, 120, 531, 16));
        horizontalSlider_13->setOrientation(Qt::Horizontal);
        spinBox_13 = new QSpinBox(groupBox_6);
        spinBox_13->setObjectName(QStringLiteral("spinBox_13"));
        spinBox_13->setGeometry(QRect(570, 115, 101, 26));
        plainTextEdit = new DrawManager(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 80, 691, 441));
        plainTextEdit->setMouseTracking(true);
        plainTextEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        createOutputFile = new QPushButton(centralWidget);
        createOutputFile->setObjectName(QStringLiteral("createOutputFile"));
        createOutputFile->setGeometry(QRect(850, 10, 60, 60));
        QFont font;
        font.setPointSize(10);
        createOutputFile->setFont(font);
        createOutputFile->setIconSize(QSize(48, 48));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        createNewSculptor->setToolTip(QApplication::translate("MainWindow", "nova escultura", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        createNewSculptor->setText(QString());
#ifndef QT_NO_TOOLTIP
        createNewVoxel->setToolTip(QApplication::translate("MainWindow", "pintar voxel", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        createNewVoxel->setText(QString());
#ifndef QT_NO_TOOLTIP
        cutVoxel->setToolTip(QApplication::translate("MainWindow", "remover voxel", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cutVoxel->setText(QString());
#ifndef QT_NO_TOOLTIP
        createNewBox->setToolTip(QApplication::translate("MainWindow", "pintar cubo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        createNewBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        cutBox->setToolTip(QApplication::translate("MainWindow", "remover cubo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cutBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        createNewSphere->setToolTip(QApplication::translate("MainWindow", "pintar esfera", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        createNewSphere->setText(QString());
#ifndef QT_NO_TOOLTIP
        cutSphere->setToolTip(QApplication::translate("MainWindow", "remover esfera", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cutSphere->setText(QString());
#ifndef QT_NO_TOOLTIP
        createNewEllipsoid->setToolTip(QApplication::translate("MainWindow", "pintar ellipsoid", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        createNewEllipsoid->setText(QString());
#ifndef QT_NO_TOOLTIP
        cutEllipsoid->setToolTip(QApplication::translate("MainWindow", "remover ellipsoid", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cutEllipsoid->setText(QString());
#ifndef QT_NO_TOOLTIP
        setPlaneXY->setToolTip(QApplication::translate("MainWindow", "visualizar plano XY", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        setPlaneXY->setText(QString());
#ifndef QT_NO_TOOLTIP
        setPlaneXZ->setToolTip(QApplication::translate("MainWindow", "visualizar plano ZX", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        setPlaneXZ->setText(QString());
#ifndef QT_NO_TOOLTIP
        setPlaneYZ->setToolTip(QApplication::translate("MainWindow", "visualizar plano YZ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        setPlaneYZ->setText(QString());
        groupBox_4->setTitle(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Retangulo", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "dimX", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "dimY", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "dimZ", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Esfera", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Raio", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Ellipse", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Rx", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Ry", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Rz", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Cor", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "R", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "G", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "B", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
        label->setText(QString());
        pushButton_15->setText(QApplication::translate("MainWindow", "aplicar", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "localiza\303\247\303\243o", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        createOutputFile->setToolTip(QApplication::translate("MainWindow", "visualizar plano ZX", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        createOutputFile->setText(QApplication::translate("MainWindow", ".off/.vec", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
