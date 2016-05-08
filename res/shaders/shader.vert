#version 110

uniform mat4 mvpMat;

attribute vec4 vColor;
attribute vec3 vPosition;

varying vec4 color;

void main(){
    color = vColor;
    gl_Position = mvpMat * vec4(vPosition, 1.0);
}