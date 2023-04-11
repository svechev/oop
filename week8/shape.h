#ifndef _SHAPE_H
#define _SHAPE_H

// nqmam vreme za razdelno

class Shape {
protected:
	char type[32];
};

class Rectangle : public Shape {
protected:
	int width;
	int height;
};

class ColoredRectangle : public Rectangle {
protected:
	char color[32];
};

class Square : public Shape {
protected:
	int side;
};

class Triangle : public Square {
protected:
	int side2;
	int side3;
};

#endif
