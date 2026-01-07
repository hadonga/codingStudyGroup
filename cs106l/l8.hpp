// a point in classes
#include "iostream"
#include "string"

class Point {
public:
	Point(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
private:
	int _x;
	int _y;
	std::string color;
};
