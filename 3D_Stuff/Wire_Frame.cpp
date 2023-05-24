//
// Created by cjtorralba on 5/22/23.
//

#include "../FPToolkit/FPToolkit.c"


#define WIDTH 800.0
#define HEIGHT 800.0


double points[] = {0.0, 0.0};


void scale(double scaleFactorX, double scaleFactorY) {
    points[0] *= scaleFactorX;
    points[1] *= scaleFactorY;
}


void translate(double transFactorX, double transFactorY) {
    points[0] += transFactorX;
    points[1] += transFactorY;
}

using namespace std;

int main(int argc, char** argv) {

   // Initialize graphics
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
