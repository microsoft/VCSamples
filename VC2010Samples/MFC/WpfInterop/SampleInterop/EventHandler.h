#pragma once

#include "ImportExport.h"
#include "ManagedObjectProxy.h"
#include <functional>

template <class T>
class CNativeEventHandler;

#ifdef __cplusplus_cli
template <class EventArgsProxy>
public ref class ManagedEventHandler
{
public:
	ManagedEventHandler(CNativeEventHandler<EventArgsProxy> *pNative)
		: m_pNative(pNative)
	{
	}

	void Detach()
	{
		m_pNative = NULL;
	}

	void OnEvent(System::Object^ sender, typename EventArgsProxy::ManagedClassType^ args)
	{
		if (m_pNative == NULL)
			throw gcnew System::ArgumentNullException("Native event handler was not attached or has already been detached");
		m_pNative->OnEvent(sender, args);
	}

private:
	CNativeEventHandler<EventArgsProxy> *m_pNative;
};
#endif

template <class EventArgsProxy>
class CManagedEventHandlerProxy : public CManagedObjectProxy
{
	DECLARE_MANAGED_PROXY(CManagedEventHandlerProxy, CManagedObjectProxy, ManagedEventHandler<EventArgsProxy>);

	CManagedEventHandlerProxy(CNativeEventHandler<EventArgsProxy> *pNative) MANAGED_ONLY_IMPL(
		: CManagedObjectProxy(gcnew ManagedEventHandler<EventArgsProxy>(pNative))
	{
	});

	void Detach() const MANAGED_ONLY_IMPL(
	{
		(*this)->Detach();
	});
};

template <class EventArgsProxy>
class CNativeEventHandler
{
public:
	typedef std::tr1::function<void (const CManagedObjectProxy &sender, const EventArgsProxy &args)> EventHandlerFunction;

	CNativeEventHandler() : m_managedEventHandler(this)
	{
	}

	~CNativeEventHandler()
	{
		if (!m_managedEventHandler.IsNull())
			m_managedEventHandler.Detach();
	}

	void SetEventHandler(const EventHandlerFunction &eventHandler)
	{
		m_eventHandler = eventHandler;
	}

	template <class EventHandlerClass>
	void SetEventHandler(EventHandlerClass *pClass, void (EventHandlerClass::*pClassMember)(const CManagedObjectProxy &sender, const EventArgsProxy &args))
	{
		using namespace std::tr1;
		SetEventHandler(bind(mem_fn(pClassMember), pClass, placeholders::_1, placeholders::_2));
	}

	void OnEvent(const CManagedObjectProxy &sender, const EventArgsProxy &args) const
	{
		if (m_eventHandler)
			m_eventHandler(sender, args);
	}

	CManagedEventHandlerProxy<EventArgsProxy> ManagedEventHandler() const
	{
		return m_managedEventHandler;
	}

private:
	CManagedEventHandlerProxy<EventArgsProxy> m_managedEventHandler;
	EventHandlerFunction m_eventHandler;
};
