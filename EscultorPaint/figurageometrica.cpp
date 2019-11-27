#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>


#include "figurageometrica.h"

using namespace std;

/*!
      Construtor da classe FiguraGeometrica.

    */
FiguraGeometrica::FiguraGeometrica()
{
    id = 0;
}

/*!
      Construtor da classe PutVoxel.
      \param x posição na dimensao x.
      \param y posição na dimensao y.
      \param z posição na dimensao z.
      \param isOn habilita o voxel (isOn=1).
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.

    */
PutVoxel::PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a)
{
    this->x = _x;
    this->y = _y;
    this->z = _z;
    this->r = _r;
    this->g = _g;
    this->b = _b;
    this->a = _a;
}

/*!
      Destrutor da classe PutVoxel

    */
PutVoxel::~PutVoxel()
{

}
/*!
    Método de desenho da classe PutVoxel.

    */
void PutVoxel::draw(Sculptor &t)
{
    t.setColor(this->r, this->g, this->b, this->a);
    t.putVoxel(x, y, z);
}

/*!
      Construtor da classe CutVoxel.
      \param isOn desabilita o voxel (isOn=0).
      \param x posição na dimensao x.
      \param y posição na dimensao y.
      \param z posição na dimensao z.

    */
CutVoxel::CutVoxel(int _x, int _y, int _z)
{
    this->x = _x;
    this->y = _y;
    this->z = _z;
}

/*!
      Destrutor da classe CutVoxel

    */
CutVoxel::~CutVoxel()
{

}

/*!
    Método de desenho da classe CutVoxel.

    */
void CutVoxel::draw(Sculptor &t)
{
    t.cutVoxel(x, y, z);
}

/*!
      Construtor da classe PutBox.
      \param x0 posição inicial na dimensao x.
      \param x1 posição final na dimensao x.
      \param y0 posição inicial na dimensao y.
      \param y1 posição final na dimensao y.
      \param z0 posição inicial na dimensao z.
      \param z1 posição final na dimensao z.
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.
    */
PutBox::PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a)
{
    this->x0 = _x0;
    this->x1 = _x1;
    this->y0 = _y0;
    this->y1 = _y1;
    this->z0 = _z0;
    this->z1 = _z1;
    this->r = _r;
    this->g = _g;
    this->b = _b;
    this->a = _a;
}

/*!
      Destrutor da classe PutBox.

    */
PutBox::~PutBox()
{

}

/*!
    Método de desenho da classe PutBox.

    */
void PutBox::draw(Sculptor &t)
{
    //draw a cube with
    t.setColor(r, g, b, a);
    for (int i = x0; i <= x1; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                t.putVoxel(i,j,k);
            }
        }
    }
}

/*!
      Construtor da classe CutBox.
      \param x0 posição inicial na dimensao x.
      \param x1 posição final na dimensao x.
      \param y0 posição inicial na dimensao y.
      \param y1 posição final na dimensao y.
      \param z0 posição inicial na dimensao z.
      \param z1 posição final na dimensao z.
    */
CutBox::CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1)
{
    this->x0 = _x0;
    this->x1 = _x1;
    this->y0 = _y0;
    this->y1 = _y1;
    this->z0 = _z0;
    this->z1 = _z1;
}

/*!
      Destrutor da classe CutBox.

    */
CutBox::~CutBox()
{

}

/*!
    Método de desenho da classe CutBox.

    */
void CutBox::draw(Sculptor &t)
{
    //draw a cube with
    for (int i = x0; i <= x1; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                t.cutVoxel(i,j,k);
            }
        }
    }
}

/*!
      Construtor da classe PutSphere.
      \param xc centróide na dimensão x.
      \param yc centróide na dimensão y.
      \param zc centróide na dimensão z.
      \param rx raio do elipsóide na dimensão x.
      \param ry raio do elipsóide na dimensão y.
      \param rz raio do elipsóide na dimensão z.
      \param radius raio da esfera
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.
    */

PutSphere::PutSphere(int _xc, int _yc, int _zc, int _radius, float _r, float _g, float _b, float _a)
{
    this->xc = _xc;
    this->yc = _yc;
    this->zc = _zc;
    this->radius = _radius;
    this->r = _r;
    this->g = _g;
    this->b = _b;
    this->a = _a;
}

/*!
      Destrutor da classe PutSphere.

    */
PutSphere::~PutSphere()
{

}

/*!
    Método de desenho da classe PutSphere.

    */
