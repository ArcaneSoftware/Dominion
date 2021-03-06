//********************************************************************************************************************//
//ORGANIZATION:
//AUTHOR:
//SUMMARY:
//********************************************************************************************************************//
#pragma once

#include "Dominion/Compilation/Syntax/NamedReference.h"

BEGIN_DOMINION_COMPILATION_SYNTAX
//****************************************************************************************************************//
//CVariable
//
//****************************************************************************************************************//
CLASS_DECLARATION(CVariable, C_VARIABLE);
class LIBRARY_EXPORT CVariable : public CNamedReference
{
public:
  CLASS_INHERITOR(CNamedReference, CVariable);

  CVariable();
  CVariable(C_VARIABLE& that);
  CVariable(C_VARIABLE&& that);
  CVariable(EAccessType access,
            C_IDENTIFIER& identifier,
            int32_t initialValueID = NONE_ID,
            int32_t realValueID = NONE_ID,
            bool isArgument = false);
  virtual ~CVariable();

  bool IsNilValue() const;
  int32_t GetSuitedValueIndex() const;

  CLASS_PROPERTY(int32_t, _initialValueID, InitialValueID);
  CLASS_PROPERTY(int32_t, _realValueID, RealValueID);
  CLASS_PROPERTY(bool, _isArgument, IsArgument);

  C_VARIABLE& operator=(C_VARIABLE& that);

private:
  int32_t _initialValueID;
  int32_t _realValueID;
  bool _isArgument;
};

END_DOMINION_COMPILATION_SYNTAX
