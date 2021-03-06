#pragma once
#include "Types.h"
#include "EmulationSettings.h"

enum class DebuggerFlags
{
	None = 0x00,
	PpuPartialDraw = 0x01,
	PpuShowPreviousFrame = 0x02,

	ShowEffectiveAddresses = 0x04,
	DisplayOpCodesInLowerCase = 0x08,
	BreakOnBrk = 0x10,
	BreakOnUnofficialOpCode = 0x20,

	DisassembleVerifiedData = 0x40,
	DisassembleUnidentifiedData = 0x80,
	ShowVerifiedData = 0x100,
	ShowUnidentifiedData = 0x200,

	IgnoreRedundantWrites = 0x400,
};

enum class AddressType
{
	InternalRam = 0,
	PrgRom = 1,
	WorkRam = 2,
	SaveRam = 3,
	Register = 4
};

enum class PpuAddressType
{
	None = 0,
	ChrRom = 1,
	ChrRam = 2,
	PaletteRam = 3
};

struct AddressTypeInfo
{
	int32_t Address;
	AddressType Type;
};

struct PpuAddressTypeInfo
{
	int32_t Address;
	PpuAddressType Type;
};

enum class DebugMemoryType
{
	CpuMemory = 0,
	PpuMemory = 1,
	PaletteMemory = 2,
	SpriteMemory = 3,
	SecondarySpriteMemory = 4,
	PrgRom = 5,
	ChrRom = 6,
	ChrRam = 7,
	WorkRam = 8,
	SaveRam = 9,
	InternalRam = 10
};

enum class CdlHighlightType
{
	None = 0,
	HighlightUsed = 1,
	HighlightUnused = 2,
};

struct PPUDebugState
{
	PPUControlFlags ControlFlags;
	PPUStatusFlags StatusFlags;
	PPUState State;
	int32_t Scanline;
	uint32_t Cycle;
	uint32_t FrameCount;
};

struct DebugState
{
	State CPU;
	PPUDebugState PPU;
	CartridgeState Cartridge;
	ApuState APU;
	NesModel Model;
};

struct OperationInfo
{
	uint16_t Address;
	int16_t Value;
	MemoryOperationType OperationType;
};

struct PpuRegisterWriteInfo
{
	uint8_t Address;
	uint8_t Value;
	uint16_t Cycle;
	int16_t Scanline;
};

enum class EventType
{
	Reset = 0,
	Nmi = 1,
	Irq = 2,
	StartFrame = 3,
	EndFrame = 4,
	CodeBreak = 5,
	StateLoaded = 6,
	StateSaved = 7,
	InputPolled = 8,
	EventTypeSize
};