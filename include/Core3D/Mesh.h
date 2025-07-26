#pragma once

#include <vector>
#include <string>
#include "Math.h"

namespace Core3D
{
    struct Triangle 
    {
        Vec3 vertices[3];
    };

    class Mesh
    {
    private:
        std::vector<Triangle> m_Triangles; 
    public:
        Mesh() = default;
        Mesh(const std::string& filename);
        ~Mesh();

        const std::vector<Triangle>& GetTriangles() const;
        void Draw();
    };
}
