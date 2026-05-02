// Function : FUN_4010538c
// Address  : 0x4010538c
// Size     : 48 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4010538c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  _DAT_3ffc8320 = 0;
  _DAT_3ffc831c = 0x80a;
  memw();
  iVar1 = FUN_4015aadc();
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x50) = 0x40105330;
    memw();
    uVar2 = 0;
  }
  else {
    FUN_4010536c();
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