void PutSphere::draw(Sculptor &t)
{
    int x1,x0,y1,y0,z1,z0, diffx, diffy, diffz, radius2, aux;
    x0 = xc - radius;
    x1 = xc + radius;
    y0 = yc - radius;
    y1 = yc + radius;
    z0 = zc - radius;
    z1 = zc + radius;

    t.setColor(r,g,b,a);
    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xc;
                diffy = j - yc;
                diffz = k - zc;
                radius2 = radius*radius;
                aux = (diffx*diffx) + (diffy*diffy) + (diffz*diffz);
                if (aux <= radius2){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}

/*!
      Este método recorta uma esfera de raio determinado pelo usuário e centrada nas coordenadas x y z determinadas pelo usuário.
      \param xcenter centróide na dimensão x.
      \param ycenter centróide na dimensão y.
      \param zcenter centróide na dimensão z.
      \param radius raio da esfera
    */
CutSphere::CutSphere(int _xc, int _yc, int _zc, int _radius)
{
    this->xc = _xc;
    this->yc = _yc;
    this->zc = _zc;
    this->radius = _radius;
}

/*!
      Destrutor da classe CutSphere.

    */
CutSphere::~CutSphere()
{

}

/*!
    Método de desenho da classe CutSphere.

    */
void CutSphere::draw(Sculptor &t)
{
    int x1,x0,y1,y0,z1,z0, diffx, diffy, diffz, radius2, aux;
    x0 = xc - radius;
    x1 = xc + radius;
    y0 = yc - radius;
    y1 = yc + radius;
    z0 = zc - radius;
    z1 = zc + radius;

    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xc;
                diffy = j - yc;
                diffz = k - zc;
                radius2 = radius*radius;
                aux = (diffx*diffx) + (diffy*diffy) + (diffz*diffz);
                if (aux <= radius2){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}

/*!
      Construtor da classe PutEllipsoid.
      \param xc centróide na dimensão x.
      \param yc centróide na dimensão y.
      \param zc centróide na dimensão z.
      \param rx raio do elipsóide na dimensão x.
      \param ry raio do elipsóide na dimensão y.
      \param rz raio do elipsóide na dimensão z.
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.
    */
PutEllipsoid::PutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a)
{
    this->xc = _xc;
    this->yc = _yc;
    this->zc = _zc;
    this->rx = _rx;
    this->ry = _ry;
    this->rz = _rz;
    this->r = _r;
    this->g = _g;
    this->b = _b;
    this->a = _a;
}

/*!
      Destrutor da classe PutEllipsoid.

    */
PutEllipsoid::~PutEllipsoid()
{

}

/*!
    Método de desenho da classe PutEllipsoid.

    */
void PutEllipsoid::draw(Sculptor &t)
{
    int x1,x0,y1,y0,z1,z0, diffx, diffy, diffz;
    float aux,rx_f,ry_f,rz_f;
    rx_f = rx;
    ry_f = ry;
    rz_f = rz;
    x0 = xc - rx;
    x1 = xc + rx;
    y0 = yc - ry;
    y1 = yc + ry;
    z0 = zc - rz;
    z1 = zc + rz;

    t.setColor(r, g, b, a);
    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xc;
                diffy = j - yc;
                diffz = k - zc;
                aux = ( (diffx*diffx)/(rx_f*rx_f))  + ( (diffy*diffy)/(ry_f*ry_f) ) + ( (diffz*diffz)/(rz_f*rz_f)) ;
                if (aux <= 1){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }

}

/*!
      Construtor da classe CutEllipsoid.
      \param xc centróide na dimensão x.
      \param yc centróide na dimensão y.
      \param zc centróide na dimensão z.
      \param rx raio do elipsóide na dimensão x.
      \param ry raio do elipsóide na dimensão y.
      \param rz raio do elipsóide na dimensão z.
    */
CutEllipsoid::CutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz)
{
    this->xc = _xc;
    this->yc = _yc;
    this->zc = _zc;
    this->rx = _rx;
    this->ry = _ry;
    this->rz = _rz;
}

/*!
      Destrutor da classe CutEllipsoid.

    */
CutEllipsoid::~CutEllipsoid()
{

}

/*!
    Método de desenho da classe CutEllipsoid.

    */
