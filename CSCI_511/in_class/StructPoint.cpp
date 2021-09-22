//Chinmay Satpanthi
//Struct Pointer
//CSCI 511
//Prof Togg Gibson

#include <iostream>

using namespace std;

struct VT_Cir {
    void (*p_circ_draw)(struct Circle *x);
    double (*p_circ_area)(struct Circle *x);
};

struct VT_Tri{
    void (*p_tri_draw)(struct Triangle *x);
    double (*p_tri_area)(struct Triangle *x);
};

struct Triangle
{
    char color;
    char shade;
    short base;
    short height;
};

struct Circle
{
    char color;
    char shade;
    double radius;
};

void setTriangle(struct Triangle *x, char col, char sha, short a, short b)
{
    x->color = col;
    x->shade = sha;
    x->base = a;
    x->height = b;
}

void setCircle(struct Circle *x, char col, char sha, double r)
{
    x->color = col;
    x->shade = sha;
    x->radius = r;
}

void drawTriangle(struct Triangle *x)
{
    cout << x->shade << " " << x->color << " triangle, base= "
         << x->base << " height= " << x->height << endl;
}

void drawCircle(struct Circle *x)
{
    cout << x->shade << " " << x->color << " circle, radius= "
         << x->radius << endl;
}

double areaTriangle(struct Triangle *x)
{
    return ((x->base * x->height)/2.0);
}

double areaCircle(struct Circle *x)
{
    double pi = 3.142;
    return (pi * (x->radius * x->radius));
}

int main()
{

  struct Triangle *tri_p, myTriangle;
  struct Circle *circ_p, myCircle;

  tri_p =  &myTriangle;
  setTriangle(tri_p, 'r', 'l', 7, 3);
  circ_p = &myCircle;
  setCircle(circ_p, 'b', 'd', 8);

  VT_Cir vtcir;
  vtcir.p_circ_draw = &drawCircle;
  vtcir.p_circ_area = &areaCircle;

  VT_Tri vttri;
  vttri.p_tri_draw = &drawTriangle;
  vttri.p_tri_area = &areaTriangle;

  vtcir.p_circ_draw(circ_p);
  cout << "Area of Circle: " << vtcir.p_circ_area(circ_p) << endl;

  cout << endl;

  vttri.p_tri_draw(tri_p);
  cout << "Area of Triangle: " << vttri.p_tri_area(tri_p) << endl;

    return 0;
}
