cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(OpenGLPhysics0)

add_executable(
	Program
	MainTest.cpp
	./Dependencies/stb_image.cpp
	./Dependencies/imgui/imgui.cpp
	./Dependencies/imgui/imgui_impl_glfw.cpp
	./Dependencies/imgui/imgui_impl_opengl3.cpp
	./Dependencies/imgui/imgui_draw.cpp
	./Dependencies/imgui/imgui_demo.cpp
	./Dependencies/imgui/imgui_widgets.cpp
	./engine/collision/Bound.cpp
	./engine/collision/Collision.cpp
	./engine/collision/CollisionBatchResolver.cpp
	./engine/graphics/IBO.cpp
	./engine/graphics/Renderer.cpp
	./engine/graphics/Shader.cpp
	./engine/graphics/Texture.cpp
	./engine/graphics/VAO.cpp
	./engine/graphics/VBO.cpp
	./engine/io/GCamera.cpp
	./engine/io/GInput.cpp
	./engine/io/GWindow.cpp
	./engine/maths/EngineMath.cpp
	./engine/physics/forces/ForceGravity.cpp
	./engine/physics/forces/ForceSpring.cpp
	./engine/physics/forces/ForceAnchoredSpring.cpp
	./engine/physics/forces/ForceBungee.cpp
	./engine/physics/forces/ForceBuoyancy.cpp
	./engine/physics/forces/ForceFakeSpring.cpp
	./engine/physics/forces/ForceRegistry.cpp
	./engine/physics/Physics2D.cpp
	./engine/physics/Rigidbody2D.cpp
	./engine/scene/Scene.cpp
	./engine/scene/SceneManager.cpp
	./engine/Object.cpp
	./SceneCollisions.cpp
	./SceneBoundTest.cpp
	./SceneForces.cpp
	./SceneTest.cpp
	./SceneOBB.cpp
	./SceneQuadTreeDemo.cpp

	./experimental/QuadTree.cpp
)

target_include_directories(Program PRIVATE "C:\\Program Files\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\x86_64-w64-mingw32\\include")

target_link_libraries(Program
	glew32
	glfw3dll
	opengl32
)