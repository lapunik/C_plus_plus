#include <iostream>
#include <string>
#include "pbPlots.h"
#include "supportLib.h"

int main()
{

	RGBABitmapImageReference canvasReference1 = CreateRGBABitmapImageReference();
	RGBABitmapImageReference canvasReference2 = CreateRGBABitmapImageReference();
	RGBABitmapImageReference canvasReference3 = CreateRGBABitmapImageReference();
	RGBABitmapImageReference canvasReference4 = CreateRGBABitmapImageReference();
	RGBABitmapImage combined = CreateImage(250 * 2, 200 * 2, GetWhite());
	RGBABitmapImage image1, image2, image3, image4;

	double[] xs = { -2, -1, 0, 1, 2 };

	double[] ys1 = { 2, -1, -2, -1, 2 };
	double[] ys2 = { -2, 1, 2, 1, -2 };
	double[] ys3 = { 0, 1, 2, 3, 4 };
	double[] ys4 = { 0, -1, -2, -3, -4 };

	boolean success;
	success = DrawScatterPlot(canvasReference1, 250, 200, xs, ys1);
	success = success && DrawScatterPlot(canvasReference2, 250, 200, xs, ys2);
	success = success && DrawScatterPlot(canvasReference3, 250, 200, xs, ys3);
	success = success && DrawScatterPlot(canvasReference4, 250, 200, xs, ys4);

	if (success) {
		image1 = canvasReference1.image;
		image2 = canvasReference2.image;
		image3 = canvasReference3.image;
		image4 = canvasReference4.image;

		DrawImageOnImage(combined, image1, 0, 0);
		DrawImageOnImage(combined, image2, 0, 200);
		DrawImageOnImage(combined, image3, 250, 0);
		DrawImageOnImage(combined, image4, 250, 200);
	}


}