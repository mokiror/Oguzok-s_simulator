#include "Stock.hpp"

void Stock::Input()
{
	sf::Event eventPlay; //переменная для событий

	//принимает нажатия с клавиатуры
	while (window->pollEvent(eventPlay))
	{
		//события, если решили закрыть окно
		if (eventPlay.key.code == sf::Keyboard::Escape) {
			window->close();
		}


		if (eventPlay.type == sf::Event::KeyPressed) {
			switch (eventPlay.key.code)
			{
			case sf::Keyboard::Right:oguz.Move('r'); break;
			case sf::Keyboard::Left:oguz.Move('l'); break;
			case sf::Keyboard::Up:oguz.Move('u'); break;
			case sf::Keyboard::Down:oguz.Move('d'); break;

			default:
			{
				break;
			}
			}
		}

		if (eventPlay.type == sf::Event::KeyReleased) {
			switch (eventPlay.key.code)
			{
			case sf::Keyboard::Right:oguz.SetStepX(0); break;
			case sf::Keyboard::Left:oguz.SetStepX(0); break;
			case sf::Keyboard::Up:oguz.SetStepY(0); break;
			case sf::Keyboard::Down:oguz.SetStepY(0); break;

			default:
			{
				break;
			}
			}
		}
	}
}

void Stock::UpdateIt(sf::Time const& time)
{
	oguz.Update(time);

	tm += time;

	if (tm > sf::milliseconds(3)) {
		auto myOguz = oguz.getPlayer();
		drop.move(0, 1);
		drop2.move(0, 1);
		drop3.move(0 , 1);
		drop4.move(0 , 1);
		drop5.move(0 , 1);
		drop6.move(0 , 1);

		if (drop.getPosition().y > window->getSize().y - drop.getGlobalBounds().height) {
			drop.setPosition(drop.getPosition().x, 0);
		}
		if (drop.getGlobalBounds().intersects(myOguz.getGlobalBounds()) && (!oguz.getDead())) {
			drop.setPosition(drop.getPosition().x, 0);
			oguz.ForDead(true);
		}

		if (drop2.getPosition().y > window->getSize().y - drop2.getGlobalBounds().height) {
			drop2.setPosition(drop2.getPosition().x, 0);
		}
		if (drop2.getGlobalBounds().intersects(myOguz.getGlobalBounds()) && (!oguz.getDead())) {
			drop2.setPosition(drop2.getPosition().x, 0);
			oguz.ForDead(true);
		}

		if (drop3.getPosition().y > window->getSize().y - drop3.getGlobalBounds().height) {
			drop3.setPosition(drop3.getPosition().x, 0);
		}
		if (drop3.getGlobalBounds().intersects(myOguz.getGlobalBounds()) && (!oguz.getDead())) {
			drop3.setPosition(drop3.getPosition().x, 0);
			oguz.ForDead(true);
		}

		if (drop4.getPosition().y > window->getSize().y - drop4.getGlobalBounds().height) {
			drop4.setPosition(drop4.getPosition().x, 0);
		}
		if (drop4.getGlobalBounds().intersects(myOguz.getGlobalBounds()) && (!oguz.getDead())) {
			drop4.setPosition(drop4.getPosition().x, 0);
			oguz.ForDead(true);
		}

		if (drop5.getPosition().y > window->getSize().y - drop5.getGlobalBounds().height) {
			drop5.setPosition(drop5.getPosition().x, 0);
		}
		if (drop5.getGlobalBounds().intersects(myOguz.getGlobalBounds()) && (!oguz.getDead())) {
			drop5.setPosition(drop5.getPosition().x, 0);
			oguz.ForDead(true);
		}

		if (drop6.getPosition().y > window->getSize().y - drop6.getGlobalBounds().height) {
			drop6.setPosition(drop6.getPosition().x, 0);
		}
		if (drop6.getGlobalBounds().intersects(myOguz.getGlobalBounds()) && (!oguz.getDead())) {
			drop6.setPosition(drop6.getPosition().x, 0);
			oguz.ForDead(true);
		}

		tm = sf::milliseconds(0);
	}
}

void Stock::Draw()
{
	//очищаем графическое окно
	window->clear();
	//отрисовываем фон игры
	window->draw(background);

	auto drawOguzok = oguz.getPlayer();
	window->draw(drawOguzok);
	window->draw(drop);
	window->draw(drop2);
	window->draw(drop3);
	window->draw(drop4);
	window->draw(drop5);
	window->draw(drop6);

	//выводим графические объекты
	window->display();

}

void Stock::Menu()
{
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1280, 720),
		L"\nOGUZOK's SIMULATOR\n", sf::Style::Fullscreen);
	sf::RectangleShape shefff = sf::RectangleShape(sf::Vector2f(1280, 720));
	shefff.setTexture(&Manager::GetTexture("C:/Users/ЛЕРА/Desktop/menuShef.png")); //ссылка для текстуры

	sf::Event eventPlay; //переменная для событий

	sf::Clock clock;

	while (window->isOpen())
	{

		window->clear();
		window->draw(shefff);
		window->display();

		//принимает нажатия с клавиатуры
		while (window->pollEvent(eventPlay))
		{
			//события, если решили закрыть окно
			if (eventPlay.key.code == sf::Keyboard::Q) {
				window->close();
			}
		}

		sf::Time timeNow = clock.restart();
	
	}

}


Stock::Stock()
{
	//чтоб картинка была
	background.setTexture(&Manager::GetTexture("C:/Users/ЛЕРА/Desktop/kitchengame.jpg")); //ссылка для текстуры
	
	drop.setTexture(&Manager::GetTexture("C:/Users/ЛЕРА/Desktop/salatt.png"));
	drop.setSize(sf::Vector2f(70, 70));
	drop.setPosition(600, 0);

	drop2.setTexture(&Manager::GetTexture("C:/Users/ЛЕРА/Desktop/tomat.png"));
	drop2.setSize(sf::Vector2f(70, 70));
	drop2.setPosition(370, 0);

	drop3.setTexture(&Manager::GetTexture("C:/Users/ЛЕРА/Desktop/tomat.png"));
	drop3.setSize(sf::Vector2f(70, 70));
	drop3.setPosition(900, 0);

	drop4.setTexture(&Manager::GetTexture("C:/Users/ЛЕРА/Desktop/salatt.png"));
	drop4.setSize(sf::Vector2f(70, 70));
	drop4.setPosition(1200, 0);

	drop5.setTexture(&Manager::GetTexture("C:/Users/ЛЕРА/Desktop/salatt.png"));
	drop5.setSize(sf::Vector2f(70, 70));
	drop5.setPosition(250, 0);

	drop6.setTexture(&Manager::GetTexture("C:/Users/ЛЕРА/Desktop/tomat.png"));
	drop6.setSize(sf::Vector2f(70, 70));
	drop6.setPosition(20, 0);
}

void Stock::Run()
{
	sf::Clock clock;

	sf::Music music;
	music.openFromFile("C:/Users/ЛЕРА/Desktop/mambo.mp3");
	music.play();
		
	Menu();

	while (window->isOpen())
	{
		sf::Time timeNow = clock.restart(); //тукцщее время

		
		Input();
		UpdateIt(timeNow);
		Draw();

		
	}

	
}
