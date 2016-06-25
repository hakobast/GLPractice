//
// Created by Hakob Astvatsatryan on 5/28/16.
//

#include "VertexAttributeLocation.h"

VertexAttributeLocation::VertexAttributeLocation(uint32_t index, const std::string& name): index_(index), name_(name){

}
uint32_t VertexAttributeLocation::getIndex() const{
    return index_;
}

std::string VertexAttributeLocation::getName() const{
    return name_;
}