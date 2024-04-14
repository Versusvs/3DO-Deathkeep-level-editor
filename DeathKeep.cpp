#pragma once
//#include "stdafx.h"
//#include "Form1.h"
///#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
///#include "burger.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <cstring>
#include <string> 
#include <fstream> 
#include <list>
#include <algorithm>
#include <vector>
#include "Vars.h"
#include <bitset>

////////////
#if 0;
#include <iso646.h>
#include <cstdio>
#include <stdio.h>
#include <windows.h>
#include <vcclr.h>
#include "resource.h"
#include <bitset>
#include <msclr\marshal_cppstd.h>
#include <direct.h>
#include <iomanip>
#include <sstream>
#include <math.h>
//#include "Form1.h"
////////////
#endif;
#include <iomanip>
#include <type_traits>

using namespace std;
//using namespace System::Windows::Forms;


extern void BuildFloor(long long val, unsigned int cube) {

}

extern void BuildWalls(unsigned int cube) {
//vertstr = "# Walls" + "\n";

}


extern void BuildCeiling(unsigned int cube) {

}

extern void PlaceObject(long long val) {

}


template <typename T>
T get_mask( size_t pos, size_t n )
{
    return ~( ~static_cast<typename std::make_unsigned<T>::type>( 0 ) << n ) << pos;
} 




extern int ValueSelector(unsigned long long a, unsigned int pos)
{
	
 //   unsigned long long a = 0xff00000050020000;
    unsigned char b;

 //   std::cout << std::hex << a << std::endl;
//system("pause");
//    for ( size_t i = 0; i < sizeof( a ); i += sizeof( b ) )
    {
        size_t pos1 = 8 * pos;
        size_t n = 8 * sizeof( b );

        auto mask = get_mask<unsigned long long>( pos1, n );

        b = ( a & mask ) >> pos1;

 //       std::cout << "mask = " << std::hex << mask 
 //                 << ", value = " << std::hex << int(b) << std::endl;
//		system("pause");
//		system("pause");
    }
	return b;
}  



#if 0;
extern void readValuesFromVoxel(System::Windows::Forms::DataGridView^ f, _ULonglong voxeldata, int floorN) {
	//Throw known bits or bytes to the dataGrid9
#if 0;
_ULonglong temp = voxeldata;
std::bitset<64> bs(temp);
int val = floorN;
System::Windows::Forms::DataGridView^ dataGridView9;

dataGridView9 = f;

std::string stdString2 = bs.to_string();
System::String^ systemString2 = msclr::interop::marshal_as<System::String^>(stdString2);
unsigned char itemType, itemSpecs, brightness = 0;
char buffer3 [20];
char buffer4 [2];

itemType = ValueSelector(voxelArray[val].value1, 7); // Item type
itemSpecs = ValueSelector(voxelArray[val].value1, 5);	// Item specifications
brightness = ValueSelector(voxelArray[val].value1, 1);	// Light flicker inside the cube
//dataGridView9->Rows[4]->Cells[2]->Value = flickeringLight.ToString();

switch(brightness) {

	case 0xF0: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Flickering Light";
		break;

	case 0xE0: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 1";
		break;

	case 0xC0: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 2";
		break;

	case 0xA0: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 3";
		break;

	case 0x80: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 4";
		break;

	case 0x60: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 5";
		break;

	case 0x40: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 6";
		break;

	case 0x20: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 7";
		break;

	case 0xD0: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 8";
		break;

	case 0xB0: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 9";
		break;

	case 0x90: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 10";
		break;

	case 0x70: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 11";
		break;

	case 0x50: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 12";
		break;

	case 0x30: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 13";
		break;

	case 0x10: 
		dataGridView9->Rows[4]->Cells[2]->Value = "Brightness 14";
		break;

	default : 
	dataGridView9->Rows[4]->Cells[2]->Value = "N/A";

}

_i64toa (itemType, buffer3, 16);
systemString2 = msclr::interop::marshal_as<System::String^>(buffer3);
dataGridView9->Rows[0]->Cells[2]->Value = systemString2;

_i64toa (itemSpecs, buffer4, 16);
systemString2 = msclr::interop::marshal_as<System::String^>(buffer4);
dataGridView9->Rows[1]->Cells[2]->Value = systemString2;


bool doorPresent = (bool((1 << 9)  &  voxelArray[val].value1));	// Door exists
dataGridView9->Rows[2]->Cells[2]->Value = doorPresent.ToString();	// Door exists

bool doorLocked = (bool((1 << 11)  &  voxelArray[val].value1));		// Door is closed
dataGridView9->Rows[3]->Cells[2]->Value = doorLocked.ToString();	// Door is closed
#endif;
}

#endif;






