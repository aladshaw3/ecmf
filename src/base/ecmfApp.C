#include "ecmfApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
ecmfApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

ecmfApp::ecmfApp(InputParameters parameters) : MooseApp(parameters)
{
  ecmfApp::registerAll(_factory, _action_factory, _syntax);
}

ecmfApp::~ecmfApp() {}

void
ecmfApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"ecmfApp"});
  Registry::registerActionsTo(af, {"ecmfApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
ecmfApp::registerApps()
{
  registerApp(ecmfApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ecmfApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ecmfApp::registerAll(f, af, s);
}
extern "C" void
ecmfApp__registerApps()
{
  ecmfApp::registerApps();
}
