#pragma once
#include "stdafx.h"
#include "ExpressionEvaluator.h"

enum BreakpointType
{
	Global = 0,
	Execute = 1,
	ReadRam = 2,
	WriteRam = 3,
	ReadVram = 4,
	WriteVram = 5,
};

class Breakpoint
{
private:
	enum BreakpointTypeFlags
	{
		Global = 0,
		Execute = 1,
		ReadRam = 2,
		WriteRam = 4,
		ReadVram = 8,
		WriteVram = 16,
	};

public:
	Breakpoint();
	~Breakpoint();

	bool Matches(uint32_t memoryAddr, AddressTypeInfo &info);
	bool Matches(uint32_t memoryAddr, PpuAddressTypeInfo &info);
	bool HasBreakpointType(BreakpointType type);
	string GetCondition();
	bool HasCondition();
	void ClearCondition();
	
private:
	DebugMemoryType _memoryType;
	BreakpointTypeFlags _type;
	int32_t _startAddr;
	int32_t _endAddr;
	char _condition[1000];
};