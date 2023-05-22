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

#include "../FPToolkit/FPToolkit.c"


/**
 * This is a functions that creates a Sierpinsky Triangle fractal recursively. By first drawing a triangle, then halving the lenghts of the sides
 * it creates another triangle, it does the @param maxIterations times.
 *
 * @param points array containing the verticies of the triangle we will be drawing.
 * @param currentIteration Used to keep track of currently drawn triangle
 * @param maxIterations Number of triangle it will draw
 */
void drawSierpinskyTriangleRecursive(double* points, int currentIteration, int maxIterations);



#endif //CS410P_FRACTALS_SERP_TRIANGLE_H
