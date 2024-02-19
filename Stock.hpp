#pragma once

#include "Header.hpp"
#include "Manager.hpp"
#include "Animation.hpp"
#include "Player.hpp"

class Stock {
public:
	Stock(); //�����������

	void Run(); //������ ����

private:
	Manager manager;

	//����� ��������� �� ���� ���������
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1280, 720),
		L"\nOGUZOK's SIMULATOR\n", sf::Style::Fullscreen);

	//���
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1280, 720));
	//������
	Player oguz = Player(*window);


	sf::RectangleShape drop;
	sf::RectangleShape drop2;
	sf::RectangleShape drop3;
	sf::RectangleShape drop4;
	sf::RectangleShape drop5;
	sf::RectangleShape drop6;
	sf::Time tm;

	void Input();	//��������� �������

	void UpdateIt(sf::Time const& time); //��������� ����������

	void Draw(); //���������

	void Menu();

};

 