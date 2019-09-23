#include <iostream>
#include "sculptor.h"

using namespace std;

int main(void)
{

  Sculptor v(5,5,5);
  v.setColor(0, 0.2, 0, 1);
  v.putVoxel(0,0,0);
  v.setColor(0.3, 0.8, 1, 1);
  v.putVoxel(1,1,1);

  v.writeOFF("/Documentos/Sculptor1 parte/projeto/.off.txt");
  v.writeVECT("/Documentos/Sculptor1 parte/projeto/.vect.txt");

}
