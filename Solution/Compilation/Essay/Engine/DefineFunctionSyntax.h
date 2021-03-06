//***********************************************************************************************************************************************************************************//
//ORGANIZATION:
//AUTHOR:
//SUMMARY:
//***********************************************************************************************************************************************************************************//
#pragma once

#include "Compilation/Essay/Engine/Elementary.h"

BEGIN_DOMINION_COMPILATION_ESSAY
//***********************************************************************************************************************************************************************************//
//CDefineVariableSyntax
//
//***********************************************************************************************************************************************************************************//
CLASS_DECLARATION(CDefineFunctionSyntax, C_DEFINE_FUNCTION_SYNTAX);
class LIBRARY_EXPORT CDefineFunctionSyntax : public CReducibleSyntax
{
public:
  CLASS_INHERITOR(CReducibleSyntax, CDefineFunctionSyntax);

  CDefineFunctionSyntax();
  CDefineFunctionSyntax(C_DEFINE_FUNCTION_SYNTAX& that);
  CDefineFunctionSyntax(C_DEFINE_FUNCTION_SYNTAX&& that);
  CDefineFunctionSyntax(int32_t liveLine, C_NAMESPACE& liveNamespace, EAccessType accessType, WSTRING& name, int32_t parameterChainID, int32_t blockID);
  virtual ~CDefineFunctionSyntax();
  //{
  virtual CIdentifier GetIdentifier() const override;
  virtual CScalar Reduce(IContextual<ESyntaxType, CReducibleSyntax>& context) const throw() override;
  //}
  CLASS_PROPERTY(EAccessType, _accessType, AccessType);
  CLASS_PROPERTY(wstring, _name, Name);
  CLASS_PROPERTY(int32_t, _parameterChainID, ParameterChainID);
  CLASS_PROPERTY(int32_t, _blockID, BlockID);

  C_DEFINE_FUNCTION_SYNTAX& operator=(C_DEFINE_FUNCTION_SYNTAX& that);
  C_DEFINE_FUNCTION_SYNTAX& operator=(C_DEFINE_FUNCTION_SYNTAX&& that);

private:
  EAccessType _accessType;
  wstring _name;
  int32_t _parameterChainID;
  int32_t _blockID;
};

END_DOMINION_COMPILATION_ESSAY
