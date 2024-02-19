#include "Animation.hpp"

Animation::Animation(sf::Sprite& sprite): forCurrentAnim(nullptr),
forSprite(sprite)
{}

//создание анимации
Animation::ForAnimation& Animation::CreateAnimation(std::string const& name,
	std::string const& textureName, sf::Time const& duration, bool loop)
{
	forAnim.emplace_back(name, textureName, duration, loop);

	//если это первая анимация, то она становится текущей
	if (forCurrentAnim == nullptr) SwitchAnimation(&forAnim.back());

	//возвращает ссылку на анимацию
	return forAnim.back();
}

void Animation::Update(sf::Time const& data)
{
	if (forCurrentAnim == nullptr) {
		return;
	}

	forCurrentTime += data;

	float scaledTime = (forCurrentTime.asSeconds() / forCurrentAnim->forDuration.asSeconds());
	auto numFrames = static_cast<int>(forCurrentAnim->forFrames.size());
	//новый кадр
	auto currentFrame = static_cast<int>(scaledTime * numFrames);

	//зацикливание кадров
	if (forCurrentAnim->forLooping) {
		currentFrame %= numFrames;
	}
	else
	{
		if (currentFrame >= numFrames) {
			currentFrame = numFrames - 1;
			endOfAnimation = true;
		}
	}

}

Animation::ForAnimation* Animation::FindAnimation(std::string const& name)
{
	//поиск анимации
	for (auto i = forAnim.begin(); i != forAnim.end(); i++)
	{
		if (i->forName == name) {
			return &*i;
		}
	}

	return nullptr;
}

void Animation::SwitchAnimation(Animation::ForAnimation* animationnn)
{
	//изменение спрайта
	if (animationnn != nullptr) {
		forSprite.setTexture(Manager::GetTexture(animationnn->forTextureName));
	}

	forCurrentAnim = animationnn; 
	forCurrentTime = sf::Time::Zero; //сброс времени
}

bool Animation::SwitchAnimation(std::string const& name)
{
	auto animation = FindAnimation(name); //пытается найти по имени анимацию
	if (animation != nullptr) {
		SwitchAnimation(animation);
		return true;
	}
	return false;
}

std::string Animation::GetNameOfAnimation() const
{
	//возвращает имя текущей анимации
	if (forCurrentAnim != nullptr) {
		return forCurrentAnim->forName;
	 }
	return "";
}

//рервать анимацию
void Animation::restart()
{
	forCurrentTime = sf::Time::Zero;
	endOfAnimation = false;
}




