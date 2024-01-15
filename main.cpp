#include <bits/stdc++.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>



// Creating the Rainfall
void Rain(int x)
{
    int i, rx, ry;
    for (i = 0; i < 1000; i++)
    {
        rx = rand() % 1000;
        ry = rand() % 1000;
        if (ry < 1000 - 4)
        {
            if (ry < 1000 - 120 ||
                    (ry > 1000 - 120 &&
                     (rx < x - 20 ||
                      rx > x + 60)))
                line(rx, ry,rx + 0.5, ry + 4);
        }
    }
}

// End the Rainfall


//  Rainfall start
void cloud(int x, int y)
{
    setcolor(WHITE	);
    setfillstyle(1, WHITE	);


    ellipse(x, y, 0, 360, 40, 20);
    floodfill(x, y, WHITE	);

    ellipse(x+50, y, 0, 360, 40, 25);
    floodfill(x+50, y, WHITE	);

}
// Rainfall End


//2nd Yellow Car Start
void drawCar(int x, int midy)
{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);

    line(0 + x, midy + 23, 0 + x, midy);
    line(0 + x, midy, 20 + x, midy);
    line(20 + x, midy, 40 + x, midy - 20);
    line(40 + x, midy - 20, 80 + x, midy - 20);
    line(80 + x, midy - 20, 100 + x, midy);
    line(100 + x, midy, 120 + x, midy);
    line(120 + x, midy, 120 + x, midy + 23);
    line(0 + x, midy + 23, 18 + x, midy + 23);
    arc(30 + x, midy + 23, 0, 180, 12);
    line(42 + x, midy + 23, 78 + x, midy + 23);
    arc(90 + x, midy + 23, 0, 180, 12);
    line(102 + x, midy + 23, 120 + x, midy + 23);

    line(28 + x, midy, 43 + x, midy - 15);
    line(43 + x, midy - 15, 57 + x, midy - 15);
    line(57 + x, midy - 15, 57 + x, midy);
    line(57 + x, midy, 28 + x, midy);

    line(62 + x, midy - 15, 77 + x, midy - 15);
    line(77 + x, midy - 15, 92 + x, midy);
    line(92 + x, midy, 62 + x, midy);
    line(62 + x, midy, 62 + x, midy - 15);
    floodfill(5 + x, midy + 22, YELLOW);
    setcolor(DARKGRAY);

    circle(30 + x, midy + 25, 9);
    circle(90 + x, midy + 25, 9);
    floodfill(30 + x, midy + 25, DARKGRAY);
    floodfill(90 + x, midy + 25, DARKGRAY);
}

//2nd Yellow Car End


