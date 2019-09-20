/**
 * @file  sculptor.h
 * @brief  Definição da classe Sculptor e
 *      métodos para desenhar figuras geométricas.
 * @author  Sarah Brazil
 * @author  Valeria Karla

*/
#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <string>


using namespace std;

/**
 * @struct Voxel
 * @brief Struct que representa um Voxel
 * @details Um Voxel é definido como um struct e comporta as propriedades necessárias para permitir armazenar três tipos
 * de informações: a cor do voxel, sua transparência e se ele deverá ser incluído ou não no modelo digital que representa a escultura.
 */
struct Voxel {
  float red,green,blue;
  float transparency;
  bool isOn;
};

/*
      Estrutura criada para receber os atributos do voxel.
      \param r é a cor vermelha.
      \param g é a cor verde.
      \param b é a cor azul.
      \param a é a transparência.
      \param isOn habilita ou desabilita os voxels.
      */
/*
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
class Sculptor{
protected:
    Voxel ***v;
    int nx,ny,nz;
    float r,g,b,a;
public:
public:
      Sculptor(int _nx, int _ny, int _nz);
      ~Sculptor();
      void setColor(float r, float g, float b, float alpha);
      void putVoxel(int x, int y, int z);
      void cutVoxel(int x, int y, int z);
      void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
      void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
      void putSphere(int xcenter, int ycenter, int zcenter, int radius);
      void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
      void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
      void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
      void printFigure();
      //void writeOFF(char filename);
     // void writeVECT(char filename);

};

#endif // SCULPTOR_H
