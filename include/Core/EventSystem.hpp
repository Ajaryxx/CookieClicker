#pragma once
#include "BaseValues.hpp"
#include "Utilities.hpp"

namespace CC
{
	using EvtCustomEvent = std::function<void()>;
	using EvtWindowClosed = std::function<void(const sf::Event::Closed&)>;
	using EvtKeyPressed = std::function<void(const sf::Event::KeyPressed&)>;


	using EventHandler = std::variant<
		EvtCustomEvent,
		EvtWindowClosed,
		EvtKeyPressed>;

	enum EventType : uint8
	{
		WINDOW_CLOSE,
		KEY_PRESSED
	};


	struct CustomEvent
	{
		std::string CustomEventName;
		EventHandleID handleID;
	};

	struct Visitor
	{

		Visitor(std::unordered_map<std::variant<EventType, std::string>, std::vector<EventHandleID>>& EventHandleIDMap,
			std::unordered_map<EventHandleID, EventHandler>& EventHandlerMap) : m_mapEventHandleIDMap(EventHandleIDMap), m_umap_EventDispatch(EventHandlerMap) {}

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
			auto itMappping = m_mapEventHandleIDMap.find(type);
			
			if (itMappping != m_mapEventHandleIDMap.end())
			{
				for (const auto& item : itMappping->second)
				{
					auto itEventHandler = m_umap_EventDispatch.find(item);
					
					if (itEventHandler != m_umap_EventDispatch.end())
					{
						if (T* func = std::get_if<T>(&itEventHandler->second))
						{
							(*func)(evt);
						}
					}
				}
			}
		}

		std::unordered_map<std::variant<EventType, std::string>, std::vector<EventHandleID>> m_mapEventHandleIDMap;
		std::unordered_map<EventHandleID, EventHandler> m_umap_EventDispatch;

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

		inline std::optional<sf::Event> GetEvent() const { return m_Event; }
		void UpdateEvents(const std::optional<sf::Event>& evt);
		//Subscribe to an SFML Event
		template<typename FUNC>
		bool Subscribe(EventType evt, EventHandleID& handleID, FUNC handler);
		//Subscribe to a custom event
		template<typename FUNC>
		bool Subscribe(const std::string& eventName, EventHandleID& handlerID, FUNC handler);
		//Create a custom event
		bool CreateCustomEvent(const std::string& eventName);
		//Unsubscribe an event(SFML and custom)
		void Unsubscribe(EventHandleID& handleID);
		//Notifys all the functions that are bound to this event
		void CustomNotify(const std::string& evtName);
		//Deletes a custom event and all its handlers
		//NOTE: This wont reset the handlerIDS of the handlers that were bound to this event. You will have to manually reset those handlerIDs or you can reuse the handlers
		bool DeleteCustomEvent(const std::string& evtName);
	private:
		EventSystem();
		//Notifys SFML events
		void Notify();
		bool IsValidEventID(EventHandleID handleID) const;
		bool IsCustomEventNameValid(const std::string& name) const;
		EventHandleID GenerateValidHandlerID() const;

	private:
		
		std::unordered_map<std::variant<EventType, std::string>, std::vector<EventHandleID>> m_umap_Mapping;
		std::unordered_map<EventHandleID, EventHandler> m_umap_EventDispatch;

		std::optional<sf::Event> m_Event;

	};

	template<typename FUNC>
	inline bool EventSystem::Subscribe(EventType evt, EventHandleID& handleID, FUNC handler)
	{
		if (!IsValidEventID(handleID))
		{
			CCLOG("You are trying to override an existing handle! HandleID: {}; EventType: {}", handleID, (uint8)evt);
			handleID = -1;
			return false;
		}
		
		handleID = GenerateValidHandlerID();
		//link handlerID with event and function
		m_umap_Mapping[evt].push_back(handleID);
		m_umap_EventDispatch[handleID] = handler;

		CCLOG("Event subscribed. Handle was bound to: {}", handleID);

		return true;
	}

	template<typename FUNC>
	inline bool EventSystem::Subscribe(const std::string& eventName, EventHandleID& handlerID, FUNC handler)
	{
		if (!IsCustomEventNameValid(eventName) || !IsValidEventID(handlerID))
		{
			CCLOG("Couldnt find event with name: {} OR you were trying to override the handlerID: {}", eventName, handlerID);
			handlerID = -1;
			return false;
		}
		handlerID = GenerateValidHandlerID();
		auto it = m_umap_Mapping.find(eventName);

		//link handlerID with event and function
		it->second.push_back(handlerID);
		m_umap_EventDispatch[handlerID] = std::function<void()>(handler);

		CCLOG("Subscribed to custom event: {}; HandleID: {}", eventName, handlerID);

		return true;
	}

}