
#ifndef FLUIDHEATSOURCECONSTANT_H
#define FLUIDHEATSOURCECONSTANT_H

#include "Kernel.h"

// Forward Declaration
class FluidHeatSourceConstant;

template<>
InputParameters validParams<FluidHeatSourceConstant>();

/**
 * Simple class to demonstrate off diagonal Jacobian contributions.
 */
class FluidHeatSourceConstant : public Kernel
{
public:
  FluidHeatSourceConstant(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;


  const  MaterialProperty<Real> & _alpha;

};

#endif //FLUIDHEATSOURCECONSTANT_H
