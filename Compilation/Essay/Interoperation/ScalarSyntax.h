//********************************************************************************************************************//
//ORGANIZATION:
//AUTHOR:
//SUMMARY:
//********************************************************************************************************************//
#pragma once

#include "Dominion/Compilation/Essay/Interoperation/AbstractSyntaxTree.h"
#include "Dominion/Compilation/Essay/Interoperation/Scalar.h"

using namespace System;

BEGIN_DOMINION_COMPILATION_ESSAY
//****************************************************************************************************//
//ChainSyntax
//
//****************************************************************************************************//
public ref class ScalarSyntax : public AbstractSyntaxTree
{
public:
  ScalarSyntax();
  ~ScalarSyntax();
protected:
  !ScalarSyntax();

public:
  property Scalar^ Value
  {
    Scalar^ get();
    void set(Scalar^ value);
  }

private:
  Scalar^ _value;
};

END_DOMINION_COMPILATION_ESSAY
