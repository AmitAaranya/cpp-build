#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct student {

	string name;
	int age;
	int rollno;

}stud;

fstream file;

vector <struct student> v_stud, m_stud;

__declspec (dllexport)bool addStud(struct student l_stud);

__declspec(dllexport) vector <struct student>  showStud();