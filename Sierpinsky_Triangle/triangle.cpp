//
// Created by cjtorralba on 5/26/23.
//
#include "../FPToolkit/FPToolkit.c"

#define WIDTH 800.0
#define HEIGHT 800.0

/**
 * This is a functions that creates a Sierpinsky Triangle fractal recursively. By first drawing a triangle, then halving the lenghts of the sides
 * it creates another triangle, it does the n (maxIterations) times.
 *
 * @param points array containing the verticies of the triangle we will be drawing.
 * @param currentIteration Used to keep track of currently drawn triangle
 * @param maxIterations Number of triangle it will draw
 */

void drawSierpinskyTriangleRecursive(double* points, int currentIteration, int maxIterations) {
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
    double triangleTwoPoints[6] = { h1, w1,
                                    points[2], points[3],
                                    h2, w2 };
    double triangleThreePoints[6] = {h3, w3,
                                     h2, w2,
                                     points[4], points[5]};

    drawSierpinskyTriangleRecursive(triangleOnePoints, currentIteration+1, maxIterations);
    drawSierpinskyTriangleRecursive(triangleTwoPoints, currentIteration+1, maxIterations);
    drawSierpinskyTriangleRecursive(triangleThreePoints, currentIteration+1, maxIterations);
}




int main(int argc, char** argv) {



    int swidth, sheight;


    // must do this before you do 'almost' any other graphical tasks
    swidth = WIDTH;
    sheight = HEIGHT;
    G_init_graphics(swidth, sheight);  // interactive graphics

    G_rgb(0.3, 0.3, 0.3); // dark gray
    G_clear();

    double pointsList[6] = {0.0, 0.0, (swidth - 1.0) / 2, sheight - 1.0, swidth - 1.0, 0.0};
    double p1[2] = {400.0, 400.0};

//    drawSierpinskyTriangleRecursive(pointsList, 0, 10);
    drawSierpinskiTriangleIterative(pointsList, 20);


    int key;
    key = G_wait_key(); // pause so user can see results

    //   G_save_image_to_file("demo.xwd") ;
    G_save_to_bmp_file("Demo.bmp");


}