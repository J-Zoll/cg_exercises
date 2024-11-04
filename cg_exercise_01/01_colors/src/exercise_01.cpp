#include <cglib/colors/exercise.h>
#include <cglib/colors/convert.h>
#include <cglib/colors/cmf.h>

#include <cglib/core/glheaders.h>
#include <cglib/core/glmstream.h>

#include <cglib/core/assert.h>
#include <iostream>

// My includes
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

/*
 * Draw the given vertices directly as GL_TRIANGLES.
 * For each vertex, also set the corresponding color.
 */
void draw_triangles(
    std::vector<glm::vec3> const &vertices,
    std::vector<glm::vec3> const &colors)
{
    cg_assert(vertices.size() == colors.size());
    cg_assert(vertices.size() % 3 == 0);

    glBegin(GL_TRIANGLES);
    for (std::size_t i = 0; i < vertices.size(); ++i)
    {
        glColor3fv(glm::value_ptr(colors[i]));
        glVertex3fv(glm::value_ptr(vertices[i]));
    }
    glEnd();
}

/*
 * Generate a regular grid of resolution N*N (2*N*N triangles) in the xy-plane (z=0).
 * Store the grid in vertex-index form.
 *
 * The vertices of the triangles should be in counter clock-wise order.
 *
 * The grid must fill exactly the square [0, 1]x[0, 1], and must
 * be generated as an Indexed Face Set (Shared Vertex representation).
 *
 * The first vertex should be at position (0,0,0) and the last
 * vertex at position (1,1,0)
 *
 * An example for N = 3:
 *
 *   ^
 *   |  ----------
 *   |  |\ |\ |\ |
 *   |  | \| \| \|
 *   |  ----------
 *   |  |\ |\ |\ |
 * y |  | \| \| \|
 *   |  ----------
 *   |  |\ |\ |\ |
 *   |  | \| \| \|
 *   |  ----------
 *   |
 *   |-------------->
 *          x
 *
 */
void generate_grid(
    std::uint32_t N,
    std::vector<glm::vec3> *vertices,
    std::vector<glm::uvec3> *indices)
{
    cg_assert(N >= 1);
    cg_assert(vertices);
    cg_assert(indices);

    vertices->clear();
    indices->clear();

    // Generate vertices
    for (std::uint32_t y = 0; y <= N; ++y)
    {
        for (std::uint32_t x = 0; x <= N; ++x)
        {
            vertices->push_back(glm::vec3(x / static_cast<float>(N), y / static_cast<float>(N), 0));
        }
    }

    // Generate indices
    for (std::uint32_t y = 0; y < N; ++y)
    {
        for (std::uint32_t x = 0; x < N; ++x)
        {
            std::uint32_t i0 = y * (N + 1) + x;
            std::uint32_t i1 = i0 + 1;
            std::uint32_t i2 = i0 + N + 1;
            std::uint32_t i3 = i2 + 1;

            indices->push_back(glm::uvec3(i0, i2, i1));
            indices->push_back(glm::uvec3(i1, i2, i3));
        }
    }
}

/*
 * Draw the given vertices as indexed GL_TRIANGLES using glDrawElements.
 * For each vertex, also set the corresponding color.
 *
 * Don't forget to enable the correct client states. After drawing
 * the triangles, you need to disable the client states again.
 */
void draw_indexed_triangles(
    std::vector<glm::vec3> const &vertices,
    std::vector<glm::vec3> const &colors,
    std::vector<glm::uvec3> const &indices)
{
    cg_assert(vertices.size() == colors.size());

    // Enable client states
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Set vertex and color pointers
    glVertexPointer(3, GL_FLOAT, 0, vertices.data());
    glColorPointer(3, GL_FLOAT, 0, colors.data());

    // Draw elements
    glDrawElements(GL_TRIANGLES, indices.size() * 3, GL_UNSIGNED_INT, indices.data());
}

/*
 * Generate a triangle strip with N segments (2*N triangles)
 * in the xy plane (z=0).
 *
 * The vertices of the triangles should be in counter clock-wise order.
 *
 * The triangle strip must fill exactly the square [0, 1]x[0, 1].
 *
 * The first vertex should be at position (0,1,0) and the last
 * vertex at position (1,0,0)
 *
 * An example for N = 3:
 *
 *   ^
 *   |  ----------
 *   |  | /| /| /|
 * y |  |/ |/ |/ |
 *   |  ----------
 *   |
 *   |-------------->
 *           x
 *
 */
void generate_strip(
    std::uint32_t N,
    std::vector<glm::vec3> *vertices)
{
    cg_assert(N >= 1);
    cg_assert(vertices);

    vertices->clear();

    // Generate vertices
    for (std::uint32_t i = 0; i <= N; ++i)
    {
        vertices->push_back(glm::vec3(i / static_cast<float>(N), 1, 0));
        vertices->push_back(glm::vec3(i / static_cast<float>(N), 0, 0));
    }
}

/*
 * Draw the given vertices as a triangle strip.
 * For each vertex, also set the corresponding color.
 */
void draw_triangle_strip(
    std::vector<glm::vec3> const &vertices,
    std::vector<glm::vec3> const &colors)
{
    cg_assert(vertices.size() == colors.size());

    glBegin(GL_TRIANGLE_STRIP);
    for (std::size_t i = 0; i < vertices.size(); ++i)
    {
        glColor3fv(glm::value_ptr(colors[i]));
        glVertex3fv(glm::value_ptr(vertices[i]));
    }
    glEnd();
}

/*
 * Integrate the given piecewise linear function
 * using trapezoidal integration.
 *
 * The function is given at points
 *     x[0], ..., x[N]
 * and its corresponding values are
 *     y[0], ..., y[N]
 */
float integrate_trapezoidal_student(
    std::vector<float> const &x,
    std::vector<float> const &y)
{
    cg_assert(x.size() == y.size());
    cg_assert(x.size() > 1);

    float integral = 0.f;

    for (std::size_t i = 0; i < x.size() - 1; ++i)
    {
        integral += (x[i + 1] - x[i]) * (y[i] + y[i + 1]) / 2.f;
    }

    return integral;
}

/*
 * Convert the given spectrum to RGB using your
 * implementation of integrate_trapezoidal(...)
 *
 * The color matching functions and the wavelengths
 * for which they are given can be found in
 *     cglib/colors/cmf.h
 * and
 *     cglib/src/colors/cmf.cpp
 *
 * The wavelengths corresponding to the spectral values
 * given in spectrum are defined in cmf::wavelengths
 */
glm::vec3 spectrum_to_rgb(std::vector<float> const &spectrum)
{
    cg_assert(spectrum.size() == cmf::wavelengths.size());

    glm::vec3 rgb(0.f);

    for (std::size_t i = 0; i < spectrum.size(); ++i)
    {
        rgb += spectrum[i] * convert::xyz_to_rgb(glm::vec3(cmf::x[i], cmf::y[i], cmf::z[i]));
    }

    return rgb;
}
// CG_REVISION 8c58412a25ac2367c053bfa840ee81b320bdd315
