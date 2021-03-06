#include "./SceneManager.h"

static std::vector<Scene*> s_scenes;
static int s_currentScene = -1;

void SceneManager::init(GLFWwindow* window, bool installCallbacks) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	//ImGuiContext* context = ImGui::CreateContext();
	//ImGui::SetCurrentContext(context);

	ImGui::StyleColorsDark();
	ImGui_ImplOpenGL3_Init("#version 330 core");

	ImGui_ImplGlfw_InitForOpenGL(window, installCallbacks);
}

void SceneManager::start() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void SceneManager::renderMenu() {
	ImGui::Begin("Scene(s)");
	ImGui::RadioButton("Default", &s_currentScene, -1);
	for (size_t i = 0; i < s_scenes.size(); i++) {
		listScene(s_scenes[i], i);
	}
	ImGui::End();
}

void SceneManager::registerScene(Scene* scene) {
	if (scene) {
		s_scenes.push_back(scene);
	}
	else {
		std::cout << "ERROR: Cannot register null scene" << std::endl;
	}

}

void SceneManager::render(){
	ImGui::Render();
}

void SceneManager::finalize() {
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void SceneManager::listScene(Scene* scene, int sceneIndex) {
	if (!scene) {
		ImGui::RadioButton("Default", &s_currentScene, sceneIndex);
	}
	else {
		ImGui::RadioButton(scene->getSceneTitle().c_str(), &s_currentScene, sceneIndex);
	}

}

void SceneManager::updateCurrentScene(GWindow* window) {
	if (s_currentScene >= 0) {
		s_scenes[s_currentScene]->update(window);
	}

}

void SceneManager::renderCurrentSceneGUI() {
	if (s_currentScene >= 0) {
		s_scenes[s_currentScene]->renderGUI();
	}

}

void SceneManager::renderCurrentScene(GWindow* window) {
	if (s_currentScene >= 0) {
		s_scenes[s_currentScene]->render(window);
	}
}

void SceneManager::setCurrentScene(int sceneIndex) {
	s_currentScene = sceneIndex;
}

void SceneManager::destroy() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	s_scenes.clear();
}