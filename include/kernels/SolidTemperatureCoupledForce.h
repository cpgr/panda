#ifndef SOLIDTEMPERATURECOUPLEDFORCE_H
#define SOLIDTEMPERATURECOUPLEDFORCE_H

#include "Kernel.h"

// Forward Declaration
class SolidTemperatureCoupledForce;

template<>
InputParameters validParams<SolidTemperatureCoupledForce>();

/**
 * Simple class to demonstrate off diagonal Jacobian contributions.
 */
class SolidTemperatureCoupledForce : public Kernel
{
public:
  SolidTemperatureCoupledForce(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

  const  MaterialProperty<Real> & _alpha;

  unsigned int _v_var;
  const VariableValue & _v;
};

#endif //SOLIDTEMPERATURECOUPLEDFORCE_H
