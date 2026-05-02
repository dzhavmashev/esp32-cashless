// Function : FUN_4014151c
// Address  : 0x4014151c
// Size     : 179 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014151c(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uStack_48;
  undefined8 uStack_44;
  undefined8 uStack_3c;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_48 = 0;
  memw();
  (*(code *)&SUB_4008b530)(&uStack_44,0,0x10);
  (*(code *)&SUB_4008b530)(auStack_34,0,0x10);
  uVar1 = 0xffffffec;
  if (param_3 - 4U < 0xd) {
    uStack_44 = (*(code *)&SUB_40064b08)
                          (*(uint *)(param_1 + 0x148) << 3,
                           *(uint *)(param_1 + 0x148) >> 0x1d | *(int *)(param_1 + 0x14c) << 3);
    memw();
    uStack_3c = (*(code *)&SUB_40064b08)(*(int *)(param_1 + 0x150) << 3,0);
    memw();
    FUN_40140fa8(param_1,&uStack_44,0x10,param_1 + 0x10);
    memw();
    uVar1 = FUN_4013d1b0(param_1 + 0x15c,param_3,&uStack_48,param_1 + 0x130,auStack_34,
                         param_1 + 0x10,param_2);
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return uVar1;
}

