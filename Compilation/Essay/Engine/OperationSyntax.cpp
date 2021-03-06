//*******************************************************************************************************************//
//ORGANIZATION:
//AUTHOR:
//SUMMARY:
//*******************************************************************************************************************//
#include "OperationSyntax.h"

using namespace Dominion::Compilation::Essay;
//*******************************************************************************************************************//
//COperationSyntax
//*******************************************************************************************************************//
COperationSyntax::COperationSyntax() :
  CAbstractSyntaxTree<ESyntaxType>(ESyntaxType::Operation)
{
}
COperationSyntax::COperationSyntax(C_OPERATION_SYNTAX& that) :
  CAbstractSyntaxTree<ESyntaxType>(that),
  _operationType(that._operationType),
  _leftOperandID(that._leftOperandID),
  _rightOperandID(that._rightOperandID)
{
}

COperationSyntax::COperationSyntax(C_OPERATION_SYNTAX&& that) :
  CAbstractSyntaxTree<ESyntaxType>(that),
  _operationType(move(that._operationType)),
  _leftOperandID(move(that._leftOperandID)),
  _rightOperandID(move(that._rightOperandID))
{
}

COperationSyntax::COperationSyntax(int32_t liveLine,
                                   C_NAMESPACE& liveNamespace,
                                   int32_t leftOperandID,
                                   EOperationType operationType,
                                   int32_t rightOperandID) :
  CAbstractSyntaxTree<ESyntaxType>(ESyntaxType::Operation, liveLine, liveNamespace),
  _operationType(operationType),
  _leftOperandID(leftOperandID),
  _rightOperandID(rightOperandID)
{
}

COperationSyntax::~COperationSyntax()
{
}

C_OPERATION_SYNTAX& COperationSyntax::operator=(C_OPERATION_SYNTAX& that)
{
  CAbstractSyntaxTree<ESyntaxType>::operator=(that);

  _operationType = that._operationType;
  _leftOperandID = that._leftOperandID;
  _rightOperandID = that._rightOperandID;

  return *this;
}
