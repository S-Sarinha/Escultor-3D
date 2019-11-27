#include "mainwindow.h"
#include "drawmanager.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include "qdebug.h"

/*!
      Método que inicializa os parâmetros da janela do programa.
      \param _nx é a quantidade de elementos na dimensao x.
      \param _ny é a quantidade de elementos na dimensao y.
      \param _nz é a quantidade de elementos na dimensao z.
      \param sculptor é o escultor criado.
      \param x_coord, y_coord e z_coord são as cordenadas atuais nas direções x, y e z.
      \param current_plane é o plano atual. 0 para XY, 1 para YZ e 2 para ZX.
      \param current_drawing_option operação atual sendo realizada. 0 - putvoxel, 1 - cutvoxel, 2 - putBox, 3 - cutBox, 4 - putSphere, 5 - cutSphere, 6 - putEllipsoid, 7 - cutEllipsoid.
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.
      \param isOn habilita o voxel (isOn=1) ou desabilita (isOn=0).
    */
void MainWindow::init()
{
    _nx = 0;
    _ny = 0;
    _nz = 0;
    sculptor = nullptr;//inicializa sculptor com valor nulo
    dialogForm = new DialogCreateSculpt(_nx, _ny, _nz);
    dialogForm->setVisible(false);
    x_coord = 0;
    y_coord = 0;
    z_coord = 0;
    // 0 - XY
    // 1 - YZ
    // 2 - ZX
    current_plane = 0;

    // 0 - putvoxel
    // 1 - cutvoxel
    // 2 - putBox
    // 3 - cutBox
    // 4 - putSphere
    // 5 - cutSphere
    // 6 - putEllipse
    // 7 - cutEllipse
    current_drawing_option = 0;//opcoes de desenho

    connect(dialogForm, SIGNAL(finished(int)), this, SLOT( create_sculpt(int) ) );
    connect(dialogForm, SIGNAL(n_changed(int, int, int)), this, SLOT( update_dim(int, int, int) ) );
    connect(ui->plainTextEdit, SIGNAL(positions(int, int , int, int, int, bool)), this, SLOT(update_positions(int, int , int, int, int, bool)) );

    clear_boxes_limits();
    disable_all_shape_group_boxes();
    disable_all_locations();
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    ui->doubleSpinBox->setValue(r/255.0);
    ui->doubleSpinBox_2->setValue(g/255.0);
    ui->doubleSpinBox_3->setValue(b/255.0);
    ui->doubleSpinBox_4->setValue(a/255.0);
    update_preview_color();
    ui->groupBox_4->setTitle("PutVoxel");
    ui->pushButton_15->setVisible(false);

}

/*!
      Método que atualiza a cor no vizualizador de cores da interface.
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.
    */
void MainWindow::update_preview_color()
{
    QPixmap myPix( QSize(ui->label->width(),ui->label->height()) );
    myPix.fill(QColor(255,255,255,255));
    QPainter painter(&myPix);

    painter.setBrush( QColor(r,g,b,a) );
    painter.drawRect(0, 0, ui->label->width(), ui->label->height());

    ui->label->setPixmap(myPix);
}

/*!
      Método que desabilita os atributos das formas geometricas que não estiverem sendo utilizadas na região de desenho.

    */
void MainWindow::disable_all_shape_group_boxes()
{
    ui->groupBox->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_2->setEnabled(false);
}

/*!
      Método que desabilita os sliders de indicação dos planos que estiverem fixos na vizualização 2D.

    */
void MainWindow::disable_all_locations()
{
    ui->horizontalSlider_11->setEnabled(false);
    ui->spinBox_11->setReadOnly(true);

    ui->horizontalSlider_12->setEnabled(false);
    ui->spinBox_12->setReadOnly(true);

    ui->horizontalSlider_13->setEnabled(false);
    ui->spinBox_13->setReadOnly(true);

}

/*!
      Método que reseta os valores dos sliders e caixas de atributos da janela principal.

    */
