// SimpleRnD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    string strBookList;

    string strlib = { "WELCOME LIBRARIAN" };

    string strOption = { "Please Choose One Option" };

    string strChoice[7] = { "1.View BookList", "2.Search for a Book", "3.Modify/Add Book",\
                            "4.Issue Book","5.Go to main menu","6.Change Password",\
                            "7.Close Application" };

    strBookList = strlib + strOption + strChoice[0] + strChoice[1] + strChoice[2] + strChoice[3] + strChoice[4] + strChoice[5] + strChoice[6];

    std::cout << "List of string = " <<strBookList<< std::endl;
}
