#pragma once

class Scene;
template<typename T>
concept SceneType = std::is_convertible_v<T*, Scene*>;
class SceneManager
{
	DECLARE_SINGLETON(SceneManager);
public:
	void Init();
	void Update(); 
	void Render(HDC hdc);
	void Release();
public:
	void LoadScene(const wstring& sceneName);
	Scene* GetCurScene() const {return m_curScene;}
private:
	template<SceneType T>
	void RegisterScene(const wstring& sceneName)
	{
		if (m_scenes.contains(sceneName))
			return;
		m_scenes[sceneName] = new T;
	}
private:
	Scene* m_curScene = nullptr;
	Scene* m_nextScene = nullptr;
	std::unordered_map<wstring, Scene*> m_scenes;
};

