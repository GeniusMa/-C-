#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


class Circle
{
private:
	int circle_center_x=0;
	int circle_center_y=0;
	double circle_radius=1;
public:
	void set_radius(int d);
	// {
	// 	circle_radius=d;
	// }

	double get_distance(int x,int y);
	// {
	// 	return sqrt(pow((circle_center_x-x),2)+pow((circle_center_y-y),2));
	// }
};

class Point
{
private:
	int point_x;
	int point_y;
public:
	void set_point_coordinates(int x,int y);
	// {
	// 	point_x=x;
	// 	point_y=y;
	// }
	int* get_point_coordinates();
	// {
	// 	static int arr[2]={point_x,point_y};
	// 	return arr;
	// }
};
