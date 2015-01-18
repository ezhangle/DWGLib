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

#include "dwgreader.h"
#include <stdio.h>
#define dbgn(x) std::cout << x << "\n";
#define dbgt(x) std::cout << x << "\t";
#define pfdn(val) std::printf("%d\n", val);
#define pfdt(val) std::printf("%d\t", val);
#define bpos(x) \
    if (x==0)  std::cout << "Bitpos is : " << 0 << "\n"; \
    else if (x==1)  std::cout << "Bitpos is : " << 1 << "\n"; \
    else if (x==2)  std::cout << "Bitpos is : " << 2 << "\n"; \
    else if (x==3)  std::cout << "Bitpos is : " << 3 << "\n"; \
    else if (x==4)  std::cout << "Bitpos is : " << 4 << "\n"; \
    else if (x==5)  std::cout << "Bitpos is : " << 5 << "\n"; \
    else if (x==6)  std::cout << "Bitpos is : " << 6 << "\n"; \
    else if (x==7)  std::cout << "Bitpos is : " << 7 << "\n"; \
    else if (x==8)  std::cout << "Bitpos is : " << 8 << "\n"; \
    else std::cout << "Error\n";


DWG_Reader::DWG_Reader(std::ifstream *str) {
    str->seekg (0, std::ios_base::end);
    strsize = str->tellg();
    str->seekg(0, std::ios_base::beg);
    u_int32_t i = 0;
    char tmp;
    while(strsize>=i) {
        str->read(&tmp, 1);
        s.push_back(tmp);
        i++;
    }

    //    for (int i = 0; i < 8; i++) {
    //        dbgt(i) pfd(Read_Bit())
    //    }
    //    dbg("\n")
    //    for (int i = 0; i < 8; i++) {
    //        dbgt(i) pfd(Read_Bit())
    //    }
    //    Read_3Bits();
}

u_int8_t DWG_Reader::Read_Bit() {
    char tmpbyte = s[bytepos];
    u_int8_t val = (tmpbyte >> (7 - bitpos)) & 1;
    bitpos++;
    if(8 == bitpos) {
        bitpos = 0;
        bytepos++;
    }
    return val;
}

u_int8_t DWG_Reader::Read_2Bits() {
    char tmpbyte = s[bytepos];
    u_int8_t val;
    if(7 > bitpos) {
        val = (tmpbyte >> (6 - bitpos)) & 3;
    } else {
        u_int8_t t = Read_Bit();
        val = Read_Bit() | (t << 1);
    }
    return val;
}

u_int8_t DWG_Reader::Read_3Bits() {
    if(0==Read_Bit()) return 0;
    if(0==Read_Bit()) return 1;
    if(0==Read_Bit()) return 3;
    return 7;
}

int16_t DWG_Reader::Read_BitShort() {
}

int32_t DWG_Reader::Read_BitLong() {
}

int64_t DWG_Reader::Read_BitLongLong() {

} 

double DWG_Reader::Read_Double() {

}

u_int8_t DWG_Reader::Read_RawChar() {

}

u_int16_t DWG_Reader::Read_RawShort() {

}

double DWG_Reader::Read_RawDouble() {

}

u_int32_t DWG_Reader::Read_RawLong() {

}

u_int64_t DWG_Reader::Read_RawLongLong() {

}

Point_3D_t DWG_Reader::Read_Extrusion(bool v) {

}

double DWG_Reader::Read_Thickness(bool v) {

}

color_t DWG_Reader::Read_Color(bool v) {

}
