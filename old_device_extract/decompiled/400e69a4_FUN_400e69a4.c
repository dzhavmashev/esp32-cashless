// Function : FUN_400e69a4
// Address  : 0x400e69a4
// Size     : 221 bytes


uint FUN_400e69a4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int aiStack_24 [9];
  
  FUN_400f0d70(param_1 + 0x38,&DAT_3f42161d);
  FUN_400ec7a4(param_1,"invalid certificates",1,") done\n");
  iVar7 = param_1 + 8;
  aiStack_24[0] = param_1;
  uVar1 = FUN_400e6788(aiStack_24,"vs_cert",iVar7);
  iVar6 = param_1 + 0x18;
  uVar2 = FUN_400e6788(aiStack_24,"ce_cert",iVar6);
  iVar5 = param_1 + 0x28;
  uVar3 = FUN_400e6788(aiStack_24,"ice_key",iVar5);
  FUN_400ec888(param_1);
  uVar4 = uVar3 & uVar1 & uVar2 & 0xff;
  if (uVar4 == 0) {
    FUN_400f0780(0x3ffc5490,"ca_cert");
    if (uVar1 == 0) {
      FUN_400f0780(0x3ffc5490,"storage");
    }
    if (uVar2 == 0) {
      FUN_400f0780(0x3ffc5490,"ificate");
    }
    if (uVar3 == 0) {
      FUN_400f0780(0x3ffc5490,"ice key");
    }
    FUN_400f0d70(iVar7,&DAT_3f42161d);
    FUN_400f0d70(iVar6,&DAT_3f42161d);
    FUN_400f0d70(iVar5,&DAT_3f42161d);
  }
  else {
    iVar7 = FUN_400da468(iVar7);
    if (((iVar7 == 0) && (iVar6 = FUN_400da468(iVar6), iVar6 == 0)) &&
       (iVar5 = FUN_400da468(iVar5), iVar5 == 0)) {
      FUN_400f0780(0x3ffc5490,"ificate");
    }
    else {
      FUN_400f0780(0x3ffc5490,"rom NVS");
      uVar4 = 0;
    }
  }
  return uVar4;
}

