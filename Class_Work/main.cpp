
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



#include <cfloat>
#include  "../FPToolkit/FPToolkit.c"
#include "serp_triangle.h"

//#define RAD_TO_DEGREE(x) ((x * M_PI) / 180)
#define DEGREE_TO_RAD(x) ((x * M_PI) / 180)


/*
 Iterated Function Generator (IFS)
 double n;
 n = drand48();
 0 <= n < 1

A drawing comprised of smaller versions of that picture



 */

#define WIDTH 1920.0
#define HEIGHT 1080.0

double points[] = {0.0, 0.0};


void scale(double scaleFactorX, double scaleFactorY) {
    points[0] *= scaleFactorX;
    points[1] *= scaleFactorY;
}


void translate(double transFactorX, double transFactorY) {
    points[0] += transFactorX;
    points[1] += transFactorY;
}

void rotate(double degrees) {
    double radians = DEGREE_TO_RAD(degrees);


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


void IFS_Pentagon(int iterations) {

    G_rgb(1.0, 0.0, 0.0);
    double scaleFactor = (3 - sqrt(5)) / 2;

    for (int i = 0; i < iterations; ++i) {
        double random = drand48();

        if (random < .2) {
            translate(0.0, 0.0);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        } else if (random > .2 && random < .4) {
            translate(.618, 0.0);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        } else if (random > .4 && random < .6) {
            translate(.809, .588);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        } else if (random > .6 && random < .8) {
            translate(.309, .951);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        } else {
            translate(-.191, .588);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        //scale(scaleFactor);

    }

}





void IFS_initials(int iterations) {

    for (int i = 0; i < iterations; ++i) {

        double random = drand48();
        if (random < (double) 1 / 8) { // Rule 1
            G_rgb(random * 255, 0.0, 0.0); // RED

            translate((double) 3 / 4, (double) 4 / 5);

            G_point(WIDTH * points[0], HEIGHT * points[1]);

        } else if (random > (double) 1 / 8 && random < (double) 2 / 8) { // Rule 2
            G_rgb(0.0, 1.0, 0.0); // GREEN

            translate((double) 2 / 4, (double) 4 / 5);

            G_point(WIDTH * points[0], HEIGHT * points[1]);
        } else if (random > (double) 2 / 8 && random < (double) 3 / 8) { // Rule 3
            G_rgb(0.0, 0.0, 1.0); // BLUE

            translate((double) 1 / 4, (double) 4 / 5);

            G_point(WIDTH * points[0], HEIGHT * points[1]);

        } else if (random > (double) 3 / 8 && random < (double) 4 / 8) { // Rule 4
            G_rgb(.3, .7, .3);

            translate((double) 1 / 4, (double) 3 / 5);

            G_point(WIDTH * points[0], HEIGHT * points[1]);
        } else if (random > (double) 4 / 8 && random < (double) 5 / 8) { // Rule 5
            G_rgb(.7, .3, .1);

            translate((double) 1 / 4, (double) 2 / 5);

            G_point(WIDTH * points[0], HEIGHT * points[1]);
        } else if (random > (double) 5 / 8 && random < (double) 6 / 8) { // Rule 6
            G_rgb(.5, .9, .1);

            translate((double) 1 / 4, (double) 1 / 5);

            G_point(WIDTH * points[0], HEIGHT * points[1]);


        } else if (random > (double) 6 / 8 && random < (double) 7 / 8) { // Rule 7
            G_rgb(.3, .7, .220);

            translate((double) 2 / 4, (double) 1 / 5);

            G_point(WIDTH * points[0], HEIGHT * points[1]);

        } else { // Rule 8
            G_rgb(.7, .3, .7);

            translate((double) 3 / 4, (double) 1 / 5);

            G_point(WIDTH * points[0], HEIGHT * points[1]);

        }
        /*
        if (random < (double) 1 / 8) { // Rule 1
            G_rgb(random * 255, 0.0, 0.0); // RED

            translate((double) 3 / 3, (double) 4 / 4);

            G_point(WIDTH * points[0], HEIGHT * points[1]);

        } else if (random > (double) 1 / 8 && random < (double) 2 / 8) { // Rule 2
            G_rgb(0.0, 1.0, 0.0); // GREEN

            translate((double) 2 / 3, (double) 4 / 4);

            G_point(WIDTH * points[0], HEIGHT * points[1]);
        } else if (random > (double) 2 / 8 && random < (double) 3 / 8) { // Rule 3
            G_rgb(0.0, 0.0, 1.0); // BLUE

            translate((double) 1 / 3, (double) 4 / 4);

            G_point(WIDTH * points[0], HEIGHT * points[1]);

        } else if (random > (double) 3 / 8 && random < (double) 4 / 8) { // Rule 4
            G_rgb(.3, .7, .3);

            translate((double) 1 / 3, (double) 3 / 4);

            G_point(WIDTH * points[0], HEIGHT * points[1]);
        } else if (random > (double) 4 / 8 && random < (double) 5 / 8) { // Rule 5
            G_rgb(.3, .7, .3);

            translate((double) 1 / 3, (double) 2 / 4);

            G_point(WIDTH * points[0], HEIGHT * points[1]);
        } else if (random > (double) 5 / 8 && random < (double) 6 / 8) { // Rule 6
            G_rgb(.5, .9, .1);

            translate((double) 1 / 3, (double) 1 / 4);

            G_point(WIDTH * points[0], HEIGHT * points[1]);


        } else if (random > (double) 6 / 8 && random < (double) 7 / 8) { // Rule 7
            G_rgb(.3, .7, .220);

            translate((double) 2 / 3, (double) 1 / 4);

            G_point(WIDTH * points[0], HEIGHT * points[1]);

        } else { // Rule 8
            G_rgb(.7, .3, .7);

            translate((double) 3 / 3, (double) 1 / 4);

            G_point(WIDTH * points[0], HEIGHT * points[1]);

        }
         */

        scale((double) 1 / 3, (double) 1 / 5);
    }


}








/*
void IFS_Carpet(int iterations) {

    for (int i = 0; i < iterations; ++i) {

        double random = drand48();

        if (random < .125) { // Drawing rule one
            G_rgb(1.0, 0.0, 0.0);

            translate(0.0, 0.0);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        else if (random > .125 && random < .250) { // Rule two
            G_rgb(0.0, 1.0, 0.0);

            translate(0.0, .333);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        else if (random > .250 && random < .375) {
            G_rgb(0.0, 0.0, 1.0);

            translate(0.0, .666);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        else if (random > .375 && random < .500) {
            G_rgb(1.0, 1.0, 0.0);

            translate(.333, 0.0);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        else if (random > .625 && random < .750) {
            G_rgb(1.0, 0.0, 1.0);
            translate(.333, .666);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        else if (random > .750 && random < .875) {
            G_rgb(0.0, 1.0, 1.0);
            translate(.666, 0.0);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        else if (random > .875 && random < .900) {
            G_rgb(0.5, 0.5, 0.5);
            translate(.666, .333);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        else {
            G_rgb(1.0, 0.5, 0.5);
            translate(.666, .666);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        scale(.333333);


    }


}

*/

/*
void IFS_ColoredQudrants(int iterations) {

    G_rgb(1.0, 0.0, 0.0);

    for (int i = 0; i < iterations; ++i) {
        double random = drand48();
        if (random < .25) { // Draw bottom left quadrant
            scale(.5);
            translate(0.0, 0.0);

            G_rgb(1.0, 0.0, 0.0);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        else if (random > .25 && random < .5) { // Top Left Quadrant

            scale(.5);

            translate(0.0, .5);

            G_rgb(0.0, 1.0, 0.0);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        else if (random > .5 && random < .75) { // Top right quadrant

            scale(.5);

            translate(.5, .5);

            G_rgb(0.0, 0.0, 1.0);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
        else { // Bottom right quadrant
            scale(.5);

            translate(0.5, 0.0);

            G_rgb(0.0, 1.0, 1.0);
            G_point(WIDTH * points[0], HEIGHT * points[1]);
        }
    }
}
*/


/**
 * Draws a line of a specified length at a specified angle, in degrees.
 *
 * @param listOfPoints The starting point in which we will draw the line from
 * @param lineLength The length of the line being drawn
 * @param angle Angle at which we wish to draw from, in degrees. It will be converted to radians in this function.
 * @param increment true if you wish to move the listOfPoints to the location of the newly drawn line.
 */
void drawLineAtAngle(double *listOfPoints, double lineLength, double angle, bool increment, bool transparent) {
    double radians = DEGREE_TO_RAD(angle);
    double yLength = lineLength * sin(radians);
    double xLength = lineLength * cos(radians);
    G_rgb(0.0, 1.0, 0.0);

    double p2[2] = {listOfPoints[0] + xLength, listOfPoints[1] + yLength};

    if (!transparent) {
        G_line(listOfPoints[0], listOfPoints[1], listOfPoints[0] + xLength, listOfPoints[1] + yLength);
    }

    if (increment) {
        listOfPoints[0] += xLength;
        listOfPoints[1] += yLength;
    }
}


void stringBuilder(char *source, int depth) {

    char temp[1000000] = {'\0'};


    for (int i = 0; i < depth; ++i) {
        for (int j = 0; j < strlen(source); ++j) {
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


void drawPythagTree(double p0[], double p1[], int currentLevel, int depth) {

    if (currentLevel >= depth) {
        return;
    }

    G_rgb(1.0, 0.0, 0.0);

    drawSquareAtAngle(p0, p1);

    double xDiff = p1[0] - p0[0];
    double yDiff = p1[1] - p0[1];

    double lineLength = sqrt((xDiff * xDiff) + (yDiff * yDiff));

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


/**
 * Any character that is capital A - Z, or f/F, moves the dame distance
 * +/- changes the angle, + increases by 30 degrees
 * @param string The string that we will be building a picture from
 */
void drawWithGrammar(char *string, double lineLength, double startingX, double startingY) {

    G_rgb(0.0, 1.0, 0.0);
    double degrees = 10.0;
    double angle = 30.0;
    double distance = lineLength;

    double p1[2] = {startingX, startingY};

    for (int i = 0; i < strlen(string) - 1; ++i) {
        if (string[i] == 'f' || string[i] >= 'A' && string[i] <= 'Z') {
            //  printf("%d", i);
            drawLineAtAngle(p1, distance, degrees, true, false);
        } else if (string[i] == '+' || string[i] == '-') {
            string[i] == '+' ? degrees += angle : degrees -= angle;
        }
    }
}


//Returns the length of how far the turtle should draw to stay on the screen
void autoPlacer(char *string, double screenHeight, double screenWidth, double startingX, double startingY) {
    //Should never reach this

    double largestX = -10000000.0;
    double largestY = -10000000.0;

    double smallestX = 10000000.0;
    double smallestY = 10000000.0;

    double degrees = 10.0;
    double angle = 30.0;
    double baseLength = 1.0;

    double p1[2] = {0.0, 0.0};

    for (int i = 0; i < strlen(string) - 1; ++i) {
        if (string[i] == 'f' || string[i] >= 'A' && string[i] <= 'Z') {
            drawLineAtAngle(p1, baseLength, angle, true, true);
        } else if (string[i] == '+' || string[i] == '-') {
            string[i] == '+' ? degrees += angle : degrees -= angle;
        }
        // p1[0] = X position
        // p1[1] = Y position
        if (p1[0] >= largestX) {
            largestX = p1[0];
        } else if (p1[0] <= smallestX) {
            smallestX = p1[0];
        }

        if (p1[1] >= largestY) {
            largestY = p1[1];
        } else if (p1[1] <= smallestY) {
            smallestY = p1[1];
        }
    }

    double midX = (largestX + smallestX) / 2.0;
    double midY = (largestY + smallestY) / 2.0;

    double scaleFactor = midX > midY ? screenWidth / midX : screenHeight / midY;


    drawWithGrammar(string, scaleFactor, midX, midY);
    printf("SF: %lf", scaleFactor);

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





//    G_triangle(0.0, 0.0, midPoint[0], midPoint[1], (swidth-1) / 2, 0);

    //drawSierpinskyTriangleRecursive(points, 0, 7);


    // must do this before you do 'almost' any other graphical tasks
    swidth = WIDTH;
    sheight = HEIGHT;
    G_init_graphics(swidth, sheight);  // interactive graphics

    G_rgb(0.3, 0.3, 0.3); // dark gray
    G_clear();

    double pointsList[6] = {0.0, 0.0, (swidth - 1.0) / 2, sheight - 1.0, swidth - 1.0, 0.0};
    double p1[2] = {400.0, 400.0};


    char s[1000000] = {'B', '\0'};

    // scanf("%s", s);
    // int length = strlen(s);

    //printf("Length: %d", length);




    stringBuilder(s, 6);

//    drawWithGrammar(s, 1.0, 500.0, 400.0);

    // autoPlacer(s, sheight, swidth, 500.0, 400.0);

    //  IFS_ColoredQudrants(100000);
    // IFS_Carpet(10000);
    // IFS_Pentagon(1000000);
    //IFS_initials(1000000);

    IFS_initials(10000000);


    //  drawKoch(p1, 100.0, 0, 0, 5);

    int key;
    key = G_wait_key(); // pause so user can see results

    //   G_save_image_to_file("demo.xwd") ;
    G_save_to_bmp_file("Demo.bmp");
}



