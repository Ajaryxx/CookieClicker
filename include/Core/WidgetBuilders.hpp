#pragma once

namespace CC
{
	struct WidgetBuilder
	{
		sf::Vector2f position;
		sf::Vector2f size;

		void CheckAndBuildLayout(tgui::Widget::Ptr widget)
		{
			position.x = std::clamp(position.x, 0.f, 1.f);
			position.y = std::clamp(position.y, 0.f, 1.f);

			BuildLayout(widget);
		}

	private:
		virtual void BuildLayout(tgui::Widget::Ptr widget) {}

	};


	struct ButtonBuilder : public WidgetBuilder
	{
		std::string text;
		bool UseBorder = false;

		sf::Texture UnfocusedTexture;
		sf::Texture HoverTexture;

		void BuildLayout(tgui::Widget::Ptr widget) override
		{
			auto button = widget->cast<tgui::Button>();
			if (!button)
			{
				CCASSERT(!button, "Widget is not a button");
				return;
			}
			button->setText(text);
			button->setPosition(tgui::Layout2d(position));
			button->setSize(tgui::Layout2d(size));
			tgui::ButtonRenderer* renderer = button->getRenderer();

			/*renderer->setTexture(UnfocusedTexture);
			renderer->setTextureHover(HoverTexture);*/

			if (!UseBorder)
				renderer->setBorders(tgui::Borders(0, 0));
		}
	};
}
