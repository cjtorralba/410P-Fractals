
#include  "../FPToolkit/FPToolkit.c"

#define DEGREE_TO_RAD(x) ((x * M_PI) / 180)

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


using namespace std;



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



void draw_menger_sponge(int iterations) {

    for (int i = 0; i < iterations; ++i) {

        double random = drand48();





    }

}






int main(int argc, char** argv) {

    int swidth, sheight;

    // must do this before you do 'almost' any other graphical tasks
    swidth = WIDTH;
    sheight = HEIGHT;

    G_init_graphics(swidth, sheight);  // interactive graphics

    G_rgb(0.3, 0.3, 0.3); // dark gray
    G_clear();



    double pointsOne[2];
    double pointsTwo[2];

    pointsOne[0] = 400.0;
    pointsOne[1] = 400.0;

    pointsTwo[0] = 400.0;
    pointsTwo[1] = 600.0;



    G_rgb(1.0, 0.0, 0.0);

    drawSquareAtAngle(pointsOne, pointsTwo);


    int key;
    key = G_wait_key(); // pause so user can see results

    //   G_save_image_to_file("demo.xwd") ;
    G_save_to_bmp_file("Demo.bmp");
    exit(EXIT_SUCCESS);
}
