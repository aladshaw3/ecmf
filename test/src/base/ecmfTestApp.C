//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ecmfTestApp.h"
#include "ecmfApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
ecmfTestApp::validParams()
{
  InputParameters params = ecmfApp::validParams();
  return params;
}

ecmfTestApp::ecmfTestApp(InputParameters parameters) : MooseApp(parameters)
{
  ecmfTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

ecmfTestApp::~ecmfTestApp() {}

void
ecmfTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  ecmfApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"ecmfTestApp"});
    Registry::registerActionsTo(af, {"ecmfTestApp"});
  }
}

void
ecmfTestApp::registerApps()
{
  registerApp(ecmfApp);
  registerApp(ecmfTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ecmfTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ecmfTestApp::registerAll(f, af, s);
}
extern "C" void
ecmfTestApp__registerApps()
{
  ecmfTestApp::registerApps();
}
