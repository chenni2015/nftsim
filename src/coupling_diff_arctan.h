/** @file coupling_diff_arctan.h
  @brief A new Coupling class, where nu_ab follows a smooth function.

  The smooth variation of nu_ab is defined by the difference of
  two arctangent functions.


  @author Farah Deeba, Paula Sanz-Leon, Sahand Assadzadeh
*/

#ifndef COUPLING_DIFF_ARCTAN_H
#define COUPLING_DIFF_ARCTAN_H

// Other neurofield headers
#include "configf.h"    // Configf;
#include "coupling.h"   // Coupling
#include "propagator.h" // Propagator;
#include "population.h" // Population;

// C++ standard library headers
#include <vector> // std::vector;

class CouplingDiffArctan : public Coupling {
  CouplingDiffArctan();
  CouplingDiffArctan(CouplingDiffArctan&);
 protected:
  double nu_min = 0.0, nu_max = 0.0;
  double t_half_down = 0.0, t_half_up = 0.0;
  double delta = 0.0; ///< Time interval [s] in which the function will go from 0.25 to 0.75 of nu_max.
  double time_tot;
  double diff_atan = 0.0, diff_atan_min = 0.0,  diff_atan_max = 0.0;
  double time = 0.0;
  double time_int = 0.0;
  std::vector<double> deltanu;

 public:
  void init( Configf& configf );
  void step(void);
  void find(void);
  CouplingDiffArctan( size_type nodes, double deltat, size_type index,
                    const Propagator& prepropag, const Population& postpop, double tempf );
  virtual ~CouplingDiffArctan(void);
};

#endif //COUPLING_DIFF_ARCTAN_H

