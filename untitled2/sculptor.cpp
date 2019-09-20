/**
 * @file	sculptor.cpp
 * @brief	Implementação do construtor, destrutor, métodos de manipulação dos voxels
 * e escrita em arquivos .vect e .off
 */

#include "sculptor.h"
#include <iostream>
#include <string>
using std::fstream;

/**
 * @brief Classe Sculptor
 * @details	Construtor da classe "sculptor".
 */
Sculptor::Sculptor(int _nz, int _ny, int _nx){

    if(_nz>0 && _nx>0 && _ny>0){
        nz=_nz; nx=_nx; ny=_ny;

        //Alocação da matriz
        v = new Voxel ** [nz];
        v[0] = new Voxel * [nz*nx];
        v[0][0] = new Voxel [nz*nx*ny];

        int i,j,k;

        for(k=0; k<nz; k++){
            if (k < nz - 1){
                v[0][(k+1)*nx] = &(v[0][0][(k+1)*ny*nx]);
                v[k+1] = &(v[0][(k+1)*nx]);
            }

            for(i=0; i<nx; i++){
                if (i>0) v[k][i] = v[k][i-1] + ny;
            }
        }

        //Inicialização de valores
        for (k=0; k<nz; k++){
            for(i=0; i<nx; i++){
                for(j=0; j<ny; j++){

                    v[k][i][j].isOn=false;
                    v[k][i][j].red   = 0;
                    v[k][i][j].green = 0;
                    v[k][i][j].blue  = 0;
                    v[k][i][j].transparency = 0;
                }
            }
        }

    }else{
        std::cout<<"Tamanho Invalido. " << std::endl;
    }
}

/**
 * @details	Destrutor da classe "sculptor".
 */
Sculptor::~Sculptor(){
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}
void Sculptor::setColor(float _r, float _g, float _b, float _a){
    if (_r>=0 && _r<=1){r=_r;}
    else{r=0;};

    if (_g>=0 && _g<=1){g=_g;}
    else{g=0;};

    if (_b>=0 && _b<=1){b=_b;}
    else{b=0;};

    if (_a>=0 && _a<=1){a=_a;}
    else{a=0;};
}
void Sculptor::putVoxel(int x, int y, int z){
    if (x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz ){

        v[x][y][z].isOn  = true;
        v[x][y][z].red   = r;
        v[x][y][z].green = g;
        v[x][y][z].blue  = b;
        v[x][y][z].transparency = a;
    }
}

/**
 * @details	Desativa o voxel na posição (x,y,z).
 */
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn  = false;
}

/**
 * @details	Método que desenha um cubo. Ativa todos os voxels pertencentes ao intervalo correspondente
 * aos parâmetros do método, atribuindo aos mesmos a cor atual do desenho.
 */

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{


    for (int k=z0;k<z1;k++) {
        for (int i=y0; i<y1 ; i++){
            for (int j=x0; j<x1; j++) {

                putVoxel(k,i,j);

            }
        }

    }

}

/**
 * @details	Método que corta um cubo. Desativa todos os voxels pertencentes ao intervalo correspondente
 * aos parâmetros do método.
 */
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{


    for (int k=z0;k<z1;k++) {
        for (int i=y0; i<y1 ; i++){
            for (int j=x0; j<x1; j++) {
                cutVoxel(k,i,j);
            }
        }
    }

}

/**
 * @details	Método que desenha uma esfera. Ativa todos os voxels que satisfazem à equação da esfera,
 * atribuindo aos mesmos a cor atual do desenho
 */
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    float esfera;


    for (int k=(zcenter-radius); k<=(zcenter+radius); k++){
        for (int i=(ycenter-radius); i<=(ycenter+radius); i++) {
            for (int j=(xcenter-radius); j<=(xcenter+radius); j++) {
                esfera= (((i-ycenter)*(i-ycenter)) + ((j-xcenter)*(j-xcenter)) + ((k-zcenter)*(k-zcenter)));

                if (esfera<= (radius*radius)){
                    putVoxel(k,i,j);
                }
            }
        }
    }

}


/**
 * @details	Método que corta uma esfera. Desativa todos os voxels que satisfazem à equação da esfera
 */
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    float esfera;


    for (int k=(zcenter-radius); k<=(zcenter+radius); k++){
        for (int i=(ycenter-radius); i<=(ycenter+radius); i++) {
            for (int j=(xcenter-radius); j<=(xcenter+radius); j++) {
                esfera= (((i-ycenter)*(i-ycenter)) + ((j-xcenter)*(j-xcenter)) + ((k-zcenter)*(k-zcenter)));

                if (esfera<= (radius*radius)){
                    cutVoxel(k,i,j);
                }
            }
        }
    }

}


/**
 * @details	Método que desenha uma elipsóide. Ativa todos os voxels que satisfazem à equação da elipsóide,
 * atribuindo aos mesmos a cor atual do desenho
 */
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{


    float n;

    for (int k=(zcenter-rz); k<=(zcenter+rz); k++){
        for (int i=(ycenter-ry); i<=(ycenter+ry); i++) {
            for (int j=(xcenter-rx); j<=(xcenter+rx); j++) {

                n=((((i-ycenter)/(float)ry)*((i-ycenter)/(float)ry))+
                   (((j-xcenter)/(float)rx)*((j-xcenter)/(float)rx))+
                   (((k-zcenter)/(float)rz)*((k-zcenter)/(float)rz)));

                if (n<=1){
                    putVoxel(k,i,j);
                }
            }
        }
    }

}

