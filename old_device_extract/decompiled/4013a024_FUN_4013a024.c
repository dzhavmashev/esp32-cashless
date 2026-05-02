// Function : FUN_4013a024
// Address  : 0x4013a024
// Size     : 30 bytes


undefined4 FUN_4013a024(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  memw();
  uStack_28 = param_1;
  uStack_24 = param_2;
  iVar1 = FUN_40186520(&uStack_28);
  uVar2 = 0;
  if (iVar1 - 2U < 3) {
    uVar2 = uStack_24;
  }
  return uVar2;
}

