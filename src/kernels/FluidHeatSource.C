#include "FluidHeatSource.h"

registerMooseObject("PandaApp", FluidHeatSource);

template<>
InputParameters validParams<FluidHeatSource>()
{
  InputParameters params = validParams<Kernel>();

  params.addRequiredCoupledVar("v", "The coupled variable which provides the force");

  return params;
}

FluidHeatSource::FluidHeatSource(const InputParameters & parameters) :
    Kernel(parameters),

    _alpha(getMaterialProperty<Real>("alpha")),

    _v_var(coupled("v")),
    _v(coupledValue("v"))
{
}

Real
FluidHeatSource::computeQpResidual()
{
  return _alpha[_qp]* (_u[_qp]-_v[_qp])*_test[_i][_qp];
//  return -_alpha[_qp]*_test[_i][_qp];
}

Real
FluidHeatSource::computeQpJacobian()
{
  return _alpha[_qp]* _phi[_j][_qp] *_test[_i][_qp];
//  return 0.0;
}

Real
FluidHeatSource::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _v_var)
    return -_alpha[_qp]*_phi[_j][_qp]*_test[_i][_qp];
  return 0.0;
}

