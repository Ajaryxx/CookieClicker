#pragma once

namespace CC
{
	struct BaseLayout
	{
		tgui::Layout2d position;
		tgui::Layout2d size;

		virtual void BuildLayout(tgui::Widget::Ptr widget) const = 0;

	};


	struct ButtonLayout : public BaseLayout
	{
		std::string text;
		bool UseBorder = false;

		sf::Texture UnfocusedTexture;
		sf::Texture HoverTexture;

		void BuildLayout(tgui::Widget::Ptr widget) const override
		{
			auto button = widget->cast<tgui::Button>();
			if (!button)
			{
				CCASSERT(!button, "Widget is not a button");
				return;
			}
			button->setText(text);
			button->setPosition(position);
			button->setSize(size);
			tgui::ButtonRenderer* renderer = button->getRenderer();

			/*renderer->setTexture(UnfocusedTexture);
			renderer->setTextureHover(HoverTexture);*/

			if (!UseBorder)
				renderer->setBorders(tgui::Borders(0, 0));
		}
	};
}