void MainWindow::clear_boxes_limits()
{
    int range_top_limit = 0;
    int range_bot_limit = 0;
    ui->horizontalSlider_11->setRange(range_bot_limit, range_top_limit);
    ui->horizontalSlider_11->setValue(range_bot_limit);

    ui->horizontalSlider_12->setRange(range_bot_limit, range_top_limit);
    ui->horizontalSlider_12->setValue(range_bot_limit);

    ui->horizontalSlider_13->setRange(range_bot_limit, range_top_limit);
    ui->horizontalSlider_13->setValue(range_bot_limit);

    ui->spinBox_11->setRange(range_bot_limit, range_top_limit);
    ui->spinBox_11->setValue(range_bot_limit);

    ui->spinBox_12->setRange(range_bot_limit, range_top_limit);
    ui->spinBox_12->setValue(range_bot_limit);

    ui->spinBox_13->setRange(range_bot_limit, range_top_limit);
    ui->spinBox_13->setValue(range_bot_limit);

    // retangulo 3d
    ui->spinBox_5->setRange(range_bot_limit, range_top_limit);
    ui->spinBox_6->setRange(range_bot_limit, range_top_limit);
    ui->spinBox_7->setRange(range_bot_limit, range_top_limit);


    // Esfera
    ui->spinBox->setRange(range_bot_limit, range_top_limit);

    //Ellipse
    ui->spinBox_2->setRange(range_bot_limit, range_top_limit);
    ui->spinBox_3->setRange(range_bot_limit, range_top_limit);
    ui->spinBox_4->setRange(range_bot_limit, range_top_limit);
}

/*!
      Método que limita os valores dos sliders e caixas de atributos da janela principal (sendo os cursores limitados por nx (número de elementos na direção x), ny (número de elementos na direção y) e nz (número de elementos na direção z).

    */
void MainWindow::set_boxes_limits()
{
    if(sculptor!=nullptr)
    {
        int range_top_limit = 9999;
        int range_bot_limit = 0;
        // Localização
        ui->horizontalSlider_11->setRange(range_bot_limit, sculptor->getNx()-1);
        ui->horizontalSlider_11->setValue(range_bot_limit);

        ui->horizontalSlider_12->setRange(range_bot_limit, sculptor->getNy()-1);
        ui->horizontalSlider_12->setValue(range_bot_limit);

        ui->horizontalSlider_13->setRange(range_bot_limit, sculptor->getNz()-1);
        ui->horizontalSlider_13->setValue(range_bot_limit);

        ui->spinBox_11->setRange(range_bot_limit, sculptor->getNx()-1);
        ui->spinBox_11->setValue(range_bot_limit);

        ui->spinBox_12->setRange(range_bot_limit, sculptor->getNy()-1);
        ui->spinBox_12->setValue(range_bot_limit);

        ui->spinBox_13->setRange(range_bot_limit, sculptor->getNz()-1);
        ui->spinBox_13->setValue(range_bot_limit);

        // retangulo 3d
        ui->spinBox_5->setRange(range_bot_limit, range_top_limit);
        ui->spinBox_6->setRange(range_bot_limit, range_top_limit);
        ui->spinBox_7->setRange(range_bot_limit, range_top_limit);


        // Esfera
        ui->spinBox->setRange(range_bot_limit, range_top_limit);

        //Ellipse

        ui->spinBox_2->setRange(range_bot_limit, range_top_limit);
        ui->spinBox_3->setRange(range_bot_limit, range_top_limit);
        ui->spinBox_4->setRange(range_bot_limit, range_top_limit);
    }

}

/*!
      Construtor padrão da classe MainWindow. Dentro dele, a interface é criada e o método init é chamado para inicializar os parâmetros da janela principal.

    */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

/*!
      Destrutor padrão da classe MainWindow.

    */
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
      Método que cria uma nova escultura.
      \param _nx é a quantidade de elementos na dimensao x.
      \param _ny é a quantidade de elementos na dimensao y.
      \param _nz é a quantidade de elementos na dimensao z.
      \param sculptor é o escultor criado.
      \param x_coord, y_coord e z_coord são as cordenadas atuais nas direções x, y e z.
      \param current_plane é o plano atual. 0 para XY, 1 para YZ e 2 para ZX.

    */
