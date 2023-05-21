#include "wrappers/sdl_context.h"
#include "wrappers/sdl_imgui.h"
#include "wrappers/sdl_imgui_context.h"

#include <glad/glad.h>
#include <cstdio>

int main(int argc, char *argv[])
{
    wrappers::SdlContext sdl_context("SDL Window",
                                     /*width=*/1920*0.75,
                                     /*height=*/1080*0.75);

		if (gladLoadGL() == 0) {
        printf("Failed to initialize OpenGL loader!\n");
        exit(-1);
    }

		wrappers::SdlImguiContext imgui_context(sdl_context.window_,
                                            sdl_context.gl_context_);
    bool quit_flag = false;
    while (!quit_flag) {
        quit_flag = wrappers::process_sdl_imgui_events(sdl_context.window_);
        if (quit_flag) {
            break;
        }

        wrappers::sdl_imgui_newframe(sdl_context.window_);

				ImGui::ShowDemoWindow();

        ImGui::Render(); // make drawlists

				// display drawlists to screen
        int display_w, display_h;
        SDL_GetWindowSize(sdl_context.window_, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(sdl_context.window_);
    }
    
    return 0;
}
