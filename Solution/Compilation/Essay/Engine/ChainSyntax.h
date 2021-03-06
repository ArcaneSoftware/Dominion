//***********************************************************************************************************************************************************************************//
//ORGANIZATION:
//AUTHOR:
//SUMMARY:
//***********************************************************************************************************************************************************************************//
#pragma once

#include "Compilation/Essay/Engine/Elementary.h"

BEGIN_DOMINION_COMPILATION_ESSAY
//***********************************************************************************************************************************************************************************//
//CChainSyntax
//
//***********************************************************************************************************************************************************************************//
CLASS_DECLARATION(CChainSyntax, C_CHAIN_SYNTAX);
class LIBRARY_EXPORT CChainSyntax : public CReducibleSyntax
{
public:
  CLASS_INHERITOR(CReducibleSyntax, CChainSyntax);

  CChainSyntax();
  CChainSyntax(C_CHAIN_SYNTAX& that);
  CChainSyntax(C_CHAIN_SYNTAX&& that);
  CChainSyntax(int32_t liveLine, C_NAMESPACE& liveNamespace, int32_t currentID, int32_t nextID);
  virtual ~CChainSyntax();
  //{
  virtual vector<int32_t> Pick(IContextual<ESyntaxType, CReducibleSyntax>* context) const throw() override;
  //}
  CLASS_PROPERTY(int32_t, _currentID, CurrentID);
  CLASS_PROPERTY(int32_t, _nextID, NextID);

  C_CHAIN_SYNTAX& operator=(C_CHAIN_SYNTAX& that);
  C_CHAIN_SYNTAX& operator=(C_CHAIN_SYNTAX&& that);

private:
  int32_t _currentID;
  int32_t _nextID;
};

END_DOMINION_COMPILATION_ESSAY
