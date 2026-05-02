// Function : FUN_40142a4c
// Address  : 0x40142a4c
// Size     : 123 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40142a4c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9,undefined4 param_10)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_401425ac(param_1,1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,auStack_34,
                       param_10);
  if ((iVar1 == 0) && (iVar2 = FUN_401862dc(param_9,auStack_34,param_10), iVar1 = 0, iVar2 != 0)) {
    FUN_4013ae54(param_8,param_2);
    iVar1 = -0xf;
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

