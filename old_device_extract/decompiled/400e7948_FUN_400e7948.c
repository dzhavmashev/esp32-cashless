// Function : FUN_400e7948
// Address  : 0x400e7948
// Size     : 154 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400e7948(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int aiStack_24 [9];
  
  if (param_1 != 0) {
    aiStack_24[0] = func_0x40094d68(0x90);
    if (aiStack_24[0] == 0) {
      uVar6 = func_0x40085c04();
      uVar1 = FUN_401847ec("02X%02X");
      uVar2 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
      pcVar4 = "iled!\r\n";
      uVar5 = 0x142;
    }
    else {
      func_0x4008b3d8(aiStack_24[0],param_1,0x90);
      iVar3 = func_0x4008fac0(_DAT_3ffc5188,aiStack_24,0xffffffff,0);
      if (iVar3 == 1) {
        return 0;
      }
      uVar6 = func_0x40085c04();
      uVar1 = FUN_401847ec("02X%02X");
      uVar2 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
      uVar5 = 0x147;
      pcVar4 = "iled!\r\n";
    }
    FUN_4012105c(pcVar4,uVar2,uVar1,uVar5,"pipInit");
  }
  return 0xffffffff;
}

