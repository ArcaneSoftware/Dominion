//*******************************************************************************************************************//
//ORGANIZATION:
//AUTHOR:
//SUMMARY:
//*******************************************************************************************************************//
#pragma once

#include "Dominion/Compilation/TransactSQL/Dependence.h"

BEGIN_DOMINION_COMPILATION_TRANSACTSQL
//*****************************************************************************************************************//
//EFlowType
//
//*****************************************************************************************************************//
enum class LIBRARY_EXPORT EFlowType
{
  If = 0,
  While
};
//*****************************************************************************************************************//
//CFlowTypeEnum
//
//*****************************************************************************************************************//
CLASS_DECLARATION(CFlowTypeEnum, C_FLOW_TYPE_ENUM);
class LIBRARY_EXPORT CFlowTypeEnum : public CEnum<EFlowType>
{
public:
  CLASS_INHERITOR(CEnum<EFlowType>, CFlowTypeEnum);

  static map<wstring, EFlowType> STRING_TO_VALUE();
  static map<EFlowType, wstring> VALUE_TO_STRING();

  CFlowTypeEnum();
  CFlowTypeEnum(C_FLOW_TYPE_ENUM& that);
  CFlowTypeEnum(C_FLOW_TYPE_ENUM&& that);
  explicit CFlowTypeEnum(EFlowType value);
  explicit CFlowTypeEnum(WSTRING& valueString);
  virtual ~CFlowTypeEnum();

  C_FLOW_TYPE_ENUM& operator=(C_FLOW_TYPE_ENUM& that);
};
//*****************************************************************************************************************//
//EOperationType
//
//*****************************************************************************************************************//
enum class LIBRARY_EXPORT EOperationType
{
  Empty = 0,
  Add,
  Subtract,
  Multiply,
  Divide,
  Modulo,

  Equal,
  NotEqual,
  Greater,
  GreaterEqual,
  NotGreater,
  Less,
  LessEqual,
  NotLessThan,

  And,
  Or,
  Xor,
  Not,
  Like,
  NotLike,
  Between,
  IsNull,
  IsNotNull
};
//*****************************************************************************************************************//
//COperationTypeEnum
//
//*****************************************************************************************************************//
CLASS_DECLARATION(COperationTypeEnum, C_OPERATION_TYPE_ENUM);
class LIBRARY_EXPORT COperationTypeEnum : public CEnum<EOperationType>
{
public:
  CLASS_INHERITOR(CEnum<EOperationType>, COperationTypeEnum);

  static map<wstring, EOperationType> STRING_TO_VALUE();
  static map<EOperationType, wstring> VALUE_TO_STRING();

  COperationTypeEnum();
  COperationTypeEnum(C_OPERATION_TYPE_ENUM& that);
  COperationTypeEnum(C_OPERATION_TYPE_ENUM&& that);
  explicit COperationTypeEnum(EOperationType value);
  explicit COperationTypeEnum(WSTRING& valueString);
  virtual ~COperationTypeEnum();

  C_OPERATION_TYPE_ENUM& operator=(C_OPERATION_TYPE_ENUM& that);
};
//*****************************************************************************************************************//
//EJoinType
//
//*****************************************************************************************************************//
enum class LIBRARY_EXPORT EJoinType
{
  JoinEntity = 0,
  LeftJoin,
  RightJoin
};
//*****************************************************************************************************************//
//CEJoinType
//
//*****************************************************************************************************************//
CLASS_DECLARATION(CEJoinType, CE_JOIN_TYPE);
class LIBRARY_EXPORT CEJoinType : public CEnum<EJoinType>
{
public:
  CLASS_INHERITOR(CEnum<EJoinType>, CEJoinType);

  static map<wstring, EJoinType> STRING_TO_VALUE();
  static map<EJoinType, wstring> VALUE_TO_STRING();

  CEJoinType();
  CEJoinType(CE_JOIN_TYPE& that);
  CEJoinType(CE_JOIN_TYPE&& that);
  explicit CEJoinType(EJoinType value);
  explicit CEJoinType(WSTRING& valueString);
  virtual ~CEJoinType();

  CE_JOIN_TYPE& operator=(CE_JOIN_TYPE& that);
};
//*****************************************************************************************************************//
//EOrderByType
//
//*****************************************************************************************************************//
enum class LIBRARY_EXPORT EOrderByType
{
  Asc = 0,
  Desc
};
//*****************************************************************************************************************//
//CEOrderByType
//
//*****************************************************************************************************************//
CLASS_DECLARATION(CEOrderByType, CE_ORDER_BY_TYPE);
class LIBRARY_EXPORT CEOrderByType : public CEnum<EOrderByType>
{
public:
  CLASS_INHERITOR(CEnum<EOrderByType>, CEOrderByType);

  static map<wstring, EOrderByType> STRING_TO_VALUE();
  static map<EOrderByType, wstring> VALUE_TO_STRING();

  CEOrderByType();
  CEOrderByType(CE_ORDER_BY_TYPE& that);
  CEOrderByType(CE_ORDER_BY_TYPE&& that);
  explicit CEOrderByType(EOrderByType value);
  explicit CEOrderByType(WSTRING& valueString);
  virtual ~CEOrderByType();

  CE_ORDER_BY_TYPE& operator=(CE_ORDER_BY_TYPE& that);
};

END_DOMINION_COMPILATION_TRANSACTSQL
