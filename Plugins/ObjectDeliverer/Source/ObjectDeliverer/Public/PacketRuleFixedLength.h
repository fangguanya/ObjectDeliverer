#pragma once

#include "CoreMinimal.h"
#include "PacketRule.h"
#include "PacketRuleFixedLength.generated.h"


UCLASS(BlueprintType, Blueprintable)
class OBJECTDELIVERER_API UPacketRuleFixedLength : public UPacketRule
{
	GENERATED_BODY()

public:
	UPacketRuleFixedLength();
	~UPacketRuleFixedLength();

	virtual void Initialize_Implementation() override;
	virtual void MakeSendPacket_Implementation(const TArray<uint8>& BodyBuffer) override;
	virtual void NotifyReceiveData_Implementation(const TArray<uint8>& DataBuffer) override;
	virtual int32 GetWantSize_Implementation() override;
	virtual UPacketRule* Clone_Implementation() override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ObjectDeliverer|PacketRule")
	int32 FixedSize = 128;

private:
	TArray<uint8> BufferForSend;
};