//Main Function
int main()
{
    int g = 0, d;
    initgraph(&g, &d, "c:\\turboc3\\bgi");

    int maxx, midy,x;

    /* max position in x-axis */
    maxx = getmaxx();

    /* mid position in y-axis */
    midy = getmaxy() / 2;


    int cloud1X = 0;  // New cloud x-coordinate
    int cloud2X = 20; // New cloud x-coordinate
    int cloud3X = 200;// New cloud x-coordinate
    int cloud4X = 225; // New cloud x-coordinate


    for (float i = 0, j = 0, k = 0, l = 0, angle = 360, angle1 = 0; i < 80, j < 100, k < 301, l < 82, angle > 0, angle1 <= 360; i += 1, j += 0.5, k += 2, l += 3, angle -= 1, angle1 += 6)
    {
        Rain(x);

        // outtextxy(rand()%600,rand()%445,"/ ");

        if (kbhit())
        {
            break;
        }
        delay(50);
        clearviewport();



        // Road divider starts
        setfillstyle(1, 15);
        setcolor(15);
        bar(k - 150, 290, 0 + k, 300);
        bar(150 + k, 290, 300 + k, 300);
        bar(450 + k, 290, 600 + k, 300);
        if (k == 300)
        {
            k -= 300;
        }
        // Road divider ends


        // Footpath starts
        setfillstyle(1, 7);
        setcolor(7);
        rectangle(0, 200, 640, 220);
        rectangle(i - 80, 200, i - 40, 220);
        bar(i - 40, 200, 0 + i, 220); //Footpath   box
        rectangle(0 + i, 200, 40 + i, 220);
        bar(40 + i, 200, 80 + i, 220);
        rectangle(80 + i, 200, 120 + i, 220);
        bar(120 + i, 200, 160 + i, 220);
        rectangle(160 + i, 200, 200 + i, 220);
        bar(200 + i, 200, 240 + i, 220);
        rectangle(240 + i, 200, 280 + i, 220);
        bar(280 + i, 200, 320 + i, 220);
        rectangle(320 + i, 200, 360 + i, 220);
        bar(360 + i, 200, 400 + i, 220);
        rectangle(400 + i, 200, 440 + i, 220);
        bar(440 + i, 200, 480 + i, 220);
        rectangle(480 + i, 200, 520 + i, 220);
        bar(520 + i, 200, 560 + i, 220);
        rectangle(560 + i, 200, 600 + i, 220);
        bar(600 + i, 200, 640 + i, 220);
        if (i == 79)
        {
            i -= 79;
        }
        // Footpath ends


        // Day starts
        if (angle >= 90 && angle <= 270)
        {
            int x = 340 * sin(angle * 3.14 / 180);
            int y = 130 * cos(angle * 3.14 / 180);
            setcolor(14);
            setfillstyle(1, 14);

            pieslice(x + 320, y + 180, 0, 360, 30); // SUN
        }
        // Day ends

        // Night starts
        if ((angle > 270 && angle < 360) || (angle >= 0 && angle < 90))
        {
            int x1 = 340 * sin((angle + 180) * 3.14 / 180);
            int y1 = 130 * cos((angle + 180) * 3.14 / 180);
            setcolor(7);
            setfillstyle(1, 7);
            pieslice(x1 + 320, y1 + 180, 0, 360, 20); // MOON
        }
        if (angle == 1)
        {
            angle += 359;
        }
        // Night ends


        // Pole starts
        setfillstyle(1, 6);
        setcolor(6);
        bar(0, 155, 640, 160);
        setfillstyle(1, 6);
        bar(j - 100, 140, j - 95, 200);
        bar(0 + j, 140, 5 + j, 200);
        bar(100 + j, 140, 105 + j, 200);
        bar(200 + j, 140, 205 + j, 200);
        bar(300 + j, 140, 305 + j, 200);
        bar(400 + j, 140, 405 + j, 200);
        bar(500 + j, 140, 505 + j, 200);
        bar(600 + j, 140, 605 + j, 200);
        if (j == 99)
        {
            j -= 99;
        }
        // Pole ends



        // 2footpath starts
        setfillstyle(1, 7);
        setcolor(7);
        rectangle(0, 400, 640, 420);
        rectangle(l - 80, 400, l - 40, 420);
        bar(l - 40, 400, 0 + l, 420);
        rectangle(0 + l, 400, 40 + l, 420);
        bar(40 + l, 400, 80 + l, 420);
        rectangle(80 + l, 400, 120 + l, 420);
        bar(120 + l, 400, 160 + l, 420);
        rectangle(160 + l, 400, 200 + l, 420);
        bar(200 + l, 400, 240 + l, 420);
        rectangle(240 + l, 400, 280 + l, 420);
        bar(280 + l, 400, 320 + l, 420);
        rectangle(320 + l, 400, 360 + l, 420);
        bar(360 + l, 400, 400 + l, 420);
        rectangle(400 + l, 400, 440 + l, 420);
        bar(440 + l, 400, 480 + l, 420);
        rectangle(480 + l, 400, 520 + l, 420);
        bar(520 + l, 400, 560 + l, 420);
        rectangle(560 + l, 400, 600 + l, 420);
        bar(600 + l, 400, 640 + l, 420);
        if (l == 81)
        {
            l -= 81;
        }
        // 2footpath ends


        // Grass starts
        setcolor(2);
        setfillstyle(9, 2);
        line(0, 421, 640, 421);
        floodfill(0, 470, 2);
        // Grass ends


        //1st Blue car

       //1st Blue car

        setcolor(MAGENTA	); // Car starts
        setfillstyle(9, MAGENTA		); //Top color


        sector(340, 280, 0, 180, 70, 45);
         setfillstyle(1, 1); // Down color


        bar(240, 280, 410, 320);
        setcolor(7); // RIM color

        setfillstyle(1, 3); // Tair color
        pieslice(265, 315, 0, 360, 15);
        pieslice(380, 315, 0, 360, 15);
        //setcolor(0);
        int x1 = 15 * sin(angle1 * 3.14 / 180);
        int y1 = 15 * cos(angle1 * 3.14 / 180);
        line(265, 315, 265 + x1, 315 + y1);
        int x2 = 15 * sin((angle1 + 90) * 3.14 / 180);
        int y2 = 15 * cos((angle1 + 90) * 3.14 / 180);
        line(265, 315, 265 + x2, 315 + y2);
        int x3 = 15 * sin((angle1 + 180) * 3.14 / 180);
        int y3 = 15 * cos((angle1 + 180) * 3.14 / 180);
        line(265, 315, 265 + x3, 315 + y3);
        int x4 = 15 * sin((angle1 + 270) * 3.14 / 180);
        int y4 = 15 * cos((angle1 + 270) * 3.14 / 180);
        line(265, 315, 265 + x4, 315 + y4);
        line(380, 315, 380 + x1, 315 + y1);
        line(380, 315, 380 + x2, 315 + y2);
        line(380, 315, 380 + x3, 315 + y3);
        line(380, 315, 380 + x4, 315 + y4);
        if (angle1 == 360)
        {
            angle1 -= 360;
        }

        // 1st Blue Car ends


        // Called 2nd car function
        drawCar(x, midy);

        x += 3; // Move the car to the right

        if (x >= maxx - 125)
        {
            x = 0; // Reset the car's position
        }

        // Called 2nd car function end


        // Update the x-coordinates of the clouds for animation
        cloud1X += 1; // Move the first cloud to the right
        cloud2X += 1.5; // Move the second cloud to the right
        cloud3X += 1.2; // Adjust the cloud movement speed
        cloud4X += 1.5;


        // Wrap the clouds to the left when they reach the right edge of the screen
        if (cloud1X > getmaxx())
        {
            cloud1X = -20;
        }
        if (cloud2X > getmaxx())
        {
            cloud2X = -20;
        }
        if (cloud3X > getmaxx())
        {
            cloud3X = -20;
        }
        if (cloud4X > getmaxx())
        {
            cloud4X = -20;
        }

        // Draw the clouds with updated coordinates
        cloud(cloud1X, 50);
        cloud(cloud2X, 80);
        cloud(cloud3X, 20);
        cloud(cloud4X, 40);

    }
    getch();
    closegraph();
    return 0;
}


