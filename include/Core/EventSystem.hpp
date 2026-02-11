#pragma once
#include "BaseValues.hpp"
#include "Utilities.hpp"

namespace CC
{

	using EvtWindowClosed = std::function<void(const sf::Event::Closed&)>;
	using EvtKeyPressed = std::function<void(const sf::Event::KeyPressed&)>;


	using EventHandler = std::variant<
		EvtWindowClosed,
		EvtKeyPressed>;

	enum EventType
	{
		WINDOW_CLOSE,
		KEY_PRESSED
	};

	struct Visitor
	{

		Visitor(std::unordered_map<EventType, std::vector<EventHandleID>>& EventHandleIDMap,
			std::unordered_map<EventHandleID, EventHandler>& EventHandlerMap) : m_mapping(EventHandleIDMap), m_umap_SFMLCommandDispatch(EventHandlerMap) {}

		void operator()(const sf::Event::Closed& evt)
		{
			FireEvent<EvtWindowClosed>(EventType::WINDOW_CLOSE, evt);
		}
		void operator()(const sf::Event::KeyPressed& evt)
		{
			FireEvent<EvtKeyPressed>(EventType::KEY_PRESSED, evt);
		}

		void operator()(const sf::Event& evt) {}


		template<typename T, typename SF_EVT> 
		void FireEvent(EventType type, const SF_EVT& evt)
		{
			auto itMappping = m_mapping.find(type);

			if (itMappping != m_mapping.end())
			{
				for (const auto& item : itMappping->second)
				{
					auto itEventHandler = m_umap_SFMLCommandDispatch.find(item);

					if (itEventHandler != m_umap_SFMLCommandDispatch.end())
					{
						if (T* func = std::get_if<T>(&itEventHandler->second))
						{
							(*func)(evt);
						}
					}
				}
			}
		}

		std::unordered_map<EventType, std::vector<EventHandleID>> m_mapping;
		std::unordered_map<EventHandleID, EventHandler> m_umap_SFMLCommandDispatch;

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


		template<typename FUNC>
		[[nodiscard]] void Subscribe(EventType evt, EventHandleID& handleID, FUNC handler);

		void Unsubscribe(EventHandleID& handle);
	private:
		EventSystem();
		void Notify();

		bool ValidHandle(EventType evt, EventHandleID& handleID);

	private:
		//SFML events
		std::unordered_map<EventType, std::vector<EventHandleID>> m_mapping;
		std::unordered_map<EventHandleID, EventHandler> m_umap_SFMLCommandDispatch;


		std::optional<sf::Event> m_Event;

	};

	template<typename FUNC>
	inline void EventSystem::Subscribe(EventType evt, EventHandleID& handleID, FUNC handler)
	{
		do
		{
			handleID = Utility::GenRandomInt32(0, INT32_MAX);
		} while (!ValidHandle(evt, handleID));

		m_mapping[evt].push_back(handleID);
		m_umap_SFMLCommandDispatch[handleID] = handler;
	}

}
