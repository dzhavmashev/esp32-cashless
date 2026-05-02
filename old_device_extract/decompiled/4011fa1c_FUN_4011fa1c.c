// Function : FUN_4011fa1c
// Address  : 0x4011fa1c
// Size     : 70 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011fa1c(void)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar3 = FUN_4011e4a0();
  uVar1 = (uint)uVar3 - _DAT_3ffc57f0;
  iVar2 = (int)((ulonglong)uVar3 >> 0x20) - _DAT_3ffc57f4;
  uVar4 = (*(code *)&SUB_40085bfc)();
  _DAT_3ffc6738 = uVar1 - (int)uVar4;
  _DAT_3ffc673c =
       ((iVar2 - (uint)((uint)uVar3 < uVar1)) - (int)((ulonglong)uVar4 >> 0x20)) -
       (uint)(uVar1 < _DAT_3ffc6738);
  memw();
  FUN_4018ddf8(0x4011fee4);
  return;
}

