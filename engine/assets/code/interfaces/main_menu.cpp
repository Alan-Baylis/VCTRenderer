#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "main_menu.h"
#include "../../../rendering/voxelizer_renderer.h"

bool UIMainMenu::drawSceneLoader = true;
bool UIMainMenu::drawFramerate = false;
bool UIMainMenu::drawSceneCameras = false;
bool UIMainMenu::drawSceneLights = false;
bool UIMainMenu::drawGeometryBuffer = false;

using namespace ImGui;

void UIMainMenu::Draw()
{
    if (BeginMainMenuBar())
    {
        if (BeginMenu("View"))
        {
            MenuItem("Show Framerate", nullptr, &drawFramerate);
            MenuItem("View Voxels", nullptr, &VoxelizerRenderer::ShowVoxels);
            MenuItem("View Geometry Buffer", nullptr, &drawGeometryBuffer);
            EndMenu();
        }

        if (BeginMenu("Scene"))
        {
            MenuItem("Cameras", nullptr, &drawSceneCameras);
            MenuItem("Lights", nullptr, &drawSceneLights);
            EndMenu();
        }

        if (BeginMenu("Window"))
        {
            MenuItem("Scene Loader", nullptr, &drawSceneLoader);
            EndMenu();
        }

        EndMainMenuBar();
    }
}

UIMainMenu::UIMainMenu()
{
}

UIMainMenu::~UIMainMenu()
{
}