
#ifndef SPHERETFFUNCTION_H
#define SPHERETFFUNCTION_H

#include "Function.h"

class SphereTfFunction;

template<>
InputParameters validParams<SphereTfFunction>();

class SphereTfFunction : public Function
{
public:
  SphereTfFunction(const InputParameters & parameters);

  virtual Real value(Real t,const Point & p) override;

};

#endif //SPHERETFFUNCTION_H
