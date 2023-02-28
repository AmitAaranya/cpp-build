#include "pch.h"
#include "User.h"


__declspec (dllexport) bool addStud(struct student l_stud)
{
	file.open("c:\\student.dat", ios::app);

	if (!file)
		return false;

	file.write((char*)&l_stud, sizeof(l_stud));
	file.close();
	return true;
}

__declspec (dllexport) vector <struct student>  showStud()
{
	file.open("student.dat", ios::in);
	file.seekg(0);

	if (!file.is_open())
	{
		v_stud.push_back(stud);
		return v_stud;
	}
	else
	{
		while (file.read((char*)&stud, sizeof(stud)))
		{
			v_stud.push_back(stud);
			if (file.eof())
				break;
		}
	}
	file.close();
	return v_stud;
}