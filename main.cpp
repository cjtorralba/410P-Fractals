
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

/*
If this file and the file, FPToolkit.c, are in the
same directory that you are trying to compile in,
do the following :

cc  FPToolkitDemoB.c   -lm  -lX11

note : the 'X' in -X11 is capitalized
*/



void drawLineWithDots(double* pointOne, double* pointTwo, int numPoints) {

    if(!pointOne[0]|| !pointOne[1]|| !pointTwo[0] || !pointTwo[1] ) {
        return;
    }

    double xInterval = (pointTwo[0]-pointOne[0]) / numPoints;
    double yInterval = (pointTwo[1]-pointOne[1]) / numPoints;

    for(double i = 0, x = xInterval, y = yInterval; i < numPoints; i++, x += xInterval, y += yInterval) {
        G_point(pointOne[0] + (x), pointOne[1] + y);
    }
}


void drawTriangleRecursive(double* points, int currentIteration, int maxIterations) {
   if(currentIteration == maxIterations) {
       return;
   }

    G_rgb (0.0, 1.0, 0.0) ; // green

    G_triangle(points[0], points[1], points[2], points[3], points[4], points[5]);

    double h1 = (points[0] + points[2]) / 2.0;
    double w1 = (points[1] + points[3]) / 2.0;
    double h2 = (points[2] + points[4]) / 2.0;
    double w2 = (points[3] + points[5]) / 2.0;
    double h3 = (points[4]+  points[0]) / 2.0;
    double w3 = (points[5] + points[1]) / 2.0;


    double triangleOnePoints[6] = {points[0], points[1],
                                   h1, w1,
                                   h3, w3};

    double triangleTwoPoints[6] = { h1, w1, points[2], points[3], h2, w2 };


    double triangleThreePoints[6] = {h3, w3, h2, w2, points[4], points[5]};

    drawTriangleRecursive(triangleOnePoints, currentIteration+1, maxIterations);
    drawTriangleRecursive(triangleTwoPoints, currentIteration+1, maxIterations);
    drawTriangleRecursive(triangleThreePoints, currentIteration+1, maxIterations);


    return;
    //Drawing bottom left triangle






}







int main()
{
    int    swidth, sheight ;
    double lowleftx, lowlefty, width, height ;
    double x[10], y[10] ;
    double numxy ;
    double a[20], b[20] ;
    double numab ;

    int rows = 500;
    int rowDistance;

    int cols;
    int colDistance;

    fprintf(stdout, "\nPlease enter the number of rows:");
    //  scanf("%d", &rows);
/*
   fprintf(stdout, "\nPlease enter the number of columns:");
   scanf("%d", &cols);
   */

/*
    std::cout << "Please enter number of rows on the screen" << std::endl;
    std::cin >> rows;
    std::cin.ignore(100, '\n');
    */
/*
    std::cout << "Please enter number of columns on the screen" << std::endl;
    std::cin >> cols;
    std::cin.ignore(100, '\n');
    */


    // must do this before you do 'almost' any other graphical tasks
    swidth = 1000;  sheight = 1000;
    G_init_graphics (swidth,sheight) ;  // interactive graphics


    rowDistance = swidth / rows;
//    colDistance = sheight / cols;


    // clear the screen in a given color
    G_rgb (0.3, 0.3, 0.3) ; // dark gray
    G_clear () ;

    /*
    G_rgb (0.0, 1.0, 0.0) ; // green
    for(int r = (sheight-1) - rowDistance, c = rowDistance; r >= 0 || c <= swidth-1; r -= rowDistance, c += rowDistance) {
        G_line(0, r, c, 0);
    }
     */


 //   G_triangle(0.0, 0.0, (swidth-1) / 2, sheight, swidth-1, 0 );


    double points[6] = {0.0, 0.0, (swidth-1.0) / 2, sheight-1.0, swidth-1.0, 0.0};


    G_rgb(0, 250, 229);


//    G_triangle(0.0, 0.0, midPoint[0], midPoint[1], (swidth-1) / 2, 0);

    drawTriangleRecursive(points, 0, 15);

//    G_fill_circle(midPoint[0], midPoint[1], 2);




    /*  GRID PAPAER
    for(int r = rowDistance; r < swidth-1; r+=rowDistance) {
        G_line (r,0, r, sheight-1) ;
    }

    for(int c = colDistance; c < sheight-1; c+=colDistance) {
        G_line (0,c, swidth-1, c) ;
    }
     */












    // triangles
    /*
    G_rgb (1.0, 1.0, 0.0) ; // yellow
    G_triangle (10, 300,  40,300,  60,250) ;
    G_triangle (10,100,  40,100,  60,150) ;
     */

    /*

    // circles
    G_rgb (1.0, 0.5, 0.0) ; // orange
    G_circle (100, 300, 75) ;
    G_fill_circle (370, 200, 50) ;


    // polygons
    G_rgb (0.0, 0.0, 0.0) ; // black
    x[0] = 100 ;   y[0] = 100 ;
    x[1] = 100 ;   y[1] = 300 ;
    x[2] = 300 ;   y[2] = 300 ;
    x[3] = 300 ;   y[3] = 100 ;
    x[4] = 200 ;   y[4] = 175 ;
    numxy = 5 ;
    G_polygon (x,y,numxy) ;


    G_rgb (0.4, 0.2, 0.1) ; // brown
    a[0] = 300 ;   b[0] = 400 ;
    a[1] = 350 ;   b[1] = 450 ;
    a[2] = 275 ;   b[2] = 500 ;
    a[3] = 125 ;   b[3] = 400 ;
    numab = 4 ;
    G_fill_polygon (a,b,numab) ;

 */

    //===============================================
    double p[2], q[2] ;

    int numPoints = 10;

    double xInterval;
    double yInterval;

    G_rgb(1,0,0) ;

    G_wait_click(p) ;
    G_fill_circle(p[0],p[1],2);

    G_wait_click(q) ;
    G_fill_circle(q[0],q[1],2) ;



    drawLineWithDots(p, q, 100);



    G_rgb(0,1,0.5) ;
//    G_line(p[0],p[1], q[0],q[1]) ;

    G_rgb(1.0, 0, .75);



    int key ;
    key =  G_wait_key() ; // pause so user can see results

    //   G_save_image_to_file("demo.xwd") ;
    G_save_to_bmp_file("Demo.bmp") ;
}



