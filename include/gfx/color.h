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

    /** Static Colours */
    static Gfx::Color WHITE{ 255, 255, 255,255 };
    static Gfx::Color BLACK{ 19, 19, 20, 255 };

    static Gfx::Color BG_GREY{ 180, 180, 200, 255 };
    static Gfx::Color LIGHT_GREY{ 244, 245, 247, 255 };
    static Gfx::Color DARK_GREY{ 86, 86, 97, 255 };

    static Gfx::Color RED{ 237, 22, 67, 255 };
    static Gfx::Color GREEN{ 87, 181, 98, 255 };
    static Gfx::Color BLUE{ 45, 107, 207, 255 };
}


#endif
