// Function : FUN_4011fec0
// Address  : 0x4011fec0
// Size     : 44 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011fec0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_4011e4a0();
  uVar2 = (*(code *)&SUB_40085b74)();
  _DAT_3ffc6d18 = (uint)uVar1 - (int)uVar2;
  _DAT_3ffc6d1c =
       ((int)((ulonglong)uVar1 >> 0x20) - (int)((ulonglong)uVar2 >> 0x20)) -
       (uint)((uint)uVar1 < _DAT_3ffc6d18);
  memw();
  return;
}

