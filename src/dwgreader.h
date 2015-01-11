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
#include <iostream>
#include <sstream>
#include <fstream>
class DWG_Reader {

public:
    DWG_Reader() { }
    uint8_t Read_Bit();
    uint8_t Read_2Bits();
    uint8_t Read_3Bits();
    int16_t Read_BitShort();
    int32_t Read_BitLong();
    int64_t Read_BitLongLong(); 
    double Read_Double();
    uint8_t Read_RawChar();
    uint16_t Read_RawShort();
    double Read_RawDouble();
    uint32_t Read_RawLong();
    uint64_t Read_RawLongLong();
    Point_3D_t Read_Extrusion(bool v);
    double Read_Thickness(bool v);
    color_t Read_Color(bool v);

private:
    uint8_t* data;
    uint32_t byte = 0;
    uint8_t bit = 0;
    DWG_Version version; 
};
