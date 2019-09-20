#include <iostream>
#include "sculptor.h"

using namespace std;



int main()
{
    int nx1, ny1, nz1, nx2, ny2, nz2, nx3, ny3, nz3, nx4, ny4, nz4;
    float red, green, blue, alpha;
    int xcenter, ycenter, zcenter, radius, radiusx, radiusy, radiusz;
    int x0, x1, y0, y1, z0, z1;


    string FigureOneVECT =
    string FigureOneOFF = "C:/Users/thaty/Documents/Projeto2unidadePA/OFFfiles/FigureOne.off";

    string FigureTwoVECT =
    string FigureTwoOFF =

    string FigureThreeVECT =
    string FigureThreeOFF =

    string FigureFourVECT =
    string FigureFourOFF =

    cout <<"===============Figura 1 - Cubo oco colorido=================\n" ;
    cout <<"Quantidade de elementos em cada dimensao (x,y,z): " ;
    cin >> nx1 >> ny1 >> nz1; //6 6 6

    Sculptor FigureOne(nx1,ny1,nz1);

    FigureOne.cutVoxel(nx1,ny1,nz1);
    cout <<"Determine a cor e a transparencia (r,g,b,alpha): " ;//1 0 0 1
    cin >> red >> green >> blue >> alpha;
    FigureOne.setColor(red,green,blue,alpha);
    FigureOne.putBox(0,0,0,ny1-1,0,nz1-1);
    cout <<"Determine a cor e a transparencia (r,g,b,alpha): " ;//0.5 0.5 0.5 1
    cin >> red >> green >> blue >> alpha;
    FigureOne.setColor(red,green,blue,alpha);
    FigureOne.putBox(nx1-1,nx1-1,0,ny1-1,0,nz1-1);
    cout <<"Determine a cor e a transparencia (r,g,b,alpha): " ;//0 1 0 1
    cin >> red >> green >> blue >> alpha;
    FigureOne.setColor(red,green,blue,alpha);
    FigureOne.putBox(0,nx1-1,0,0,0,nz1-1);
    cout <<"Determine a cor e a transparencia (r,g,b,alpha): " ;// 0.2 0.8 0.5 1
    cin >> red >> green >> blue >> alpha;
    FigureOne.setColor(red,green,blue,alpha);
    FigureOne.putBox(0,nx1-1,ny1-1,ny1-1,0,nz1-1);
    cout <<"Determine a cor e a transparencia (r,g,b,alpha): " ;// 0 0 1 1
    cin >> red >> green >> blue >> alpha;
    FigureOne.setColor(red,green,blue,alpha);
    FigureOne.putBox(0,nx1-1,0,ny1-1,0,0);
    cout <<"Determine a cor e a transparencia (r,g,b,alpha): " ;// 0.6 0.4 0.3 1
    cin >> red >> green >> blue >> alpha;
    FigureOne.setColor(red,green,blue,alpha);
    FigureOne.putBox(0,nx1-1,0,ny1-1,nz1-1,nz1-1);
    FigureOne.writeVECT(FigureOneVECT);
    FigureOne.writeOFF(FigureOneOFF);



    cout <<"===============Figura 2 - Esfera oca=================\n" ;
    cout <<"Quantidade de elementos em cada dimensao (x,y,z): " ;
    cin >> nx2 >> ny2 >> nz2; //31 31 31

    Sculptor FigureTwo(nx2,ny2,nz2);

    cout <<"Determine a cor e a transparencia (r,g,b,alpha): " ;// 1 0 0 1
    cin >> red >> green >> blue >> alpha;
    FigureTwo.setColor(red,green,blue,alpha);
    cout <<"Determine as coordenadas do centro e o raio (xcenter, ycenter, zcenter, raio): " ;// 15 15 15 15
    cin >> xcenter >> ycenter >> zcenter >> radius;
    FigureTwo.putSphere(xcenter,ycenter,zcenter,radius);
    FigureTwo.cutSphere(xcenter,ycenter,zcenter,radius-1);
    FigureTwo.writeVECT(FigureTwoVECT);
    FigureTwo.writeOFF(FigureTwoOFF);

    cout <<"===============Figura 3 - Elipsoide oco=================\n" ;
    cout <<"Quantidade de elementos em cada dimensao (x,y,z): " ;
    cin >> nx3 >> ny3 >> nz3;//31 31 31

    Sculptor FigureThree(nx3,ny3,nz3);

    cout <<"Determine a cor e a transparencia (r,g,b,alpha): " ;// 0.2 1 0.5 1
    cin >> red >> green >> blue >> alpha;
    FigureThree.setColor(red,green,blue,alpha);
    cout <<"Determine as coordenadas do centro e os raios (xcenter, ycenter, zcenter, raio_x, raio_y, raio_z): " ;// 15 15 15 15 14 13
    cin >> xcenter >> ycenter >> zcenter >> radiusx >> radiusy >> radiusz;
    FigureThree.putEllipsoid(xcenter,ycenter,zcenter,radiusx,radiusy,radiusz);
    FigureThree.cutEllipsoid(xcenter,ycenter,zcenter,radiusx-1,radiusy-1,radiusz -1);
    FigureThree.writeVECT(FigureThreeVECT);
    FigureThree.writeOFF(FigureThreeOFF);

    cout <<"===============Figura 4 - Cubo oco=================\n" ;
    cout <<"Quantidade de elementos em cada dimensao (x,y,z): " ;
    cin >> nx4 >> ny4 >> nz4;//6 6 6

    Sculptor FigureFour(nx4,ny4,nz4);

    cout <<"Determine a cor e a transparencia (r,g,b,alpha): " ;// 0.8 0.3 0.6 1
    cin >> red >> green >> blue >> alpha;
    FigureFour.setColor(red,green,blue,alpha);
    cout <<"Determine os limites do cubo (x0,x1,y0,y1,z0,z1): " ;// 0 5 0 5 0 5
    cin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
    FigureFour.putBox(x0,x1,y0,y1,z0,z1);
    FigureFour.cutBox(x0+1,x1-1,y0+1,y1-1,z0+1,z1-1);
    FigureFour.writeVECT(FigureFourVECT);
    FigureFour.writeOFF(FigureFourOFF);

    //makefig.printFigure();
    return 0;
}
