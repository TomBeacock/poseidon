#version 330 core

layout(location = 0) in vec2 v_in_pos;
layout(location = 1) in vec2 v_in_uv;
layout(location = 2) in vec4 v_in_color;
layout(location = 3) in int v_in_texture;

out vec2 v_out_uv;
out vec4 v_out_color;
flat out int v_out_texture;

uniform mat4 u_model;
uniform mat4 u_projection;

void main() {
	v_out_uv = v_in_uv;
	v_out_color = v_in_color;
	v_out_texture = v_in_texture;
	gl_Position = u_projection * u_model * vec4(v_in_pos, 0.0, 1.0);
}