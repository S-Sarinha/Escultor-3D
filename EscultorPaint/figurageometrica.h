#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H


#include <string>
#include <vector>
#include "sculptor.h"


class FiguraGeometrica
{
public:
  FiguraGeometrica();
  virtual void draw(Sculptor &t) = 0;

  protected:
    int id;

};

class PutVoxel: public FiguraGeometrica {
   public:
      PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
      ~PutVoxel();

      void draw(Sculptor &t);

  protected:
    int x,y,z;
    float r,g,b,a;
};

class CutVoxel: public FiguraGeometrica {
   public:
      CutVoxel(int _x, int _y, int _z);
      ~CutVoxel();

      void draw(Sculptor &t);

  protected:
    int x,y,z;
    float r,g,b,a;
};

class PutBox: public FiguraGeometrica {
   public:
      PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
      ~PutBox();

      void draw(Sculptor &t);

  protected:
    int x0,x1, y0, y1, z0, z1;
    float r,g,b,a;
};

class CutBox: public FiguraGeometrica {
   public:
      CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1);
      ~CutBox();

      void draw(Sculptor &t);

  protected:
    int x0,x1, y0, y1, z0, z1;
};

class PutSphere: public FiguraGeometrica {
   public:
      PutSphere(int _xc, int _yc, int _zc, int _radius, float _r, float _g, float _b, float _a);
      ~PutSphere();

      void draw(Sculptor &t);

  protected:
    int xc, yc, zc, radius;
    float r,g,b,a;
};

class CutSphere: public FiguraGeometrica {
   public:
      CutSphere(int _xc, int _yc, int _zc, int _radius);
      ~CutSphere();

      void draw(Sculptor &t);

  protected:
    int xc, yc, zc, radius;
};

class PutEllipsoid: public FiguraGeometrica {
   public:
      PutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
      ~PutEllipsoid();

      void draw(Sculptor &t);

  protected:
    int xc, yc, zc, rx, ry, rz;
    float r,g,b,a;
};

class CutEllipsoid: public FiguraGeometrica {
   public:
      CutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz);
      ~CutEllipsoid();

      void draw(Sculptor &t);

  protected:
    int xc, yc, zc, rx, ry, rz;
};

vector<string> split_string(string s);

Sculptor* load_sculpt_from_file(const char* filename);

#endif // FIGURAGEOMETRICA_H
