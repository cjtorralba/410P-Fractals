/**
 * @author Christian Torralba
 * @version 1.0
 * @since 1.0
 *
 * This is the header file for the serp_triangle function
 */

#pragma once
#ifndef CS410P_FRACTALS_SERP_TRIANGLE_H
#define CS410P_FRACTALS_SERP_TRIANGLE_H



/**
 * This is a functions that creates a Sierpinsky Triangle fractal recursively. By first drawing a triangle, then halving the lenghts of the sides
 * it creates another triangle, it does the @param maxIterations times.
 *
 * @param points array containing the verticies of the triangle we will be drawing.
 * @param currentIteration Used to keep track of currently drawn triangle
 * @param maxIterations Number of triangle it will draw
 */
void drawSierpinskyTriangleRecursive(double* points, int currentIteration, int maxIterations); {
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

    drawTriangleRecursive(triangleOnePoints, currentIteration+1, maxIterations);
    drawTriangleRecursive(triangleTwoPoints, currentIteration+1, maxIterations);
    drawTriangleRecursive(triangleThreePoints, currentIteration+1, maxIterations);


    return;

}





#endif //CS410P_FRACTALS_SERP_TRIANGLE_H
