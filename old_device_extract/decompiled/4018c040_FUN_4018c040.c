// Function : FUN_4018c040
// Address  : 0x4018c040
// Size     : 112 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_4018c040(void)

{
  bool bVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  if (DAT_3ffca1d9 != '\x01') {
    return false;
  }
  uVar5 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  if (DAT_3ffc1a44 != '\0') {
    memw();
    uVar4 = 3000000;
    if (DAT_3ffc1a3c == '\0') goto LAB_4018c07e;
  }
  uVar4 = _DAT_3ffc0020;
LAB_4018c07e:
  uVar3 = (uint)uVar5 - _DAT_3ffca220;
  if (((int)((ulonglong)uVar5 >> 0x20) - _DAT_3ffca224 == (uint)((uint)uVar5 < uVar3)) &&
     (uVar3 < uVar4)) {
    return false;
  }
  bVar1 = _DAT_3ffca214 == 0;
  uVar2 = CONCAT44(_DAT_3ffca224,_DAT_3ffca220);
  if (!bVar1) {
    _DAT_3ffca214 = 0;
    uVar2 = uVar5;
  }
  _DAT_3ffca224 = (int)((ulonglong)uVar2 >> 0x20);
  _DAT_3ffca220 = (int)uVar2;
  memw();
  return bVar1;
}