void MainWindow::create_sculpt(int finished)
{
    dialogForm->setVisible(false);
    if (finished == 1)
    {
        if(_nx > 0 && _ny > 0 && _nz >0)
        {
            if(sculptor!=nullptr)
            {
                delete sculptor;
            }
            sculptor = new Sculptor(_nx, _ny, _nz);
            current_plane = 0;
            x_coord = 0;
            y_coord = 0;
            z_coord = 0;
            ui->plainTextEdit->updateSculptInfo(sculptor, x_coord, y_coord, z_coord, current_plane);
            if(current_plane == 0)
            {
                on_setPlaneXY_released();
            }
            else if(current_plane == 1)
            {
                on_setPlaneXZ_released();
            }
            else if(current_plane == 2)
            {
                on_setPlaneYZ_released();
            }

            this->set_boxes_limits();
            ui->plainTextEdit->repaint();
        }
    }
}

/*!
      Método que atualiza os valores das coordenadas x y e z quando um sinal é emitido a partir dos eventos ocorridos na classe drawmanager.
      \param x é a posição na dimensao x.
      \param y é a posição na dimensao y.
      \param z é a posição na dimensao z.
      \param row é o índice do quadrado selecionado no grid na direção horizontal.
      \param col é o índice do quadrado selecionado no grid na direção vertical.
      \param sculptUpdated indica qual evento ocorreu. false para mouse movement e true para mouse press.
      \param x_coord, y_coord e z_coord são as cordenadas atuais nas direções x, y e z.

    */
void MainWindow::update_positions(int x,int y, int z, int row, int col, bool sculptUpdated)
{
    row_coord =  row;
    col_coord = col;
    if (row_coord >= 0 && col_coord >= 0)
    {
        x_coord = x;
        y_coord = y;
        z_coord = z;
        on_spinBox_13_valueChanged(z_coord);
        on_spinBox_12_valueChanged(y_coord);
        on_spinBox_11_valueChanged(x_coord);
        if (sculptUpdated)
        {
            on_pushButton_15_pressed();
        }
    }
}

/*!
      Método que atualiza as dimensões da escultura.
      \param _nx é a quantidade de elementos na dimensao x.
      \param _ny é a quantidade de elementos na dimensao y.
      \param _nz é a quantidade de elementos na dimensao z.
    */
void MainWindow::update_dim(int nx,int ny, int nz)
{
    _nx = nx;
    _ny = ny;
    _nz = nz;
}

