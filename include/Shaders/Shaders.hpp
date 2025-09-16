#pragma once

//Baic Vertex Shader
const char* BasicVertexShader = R"(

#version 330 core

layout(location = 0) in vec2 a_position;
layout(location = 1) in vec2 a_texCoords;
layout(location = 2) in vec4 a_color;

uniform mat4 u_mvp;

out vec4 ao_color;
out vec2 ao_texCoords;

void main()
{
	gl_Position = u_mvp * vec4(a_position, 0.f, 1.f);
	ao_texCoords = a_texCoords;
	ao_color = a_color;	
}

)";

//Baic Fragment Shader
const char* BasicFragmentShader = R"(

#version 330 core

out vec4 o_color;

uniform bool u_useTexture;
uniform sampler2D u_sampler;

in vec2 ao_texCoords;
in vec4 ao_color;


void main()
{

	if(u_useTexture)
	{
		vec4 texColor = texture(u_sampler, ao_texCoords);
		o_color = texColor * ao_color;
	}
	else
	{
		o_color = ao_color;
	}
	
}

)";