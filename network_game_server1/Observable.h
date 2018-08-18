#pragma once

#include <set>
#include <vector>

template<class Observer>
class Observable
{
private:
	struct ObserverRequest {
		void (Observable<Observer>::*operation)(Observer*);
		Observer *observer;
	};
	std::set<Observer*> m_observers;
	int m_count;
	std::vector<ObserverRequest> m_requests;

public:
	
	virtual ~Observable() {
	}

	void subscribe(Observer* observer) {
		if (m_count != 0) {
			m_requests.push_back(ObserverRequest{ &Observable<Observer>::subscribe, observer });
		}
		else if (observer) {
			m_observers.insert(observer);
		}
	}

	void unsubscribe(Observer* observer) {
		if (m_count != 0) {
			m_requests.push_back(ObserverRequest{ &Observable<Observer>::unsubscribe,observer });
		}
		else if (observer) {
			m_observers.erase(observer);
		}
	}
protected:
	Observable():m_count(0){
	}

	template<typename F,typename... Args>
	void notifyObservers(F f, Args... args) {
	
		++m_count;
		for (Observer* o : m_observers) {
			(o->*f)(args...);
		}
		--m_count;

		if (m_count == 0) {
			for (const ObserverRequest& r : m_requests) {
				(this->*r.operation)(r.observer);
			}
			m_requests.clear();
		}
	}
};

