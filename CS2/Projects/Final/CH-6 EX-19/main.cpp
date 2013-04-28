/*
Programmer-     Jonathan Chan
Assignment-     CH-6 EX-19
Due Date        12/15/11
Class-          CS2
Description-    This program creates an svg file of an image of the professor
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void professor_svg();

int main()
{
    professor_svg();
    return 0;
}



void professor_svg()
{

    cout << "professor.svg created!";
    //declaration
    ofstream out_stream;

    //creates file
    out_stream.open("professor.svg");

    //file check
    if (out_stream.fail())
    {
        cout << "Failed to open output file.\n";
        exit(1);
    }

    //svg header
    out_stream << "<?xml version=\"1.0\" standalone=\"no\"?>" << endl;
    out_stream << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << endl;
    out_stream << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl;
    out_stream << "<svg width=\"500\" height=\"500\"" << endl;
    out_stream << "xmlns=\"http://www.w3.org/2000/svg\">" <<endl;

    //ears
    out_stream << "<circle cx=\"130\" cy=\"225\" r=\"75\" stroke=\"black\" stroke-width=\"3\" fill=\"rgb(221, 169, 139)\"/>" <<endl;
    out_stream << "<circle cx=\"370\" cy=\"225\" r=\"75\" stroke=\"black\" stroke-width=\"3\" fill=\"rgb(221, 169, 139)\"/>" <<endl;

    //main face
    out_stream << "<circle cx=\"249\" cy=\"249\" r=\"175\" stroke=\"black\" stroke-width=\"3\" fill=\"rgb(221, 169, 139)\"/>" <<endl;

    //eyes
    out_stream << "<circle cx=\"175\" cy=\"200\" r=\"25\" stroke=\"black\" stroke-width=\"3\" fill=\"rgb(255, 255, 255)\"/>" <<endl;
    out_stream << "<circle cx=\"325\" cy=\"200\" r=\"25\" stroke=\"black\" stroke-width=\"3\" fill=\"rgb(255, 255, 255)\"/>" <<endl;

    //pupils
    out_stream << "<circle cx=\"175\" cy=\"200\" r=\"10\" stroke=\"rgb(107, 66, 38)\" stroke-width=\"3\" fill=\"rgb(107, 66, 38)\"/>" <<endl;
    out_stream << "<circle cx=\"324\" cy=\"200\" r=\"10\" stroke=\"rgb(107, 66, 38)\" stroke-width=\"3\" fill=\"rgb(107, 66, 38)\"/>" <<endl;
    out_stream << "<circle cx=\"175\" cy=\"200\" r=\"2\" stroke=\"black\" stroke-width=\"3\" fill=\"rgb(0, 0, 0)\"/>" <<endl;
    out_stream << "<circle cx=\"324\" cy=\"200\" r=\"2\" stroke=\"black\" stroke-width=\"3\" fill=\"rgb(0, 0, 0)\"/>" <<endl;


    //nose
    out_stream << "<ellipse cx=\"250\" cy=\"275\" rx=\"20\" ry=\"35\" style=\"fill:rgb(221,169, 139);stroke:black;stroke-width:2\"/>" <<endl;

    //glasses
    out_stream << "<polyline points =\"125,150 225,150 225,250 125,250 125,150\" style=\"fill-opacity:0;stroke:black;stroke-width:6\"/>" <<endl;
    out_stream << "<polyline points =\"275,150 375,150 375,250 275,250 275,150\" style=\"fill-opacity:0;stroke:black;stroke-width:6\"/>" <<endl;
    out_stream << "<line x1=\"225\" y1=\"240\" x2=\"275\" y2=\"240\" style=\"stroke:black;stroke-width:6\"/>" <<endl;
    out_stream << "<line x1=\"100\" y1=\"150\" x2=\"125\" y2=\"200\" style=\"stroke:black;stroke-width:6\"/>" <<endl;
    out_stream << "<line x1=\"400\" y1=\"150\" x2=\"375\" y2=\"200\" style=\"stroke:black;stroke-width:6\"/>" <<endl;

    //hair
    out_stream << "<polyline points =\"120,130 180,90 200,100 125,140 120,130\" style=\"fill:rgb(0,0,0);stroke:black;stroke-width:6\"/>" <<endl;
    out_stream << "<polyline points =\"380,130 320,90 300,100 375,140 380,130\" style=\"fill:rgb(0,0,0);stroke:black;stroke-width:6\"/>" <<endl;

    //mouth
    out_stream << "<polyline points =\"175,335 325,335 300,370 200,370, 175,335\" style=\"fill:rgb(255,255,255);stroke:rgb(107, 66, 38);stroke-width:2\"/>" <<endl;

    //close svg and stream
    out_stream << "</svg>" <<endl;
    out_stream.close();
}