/*!
      Método que seleciona a exibição do plano XY e suas propriedades quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_setPlaneXY_released()
{
    this->current_plane = 0;
    disable_all_locations();
    // enable Z
    ui->horizontalSlider_13->setEnabled(true);
    ui->spinBox_13->setReadOnly(false);

    ui->plainTextEdit->setCurrent_plane(this->current_plane);
    ui->plainTextEdit->repaint();
}

/*!
      Método que seleciona a exibição do plano YZ e suas propriedades quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_setPlaneYZ_released()
{
    this->current_plane = 1;
    disable_all_locations();
    // enable X
    ui->horizontalSlider_11->setEnabled(true);
    ui->spinBox_11->setReadOnly(false);

    ui->plainTextEdit->setCurrent_plane(this->current_plane);
    ui->plainTextEdit->repaint();
}

/*!
      Método que seleciona a exibição do plano XZ e suas propriedades quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_setPlaneXZ_released()
{
    this->current_plane = 2;
    disable_all_locations();
    // enable Y
    ui->horizontalSlider_12->setEnabled(true);
    ui->spinBox_12->setReadOnly(false);

    ui->plainTextEdit->setCurrent_plane(this->current_plane);
    ui->plainTextEdit->repaint();
}

/*!
      Método de criação de um novo voxel quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_createNewVoxel_released()
{
    //putvoxel enabled
    disable_all_shape_group_boxes();
    current_drawing_option = 0;
    ui->groupBox_4->setTitle("PutVoxel");
}

/*!
      Método da operação de CutVoxel quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_cutVoxel_released()
{
    //cutvoxel enabled
    disable_all_shape_group_boxes();
    current_drawing_option = 1;
    ui->groupBox_4->setTitle("CutVoxel");
}

/*!
      Método de criação de um cubo quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_createNewBox_released()
{
    //putBox enabled
    disable_all_shape_group_boxes();
    ui->groupBox_3->setEnabled(true);
    current_drawing_option = 2;
    ui->groupBox_4->setTitle("PutBox");
}

/*!
      Método da operação de CutBox quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_cutBox_released()
{
    //cutBox enabled
    disable_all_shape_group_boxes();
    ui->groupBox_3->setEnabled(true);
    current_drawing_option = 3;
    ui->groupBox_4->setTitle("CutBox");
}

/*!
      Método de criação de uma esfera quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_createNewSphere_released()
{
    //putSphere enabled
    disable_all_shape_group_boxes();
    ui->groupBox->setEnabled(true);
    current_drawing_option = 4;
    ui->groupBox_4->setTitle("PutSphere");
}

/*!
      Método da operação de CutSphere quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_cutSphere_released()
{
    //cutSphere enabled
    disable_all_shape_group_boxes();
    ui->groupBox->setEnabled(true);
    current_drawing_option = 5;
    ui->groupBox_4->setTitle("CutSphere");
}

/*!
      Método de criação de um elipsóide quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_createNewEllipsoid_released()
{
    //putEllipse enabled
    disable_all_shape_group_boxes();
    ui->groupBox_2->setEnabled(true);
    current_drawing_option = 6;
    ui->groupBox_4->setTitle("PutEllipsoid");
}

/*!
      Método da operação de CutEllipsoid quando o botão da barra de tarefa referente a essa operação for liberado.
    */
void MainWindow::on_cutEllipsoid_released()
{
    //cutEllipse enabled
    disable_all_shape_group_boxes();
    ui->groupBox_2->setEnabled(true);
    current_drawing_option = 7;
    ui->groupBox_4->setTitle("CutEllipsoid");
}

/*!
      Método que altera valor da localização na dimensão Z na caixa de atributo.
*/
void MainWindow::on_spinBox_13_valueChanged(int arg1)
{
    z_coord = arg1;
    if (arg1 <=  ui->horizontalSlider_13->maximum())
    {
        ui->horizontalSlider_13->setValue(arg1);
    }else
    {
        ui->horizontalSlider_13->setValue(ui->horizontalSlider_13->maximum());
    }
    ui->spinBox_13->setValue(arg1);


    z_coord = arg1;
    ui->plainTextEdit->updateSculptInfo(sculptor, x_coord, y_coord, z_coord, current_plane);
    ui->plainTextEdit->repaint();
}

/*!
      Método que altera a posição no slider da direção Z.
*/
void MainWindow::on_horizontalSlider_13_valueChanged(int value)
{
    on_spinBox_13_valueChanged(value);
}

/*!
      Método que altera valor da localização na dimensão Y na caixa de atributo.
*/
void MainWindow::on_spinBox_12_valueChanged(int arg1)
{
    y_coord = arg1;
    if (arg1 <=  ui->horizontalSlider_12->maximum())
    {
        ui->horizontalSlider_12->setValue(arg1);
    }else
    {
        ui->horizontalSlider_12->setValue(ui->horizontalSlider_12->maximum());
    }
    ui->spinBox_12->setValue(arg1);

    y_coord = arg1;
    ui->plainTextEdit->updateSculptInfo(sculptor, x_coord, y_coord, z_coord, current_plane);
    ui->plainTextEdit->repaint();
}

/*!
      Método que altera a posição no slider da direção Y.
*/
void MainWindow::on_horizontalSlider_12_valueChanged(int value)
{
    on_spinBox_12_valueChanged(value);
}