/**
 * @details	Método que corta uma elipsóide. Desativa todos os voxels que satisfazem à equação da elipsóide
 */
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{

    float n;

    for (int k=(zcenter-rz); k<=(zcenter+rz); k++){
        for (int i=(ycenter-ry); i<=(ycenter+ry); i++) {
            for (int j=(xcenter-rx); j<=(xcenter+rx); j++) {

                n=((((i-ycenter)/(float)ry)*((i-ycenter)/(float)ry))+
                   (((j-xcenter)/(float)rx)*((j-xcenter)/(float)rx))+
                   (((k-zcenter)/(float)rz)*((k-zcenter)/(float)rz)));

                if (n<=1){
                    cutVoxel(k,i,j);
                }
            }
        }
    }

}

/**
 * @details	Método que grava a escultura em um arquivo VECT para permetir a visualização do desenho
 */
void Sculptor::writeVECT(string filename)
{
    int nVoxel = 0;//contador de voxels
    ofstream outfile(filename);

    //Verifica se o arquivo foi aberto
    if (!outfile.is_open()){
        std::cout << "Erro ao abrir o arquivo \n";
        return;
    }

    outfile << "VECT" << endl;

    //Quantidade de voxels ativos
    for (int k = 0; k < nz; k++){
        for (int i = 0; i < nx; i++){
            for (int j = 0; j < ny; j++){
                if (v[k][i][j].isOn == true){
                    nVoxel++;
                }
            }
        }
    }

    //Escrevendo o número de poligonos, vertices e cores
    outfile << nVoxel << " " << nVoxel << " " << nVoxel << endl;

    //Número de vertices por poligono
    for (int i = 0; i < nVoxel; i++){
        outfile << "1" << " ";
    }

    outfile << endl;

    //Número de cores por poligono
    for (int i = 0; i < nVoxel; i++){
        outfile << "1" << " ";
    }

    outfile << endl;

    //Coordenadas do número de vertices
    for (int k = 0; k < nz; k++){
        for (int i = 0; i < nx; i++){
            for (int j = 0; j < ny; j++){
                if (v[k][i][j].isOn == 0){
                    outfile << i << " " << j << " " << k << endl;
                }
            }
        }
    }

    //Cores e transparência
    for (int k = 0; k < nz; k++){
        for (int i = 0; i < nx; i++){
            for (int j = 0; j < ny; j++){
                if (v[k][i][j].isOn){
                    outfile << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue
                            << " " << v[k][i][j].transparency << "\n";
                }
            }
        }
    }

    outfile.close();
    std::cout << "Arquivo VECT criado\n";
}

/**
 * @details	Método que grava a escultura em um arquivo OFF para permetir a visualização do desenho
 */
void Sculptor::writeOFF(string filename)
{
    ofstream outfile(filename);

    int nVoxel = 0;//contador de voxel
    int f = 0;//face

    //Verificar se o arquivo foi aberto
    if (!outfile.is_open()) {
        std::cout << "Erro ao abrir o arquivo \n";
        return;
    }

    //Escreve a primeira linha contendo o formato do arquivo
    outfile << "OFF\n";

    //Percorre a matriz para saber a quantidade de voxels ativos
    for (int k = 0; k < nz; k++){
        for (int i = 0; i < nx; i++){
            for (int j = 0; j < ny; j++){
                if (v[k][i][j].isOn){
                    nVoxel++;
                }
            }
        }
    }

    //Escrevendo o número de vértices, faces e arestas(padrão como 0)
    outfile << 8 * nVoxel << " " << 6 * nVoxel << " 0\n";

    //Escrevendo as coordenadas dos vértices
    for (int k = 0; k < nz; k++){
        for (int j = 0; j < nx; j++){
            for (int i = 0; i < ny; i++){
                if (v[k][j][i].isOn){
                    outfile << i-0.5 << " " << j+0.5 << " " << k-0.5 << "\n"
                            << i-0.5 << " " << j-0.5 << " " << k-0.5 << "\n"
                            << i+0.5 << " " << j-0.5 << " " << k-0.5 << "\n"
                            << i+0.5 << " " << j+0.5 << " " << k-0.5 << "\n"
                            << i-0.5 << " " << j+0.5 << " " << k+0.5 << "\n"
                            << i-0.5 << " " << j-0.5 << " " << k+0.5 << "\n"
                            << i+0.5 << " " << j-0.5 << " " << k+0.5 << "\n"
                            << i+0.5 << " " << j+0.5 << " " << k+0.5 << "\n";
                }
            }
        }
    }

    for (int k = 0; k < nz; k++){
        for (int i = 0; i < nx; i++){
            for (int j = 0; j < ny; j++){
                if (v[k][i][j].isOn){
                    f = 8*f;
                    outfile << "4 " << f+0 << " " << f+3 << " " << f+2 << " " << f+1 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n"
                            << "4 " << f+4 << " " << f+5 << " " << f+6 << " " << f+7 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n"
                            << "4 " << f+0 << " " << f+1 << " " << f+5 << " " << f+4 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n"
                            << "4 " << f+0 << " " << f+4 << " " << f+7 << " " << f+3 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n"
                            << "4 " << f+3 << " " << f+7 << " " << f+6 << " " << f+2 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n"
                            << "4 " << f+1 << " " << f+2 << " " << f+6 << " " << f+5 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n";
                    f = f/8+1;
                }
            }
        }
    }

    outfile.close();
    std::cout << "Arquivo OFF criado\n";
}
