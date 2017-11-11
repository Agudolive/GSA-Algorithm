#ifndef SETUPPARAM_H
#define SETUPPARAM_H

#include <ostream>

class SetUpParams
{
	//ici vous devez mettre quelques parametres tels que :

private:
	unsigned int   _independent_runs;         //number of independent runs
	unsigned int   _nb_evolution_steps;       // number of iterations per run
	unsigned int   _population_size;		// number of solutions in the population
	unsigned int   _solution_size;	        // size of each particle

public:
	SetUpParams();
	~SetUpParams();

	//friend std::ostream& operator<< (std::ostream& os, const SetUpParams& setup);
	//friend std::istream& operator>> (std::istream& is, SetUpParams& setup);

	const unsigned int   independent_runs() const;
	const unsigned int   nb_evolution_steps() const;
	const unsigned int   population_size() const;
	const unsigned int   solution_size() const;

	void independent_runs(const unsigned int val);
	void nb_evolution_steps(const unsigned int val);
	void population_size(const unsigned int val);
	void solution_size(const unsigned int val);
};

#endif