/*!
      Método que altera valor da localização na dimensão Y na caixa de atributo.
*/
void MainWindow::on_spinBox_11_valueChanged(int arg1)
{
    x_coord = arg1;
    if (arg1 <=  ui->horizontalSlider_11->maximum())
    {
        ui->horizontalSlider_11->setValue(arg1);
    }else
    {
        ui->horizontalSlider_11->setValue(ui->horizontalSlider_11->maximum());
    }
    ui->spinBox_11->setValue(arg1);

    x_coord = arg1;
    ui->plainTextEdit->updateSculptInfo(sculptor, x_coord, y_coord, z_coord, current_plane);
    ui->plainTextEdit->repaint();
}

/*!
      Método que altera a posição no slider da direção X.
*/
void MainWindow::on_horizontalSlider_11_valueChanged(int value)
{
    on_spinBox_11_valueChanged(value);
}

/*!
      Método que altera valor da cor do canal vermelho na caixa de atributo.
*/
void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    r = (arg1*255);
    update_preview_color();
}

/*!
      Método que altera valor da cor do canal verde na caixa de atributo.
*/
void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    g = (arg1*255);
    update_preview_color();
}

/*!
      Método que altera valor da cor do canal azul na caixa de atributo.
*/
void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
    b = (arg1*255);
    update_preview_color();
}

/*!
      Método que altera valor da transparência na caixa de atributo.
*/
void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    a = (arg1*255);
    update_preview_color();
}

/*!
      Método que habilita a janela de criar nova escultura.
*/
void MainWindow::on_createNewSculptor_released()
{
    dialogForm->setVisible(true);
}

