/*
        Copyright (C) 2014 DWGLib

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

    Created : Gaganjyot Singh

*/

#pragma once
#include "base.h"
#include "dwgreader.h"
class TE {
protected:
    Point_2D_t extrusion_;
    double thickness_;
public:
    double getThickness() { return thickness_; }
    Point_2D_t getExtrusion() { return extrusion_; }
    void setThickness(double t) { thickness_ = t; }
    void setExtrusion(Point_2D_t e) { extrusion_ = e; }

};

class Point : public TE {
private:
    double x_, y_;

public:

    Point();

    double getX() { return x_; }
    double getY() { return y_; }

    void setX(double x) { x_ = x; }
    void setY(double y) { y_ = y; }
};


class Line : public TE {
private:
    Point_2D_t start_, end_;

public:

    Line();

    Point_2D_t getStart() { return start_; }
    Point_2D_t getEnd() { return end_; }

    void setStart(Point_2D_t s) { start_ = s; }
    void setEnd(Point_2D_t e) { end_ = e; }

    bool ParseLine();

};

class Circle : public TE {
private:
    Point_2D_t center_;
    double radius_;
public:

    Circle() {}

    Point_2D_t getCenter() { return center_; }
    double getRadius() { return radius_; }

    void setCenter(Point_2D_t c) { center_ = c; }
    void setRadius(double r) { radius_ = r; }
};

class Arc : public TE {
private:
    Point_2D_t center_;
    double radius_, startAngle_, endAngle_;
public:

    Arc() {}

    Point_2D_t getCenter() { return center_; }
    double getRadius() { return radius_; }
    double getStartAngle() { return startAngle_; }
    double getEndAngle() { return endAngle_; }

    void setCenter(Point_2D_t c) { center_ = c; }
    void setRadius(double r) { radius_ = r; }
    void setStartAngle(double s) { startAngle_ = s; }
    void setEndAngle(double e) { endAngle_ = e; }
};

class Ellipse : public TE {
private:
    Point_2D_t center_, majorP_;
    double radius_, startAngle_, endAngle_;
public:

    Ellipse() {}

    Point_2D_t getCenter() { return center_; }
    Point_2D_t getMajorPoint() { return majorP_; }
    double getRadius() { return radius_; }
    double getStartAngle() { return startAngle_; }
    double getEndAngle() { return endAngle_; }

    void setCenter(Point_2D_t c) { center_ = c; }
    void setMajorPoint(Point_2D_t p) { majorP_ = p; }
    void setRadius(double r) { radius_ = r; }
    void setStartAngle(double s) { startAngle_ = s; }
    void setEndAngle(double e) { endAngle_ = e; }
};
