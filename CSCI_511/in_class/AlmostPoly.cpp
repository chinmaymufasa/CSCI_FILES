//Chinmay Satpanthi
//Struct Pointer
//CSCI 511
//Prof Togg Gibson

#include <iostream>

using namespace std;

struct VT_Cir
{
    void (*p_circ_draw)(struct Circle *x);
    double (*p_circ_area)(struct Circle *x);
};

struct VT_Tri
{
    void (*p_tri_draw)(struct Triangle *x);
    double (*p_tri_area)(struct Triangle *x);
};

struct Triangle
{
    char color;
    VT_Tri vttri;
    char shade;
    short base;
    short height;
};

struct Circle
{
    
    char color;
    VT_Cir vtcir;
    char shade;
    double radius;
};

union shape_ptr
{
    struct Circle *cir_ptr;
    struct Triangle *tri_ptr;
};

void do_poly(union shape_ptr shape){
    cout << "Draw: " << shape.tri_ptr->vttri.p_tri_draw << endl;
    cout << "Area: " << shape.tri_ptr->vttri.p_tri_area << endl;

}

void setTriangle(struct Triangle *x, char col, char sha, short a, short b)
{
    x->color = col;
    x->shade = sha;
    x->base = a;
    x->height = b;
    
    // x->vttri.p_tri_area(x);
    // x->vttri.p_tri_draw(x);
    // vttri.p_tri_draw = &drawTriangle;
    // vttri.p_tri_area = &areaTriangle;
}

void setCircle(struct Circle *x, char col, char sha, double r)
{
    x->color = col;
    x->shade = sha;
    x->radius = r;

    x->vtcir.p_circ_area(x);
    x->vtcir.p_circ_draw(x);

    // vtcir.p_circ_draw = &drawCircle;
    // vtcir.p_circ_area = &areaCircle;
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
    return ((x->base * x->height) / 2.0);
}

double areaCircle(struct Circle *x)
{
    double pi = 3.142;
    return (pi * (x->radius * x->radius));
}

int main()
{

    union shape_ptr shapes[4];

    struct Triangle *pt_tri1, myTriangle1;
    struct Triangle  *pt_tri2, myTriangle2;
    struct Circle *pt_cir1, myCircle1;
    struct Circle *pt_cir2, myCircle2;

    shapes[0].cir_ptr = &myCircle1;
    shapes[1].cir_ptr = &myCircle2;
    shapes[2].tri_ptr = &myTriangle1;
    shapes[3].tri_ptr = &myTriangle2;

    for (int i =0; i < 4;i++) {
        do_poly(shapes[i]);
    }

    // tri_p = &myTriangle;
    // setTriangle(tri_p, 'r', 'l', 7, 3);
    // circ_p = &myCircle;
    // setCircle(circ_p, 'b', 'd', 8);


    // vtcir.p_circ_draw(circ_p);
    // cout << "Area of Circle: " << vtcir.p_circ_area(circ_p) << endl;

    // cout << endl;

    // vttri.p_tri_draw(tri_p);
    // cout << "Area of Triangle: " << vttri.p_tri_area(tri_p) << endl;

    return 0;
}
