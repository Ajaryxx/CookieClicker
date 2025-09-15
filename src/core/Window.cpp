#include "PCH.hpp"
#include "core/Window.hpp"
#include "utility/OpenGLUtilities/VertexBuffer2D.hpp"
#include "utility/OpenGLUtilities/Shader.hpp"
#include "utility/OpenGLUtilities/Texture.hpp"
#include "Shaders/Shaders.hpp"

Window::~Window()
{
	spdlog::info("Window Destroyed");
}
bool Window::Init()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		spdlog::error("SDL couldnt be initzialized {}", SDL_GetError());
		return false;
	}

	SetAllOpenGLWindowAttributes();
	
	m_Window = SDL_CreateWindow(m_WindowParameters.title, m_WindowParameters.width, m_WindowParameters.height, m_WindowParameters.windowFlags);
	if (!m_Window)
	{
		spdlog::error("SDL WINDOW INIT ERROR {}", SDL_GetError());
		return false;
	}
	m_GLContext = SDL_GL_CreateContext(m_Window);
	if (!m_GLContext)
	{
		spdlog::error("FAILED TO CREATE OPENGL CONTEXT {}", SDL_GetError());
		return false;
	}

	int result = gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
	if (!result)
	{
		spdlog::error("FAILED TO LOAD OPENGL FUNCTION POINTER");
		return false;
	}
	spdlog::info("Window and OpenGl context succesfully initzialized! :)");

	return true;
}

void Window::SetAllOpenGLWindowAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void Window::Loop()
{
	Vertex2D vertex[4] =
	{
		Vertex2D{glm::vec2(-0.5f, -0.5f),
				glm::vec2(0.f, 0.f), 
				Color::WHITE},
		Vertex2D{glm::vec2(-0.5f, 0.5f),
				glm::vec2(0.f, 1.f),
				Color::WHITE},
		Vertex2D{glm::vec2(0.5f, -0.5f),
				glm::vec2(1.f, 0.f), 
				Color::WHITE},
		Vertex2D{glm::vec2(0.5f, 0.5f),
				glm::vec2(1.f, 1.f),
				Color::WHITE},
	};

	VertexBuffer2D buffer(4, vertex, GL_STATIC_DRAW);


	Shader shader(BasicVertexShader, BasicFragmentShader);

	Texture texture("C:\\Users\\joelf\\Pictures\\campfire_fire.png");

	shader.bind();
	texture.bind();
	int a = glGetUniformLocation(shader.GetShaderID(), "u_mvp");
	int b = glGetUniformLocation(shader.GetShaderID(), "u_useTexture");
	int c = glGetUniformLocation(shader.GetShaderID(), "u_sampler");

	glUniformMatrix4fv(a, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.f)));
	glUniformMatrix4fv(a, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.f)));
	glUniform1i(b, 1);
	glUniform1i(c, 0);
	
	

	SDL_Event event;
	while (ShouldLoop)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				ShouldLoop = false;
				break;
			}
		}
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		buffer.bind();
		shader.bind();
		texture.bind();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		texture.unbind();
		shader.unbind();
		buffer.unbind();

		SDL_GL_SwapWindow(m_Window);
	}

	SDL_GL_DestroyContext(m_GLContext);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}
