/********************************************************************
This example program is to demonstrate the packet fields value extraction using union  
**********************************************************************/
#include <stdint.h>
#include <stdio.h>

union Packet{
	uint32_t packetvalue;
	struct {
		uint32_t Crc  : 2;
		uint32_t Status :1;
		uint32_t Payload:12;
		uint32_t Bat: 3;
		uint32_t Sensor:3;
		uint32_t Longaddr:8;
		uint32_t Shortaddr:2;
		uint32_t Addrmode:1;
	}packetFields;
};

int main(void){
union Packet frame;

printf("enter the Packet data \n");
fflush(stdout);
scanf("%x",&frame.packetvalue);

printf("Crc: %x \n",frame.packetFields.Crc);
fflush(stdout);
printf("Status: %x \n",frame.packetFields.Status);
fflush(stdout);
printf("Payload: %x \n",frame.packetFields.Payload);
fflush(stdout);
printf("Bat: %x \n",frame.packetFields.Bat);
fflush(stdout);
printf("Sensor: %x \n",frame.packetFields.Sensor);
fflush(stdout);
printf("Longaddr: %x \n",frame.packetFields.Longaddr);
fflush(stdout);
printf("Shortaddr: %x \n",frame.packetFields.Shortaddr);
fflush(stdout);
printf("Addrmode: %x \n",frame.packetFields.Addrmode);
fflush(stdout);

printf("Size of strcut is %I64lld  \n" ,sizeof(frame));
}

/*******************************************************************
*****************Console Output*************************************
enter the Packet data 
ffff1234
Crc: 0 
Status: 1 
Payload: 246 
Bat: 6 
Sensor: 7 
Longaddr: ff 
Shortaddr: 3 
Addrmode: 1 
Size of strcut is 4 
*****************************************************************/
