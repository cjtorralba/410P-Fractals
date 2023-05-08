
/*
    FPToolkit.c : A simple set of graphical tools.
    FPToolkitDemo.c
    Copyright (C) 2018  Ely

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License (version 3)
    as published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/





/*

This code assumes an underlying X11 environment.

       Most freshly installed unbuntu environments do not have
       the X11 developr stuff they'll need to do graphics.
       To download X11 developer stuff, connect to the internet and
       issue the following two commands.  Each will ask for your password
       and each will take a few minutes.  At some point it might even
       look like nothing is happening....be patient :

sudo  apt-get  install  libx11-dev

sudo  apt-get  install  xorg-dev

*/



#include  "FPToolkit/FPToolkit.c"
#include "serp_triangle.h"

//#define RAD_TO_DEGREE(x) ((x * M_PI) / 180)
#define DEGREE_TO_RAD(x) ((x * M_PI) / 180)











void drawSquareAtAngle(double p1[], double p2[]);




/**
 * Draws a line of a specified length at a specified angle, in degrees.
 *
 * @param points The starting point in which we will draw the line from
 * @param lineLength The length of the line being drawn
 * @param angle Angle at which we wish to draw from, in degrees. It will be converted to radians in this function.
 * @param increment true if you wish to move the points to the location of the newly drawn line.
 */
void drawLineAtAngle(double* points, double lineLength, double angle, bool increment) {
    double radians = DEGREE_TO_RAD(angle);
    double yLength = lineLength * sin(radians);
    double xLength= lineLength * cos(radians);
    G_rgb(0.0, 1.0, 0.0);

    double p2[2] = { points[0] + xLength, points[1] + yLength};

    G_line(points[0], points[1], points[0] + xLength, points[1] + yLength);

    if( increment) {
        points[0] += xLength;
        points[1] += yLength;
    }
}





void stringBuilder(char* source, int depth) {

    char temp[1000000] = {'\0'};


   for(int i = 0; i < depth; ++i) {
       for( int j = 0; j < strlen(source) ; ++j) {
           switch (source[j]) {

               case 'A':
                   strcat(temp, "+A-C-A+");
                   break;

               case 'B':
                   strcat(temp, "B+C+B");
                   break;

               case 'C':
                   strcat(temp, "A-C-A");
                   break;

               case '+':
                   strcat(temp, "+");
                   break;
               case '-':
                   strcat(temp, "-");
                   break;

               default:
                   break;
           }
       }
           strcpy(source, temp);
           memset(temp, '\0', sizeof(temp));
   }

}







/**
 * Any character that is capital A - Z, or f/F, moves the dame distance
 * +/- changes the angle, + increases by 30 degrees
 * @param string The string that we will be building a picture from
 */
void drawWithGrammar(char* string) {

    double degrees = 10.0;
    double angle = 30.0;
    double distance = 1.0;

    double p1[2] = {700.0, 400.0 };

    for(int i = 0; i < strlen(string) - 1; ++i) {
        if(string[i] == 'f' || string[i] >= 'A' && string[i] <= 'Z') {
            //  printf("%d", i);
            drawLineAtAngle(p1, distance, degrees, true);
        }
        else if(string[i] == '+' || string[i] == '-') {
            string[i] == '+' ? degrees += angle : degrees -= angle;
        }
    }
}






void drawPythagTree(double p0[], double p1[], int currentLevel, int depth) {

    if (currentLevel >= depth) {
        return;
    }

    G_rgb(1.0, 0.0, 0.0);

    drawSquareAtAngle(p0, p1);

    double xDiff = p1[0] - p0[0];
    double yDiff = p1[1] - p0[1];

    double lineLength = sqrt( (xDiff * xDiff) +(yDiff * yDiff));

    double angle = atan(yDiff / xDiff);
    double p2[2], p3[2];

    p2[0] = p0[0] - (lineLength * sin(angle));
    p2[1] = p0[1] + (lineLength * cos(angle));

    p3[0] = p1[0] - (lineLength * sin(angle));
    p3[1] = p1[1] + (lineLength * cos(angle));

    G_fill_circle(p2[0], p2[1], 2);
    G_fill_circle(p3[0], p3[1], 2);

    double triangleAngle = DEGREE_TO_RAD(30.0);
    double triangleX = lineLength * cos(triangleAngle);
    double triangleY = lineLength * sin(triangleAngle);

    double innerLineLength = triangleY * sin(angle);


    double triangleHeight = triangleX * sin(triangleAngle);
    double lengthDiff = triangleY * sin(triangleAngle);

    double scaleFactor = lengthDiff / lineLength;

    p3[0] -= (xDiff * scaleFactor);
    p3[1] += triangleHeight;

    printf("yDiff: %lf", yDiff);

    G_rgb(0.0, 0.0, 1.0);

    G_fill_circle(p3[0], p3[1], 2);

//    G_circle(p2[0] - (yDiff / 2.0), p2[1] + ((yDiff / 2.0) * sqrt(3.0)), 2);
//    printf("Good circle: %f, %f", p2[0] - (yDiff / 2.0), p2[1] + ((yDiff / 2.0) * sqrt(3.0)));


    //drawPythagTree(p2, p3, currentLevel+1, depth);
}



