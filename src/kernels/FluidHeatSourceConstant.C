#include "FluidHeatSourceConstant.h"

registerMooseObject("PandaApp", FluidHeatSourceConstant);

template<>
InputParameters validParams<FluidHeatSourceConstant>()
{
  InputParameters params = validParams<Kernel>();


  return params;
}

FluidHeatSourceConstant::FluidHeatSourceConstant(const InputParameters & parameters) :
    Kernel(parameters),

    _alpha(getMaterialProperty<Real>("alpha"))
{
}

Real
FluidHeatSourceConstant::computeQpResidual()
{
  return _alpha[_qp]* (_u[_qp]-1000.0)*_test[_i][_qp];
//  return -_alpha[_qp]*_test[_i][_qp];
}

Real
FluidHeatSourceConstant::computeQpJacobian()
{
  return _alpha[_qp]* _phi[_j][_qp] *_test[_i][_qp];
//  return 0.0;
}



