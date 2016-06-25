//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <glm/glm.hpp>
#include <string>
#include "../mat/Vector2.h"
#include "../utils/SmartPointer.h"

class GameObject{
public:
    GameObject();
    virtual ~GameObject();
    virtual void update() = 0;
    void setPosition(const Vector2& position);
    void setRotation(float angle);
    void translate(const Vector2& deltaPosition);
    void rotate(float deltaAngle);
	void setName(const std::string& name);
	std::string getName() const;
    const glm::mat4& getTransformMatrix();
private:
	std::string name_;
    glm::mat4 mMat_;
    Vector2 position_;
    float angle_ = 0.0f;
};


#endif //CLEARN_GAMEOBJECT_H
