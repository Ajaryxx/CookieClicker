#pragma once

struct BaseLayout
{
	tgui::Layout2d position;
	tgui::Layout2d size;

	virtual void BuildLayout(tgui::Widget::Ptr widget) const = 0;
	
};


struct ButtonLayout : public BaseLayout
{
	std::string text;
	bool border = false;

	sf::Texture UnfocusedTexture;
	sf::Texture HoverTexture;

	void BuildLayout(tgui::Widget::Ptr widget) const override
	{
		auto button = widget->cast<tgui::Button>();
		if (!button)
			return;
		button->setText(text);
		button->setPosition(position);
		button->setSize(size);
		tgui::ButtonRenderer* renderer = button->getRenderer();
		renderer->setTexture(UnfocusedTexture);
		renderer->setTextureHover(HoverTexture);
		if (!border)
			renderer->setBorders(tgui::Borders(0, 0));
	}
};


