#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell*> spells;
		Warlock(void);
		Warlock &operator=(const Warlock &src);
		Warlock(const Warlock &src);
	public:
		const std::string &getName(void) const;
		const std::string &getTitle(void) const;
		void setTitle(const std::string &newTitle);
		Warlock(const std::string& name, const std::string& title);
		void introduce(void) const;
		~Warlock(void);
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget& target);
};

#endif
