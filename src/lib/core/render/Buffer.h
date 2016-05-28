//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#ifndef BUFFER_H
#define BUFFER_H

#include "../../utils/SmartPointer.h"

class Buffer : public SmartPointer<Buffer>{
public:
    virtual ~Buffer(){};
    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual void setData(uint32_t size, const void* data) = 0;
    virtual void setDataOffset(uint32_t offset, uint32_t size, const void* data) = 0;
};


#endif //BUFFER_H
