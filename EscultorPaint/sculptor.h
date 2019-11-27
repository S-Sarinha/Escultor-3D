#ifndef SCULPTOR_H
#define SCULPTOR_H


#include <string>


using namespace std;

/*!
      Estrutura criada para receber os atributos do voxel.
      \param r é a cor vermelha.
      \param g é a cor verde.
      \param b é a cor azul.
      \param a é a transparência.
      \param isOn habilita ou desabilita os voxels.
    */
struct Voxel {
  float r,g,b; // Colors
  float a;// Transparency
  bool isOn; // Included or not
};

/*!
      Classe principal deste projeto.
      \param v é a estrutura voxel criada.
      \param nx é o número de elementos na dimensão x.
      \param ny é o número de elementos na dimensão y.
      \param nz é o número de elementos na dimensão z.
      \param r é a cor vermelha.
      \param g é a cor verde.
      \param b é a cor azul.
      \param a é a transparência.
    */

class Sculptor
{
protected:
    Voxel ***v;// 3D matrix
    float r,g,b,a; // Current drawing color
    int nx,ny,nz; // Dimensions

public:
      Sculptor();
      Sculptor(int _nx, int _ny, int _nz);
      ~Sculptor();
      void setColor(float r, float g, float b, float alpha);
      void putVoxel(int x, int y, int z);
      void cutVoxel(int x, int y, int z);
      void printFigure();
      void writeOFF(char filename);


      int getNx() const;
      int getNy() const;
      int getNz() const;
      Voxel ***getV() const;
};

#endif // SCULPTOR_H
