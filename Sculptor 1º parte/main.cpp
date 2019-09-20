#include <iostream>
#include <cstdlib>
#include <sculptor.h>

using namespace std;

int main()
{
    voxel*** v;
    int nx, ny, nz;
    float r, g, b, a;

    //dimensoes
    cin >> nx >> ny >> nz;

    //criando um objeto cubo da classe Sculptor
    sculptor cubo(nx, ny, nz);

    //cores
    cin >> r >> g >> b >> a;

    //atribuindo valores de cores e transparência para o cubo através do método setColor
    cubo.setColor(r, g, b, a);


    cubo.putBox(0,1,0,1,0,1);


    return 0;

}
