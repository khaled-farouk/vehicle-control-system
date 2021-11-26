/*
 ============================================================================
 Name        : vehicle-control-system.c
 Author      : khaled_farouk
 Version     :
 Copyright   : Your copyright notice
 Description : vehicle-control-system
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include "control.h"
#define ON 1
#define OFF 0

int main(void) {
struct car_state car1;
	car1.Engine_state=OFF;

	while(1){
		print_main(); //
		while(car1.Engine_state==ON)
			print_sensors_set_menu();
	}


	return EXIT_SUCCESS;
	}
