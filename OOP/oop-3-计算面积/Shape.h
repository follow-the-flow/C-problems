#define pai 3.14
class Shape {
public:
    virtual double getArea()=0;
    virtual ~Shape()=default;
};
class Rectangle:public Shape {
public:
double width,height;
Rectangle(double W,double H):width(W),height(H){

}
~Rectangle(){}

double getArea(){
    double area=width*height;
    return area;
}

};
class Circle :public Shape{
public:
double radius;
double getArea(){
    double area=pai*radius*radius;
    return area;
}
Circle(double r):radius(r){
}
~Circle(){}
};