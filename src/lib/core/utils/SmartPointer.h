//
// Created by Hakob Astvatsatryan on 4/27/16.
//

#ifndef SMARTOBJECT_H
#define SMARTOBJECT_H

#include <memory>

template<typename T>
class SmartPointer : public std::enable_shared_from_this<T>{
public:
    virtual ~SmartPointer(){}
    typedef std::shared_ptr<T> Pointer;
    typedef std::weak_ptr<T> WeakPointer;

    std::shared_ptr<T> getPtr(){
        return this->shared_from_this();
    }
};
#endif //SMARTOBJECT_H
