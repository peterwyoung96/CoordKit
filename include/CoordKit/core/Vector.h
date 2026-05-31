#pragma once

/**
 * @file Vector.h
 * @date 2026-05-30
 * @author Peter Young
 * 
 * @brief A basic structure for vectors of size N and type T
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <cmath>
#include <array>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace coordkit
{

/// @brief A vector of size N and type T
/// @tparam T the type of value stored in the vector (default = float)
/// @tparam N the number of dimensions
template <std::size_t N, typename T = float>
struct Vec
{
    std::array<T, N> data{};

    /// @brief Default constructor (zero-initialized)
    constexpr Vec() = default;

    /// @brief Full constructor (requires N inputs)
    /// @tparam ...Args 
    /// @param ...args 
    template<typename... Args>
        requires (sizeof...(Args) == N)
    constexpr Vec(Args... args)
        : data { static_cast<T>(args)... } {}

    constexpr T& operator[](std::size_t i) 
    { return data[i]; }

    constexpr const T& operator[](std::size_t i) const 
    { return data[i]; }

    std::string to_string() const
    {
        std::string str = "(";
        for (int i = 0; i < N; ++i)
        {
            if (i != 0) str += " ";
            str += std::to_string(data[i]);
            if (i != N-1) str += ",";
        }
        str += ")";
        return str;
    }

    constexpr Vec& operator+=(const Vec& rhs)
    {
        for (std::size_t i = 0; i < N; ++i)
            data[i] += rhs.data[i];
        return *this;
    }

    constexpr Vec& operator-=(const Vec& rhs)
    {
        for (std::size_t i = 0; i < N; ++i)
            data[i] -= rhs.data[i];
        return *this;
    }

    constexpr Vec& operator*=(const T& scalar)
    {
        for (std::size_t i = 0; i < N; ++i)
            data[i] *= scalar;
        return *this;
    }

    constexpr Vec& operator/=(const T& scalar)
    {
        for (std::size_t i = 0; i < N; ++i)
            data[i] /= scalar;
        return *this;
    }

    constexpr bool operator==(const Vec&) const = default;

}; // end-struct Vec


/// @brief Copy a vector (essentially additive identity)
/// @tparam T 
/// @tparam N 
/// @param v 
/// @return 
template <std::size_t N, typename T>
constexpr Vec<N, T> operator+(const Vec<N, T>& v)
{ return v; }


template <std::size_t N, typename T>
Vec<N, T> operator-(const Vec<N, T>& v)
{
    Vec<N, T> result;
    for (std::size_t i = 0; i < N; ++i)
        result[i] = -v[i];
    return result;
}


/// @brief Allow for vectors to be added together.
/// @tparam T 
/// @tparam N 
/// @param a 
/// @param b 
/// @return 
template <std::size_t N, typename T>
constexpr Vec<N, T> operator+(const Vec<N, T>& a, const Vec<N, T>& b) 
{
    Vec<N, T> result;
    for (std::size_t i = 0; i < N; i++)
        result[i] = a[i] + b[i];
    return result;
} // end-operator+


/// @brief Allow for vectors to be substracted.
/// @tparam T 
/// @tparam N 
/// @param a 
/// @param b 
/// @return 
template <std::size_t N, typename T>
constexpr Vec<N, T> operator-(const Vec<N, T>& a, const Vec<N, T>& b) 
{
    Vec<N, T> result;
    for (std::size_t i = 0; i < N; i++)
        result[i] = a[i] - b[i];
    return result;
} // end-operator-


template <std::size_t N, typename T>
constexpr Vec<N, T> operator*(Vec<N,T> lhs, const T& scalar)
{
    lhs *= scalar;
    return lhs;
}


template <std::size_t N, typename T>
constexpr Vec<N, T> operator*(const T& scalar, Vec<N,T> rhs)
{
    rhs *= scalar;
    return rhs;
}


template <std::size_t N, typename T>
constexpr Vec<N, T> operator/(Vec<N,T> lhs, const T& scalar)
{
    lhs /= scalar;
    return lhs;
}


template <std::size_t N, typename T>
constexpr Vec<N, T> operator/(const T& scalar, Vec<N,T> rhs)
{
    rhs /= scalar;
    return rhs;
}


/// @brief Allow for dot products
/// @tparam T 
/// @tparam N 
/// @param a 
/// @param b 
/// @return 
template <std::size_t N, typename T>
constexpr T dot(const Vec<N, T>& a, const Vec<N, T>& b) 
{
    T result{};
    for (std::size_t i = 0; i < N; i++)
        result += a[i] * b[i];
    return result;
} // end-dot


/// @brief Cross product (3D specific)
/// @tparam T 
/// @param a 
/// @param b 
/// @return 
template <typename T>
constexpr Vec<3, T> cross(const Vec<3, T>& a,
                          const Vec<3, T>& b)
{
    return Vec<3, T>(
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0]
    );
} // end-cross


/// @brief Get the length of the vector
/// @tparam T 
/// @tparam N 
/// @param v 
/// @return 
template <std::size_t N, typename T>
constexpr T length(const Vec<N, T>& v)
{ return std::sqrt(dot(v, v)); } 


/// @brief Normalize the vector (i.e. length = 1)
/// @tparam T 
/// @tparam N 
/// @param v 
/// @return 
template <std::size_t N, typename T>
constexpr Vec<N, T> normalize(const Vec<N, T>& v) 
{
    T len = length(v);
    if (len == T(0)) return v;

    Vec<N, T> result;
    for (std::size_t i = 0; i < N; i++)
        result[i] = v[i] / len;
    return result;
} // end-normalize



/// @brief A special wrapper for 2D vectors
/// @tparam T 
template <typename T = float>
struct Vec2 : public Vec<2,T>
{
    using Base = Vec<2,T>;

    Vec2() = default;

    Vec2(T val0, T val1)
     : Base(val0, val1) {}

    T& x() { return this->data[0]; }
    T& y() { return this->data[1]; }
}; // end-struct Vec2


/// @brief A special wrapper for 3D vectors
/// @tparam T 
template <typename T = float>
struct Vec3 : public Vec<3, T> 
{
    using Base = Vec<3,T>;

    Vec3() = default;

    Vec3(T val0, T val1, T val2)
     : Base(val0, val1, val2) {}

    T& x() { return this->data[0]; }
    T& y() { return this->data[1]; }
    T& z() { return this->data[2]; }
}; // end-struct Vec3
    
} // namespace coordkit

// // EOF //////////////////////////////////////////////////////////////////////