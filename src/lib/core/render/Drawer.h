//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#ifndef DRAWER_H
#define DRAWER_H

#include "../../utils/SmartPointer.h"
#include "Buffer.h"
#include <vector>

enum class AttributeFormat{
    INT,
    FLOAT,
};

enum class DrawingType{
    TRIANGLE,
    QUAD,
};

class Drawer : public SmartPointer<Drawer>{

public:
    virtual ~Drawer(){}
    virtual void draw(DrawingType type, uint32_t startIndex, uint32_t count) = 0;

    void addAttribute(uint32_t index, uint32_t size, AttributeFormat format, uint32_t stride, Buffer::Pointer buffer);
protected:
    class VertexAttribute{
    public:
        uint32_t index;
        uint32_t size;
        uint32_t stride;
        AttributeFormat format;
        Buffer::Pointer buffer;

        VertexAttribute(uint32_t index, uint32_t size, AttributeFormat format, uint32_t stride, Buffer::Pointer buffer):
                index(index), size(size), format(format), stride(stride), buffer(buffer){}
    };
    std::vector<VertexAttribute> attributes;
};


#endif //DRAWER_H
