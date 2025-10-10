#include "TextComponent.h"
#include "../GameObject.h"
#include "TextRenderer.h"

void TextComponent::setString(const std::string& str)
{
	text = str;
	updateRenderer();
}

void TextComponent::setFont(sf::Font* newFont)
{
	font = newFont;
	updateRenderer();
}

void TextComponent::setCharacterSize(unsigned int size)
{
	charSize = size;
	updateRenderer();
}

void TextComponent::setFillColor(const sf::Color& color)
{
	fillColor = color;
	updateRenderer();
}

void TextComponent::setStyle(sf::Text::Style style)
{
	textStyle = style;
	updateRenderer();
}

const std::string& TextComponent::getString() const
{
	return text;
}
sf::Font* TextComponent::getFont() const
{
	return font;
}
unsigned int TextComponent::getCharacterSize() const
{
	return charSize;
}
sf::Color TextComponent::getFillColor() const
{
	return fillColor;
}
sf::Text::Style TextComponent::getStyle() const
{
	return textStyle;
}

void TextComponent::updateRenderer()
{
	TextRenderer* renderer = game_object->getComponent<TextRenderer>();
	if (!renderer)
		return;

	sf::Text* renderText = renderer->getText();
	renderText->setString(text);
	if (font)
		renderText->setFont(*font);
	renderText->setCharacterSize(charSize);
	renderText->setFillColor(fillColor);
	renderText->setStyle(textStyle);
}