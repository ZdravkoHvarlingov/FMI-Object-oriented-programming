#include <iostream>
#include <vector>
#include <fstream>

struct Point
{
	int x, y;
	
	Point(int x = 0, int y = 0)
		: x(x), y(y)
	{
		++objectsCount;
	}

	static int GetObjectsCount()
	{
		return objectsCount;
	}

	~Point()
	{
		--objectsCount;
	}

private:
	static int objectsCount;
};

int Point::objectsCount = 0;

std::ostream& operator<<(std::ostream &out, const Point &point)
{
	out << point.x << " " << point.y;

	return out;
}

std::istream& operator>>(std::istream &in, Point &point)
{
	in >> point.x >> point.y;

	return in;
}

int main()
{
	/*std::cout << Point::GetObjectsCount() << std::endl;
	Point x(1, 1);
	std::cout << Point::GetObjectsCount() << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		Point point = Point(3, 3);
		std::cout << Point::GetObjectsCount() << std::endl;
	}*/

	std::vector<Point> points;
	for (int i = 0; i < 10; i++)
	{
		points.push_back({ i, i });
	}

	std::ofstream out("serialization.txt");
	out << points.size() << std::endl;
	for (size_t i = 0; i < points.size(); i++)
	{
		out << points[i] << std::endl;
	}
	out.close();

	std::ifstream in("serialization.txt");
	std::vector<Point> readPoints;
	int size;
	in >> size;
	for (size_t i = 0; i < size; i++)
	{
		Point point;
		in >> point;
		readPoints.push_back(point);
	}

	//Point &p = readPoints[i];
	for (Point &p : readPoints)
	{
		std::cout << p << std::endl;
	}
	for (size_t i = 0; i < readPoints.size(); i++)
	{
		std::cout << readPoints[i] << std::endl;
	}

    return 0;
}

