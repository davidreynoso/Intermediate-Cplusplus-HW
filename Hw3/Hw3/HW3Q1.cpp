

#include <iostream>
using namespace std;

class CVector {
  public:
    int x,y;
    CVector ():x(0),y(0){};
    CVector (int a,int b) : x(a), y(b) {}
    CVector operator + (const CVector&);
};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

class Polygon {
protected:
    CVector* vertex;
    int vertex_n;
public:
    Polygon(): vertex_n(0), vertex(nullptr) {} // constructor
    Polygon(int vertex_n_, int vertex_x_coordinate[], int vertex_y_coordinate[]): vertex_n(vertex_n_), vertex(new CVector[vertex_n_]) { // constructor
        for (int i = 0; i < vertex_n; i++) {
            vertex[i].x = vertex_x_coordinate[i];
            vertex[i].y = vertex_y_coordinate[i];
        }
    }
    void display_vertex() { // display contents of vertex function
        for (int i = 0; i < vertex_n; i++) {
            cout << vertex[i].x << ", " << vertex[i].y << endl;
        }
    }
    ~Polygon() {delete[] vertex;} // Destructor
    Polygon (const Polygon& x) { // copy constructor
        vertex_n = x.vertex_n;
        vertex = new CVector[vertex_n];
        for (int i = 0; i < vertex_n; i++) {
            vertex[i] = x.vertex[i];
        }
    }
    Polygon& operator= (const Polygon& x) { // copy assignment
        delete[] vertex;
        vertex = new CVector[vertex_n];
        for (int i = 0; i < vertex_n; i++) {
            vertex[i] = x.vertex[i];
        }
        return *this;
    }
    Polygon (Polygon&& x): vertex(x.vertex) {x.vertex = nullptr;} // move constructor
    Polygon& operator= (Polygon&& x) { // move assignment
        delete[] vertex;
        vertex = x.vertex;
        x.vertex = nullptr;
        return *this;
    }
};


int main() {
    int x[4] = {0,1,1,0};
    int y[4] = {0,0,1,1};
    int z[4] = {2,2,-2,-2 };
    Polygon polygon1(4,x,y);
    cout << "polygon1" << endl;
    polygon1.display_vertex();
    Polygon polygon2(polygon1);
    cout << "polygon2" << endl;
    polygon2.display_vertex();
    Polygon polygon3 = polygon1;
    polygon3 = Polygon(4, x, z);
    cout << "polygon3" << endl;
    polygon3.display_vertex();
    Polygon polygon4 = Polygon(4, y, z);
    cout << "polygon4" << endl;
    polygon4.display_vertex();
    cout<< "1/27/2023 " << "David Reynoso" << endl;
}
