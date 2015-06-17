#include "Cube.h"

float _rotation;

static GLint vertices[][3] =
{
    { -0x10000, -0x10000, -0x10000 },
    { 0x10000, -0x10000, -0x10000 },
    { 0x10000,  0x10000, -0x10000 },
    { -0x10000,  0x10000, -0x10000 },
    { -0x10000, -0x10000,  0x10000 },
    { 0x10000, -0x10000,  0x10000 },
    { 0x10000,  0x10000,  0x10000 },
    { -0x10000,  0x10000,  0x10000 }
};

static GLint colors[][4] =
{
    { 0x00000, 0x00000, 0x00000, 0x10000 },
    { 0x10000, 0x00000, 0x00000, 0x10000 },
    { 0x10000, 0x10000, 0x00000, 0x10000 },
    { 0x00000, 0x10000, 0x00000, 0x10000 },
    { 0x00000, 0x00000, 0x10000, 0x10000 },
    { 0x10000, 0x00000, 0x10000, 0x10000 },
    { 0x10000, 0x10000, 0x10000, 0x10000 },
    { 0x00000, 0x10000, 0x10000, 0x10000 }
};

GLubyte indices[] =
{
    0, 4, 5,    0, 5, 1,
    1, 5, 6,    1, 6, 2,
    2, 6, 7,    2, 7, 3,
    3, 7, 4,    3, 4, 0,
    4, 7, 6,    4, 6, 5,
    3, 0, 1,    3, 1, 2
};

void Cube_setupGL(double width, double height)
{
    // Initialize GL state.
    glDisable(GL_DITHER);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
    glClearColor(1.0f, 0.41f, 0.71f, 1.0f);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, width, height);
    GLfloat ratio = (GLfloat)width / height;
}

void Cube_tearDownGL()
{
}

void Cube_update()
{
    _rotation += 1.f;

}
void Cube_prepare()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Cube_draw()
{
    glFrontFace(GL_CW);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
}
