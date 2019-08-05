#ifndef ASCIIIMAGE
#define ASCIIIMAGE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class AsciiImage
{
public:
    AsciiImage();

    bool LoadImage(ifstream &file);
    void PrintImage(bool showTitle, bool showName, bool showID, bool showCateg, bool showURL);

private:
    string title;
    vector <string> image;
    string imageID;
    string artist;
    string category;
    string url;
    string firstName;
    string lastName;
    int maxWidth;

    void PrintHorizontalBorder();
    void PrintWithVerticalBorders(string s);
};
#endif