#pragma once

using EvtWindowClosed = std::function<void(const sf::Event::Closed&)>;
using EvtKeyPressed = std::function<void(const sf::Event::KeyPressed&)>;


using EventHandler = std::variant<
	EvtWindowClosed,
	EvtKeyPressed>;

enum Events
{
	WINDOW_CLOSE,
	KEY_PRESSED
};

struct Visitor
{

	Visitor(std::unordered_map<Events, std::vector<EventHandler>>& map) : m_map(map) { }

	void operator()(const sf::Event::Closed& evt)
	{
		auto it = m_map.find(Events::WINDOW_CLOSE);

		if (it != m_map.end())
		{
			for (auto& item : it->second)
			{
				if (std::holds_alternative<EvtWindowClosed>(item))
				{
					std::get<EvtWindowClosed>(item)(evt);
				}
			}			
		}
	}
	void operator()(const sf::Event::KeyPressed& evt)
	{
		auto it = m_map.find(Events::KEY_PRESSED);

		if (it != m_map.end())
		{
			for (auto& item : it->second)
			{
				if(std::holds_alternative<EvtKeyPressed>(item))
				{
					std::get<EvtKeyPressed>(item)(evt);
				}
			}

		}
	}

	void operator()(const sf::Event& evt) {	}

	std::unordered_map<Events, std::vector<EventHandler>>& m_map;

};

class EventSystem
{
public:

	~EventSystem();
	EventSystem(const EventSystem&) = delete;
	EventSystem& operator=(const EventSystem&) = delete;

	inline static EventSystem& Get()
	{
		static EventSystem system;
		return system;
	}

	void UpdateEvents(const std::optional<sf::Event>& evt);

	template<typename HANDLER>
	void ListenEvent(Events evt, HANDLER handler);

private:
	EventSystem();
	void Notify();


private:
	//SFML events
	std::unordered_map<Events, std::vector<EventHandler>> m_umap_SFMLCommandDispatch;


	std::optional<sf::Event> m_Event;

};

template<typename HANDLER>
inline void EventSystem::ListenEvent(Events evt, HANDLER handler)
{
	auto it = m_umap_SFMLCommandDispatch.find(evt);
	
	if (it != m_umap_SFMLCommandDispatch.end())
	{
		it->second.push_back(handler);
	}
	else
	{
		m_umap_SFMLCommandDispatch[evt].push_back(handler);
	}
}
