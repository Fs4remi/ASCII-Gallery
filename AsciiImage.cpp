#include "AsciiImage.h"
#include<vector>
AsciiImage::AsciiImage()
{
    title = " ";
    imageID = " ";
    url = " ";
    category = " ";
    artist = " ";
    firstName = "Unknown";
    lastName = "Unknown";
    maxWidth = 0;
}

bool AsciiImage::LoadImage(ifstream& file)
{
    int sizeCompare[4];
    string line;

    if(file.eof())
    {
        cout << "End of file" << endl;
        return false;
    }

    getline(file, line);

    while(line == " ")
    {
        if (file.eof())
        {
            return false;
        }
        getline(file, line);
    }
    title = line;

    if (file.eof())
    {
        return false;
    }

    getline(file, imageID);
    //cout << imageID << endl;

    do
    {
        getline(file, line);
        image.push_back(line);
        if (maxWidth < line.size())
        {
            maxWidth = line.size();
        }
    }while(line != "=====\r");
    //gets rid of =====
    image.pop_back();

    //TEST prints out the image vector
   /* for(vector<string>::const_iterator i = image.begin(); i != image.end(); ++i)
    {
        cout << *i << endl;
    }*/

    getline(file, url);
    //cout << url << endl;

    getline(file, category);
    //cout << category << endl;

    if (!file.eof())
    {
        getline(file,artist);
        //cout << artist << endl;
        stringstream breakUp(artist);
        breakUp >> firstName >> lastName;
    }

    sizeCompare[0] = title.size();
    sizeCompare[1] = url.size();
    sizeCompare[2] = category.size();
    sizeCompare[3] = firstName.size() + 1 + lastName.size();

    for(int i = 0; i < 4; i++)
    {
        if(sizeCompare[i] > maxWidth)
        {
            maxWidth = sizeCompare[i];
        }
    }

    maxWidth += 4;
    return true;
}

void AsciiImage::PrintImage(bool showTitle, bool showName, bool showID, bool showCateg, bool showURL)
{
    // Print the image with the board and options

    PrintHorizontalBorder();

    if(showTitle)
    {
        PrintWithVerticalBorders(title);
    }

    if(showID)
    {
        PrintWithVerticalBorders(imageID);
    }

    for (vector<string>::const_iterator i = image.begin(); i != image.end(); ++i)
    {
        PrintWithVerticalBorders(*i);
    }

    if(showURL)
    {
        PrintWithVerticalBorders(url);
    }

    if(showCateg)
    {
        PrintWithVerticalBorders("Category: " + category);
    }

    if(showName)
    {
        PrintWithVerticalBorders("Artist: " + firstName + " " + lastName);
    }

    PrintHorizontalBorder();
}

void AsciiImage::PrintHorizontalBorder()
{
    // Print the horizontal border
    for(int i = 0; i < maxWidth ; i++)
    {
        cout << "=" ;
    }
    cout << endl;
}

void AsciiImage::PrintWithVerticalBorders(string s)
{
    // Print the string s with "|" on both sides
    cout << "| " << s;

    for(int i = 0; i < (maxWidth - s.size()); i++)
    {
        cout << " ";
    }
    cout << " |" << endl;
}