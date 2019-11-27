#include "sculptor.h"
#include <iostream>
#include <fstream>


/*!
      Este é o construtor da classe Escultor.
      \param _nx é a quantidade de elementos na dimensao x.
      \param _ny é a quantidade de elementos na dimensao y.
      \param _nz é a quantidade de elementos na dimensao z.
      \param v é o voxel criado.
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.
      \param isOn habilita o voxel (isOn=1) ou desabilita (isOn=0).
    */

int Sculptor::getNx() const
{
    return nx;
}

int Sculptor::getNy() const
{
    return ny;
}

int Sculptor::getNz() const
{
    return nz;
}

Voxel ***Sculptor::getV() const
{
    return v;
}

Sculptor::Sculptor()
{
    nx = 0;
    ny = 0;
    nz = 0;
    r = 0;
    g = 0;
    b = 0;
    a = 0;
    v = NULL;
}

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = 0;
    g = 0;
    b = 0;
    a = 0;
    v = new Voxel**[nx];
    int i,j,k;

    for (i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];
        for (j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
            for (k = 0; k <nz; k++) {
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
                v[i][j][k].isOn = false;
            }
        }
    }
}

/*!
      Este é o destrutor da classe Escultor.
      \param _nx é a quantidade de elementos na dimensao x.
      \param _ny é a quantidade de elementos na dimensao y.
      \param v é o voxel criado.
      \param i, j são contadores.
    */
Sculptor::~Sculptor()
{
    int i,j;
    for (i = 0; i < nx; i++){
        for (j = 0; j < ny; j++) {
            delete [] v[i][j];
        }
        delete [] v[i];
    }
    if (v != NULL)
    {
        delete []v;
        v = NULL;
    }
}

/*!
      Este método seleciona as cores desejadas para os voxels.
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.
      \param isOn habilita o voxel (isOn=1) ou desabilita (isOn=0).
    */

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
}

/*!
      Este método habilita os voxels desejados e atribui a coloração determinada pelo usuário.
      \param x posição na dimensao x.
      \param y posição na dimensao y.
      \param z posição na dimensao z.
      \param isOn habilita o voxel (isOn=1).
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.

    */

void Sculptor::putVoxel(int x, int y, int z)
{
    if (x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz){
        v[x][y][z].isOn = true;
        v[x][y][z].r = this->r;
        v[x][y][z].g = this->g;
        v[x][y][z].b = this->b;
        v[x][y][z].a = this->a;
    }

}

/*!
      Este método desabilita os voxels desejados e atribui a coloração determinada pelo usuário.
      \param isOn desabilita o voxel (isOn=0).
      \param x posição na dimensao x.
      \param y posição na dimensao y.
      \param z posição na dimensao z.

    */

void Sculptor::cutVoxel(int x, int y, int z)
{
    if (x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz){
    v[x][y][z].isOn = false;
    }
}

/*!
      Este método desenha na tela os atributos da classe. Utilizado no projeto só para teste intermediário da implementação.

    */
void Sculptor::printFigure()
{
    cout << "red channel" << endl;
    for (int i = 0; i < this->nx ; i++){
        cout << i << endl;
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                cout << v[i][j][k].r << " " ;
            }
            cout << endl;
        }
        cout << "\n\n";
    }

    cout << "green channel" << endl;
    for (int i = 0; i < this->nx ; i++){
        cout << i << endl;
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                cout << v[i][j][k].g << " " ;
            }
            cout << endl;
        }
        cout << "\n\n";
    }

    cout << "blue channel" << endl;
    for (int i = 0; i < this->nx ; i++){
        cout << i << endl;
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                cout << v[i][j][k].b << " " ;
            }
            cout << endl;
        }
        cout << "\n\n";
    }

    cout << "alpha" << endl;
    for (int i = 0; i < this->nx ; i++){
        cout << i << endl;
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                cout << v[i][j][k].a << " " ;
            }
            cout << endl;
        }
        cout << "\n\n";
    }

    cout << "ison" << endl;
    for (int i = 0; i < this->nx ; i++){
        cout << i << endl;
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                cout << v[i][j][k].isOn << " " ;
            }
            cout << endl;
        }
        cout << "\n\n";
    }
}


