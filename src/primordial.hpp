////////////////////////////////////////////////////////////
// PRIMORDIAL
// ----------
// Provides a variety of basic math functions
//
// Written by surfactants (https://github.com/surfactants)
//
// LICENSE
// -------
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#pragma once

#include <SFML/System/Vector2.hpp>

#include <cmath>

constexpr static float PI { 3.14159265359 };

/// roundFloat ///
/// \brief Rounds a float to the nearest integer
int roundFloat(float f);

/// scalarDistance ///
/// \brief Scalar distance between two Vector2<T> (Pythagorean theorem).
template <typename T>
T scalarDistance(const sf::Vector2<T> v, const sf::Vector2<T> w)
{
    T a = std::abs(w.x - v.x);
    T b = std::abs(w.y - v.y);
    return static_cast<T>(std::sqrt(pow(a, 2) + pow(b, 2)));
}

/// vectorDistance ///
/// \brief Distance between two Vector2<T> (simple subtraction).
template <typename T>
sf::Vector2<T> vectorDistance(const sf::Vector2<T> v, const sf::Vector2<T> w)
{
    return sf::Vector2<T>(w.x - v.x, w.y - v.y);
}

/// sign ///
/// \brief Tests the sign of val. Returns +1 if positive, -1 if negative, and 0 if val is 0.
template <typename T>
int sign(T val)
{
    return (T(0) < val) - (val < T(0));
}

/// calculateMoveVector ///
/// \brief ...
sf::Vector2f calculateMoveVector(float angle, float velocity);

/// calculateAngle ///
/// \brief ...
template <typename T>
float calculateAngle(sf::Vector2<T> v, sf::Vector2<T> w)
{
    float theta;

    //defines a right triangle between two points
    float opp = w.y - v.y;
    float adj = w.x - v.x;

    //calculates theta in radians
    theta = atan(opp / adj);

    //converts theta to degrees
    theta *= 180 / PI;
    //theta += 90.f;

    //converts theta for use with GLSL
    if (adj > 0) {
        //theta += 90;
    }
    else if (adj < 0) {
        //theta += 180;
    }

    return theta;
}
