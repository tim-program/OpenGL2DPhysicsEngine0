cmake_minimum_required(VERSION 3.13)

project(OpenGLPhysics0 C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
	./Dependencies/imgui/imgui_tables.cpp
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

target_include_directories(Program PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_directories(Program PRIVATE ${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(Program
	glew32
	glfw3dll
	opengl32
)

# Copy the runtime DLLs next to the built executable
add_custom_command(TARGET Program POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${CMAKE_SOURCE_DIR}/bin/glew32.dll
		${CMAKE_SOURCE_DIR}/bin/glfw3.dll
		$<TARGET_FILE_DIR:Program>
)
