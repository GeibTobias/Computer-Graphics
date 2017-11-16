#include <iostream>
#include "renderer.h"
#include <core/image.h>
#include <main/a_julia.cpp>
#include <algorithm>

using namespace std;
using namespace rt;

void Renderer::test_render1(Image& img) {
	uint w = img.width();
	uint h = img.height();
	Image imgTemp(w, h);
	for (uint xAxis = 0; xAxis < w; xAxis++) {
		for (uint yAxis = 0; yAxis < h; yAxis++) {
			img.operator()(xAxis, yAxis);
			RGBColor pixModif = a1computeColor(xAxis, yAxis, w, h);
			
		}
	}
}