void CutEllipsoid::draw(Sculptor &t)
{
    int x1,x0,y1,y0,z1,z0, diffx, diffy, diffz;
    float aux,rx_f,ry_f,rz_f;
    rx_f = rx;
    ry_f = ry;
    rz_f = rz;
    x0 = xc - rx;
    x1 = xc + rx;
    y0 = yc - ry;
    y1 = yc + ry;
    z0 = zc - rz;
    z1 = zc + rz;

    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xc;
                diffy = j - yc;
                diffz = k - zc;
                aux = ( (diffx*diffx)/(rx_f*rx_f))  + ( (diffy*diffy)/(ry_f*ry_f) ) + ( (diffz*diffz)/(rz_f*rz_f)) ;
                if (aux <= 1){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}

vector<string> split_string(string s)
{
    vector<string> tokens;
    size_t pos = 0;
    while (true)
    {
        pos = s.find(' ');
        if (pos == string::npos)
        {
            tokens.push_back(s.substr(0, s.size()));
            break;
        }
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);

    }

    return tokens;
}

Sculptor* load_sculpt_from_file(const char* filename)
{
    vector<string> commands;

    Sculptor* sculpt = nullptr;
    ifstream infile(filename);
    string line;
    while (getline(infile, line))
    {
        istringstream iss(line);
        commands.push_back(line);
    }
    infile.close();

    vector<string>first_comm_args = split_string(commands[0]);
    vector<FiguraGeometrica *> fgs;

    for (size_t i=0; i < commands.size(); i++)
    {
        vector<string>comm_args = split_string(commands[i]);

        // command
        if(comm_args[0].compare("dim") == 0)
        {
            int largura = atoi( comm_args[1].c_str() );
            int altura = atoi( comm_args[2].c_str() );
            int profundidade = atoi( comm_args[3].c_str() );
            if (sculpt != nullptr)
            {
                delete sculpt;
            }
            sculpt = new Sculptor(largura, altura, profundidade);
        }
        else if(comm_args[0].compare("putvoxel") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int y0 = atoi( comm_args[2].c_str() );
            int z0 = atoi( comm_args[3].c_str() );

            float r = atof( comm_args[4].c_str() );
            float g = atof( comm_args[5].c_str() );
            float b = atof( comm_args[6].c_str() );
            float a = atof( comm_args[7].c_str() );
            fgs.push_back( new PutVoxel(x0, y0, z0, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutvoxel") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int y0 = atoi( comm_args[2].c_str() );
            int z0 = atoi( comm_args[3].c_str() );
            fgs.push_back( new CutVoxel(x0, y0, z0)  );
        }
        else if(comm_args[0].compare("putbox") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int x1 = atoi( comm_args[2].c_str() );
            int y0 = atoi( comm_args[3].c_str() );
            int y1 = atoi( comm_args[4].c_str() );
            int z0 = atoi( comm_args[5].c_str() );
            int z1 = atoi( comm_args[6].c_str() );


            float r = atof( comm_args[7].c_str() );
            float g = atof( comm_args[8].c_str() );
            float b = atof( comm_args[9].c_str() );
            float a = atof( comm_args[10].c_str() );
            fgs.push_back( new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutbox") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int x1 = atoi( comm_args[2].c_str() );
            int y0 = atoi( comm_args[3].c_str() );
            int y1 = atoi( comm_args[4].c_str() );
            int z0 = atoi( comm_args[5].c_str() );
            int z1 = atoi( comm_args[6].c_str() );
            fgs.push_back( new CutBox(x0, x1, y0, y1, z0, z1)  );
        }
        else if(comm_args[0].compare("putsphere") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int radius = atoi( comm_args[4].c_str() );


            float r = atof( comm_args[5].c_str() );
            float g = atof( comm_args[6].c_str() );
            float b = atof( comm_args[7].c_str() );
            float a = atof( comm_args[8].c_str() );
            fgs.push_back( new PutSphere(xc, yc, zc, radius, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutsphere") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int radius = atoi( comm_args[4].c_str() );
            fgs.push_back( new CutSphere(xc, yc, zc, radius)  );
        }
        else if(comm_args[0].compare("putellipsoid") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int rx = atoi( comm_args[4].c_str() );
            int ry = atoi( comm_args[5].c_str() );
            int rz = atoi( comm_args[6].c_str() );


            float r = atof( comm_args[7].c_str() );
            float g = atof( comm_args[8].c_str() );
            float b = atof( comm_args[9].c_str() );
            float a = atof( comm_args[10].c_str() );
            fgs.push_back( new PutEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutellipsoid") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int rx = atoi( comm_args[4].c_str() );
            int ry = atoi( comm_args[5].c_str() );
            int rz = atoi( comm_args[6].c_str() );
            fgs.push_back( new CutEllipsoid(xc, yc, zc, rx, ry, rz)  );

        }
        else
        {
            cout << "invalid command" << endl;
        }

    }

    if(sculpt != nullptr)
    {
        for(size_t i=0; i < fgs.size(); i++)
        {
            fgs[i]->draw(*sculpt);
        }
    }
    return sculpt;
}
