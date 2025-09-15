#pragma once

//Baic Vertex Shader
const char* BasicVertexShader = R"(

#version 330 core

layout(location = 0) in vec2 a_position;
layout(location = 1) in vec2 a_texCoords;
layout(location = 2) in vec4 a_color;

out vec4 ao_color;

void main()
{
	gl_Position = vec4(a_position, 0.f, 1.f);
	ao_color = a_color;
}

)";

//Baic Fragment Shader
const char* BasicFragmentShader = R"(

#version 330 core

layout(location = 0) out vec4 o_color;

in vec4 ao_color;

void main()
{
	o_color = ao_color;
}

)";