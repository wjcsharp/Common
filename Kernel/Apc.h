/**
 * @file Apc.h
 * @author created by: Peter Hlavaty
 */

#ifndef __APC_H__
#define __APC_H__

#include "../base/Common.h"

class CDisableKernelApc
{
public:
	_IRQL_requires_max_(APC_LEVEL)
	CDisableKernelApc()
	{
		KeEnterGuardedRegion();
	}
	_IRQL_requires_max_(APC_LEVEL)
	~CDisableKernelApc()
	{
		KeLeaveGuardedRegion();
	}
};

class CDisableSpecialApc
{
public:
	_IRQL_requires_max_(APC_LEVEL)
	CDisableSpecialApc()
	{
		KeEnterCriticalRegion();
	}
	_IRQL_requires_max_(APC_LEVEL)
	~CDisableSpecialApc()
	{
		KeLeaveCriticalRegion();
	}
};

class CDisableApc :
	private CDisableSpecialApc,
	private CDisableKernelApc
{
public:
	_IRQL_requires_max_(APC_LEVEL)
	CDisableApc() :
		CDisableKernelApc(),
		CDisableSpecialApc()
	{
	}
};

#endif //__APC_H__
