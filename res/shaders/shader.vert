#version 110

uniform mat4 un_mvpMat;

attribute vec3 in_Position;
attribute vec2 in_TexCoord;
attribute vec4 in_Color;

varying vec2 v_texCoord;
varying vec4 v_color;

void main(){
    v_color = in_Color;
    v_texCoord = in_TexCoord;
    gl_Position = un_mvpMat * vec4(in_Position, 1.0);
}