#version 110

uniform mat4 mvpMat;

attribute vec3 position;

void main(){
    gl_Position = mvpMat * vec4(position, 1.0);
}