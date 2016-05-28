//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#include "Drawer.h"

void Drawer::addAttribute(uint32_t index, uint32_t size, AttributeFormat format,
                          uint32_t stride, Buffer::Pointer buffer){

    attributes.push_back(VertexAttribute(index, size, format, stride, buffer));
}