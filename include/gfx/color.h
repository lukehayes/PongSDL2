#ifndef COLOR_H
#define COLOR_H

namespace Gfx {

	class Color {

	public:

		Color() : r(255), g(255), b(255), a(255) {}
		Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}
	
		int r;
		int g;
		int b;
		int a;
	};
}

extern Gfx::Color RED(255,0,0,255);
extern Gfx::Color GREEN(0,255,0,255);
extern Gfx::Color BLUE(0,0,255,255);

#endif;
