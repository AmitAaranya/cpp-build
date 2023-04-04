#include "pch.h"
#include "Device.h"

__declspec (dllexport)bool opendevice(char* strdevice) {

	return true;
}

__declspec(dllexport) int closedevice() {
	return true;
}