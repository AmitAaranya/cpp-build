#pragma once

//////////////////////////////////////////////////////////////
typedef struct tagCMD_DATA
{
	unsigned char DataLog_NO : 8;
	unsigned char Data[9];
}CMD_DATA, * PCMD_DATA;

//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
typedef struct tagStartHeader
{
	unsigned char AAH : 8;
	unsigned char XXH : 8;
}StartHeader;

//////////////////////////////////////////////////////////////
typedef struct tagEndHeader
{
	unsigned char BBH : 8;
}EndHeader;

//////////////////////////////////////////////////////////////
typedef struct tagDataLogger
{
	unsigned char nID : 8;
	unsigned char nSERIAL_NO_MSB : 8;
	unsigned char nSERIAL_NO_LSB : 8;
}DataLogger, * pDataLogger;


//////////////////////////////////////////////////////////////
__declspec (dllexport)bool opendevice(char  *strdevice);

__declspec(dllexport) int closedevice();