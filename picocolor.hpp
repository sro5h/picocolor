/*
   picocolor.hpp - 1.1.1

   Author:
        Paul Meffle

   Summary:
        picocolor is a single-file header that implements stream manipulators
        for ansi color sequences.

   Revision history:
        1.0   (14.08.2017) initial release
        1.0.1 (13.09.2017) add documentation
        1.1.0 (08.10.2017) only output color sequence if std::ostream is a tty
        1.1.1 (08.10.2017) remove color sequence arrays
*/

#ifndef _PICOCOLOR_HPP
#define _PICOCOLOR_HPP

// Determine the platform
#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#define PICOCOLOR_WINDOWS
#elif defined(__unix__) || defined(__unix) || defined(__linux__) ||\
        defined(__APPLE__) || defined(__MACH)
#define PICOCOLOR_UNIX
#endif


#include <iostream>

#if defined(PICOCOLOR_UNIX)
#include <unistd.h>
#elif defined(PICOCOLOR_WINDOWS)
#include <io.h>
#endif

/**
 * Holds all possible colors for both foreground and background.
 * Used for array indices, don't change the numbers!
 */
enum Color {
        Black = 0,
        Red = 1,
        Green = 2,
        Yellow = 3,
        Blue = 4,
        Magenta = 5,
        Cyan = 6,
        White = 7,
        Reset = 9,
};

/**
 * An ostream manipulator that changes the foreground color.
 */
class fg {
public:
        /**
         * @param color The color to change to
         */
        fg(const Color& color);

        /**
         * Looks up the ansi escape sequence for 'color' and ouputs it to
         * the ostream 'os'.
         *
         * @param os The ostream to manipulate
         *
         * @return A reference to 'os'
         */
        std::ostream& operator()(std::ostream& os) const;

private:
        Color color;
};

/**
 * An ostream manipulator that changes the background color.
 */
class bg {
public:
        /**
         * @param color The color to change to
         */
        bg(const Color& color);

        /**
         * Looks up the ansi escape sequence for 'color' and ouputs it to
         * the ostream 'os'.
         *
         * @param os The ostream to manipulate
         *
         * @return A reference to 'os'
         */
        std::ostream& operator()(std::ostream& os) const;

private:
        Color color;
};

#endif // _PICOCOLOR_HPP

#ifdef PICOCOLOR_IMPL

bool isTty(std::ostream& os)
{
        if (os.rdbuf() == std::cout.rdbuf()) {
#if defined(PICOCOLOR_UNIX)
                return isatty(fileno(stdout));
#elif defined(PICOCOLOR_WINDOWS)
                return _isatty(_fileno(stdout));
#endif
        }

        if (os.rdbuf() == std::cerr.rdbuf() || os.rdbuf() == std::clog.rdbuf()) {
#if defined(PICOCOLOR_UNIX)
                return isatty(fileno(stderr));
#elif defined(PICOCOLOR_WINDOWS)
                return _isatty(_fileno(stderr));
#endif
        }

        return false;
}

fg::fg(const Color& color)
        : color(color)
{
}

std::ostream& fg::operator()(std::ostream& os) const
{
        if (isTty(os)) {
                os << "\033[3" << static_cast<int>(color) << "m";
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
        if (isTty(os)) {
                os << "\033[4" << static_cast<int>(color) << "m";
        }

        return os;
}

std::ostream& operator<<(std::ostream& os, const bg& background)
{
        return background(os);
}

#endif // PICOCOLOR_IMPL

#undef PICOCOLOR_WINDOWS
#undef PICOCOLOR_UNIX

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
