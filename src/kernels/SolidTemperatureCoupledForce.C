#include "SolidTemperatureCoupledForce.h"

registerMooseObject("PandaApp", SolidTemperatureCoupledForce);

template<>
InputParameters validParams<SolidTemperatureCoupledForce>()
{
  InputParameters params = validParams<Kernel>();

  params.addRequiredCoupledVar("v", "The coupled variable which provides the force");

  return params;
}

SolidTemperatureCoupledForce::SolidTemperatureCoupledForce(const InputParameters & parameters) :
    Kernel(parameters),

    _alpha(getMaterialProperty<Real>("alpha")),

    _v_var(coupled("v")),
    _v(coupledValue("v"))
{
}

Real
SolidTemperatureCoupledForce::computeQpResidual()
{
  return 1.0e-0*_alpha[_qp]* (_u[_qp]-_v[_qp])*_test[_i][_qp];
}

Real
SolidTemperatureCoupledForce::computeQpJacobian()
{
  return 1.0e-0*_alpha[_qp]* _phi[_j][_qp] *_test[_i][_qp];
}

Real
SolidTemperatureCoupledForce::computeQpOffDiagJacobian(unsigned int jvar)
{
  
  if (jvar == _v_var)
    return -1.0e-0*_alpha[_qp]*_phi[_j][_qp]*_test[_i][_qp];
  return 0.0;
}