void autoPlacer(char* string, double screenHeight, double screenWidth) {





}










void drawKoch(double p1[], double length, double angle, int currentLevel, int maxIterations) {
    G_rgb(0.0, currentLevel * 10, 0.0);

    if (currentLevel >= maxIterations) {
        return;
    }

    double thirdLength = length / 3.0;
    double radians = DEGREE_TO_RAD(angle);

    double height = thirdLength * sin(radians);
/*
    drawLineAtAngle(p1, length, angle);
    p1[0] += length / 3.0;
    drawLineAtAngle(p1, length / 3, angle += 60.0);

    length /= 3.0;
    p1[0] += length / 3.0;
    G_rgb(1.0, 0.0, 0.0);
    drawLineAtAngle(p1, length / 3, angle += 120.0);
    */



}













void drawSquareAtAngle(double p1[], double p2[]) {
    double xDiff = p2[0] - p1[0];
    double yDiff = p2[1] - p1[1];
    double lineLength = sqrt((xDiff * xDiff) + (yDiff * yDiff));

    double angle = atan(yDiff / xDiff);
    //angle = RAD_TO_DEGREE(angle);


    double p3[2], p4[2];


    p3[0] = p1[0] - (lineLength * sin(angle));
    p3[1] = p1[1] + (lineLength * cos(angle));

    p4[0] = p2[0] - (lineLength * sin(angle));
    p4[1] = p2[1] + (lineLength * cos(angle));


    G_line(p1[0], p1[1], p2[0], p2[1]);
    G_line(p1[0], p1[1], p3[0], p3[1]);
    G_line(p3[0], p3[1], p4[0], p4[1]);
    G_line(p4[0], p4[1], p2[0], p2[1]);

}












void drawLineWithDots(double *pointOne, double *pointTwo, int numPoints) {

    if (!pointOne[0] || !pointOne[1] || !pointTwo[0] || !pointTwo[1]) {
        return;
    }

    double xInterval = (pointTwo[0] - pointOne[0]) / numPoints;
    double yInterval = (pointTwo[1] - pointOne[1]) / numPoints;

    for (double i = 0, x = xInterval, y = yInterval; i < numPoints; i++, x += xInterval, y += yInterval) {
        G_rgb(x * i * y, y * i * numPoints, numPoints);
        G_point(pointOne[0] + (x), pointOne[1] + y);
    }
}


int main() {
    int swidth, sheight;
    double lowleftx, lowlefty, width, height;
    double x[10], y[10];
    double numxy;
    double a[20], b[20];
    double numab;

    int rows = 500;
    int rowDistance;

    int cols;
    int colDistance;

    double points[6] = {0.0, 0.0, (swidth - 1.0) / 2, sheight - 1.0, swidth - 1.0, 0.0};




//    G_triangle(0.0, 0.0, midPoint[0], midPoint[1], (swidth-1) / 2, 0);

    //drawSierpinskyTriangleRecursive(points, 0, 7);


    // must do this before you do 'almost' any other graphical tasks
    swidth = 1000;
    sheight = 1000;
    G_init_graphics(swidth, sheight);  // interactive graphics

    G_rgb(0.3, 0.3, 0.3); // dark gray
    G_clear();

    double p1[2] = {400.0, 400.0};


    char s[1000000] = {'B', '\0'};

   // scanf("%s", s);
   // int length = strlen(s);

    //printf("Length: %d", length);




    stringBuilder( s, 10);

    drawWithGrammar(s);
    //drawWithGrammar(s);

    //  drawKoch(p1, 100.0, 0, 0, 5);

    int key;
    key = G_wait_key(); // pause so user can see results

    //   G_save_image_to_file("demo.xwd") ;
    G_save_to_bmp_file("Demo.bmp");
}



