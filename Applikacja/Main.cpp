#include "Silnik/Application.h"
#include "AppLayer.h"
#include <iostream>
int main()
{
	Engine::Application Aplikacja = Engine::Application(800, 1280);
	Aplikacja.PushLayer<AppLayer>();
	Aplikacja.Start();
}