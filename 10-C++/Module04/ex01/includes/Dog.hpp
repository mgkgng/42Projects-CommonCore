#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	
	public:
		Dog(void);
		Dog(Dog const &);
		~Dog(void);
		
		Dog& operator=(Dog const &);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;

	private:
		Brain*	_brain;
};