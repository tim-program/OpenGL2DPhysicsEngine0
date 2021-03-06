#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "./Dependencies/glm/glm.hpp"

#include "./engine/Object.h"
#include "./engine/collision/Bound.h"
#include "./engine/collision/Collision.h"
#include "./engine/collision/CollisionBatchResolver.h"
#include "./engine/graphics/Shader.h"
#include "./engine/graphics/Renderer.h"
#include "./engine/graphics/Texture.h"
#include "./engine/io/GWindow.h"
#include "./engine/io/GInput.h"
#include "./engine/physics/Physics2D.h"
#include "./engine/physics/forces/ForceGravity.h"
#include "./engine/scene/Scene.h"

class SceneForces : public Scene{
	private:
		float m_force;
		float m_gravityMultiplier;
		bool m_useGravity;
		Shader* m_shader;
		Texture* m_texture;
		Object* m_player;
		
	public:
		SceneForces();
		SceneForces(Shader* shader, Texture* texture);
		~SceneForces();

		void render(GWindow* window);
		void update(GWindow* window);
		void renderGUI();

	private:
		void input(GWindow* window);
		void runPhysics(float dt, GWindow* window = NULL);
};
