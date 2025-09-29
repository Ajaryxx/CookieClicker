#include "PCH.hpp"
#include "core/Window.hpp"
#include "scenes/BaseScene.hpp"
#include "shapes/Object2D.hpp"
#include "shapes/RectangleShape.hpp"


Window::~Window()
{
	spdlog::info("Window Destroyed");
}
void Window::SetAllOpenGLWindowAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

#ifdef ENABLE_OPENGL_DEBUG
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
#endif // ENABLE_OPENGL_DEBUG

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

	glViewport(0, 0, 800, 600);

	return true;
}

void Window::Loop()
{
	BaseScene scene;
	auto& layer = scene.AddLayer("a", 0);
	auto& obj = layer->AddObject<RectangleShape>("SpirteTest");
	obj->SetSize({ 100.f, 100.f });
	obj->SetPosition({ 690.f, 500.f });

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
		for (const auto& item : scene.GetSceneLayers())
		{
			for (const auto& draw : item.second->GetLayerObjects())
			{
				draw->draw();
			}
			
		}
		

		
		SDL_GL_SwapWindow(m_Window);
	}

	SDL_GL_DestroyContext(m_GLContext);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}
