#pragma once

/**
 * @file Coordinates.h
 * @date 2026-05-30
 * @author Peter Young
 * 
 * @file Extensions of the basic vector classes for math purposes
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <CoordKit/core/Vector.h>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace coordkit::math
{

/// @brief A special wrapper for 2D cartesian vectors
/// @tparam T 
template <typename T = float>
struct Cartesian2f : public Vec<2,T>
{
    using Base = Vec<2,T>;

    Cartesian2f() = default;
    Cartesian2f(std::initializer_list<T> init)
     : Base(init) {}

    T& x() { return this->data[0]; }
    T& y() { return this->data[1]; }
}; // end-struct Cartesian2f


/// @brief A special wrapper for 3D cartesian vectors
/// @tparam T 
template <typename T = float>
struct Cartesian3f : public Vec<3, T> 
{
    using Base = Vec<3,T>;

    Cartesian3f() = default;
    Cartesian3f(std::initializer_list<T> init)
        : Base(init) {}

    T& x() { return this->data[0]; }
    T& y() { return this->data[1]; }
    T& z() { return this->data[2]; }
}; // end-struct Cartesian3f


/// @brief A special wrapper for 2D polar coordinates
/// @tparam T 
template <typename T = float>
struct Polar2f : public Vec<2, T>
{
    using Base = Vec<2,T>;

    Polar2f() = default;
    Polar2f(std::initializer_list<T> init)
     : Base(init) {}

    T& r() { return this->data[0]; }
    T& theta() { return this->data[1]; }
}; // end-struct Polar2f


/// @brief A special wrapper for 3D spherical vectors
/// @tparam T 
template <typename T = float>
struct Spherical3f : public Vec<3, T> 
{
    using Base = Vec<3,T>;

    Spherical3f() = default;
    Spherical3f(std::initializer_list<T> init)
        : Base(init) {}

    T& r() { return this->data[0]; }
    T& theta() { return this->data[1]; }
    T& phi() { return this->data[2]; }
}; // end-struct Cartesian3f
    
} // namespace coordkit::math

// // EOF //////////////////////////////////////////////////////////////////////