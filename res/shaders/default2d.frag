#version 330 core

in vec2 v_out_uv;
in vec4 v_out_color;
flat in int v_out_texture;

out vec4 f_out_color;

uniform sampler2D u_textures[32];

void main() {
	f_out_color = texture(u_textures[v_out_texture], v_out_uv) * v_out_color;
}