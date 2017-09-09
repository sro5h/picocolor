#ifndef _PICOCOLOR_HPP
#define _PICOCOLOR_HPP

#include <iostream>

// Used for array indices, don't change the numbers!
enum Color {
        Reset = 0,
        Black,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White,

        COLOR_COUNT
};

const char* fgColors[] = {
        "\033[39m",
        "\033[30m",
        "\033[31m",
        "\033[32m",
        "\033[33m",
        "\033[34m",
        "\033[35m",
        "\033[36m",
        "\033[37m"
};

const char* bgColors[] = {
        "\033[49m",
        "\033[40m",
        "\033[41m",
        "\033[42m",
        "\033[43m",
        "\033[44m",
        "\033[45m",
        "\033[46m",
        "\033[47m",
};

class fg {
public:
        fg(const Color& color);

        std::ostream& operator()(std::ostream& os) const;

private:
        Color color;
};

class bg {
public:
        bg(const Color& color);

        std::ostream& operator()(std::ostream& os) const;

private:
        Color color;
};

#endif // _PICOCOLOR_HPP

#ifdef PICOCOLOR_IMPL

fg::fg(const Color& color)
        : color(color)
{
}

std::ostream& fg::operator()(std::ostream& os) const
{
        if (color >= 0 && color < COLOR_COUNT) {
                os << fgColors[color];
        }

        return os;
}

std::ostream& operator<<(std::ostream& os, const fg& foreground)
{
        return foreground(os);
}

bg::bg(const Color& color)
        : color(color)
{
}

std::ostream& bg::operator()(std::ostream& os) const
{
        if (color >= 0 && color < COLOR_COUNT) {
                os << bgColors[color];
        }

        return os;
}

std::ostream& operator<<(std::ostream& os, const bg& background)
{
        return background(os);
}

#endif // PICOCOLOR_IMPL

/*
   zlib license:

   Copyright (c) 2017 Paul Meffle http://github.com/sro5h
   This software is provided 'as-is', without any express or implied warranty.
   In no event will the authors be held liable for any damages arising from the
   use of this software.
   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:
     1. The origin of this software must not be misrepresented; you must not
        claim that you wrote the original software. If you use this software in
        a product, an acknowledgment in the product documentation would be
        appreciated but is not required.
     2. Altered source versions must be plainly marked as such, and must not be
        misrepresented as being the original software.
     3. This notice may not be removed or altered from any source distribution.
*/
