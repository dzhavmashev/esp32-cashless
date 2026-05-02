// Function : FUN_401617f4
// Address  : 0x401617f4
// Size     : 65 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401617f4(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
  if (iVar1 == 0) {
    _DAT_3ffca208 = _DAT_3ffc0024;
    memw();
    iVar1 = _DAT_3ffc0014;
  }
  else {
    _DAT_3ffca208 = (**(code **)(_DAT_3ffc1a34 + 0x1c0))();
    _DAT_3ffca208 = _DAT_3ffca204 * _DAT_3ffca208;
    iVar1 = _DAT_3ffc0018;
  }
  if (iVar1 != _DAT_3ffca200) {
    _DAT_3ffca200 = iVar1;
  }
  memw();
  return;
}

