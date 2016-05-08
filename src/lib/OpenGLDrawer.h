//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#ifndef OPENGLDRAWER_H
#define OPENGLDRAWER_H

#include "OpenGL.h"
#include "Drawer.h"

class OpenGLDrawer : public Drawer{
public:
    OpenGLDrawer();
    virtual ~OpenGLDrawer();
    virtual void draw(DrawingType type, uint32_t startIndex, uint32_t count);
private:
    GLenum toGL(AttributeFormat format);
    GLenum toGL(DrawingType type);
};


#endif //OPENGLDRAWER_H
