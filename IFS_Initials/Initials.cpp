//
// Created by cjtorralba on 5/22/23.
//

#include "../FPToolkit/FPToolkit.c"
#include <stdlib.h>

#define WIDTH 1920.0
#define HEIGHT 1080.0

using namespace std;

double points[] = {0.0, 0.0};


void scale(double scaleFactorX, double scaleFactorY) {
    points[0] *= scaleFactorX;
    points[1] *= scaleFactorY;
}


void translate(double transFactorX, double transFactorY) {
    points[0] += transFactorX;
    points[1] += transFactorY;
}

void IFS_Initials(int iterations) {

    for (int i = 0; i < iterations; ++i) {


    }
}


int main(int argc, char **argv) {
    int swidth, sheight;

    // must do this before you do 'almost' any other graphical tasks
    swidth = WIDTH;
    sheight = HEIGHT;

    G_init_graphics(swidth, sheight);  // interactive graphics

    G_rgb(0.3, 0.3, 0.3); // dark gray
    G_clear();


    // Drawing





    // Waiting for keypress
    int key;
    key = G_wait_key(); // pause so user can see results

    //   G_save_image_to_file("demo.xwd") ;
    G_save_to_bmp_file("Demo.bmp");


    exit(EXIT_SUCCESS);
}
