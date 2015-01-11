/*  
       Copyright (C) 2014  Gaganjyot <thegaganx (at) gmail (dot) com
 
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
 
 Date : Jan 5, 2015
 Authors : Gaganjyot
 
*/

#pragma once
#include <iostream>

enum class DWG_Version { R13, R14, R2000, R2004, R2007, R2010, R2013, Unknown_Version };

class handle_t {
public:
    uint8_t code;
    uint8_t size;
    uint32_t value;
};

class color_t {
public:
    uint16_t index;
    uint32_t rgb;
    uint8_t byte;
    std::string name;
    std::string book_name;
};

class Point_2D_t {
public:
    double x_, y_;
};

class Point_3D_t : public Point_2D_t {
public:
    double _z;
};
