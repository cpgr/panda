

#include "Permeability.h"

registerMooseObject("PandaApp", Permeability);

template<>
InputParameters validParams<Permeability>()
{
  InputParameters params = validParams<AuxKernel>();

  return params;
}

Permeability::Permeability(const InputParameters & parameters) :
    AuxKernel(parameters),

    _Re(getMaterialProperty<Real>("Re"))
{
}

Real
Permeability::computeValue()
{

  return 0.06*0.06*pow(0.39,3.0)/(160.0*0.61*0.61+3.0*pow(0.61,1.1)*pow(_Re[_qp],0.9));
}
