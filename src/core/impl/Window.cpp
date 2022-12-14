#include "../include/Window.h"

Window::Window(const uint32_t& windowWidth, const uint32_t& windowHeight, const char* windowTitle)
{
    WindowProps windowProperties;

    windowProperties.WindowWidth = windowWidth;
    windowProperties.WindowHeight = windowHeight;
    windowProperties.WindowTitle = windowTitle;

    InitWindow(windowProperties);
}

Window::Window()
{
    InitWindow();
    MakeWindowContextCurrent();
}

int Window::InitWindow(const WindowProps& windowProperties)
{
    m_WindowData.WindowWidth = windowProperties.WindowWidth;
    m_WindowData.WindowHeight = windowProperties.WindowHeight;
    m_WindowData.WindowTitle = windowProperties.WindowTitle;

    if (!glfwInit())
        return -1;

    m_Window = glfwCreateWindow(windowProperties.WindowWidth, windowProperties.WindowHeight,
                                windowProperties.WindowTitle, nullptr, nullptr);

    if (!m_Window)
    {
        glfwTerminate();
        return -1;
    }

    return 0;
}

void Window::MakeWindowContextCurrent()
{
    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, this);

    // these are only related to event stuff. No way they touch the other callbacks.
    // Report if they do so!!!
    m_Event.SetCallbacks(m_Window);

    if (glewInit() != GLEW_OK)
        std::cout << "glewInit error!" << std::endl;

    m_Log.Info("Started Game Successfully!");

}

void Window::DestroyWindow()
{
    glfwTerminate();
}

Window::~Window()
{
    DestroyWindow();
}