#version 110

uniform sampler2D un_texture;
uniform vec4 un_color;

varying vec2 v_texCoord;

void main(){
    gl_FragColor = texture2D(un_texture, v_texCoord) * un_color;
}