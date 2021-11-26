/*
 * control.c
 *

 *      Author: khaled farouk
 */
#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include "control.h"

#define ON 1
#define OFF 0

void display_vehicle_state(void){
	// display the vehicle state
	printf("AC condition is : %d\n",car1.AC_state);
	printf("Engine state is: %d\n",car1.Engine_state);
	printf("vehicle speed is: %d\n",car1.vehicle_speed);
	printf("Room temperature is: %d\n",car1.room_temp);
	printf("Engine temperature controller state is: %d\n",car1.Engine_controller);
	printf("Engine temperature is: %d\n",car1.Engine_temp);
}
/* what to do in the car*/
void print_sensors_set_menu(void){
	car1.Engine_state=ON;

	printf("Now displaying Sensors set menu: \n\n");
	printf("a.\t Turn off the engine\n");
	printf("b.\t Set the traffic light color\n");
	printf("c.\t Set the room temperature\n");
	printf("d.\t Set engine temperature");
	printf("\n\n");
	char choice;
	scanf(" %c",&choice);
	system_response(choice);
	display_vehicle_state();

}
/* control speed depends on the traffics*/
void set_traffic(){
	char traffic;
	printf("please enter traffic light color\n");
	scanf(" %c",&traffic);
	if(traffic=='G'){
		car1.vehicle_speed=100;
		printf("i am here \n\n");
	}
	else if(traffic=='O'){
		car1.vehicle_speed=30;

	}
	else if(traffic=='R'){
		car1.vehicle_speed=0;

	}

}
/* control the AC unit of the car*/
void set_roomtemp(){
	int temp;
	printf("please enter the temperature of the room \n");
	scanf("%d",&temp);
	if(temp<10){
		car1.AC_state=ON;
		car1.AC_temp=20;
		car1.room_temp=temp;

	}
	else if(temp>30){
		car1.AC_state=ON;
		car1.AC_temp=20;
		car1.room_temp=temp;


	}
	else{
		car1.AC_state=OFF;


	}


}
/* control the engine controller and set's its temperature*/
void set_engine(){
	int temp;
	printf("please enter the engine temperature\n");
	scanf("%d",&temp);
	if(temp<100){
		car1.Engine_controller=ON;
		car1.controller_temp=125;
		car1.Engine_temp=temp;

	}
	else if(temp>150){
		car1.Engine_controller=ON;
		car1.controller_temp=125;
		car1.Engine_temp=temp;

	}
	else{
		car1.Engine_controller=OFF;

	}



}

/* sensors control */

void system_response(char choice){

	if(choice=='a'){
		car1.Engine_state=OFF;
		return;
	}
	else if (choice=='b'){
		set_traffic();

	}
	else if(choice=='c'){

		set_roomtemp();

	}
	else if(choice=='d'){

		set_engine();

	}
	if(car1.vehicle_speed==30){
		car1.room_temp =car1.room_temp*(5.0/4)+1;
		car1.Engine_temp=car1.Engine_temp*(5.0/4)+1;
		if(car1.AC_state==OFF){
			car1.AC_state=ON;
		}
		if(car1.Engine_controller==OFF){
			car1.Engine_controller=ON;

		}
	}

}
/* quit the system  */
void quit_system(void){
	printf("System closed Good bye\n");
	exit(0);

}
/*printing */
void print_main(void){
	char choice;

	do{
		printf("a.\t Turn on the veichle engine\n");
		printf("b.\t Turn off the veichle engine\n");
		printf("c.\t Quit the system");
		printf("\n\n");
		scanf(" %c",&choice);
	}while(choice=='b');
	if(choice=='a'){
		print_sensors_set_menu();
	}
	else if(choice=='c'){
		quit_system();

	}


}




