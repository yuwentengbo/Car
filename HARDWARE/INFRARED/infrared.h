#ifndef __INFRARED_H_
#define __INFRARED_H_
#include "sys.h"

#define DOL	PBin(6)
#define DOR PBin(7)

#define ONLY_L	1
#define ONLY_R  2
#define BOTH	3

void Infrared_init();
u8 Infrared_scan();
#endif