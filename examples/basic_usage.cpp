// // HEADERS //////////////////////////////////////////////////////////////////
#include <iostream>
#include <CoordKit/core/Vector.h>

// // MAIN METHOD //////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    std::cout << "Hello, world!" << std::endl;

    coordkit::Vec<3> vec1 { 1.0f, 2.0f, 3.0f };
    std::cout << "vec1 = " << vec1.to_string() << std::endl;

    coordkit::Vec3 vec2 { 3.0f, 2.0f, 1.0f };
    std::cout << "vec2 = " << vec2.to_string() << std::endl;
    
    std::cout << "vec1 + vec2 = " << (vec1+vec2).to_string() << std::endl;

    auto vec3 = vec1 + vec2;
    for (int i = 0; i < 3; ++i)
        std::cout << "comp #" << (i+1) << " = " << vec3[i] << "\n";

    std::cout << "2*vec1 = " << (2.0f * vec1).to_string() << std::endl;
    std::cout << "vec2*3 = " << (vec2 * 3.0f).to_string() << std::endl;
    return 0;
}

// // EOF //////////////////////////////////////////////////////////////////////