// Function : FUN_400d7464
// Address  : 0x400d7464
// Size     : 150 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d7464(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int aiStack_44 [2];
  code *pcStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_34 [8];
  code *pcStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"nfirmed");
  uVar1 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  FUN_400d37b0(*(undefined4 *)(param_1 + 0x10));
  FUN_400d39ec(*(undefined4 *)(param_1 + 0x10));
  uStack_38 = 0x400d8444;
  pcStack_3c = FUN_40183d4c;
  iVar2 = *(int *)(param_1 + 0x10);
  pcStack_2c = (code *)0x0;
  aiStack_44[0] = param_1;
  FUN_40183d4c(auStack_34,aiStack_44,2);
  uStack_28 = uStack_38;
  pcStack_2c = pcStack_3c;
  FUN_400d73b8(auStack_34,iVar2 + 0x50);
  uVar1 = *(undefined4 *)(iVar2 + 0x58);
  *(code **)(iVar2 + 0x58) = pcStack_2c;
  uVar3 = *(undefined4 *)(iVar2 + 0x5c);
  *(undefined4 *)(iVar2 + 0x5c) = uStack_28;
  pcStack_2c = (code *)uVar1;
  uStack_28 = uVar3;
  (*(code *)&LAB_40183a17_1)(auStack_34);
  (*(code *)&LAB_40183a17_1)(aiStack_44);
  FUN_400e7730(*(undefined4 *)(param_1 + 0x18),2);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

