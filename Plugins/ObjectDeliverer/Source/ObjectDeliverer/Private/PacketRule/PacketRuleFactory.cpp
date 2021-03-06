// Copyright 2019 ayumax. All Rights Reserved.
#include "PacketRuleFactory.h"
#include "PacketRuleFixedLength.h"
#include "PacketRuleSizeBody.h"
#include "PacketRuleTerminate.h"
#include "PacketRuleNodivision.h"

UPacketRuleFixedLength* UPacketRuleFactory::CreatePacketRuleFixedLength(int32 FixedSize)
{
	auto PacketRule = NewObject<UPacketRuleFixedLength>();
	PacketRule->FixedSize = FixedSize;
	return PacketRule;
}

UPacketRuleSizeBody* UPacketRuleFactory::CreatePacketRuleSizeBody(int32 SizeLength, ECNBufferEndian SizeBufferEndian)
{
	auto PacketRule = NewObject<UPacketRuleSizeBody>();
	PacketRule->SizeLength = SizeLength;
	PacketRule->SizeBufferEndian = SizeBufferEndian;
	return PacketRule;
}

UPacketRuleTerminate* UPacketRuleFactory::CreatePacketRuleTerminate(const TArray<uint8>& Terminate)
{
	auto PacketRule = NewObject<UPacketRuleTerminate>();

	if (Terminate.Num() > 0)
	{
		PacketRule->Terminate = Terminate;
	}
	return PacketRule;
}

UPacketRuleNodivision* UPacketRuleFactory::CreatePacketRuleNodivision()
{
	return NewObject<UPacketRuleNodivision>();
}