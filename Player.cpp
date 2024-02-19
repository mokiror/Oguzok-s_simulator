#include "Player.hpp"

void Player::SetStepX(float x)
{
	stepX = x;
}

void Player::SetStepY(float y)
{
	stepY = y;
}

void Player::Move(char diraction, float step)
{
	if (!dead) {
		switch (diraction)
		{
		case 'u': 
		{	 if (SpritePlayer.getPosition().y > koor.numY){
				stepY = -step;
			}
			break;
		}
		case 'd':
		{
			if (SpritePlayer.getPosition().y < koor.maxY) {
				stepY = step;
			}
			break;
		}
		case 'r':
		{
			if (SpritePlayer.getPosition().x < koor.maxX) {
				stepX = step;
			}
			if (AnimPlayer.GetNameOfAnimation() != "idleForward") {
				AnimPlayer.SwitchAnimation("idleForward");
			}
			break;
		}
		case 'l':
		{
			if (SpritePlayer.getPosition().x > koor.numX) {
				stepX = -step;
			}
			if (AnimPlayer.GetNameOfAnimation() != "idleBack") {
				AnimPlayer.SwitchAnimation("idleBack");
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}
	if (counter == 5) {

		std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1280, 720),
			L"\nOGUZOK's SIMULATOR\n", sf::Style::Fullscreen);
		sf::RectangleShape forTheENd = sf::RectangleShape(sf::Vector2f(1280, 720));
		forTheENd.setTexture(&Manager::GetTexture("C:/Users/ЛЕРА/Desktop/theend.jpg")); //ссылка для текстуры

		sf::Event eventPlay; //переменная для событий

		sf::Clock clock;

		while (window->isOpen())
		{

			//принимает нажатия с клавиатуры
			while (window->pollEvent(eventPlay))
			{
				//события, если решили закрыть окно
				if (eventPlay.key.code == sf::Keyboard::Escape) {
					window->close();
				}
			}

			window->clear();
			window->draw(forTheENd);
			window->display();

			sf::Time timeNow = clock.restart();
		}

		
		
	}
}

void Player::Update(sf::Time const& timmme)
{
	if (!dead) {
		AnimPlayer.Update(timmme);
	}

	timeUpdate += timmme;

	if (timeUpdate > sf::milliseconds(3)) {

		timeUpdate = sf::milliseconds(0);

		if (!dead) {
			SpritePlayer.move(stepX, stepY);

			if (SpritePlayer.getPosition().x < koor.numX) {
				SpritePlayer.setPosition(koor.numX, SpritePlayer.getPosition().y);
			}
			if (SpritePlayer.getPosition().x > koor.maxX- SpritePlayer.getGlobalBounds().width) {
				SpritePlayer.setPosition(koor.maxX - SpritePlayer.getGlobalBounds().width, SpritePlayer.getPosition().y);
			}
			if (SpritePlayer.getPosition().y < koor.numY) {
				SpritePlayer.setPosition(SpritePlayer.getPosition().x, koor.numY);
			}
			if (SpritePlayer.getPosition().y > koor.maxY - SpritePlayer.getGlobalBounds().height) {
				SpritePlayer.setPosition(SpritePlayer.getPosition().x, koor.maxY - SpritePlayer.getGlobalBounds().height);
			}
		}
		else {
			if (SpritePlayer.getRotation() == 0) {
				SpritePlayer.setPosition(SpritePlayer.getPosition().x + SpritePlayer.getGlobalBounds().height, SpritePlayer.getPosition().y);
				SpritePlayer.setRotation(90);
			}
			SpritePlayer.move(0, 1);
			if (SpritePlayer.getPosition().y > koor.maxY) {
				SpritePlayer.setRotation(0);
				SpritePlayer.setPosition(position.x, position.y);
				dead = false;
			}
		}
	}

}

void Player::SetKoordinatesPlayer(float x, float y, float maxx, float maxy)
{
	koor.numX = x;
	koor.numY = y;
	koor.maxX = maxx;
	koor.maxY = maxy;
}

