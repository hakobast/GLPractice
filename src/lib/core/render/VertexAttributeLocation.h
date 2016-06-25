//
// Created by Hakob Astvatsatryan on 5/28/16.
//

#ifndef CLEARN_VERTEXATTRIBUTELOCATION_H
#define CLEARN_VERTEXATTRIBUTELOCATION_H

#include <string>

class VertexAttributeLocation {
public:
    VertexAttributeLocation(uint32_t index, const std::string& name);
    uint32_t getIndex() const;
    std::string getName() const;
private:
    const uint32_t index_;
    const std::string name_;
};


#endif //CLEARN_VERTEXATTRIBUTELOCATION_H
