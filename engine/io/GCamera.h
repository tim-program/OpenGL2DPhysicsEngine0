#pragma once

#include <iostream>

#include "../../Dependencies/glm/glm.hpp"
#include "../../Dependencies/glm/gtc/matrix_transform.hpp"

class GCamera{
private:
	glm::mat4 m_viewMatrix;
	glm::vec2 m_cameraPos;
	float m_zoom;

public:
	GCamera();
	GCamera(glm::vec2 pos);
	~GCamera();
	glm::mat4 getViewMatrix();
	void setCameraPos(float px, float py);
	void setCameraPos(glm::vec2 pos);
	void setCameraZoom(float zoom);
	void addCameraPosOffset(float px, float py);
	void addCameraZoomOffset(float zoom);
	glm::vec2 getCameraPos();
	float getCameraZoom();
};