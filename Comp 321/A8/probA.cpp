#include <bits/stdc++.h>
using namespace std;

/**
 * Author: Ulf Lundstrom
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Description: Class to handle points in the plane.
 * 	T can be e.g. double or long long. (Avoid int.)
 * Status: Works fine, used a lot
 */
// #pragma once

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

using P = Point<double>;

int main()
{

    vector<P> points(3);
    for (int i = 0; i < 3; i++)
    {
        double x, y;
        cin >> x >> y;
        points[i] = P(x, y);
    }
    
        
    double dist1_2 = (points[1] - points[2]).dist2();
    double dist0_1 = (points[0] - points[1]).dist2();
    double dist0_2 = (points[0] - points[2]).dist2();
    P p;
    if (dist1_2 > dist0_1 && dist1_2 > dist0_2){
        p = points[1] + points[2] - points[0];
    }else if (dist0_1 > dist1_2 && dist0_1 > dist0_2){
        p = points[0] + points[1] - points[2];
    }
    else{
        p = points[0] + points[2] - points[1];
    }
    cout << p.x << " " << p.y << "\n";
    // int oppCorner = -1;
    // if (dist0_1 == dist0_2){
    //     oppCorner = 0;
    // }
    // else if (dist0_1 == dist1_2){
    //     oppCorner = 1;
    // }
    // else{
    //     oppCorner = 2;
    // }

    // if (oppCorner == 0){
    //     int dx = points[1].x - points[0].x;
    //     int dy = points[2].y - points[0].y;
    //     cout << points[2].x + dx << " " << points[1].y + dy;
    // }else if (oppCorner == 1){
    //     int dx = points[2].x - points[1].x;
    //     int dy = points[0].y - points[1].y;
    //     cout << points[0].x + dx << " " << points[2].y + dy;
    // }
    // else{
    //     int dx = points[0].x - points[2].x;
    //     int dy = points[1].y - points[2].y;
    //     cout << points[1].x + dx << " " << points[0].y + dy;
    // }
    // cout << "\n";
    // cout << "x y: " << points[oppCorner].x << " " << points[oppCorner].y << "\n";
}