/*!
      Método que realiza o desenho na posição selecionada pelo usuario.
*/
void MainWindow::on_pushButton_15_pressed()
{
    //current_drawing_option
    // 0 - putvoxel
    // 1 - cutvoxel
    // 2 - putBox
    // 3 - cutBox
    // 4 - putSphere
    // 5 - cutSphere
    // 6 - putEllipse
    // 7 - cutEllipse
    if(this->sculptor != nullptr)
    {
        float red_f, green_f, blue_f, alpha_f;
        red_f = r/255.0;
        green_f = g/255.0;
        blue_f = b/255.0;
        alpha_f = a/255.0;
        if(current_drawing_option == 0)
        {
            fgs.push_back( new PutVoxel(x_coord, y_coord, z_coord, red_f, green_f, blue_f, alpha_f)  );
            fgs[fgs.size()-1]->draw(*sculptor);
        }
        else if(current_drawing_option == 1)
        {
            fgs.push_back( new CutVoxel(x_coord, y_coord, z_coord)  );
            fgs[fgs.size()-1]->draw(*sculptor);
        }
        else if(current_drawing_option == 2)
        {

            int dimx = ui->spinBox_5->value();
            int dimy = ui->spinBox_6->value();
            int dimz = ui->spinBox_7->value();
            int x0 = x_coord;
            int y0 = y_coord;
            int z0 = z_coord;
            int x1 = x0 + dimx - 1;
            int y1 = y0 + dimy - 1;
            int z1 = z0 + dimz - 1;



            if(row_coord >= 0 && col_coord >= 0)
            {
                fgs.push_back( new PutBox(x0-(dimx), x0+(dimx), y0-(dimy), y0+(dimy), z0-(dimz), z0+(dimz), red_f, green_f, blue_f, alpha_f)  );
                fgs[fgs.size()-1]->draw(*sculptor);
            }


        }
        else if(current_drawing_option == 3)
        {
            int dimx = ui->spinBox_5->value();
            int dimy = ui->spinBox_6->value();
            int dimz = ui->spinBox_7->value();
            int x0 = x_coord;
            int y0 = y_coord;
            int z0 = z_coord;
            int x1 = x0 + dimx - 1;
            int y1 = y0 + dimy - 1;
            int z1 = z0 + dimz - 1;


            if(row_coord >= 0 && col_coord >= 0)
            {
                fgs.push_back( new CutBox(x0-(dimx), x0+(dimx), y0-(dimy), y0+(dimy), z0-(dimz), z0+(dimz))  );
                fgs[fgs.size()-1]->draw(*sculptor);
            }


        }
        else if(current_drawing_option == 4)
        {
            int radius = ui->spinBox->value();
            int xc = x_coord;
            int yc = y_coord;
            int zc = z_coord;


            if (row_coord >= 0 && col_coord >= 0){
                if(radius > 0)
                {
                    fgs.push_back( new PutSphere(xc, yc, zc, radius, red_f, green_f, blue_f, alpha_f)  );
                    fgs[fgs.size()-1]->draw(*sculptor);
                }
                else
                {
                    QMessageBox messageBox;
                    messageBox.critical(nullptr, "Error","invalid radius");
                    messageBox.setFixedSize(500,200);
                }
            }
        }
        else if(current_drawing_option == 5)
        {
            int radius = ui->spinBox->value();
            int xc = x_coord;
            int yc = y_coord;
            int zc = z_coord;

            if(row_coord >= 0 && col_coord >= 0){
                if(radius > 0)
                {
                    fgs.push_back( new CutSphere(xc, yc, zc, radius)  );
                    fgs[fgs.size()-1]->draw(*sculptor);
                }
                else
                {
                    QMessageBox messageBox;
                    messageBox.critical(nullptr, "Error","invalid radius");
                    messageBox.setFixedSize(500,200);
                }
            }
        }
        else if(current_drawing_option == 6)
        {
            int radiusX = ui->spinBox_2->value();
            int radiusY = ui->spinBox_3->value();
            int radiusZ = ui->spinBox_4->value();
            int xc = x_coord;
            int yc = y_coord;
            int zc = z_coord;

            if(row_coord >= 0 && col_coord >= 0){
                if(radiusX > 0 && radiusY > 0 && radiusZ > 0)
                {
                    fgs.push_back( new PutEllipsoid(xc, yc, zc, radiusX, radiusY, radiusZ, red_f, green_f, blue_f, alpha_f)  );
                    fgs[fgs.size()-1]->draw(*sculptor);
                }
                else
                {
                    QMessageBox messageBox;
                    messageBox.critical(nullptr, "Error","invalid radius");
                    messageBox.setFixedSize(500,200);
                }
            }

        }
        else if(current_drawing_option == 7)
        {
            int radiusX = ui->spinBox_2->value();
            int radiusY = ui->spinBox_3->value();
            int radiusZ = ui->spinBox_4->value();
            int xc = x_coord;
            int yc = y_coord;
            int zc = z_coord;

            if(row_coord >= 0 && col_coord >= 0){
                if(radiusX > 0 && radiusY > 0 && radiusZ > 0)
                {
                    fgs.push_back( new CutEllipsoid(xc, yc, zc, radiusX, radiusY, radiusZ)  );
                    fgs[fgs.size()-1]->draw(*sculptor);
                }
                else
                {
                    QMessageBox messageBox;
                    messageBox.critical(nullptr, "Error","invalid radius");
                    messageBox.setFixedSize(500,200);
                }
            }
            ui->plainTextEdit->updateSculptInfo(sculptor, x_coord, y_coord, z_coord, current_plane);
            ui->plainTextEdit->repaint();
        }
    }
}

/*!
      Método que quando selecionado na barra de tarefas escreve o arquivo OFF/VECT.
*/
void MainWindow::on_createOutputFile_released()
{
    if(this->sculptor != nullptr)
    {
        //QFileDialog object
        QFileDialog objFlDlg(this);
        //Set the file dialog optin to show the directory only
        objFlDlg.setOption(QFileDialog::ShowDirsOnly, true);
        //Show the file dialog as a save file dialog
        objFlDlg.setAcceptMode(QFileDialog::AcceptSave);
        //The constant file name
        objFlDlg.selectFile("sculpt");
        //Make the file dialog file name read only
        //The file name entering widget is a QLineEdit
        //So find the widget in the QFileDialog
        //Show the file dialog
        //If save button clicked
        if(objFlDlg.exec()){
            QString fileNameOff = objFlDlg.selectedFiles().at(0)+".off";

            string filenameOFF_std(fileNameOff.toStdString());

        }
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error","Empty sculpt");
        messageBox.setFixedSize(500,200);
    }

}
