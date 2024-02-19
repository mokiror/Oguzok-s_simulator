#include "Manager.hpp"

//����������� �������� ����
Manager* Manager::staticInstance = nullptr;


Manager::Manager() {

		assert(staticInstance == nullptr );
	staticInstance = this; //����������� ��������� �� ��������
}

sf::Texture& Manager::GetTexture(std::string const& filename)
{
	//�������� ���� ����� ���������
	auto& texMap = staticInstance->mapTexture;
	auto pairFound = texMap.find(filename);

	if (pairFound != texMap.end()) { //���� �� �������
		return pairFound->second; //���� ��� ����� �������
	}
	else {
		//���� �� �������, �� ���� �� �����
		auto& texturre = texMap[filename];
		texturre.loadFromFile(filename);
		return texturre;
	}
}

sf::SoundBuffer& Manager::GetSoundBuffer(std::string const& filename) {

	auto& staticBufferMap = staticInstance->mapSoundBuffer;
	auto pairFound = staticBufferMap.find(filename);

	if (pairFound != staticBufferMap.end()) { 
		return pairFound->second;
	}
	else {

		auto& staticBuffer = staticBufferMap[filename];
		staticBuffer.loadFromFile(filename);
		return staticBuffer;
	}
}

sf::Font& Manager::GetFont(std::string const& filename) {

	auto& fontMap = staticInstance->mapFont;
	auto pairFound = fontMap.find(filename);

	if (pairFound != fontMap.end()) {
		return pairFound->second;
	}
	else {

		auto& fonttt = fontMap[filename];
		fonttt.loadFromFile(filename);
		return fonttt;
	}
}

