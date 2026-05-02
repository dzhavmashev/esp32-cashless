// Function : FUN_400f1960
// Address  : 0x400f1960
// Size     : 221 bytes


void FUN_400f1960(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 uStack_38;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  param_1 = param_1 & 0xff;
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar7 = func_0x40085c04();
    uVar2 = FUN_401847ec("");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
    pcVar5 = "-gpio.c";
    uVar6 = 0x66;
  }
  else {
    uStack_38 = (*(code *)&SUB_4000c818)(1,0,param_1);
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    memw();
    uStack_24 = *(uint *)((param_1 + 0x20) * 4 + 0x3ff44008) >> 7 & 7;
    if ((param_2 & 0xff) < 0x20) {
      uStack_30 = param_2 & 3;
      if ((param_2 & 0x10) != 0) {
        uStack_30 = uStack_30 | 4;
      }
      uStack_2c = (uint)((param_2 & 4) != 0);
      if ((param_2 & 8) != 0) {
        uStack_28 = 1;
      }
    }
    iVar4 = FUN_400f4104(&uStack_38);
    if (iVar4 == 0) {
      return;
    }
    uVar7 = func_0x40085c04();
    uVar2 = FUN_401847ec("");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
    uVar6 = 0x82;
    pcVar5 = "ected\r\n";
  }
  FUN_4012105c(pcVar5,uVar3,uVar2,uVar6,"ailed\r\n");
  return;
}

