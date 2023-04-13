#pragma once
#include <string>
class GameEngine
{
public:
	GameEngine();
	virtual ~GameEngine();

	virtual void init();   //초기화 함수, 재정의 가능
	virtual void Load(std::string Filename);
	void Run();
	void Stop();

	inline class UWorld* GetWorld() const { return World; }

protected:
	void input();
	void Tick();
	void Render();

	bool bIsRunning = true;

	class UWorld* World;

};

