// Function : FUN_4018bdc0
// Address  : 0x4018bdc0
// Size     : 211 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018bdc0(void)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  uint local_30 [12];
  
  uVar3 = _DAT_3ffca250;
  if (DAT_3ffca1d9 == '\x02') {
    FUN_4018b7dc(0);
    if (DAT_3ffc1a44 != '\0') {
      memw();
      if ((DAT_3ffc1a3c == 0) && (_DAT_3ffc1a40 != 0)) {
        memw();
        local_30[0] = (uint)DAT_3ffc1a3c;
        iVar1 = FUN_40146820(local_30);
        if ((iVar1 == 0) && (local_30[0] == 3)) {
          FUN_4018b7dc(1);
        }
      }
    }
    uVar3 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    _DAT_3ffc7c3c = _DAT_3ffc7c3c + 1;
    uVar2 = (uint)uVar3 - _DAT_3ffca248;
    iVar1 = ((int)((ulonglong)uVar3 >> 0x20) - _DAT_3ffca24c) - (uint)((uint)uVar3 < uVar2);
    _DAT_3ffc7c44 = (uint)(_DAT_3ffc7c40 + uVar2 < _DAT_3ffc7c40) + _DAT_3ffc7c44 + iVar1;
    _DAT_3ffc7c54 = (uint)(_DAT_3ffc7c50 + uVar2 < _DAT_3ffc7c50) + _DAT_3ffc7c54 + iVar1;
    _DAT_3ffca264 = (uint)(_DAT_3ffca260 + uVar2 < _DAT_3ffca260) + _DAT_3ffca264 + iVar1;
    _DAT_3ffc7c40 = _DAT_3ffc7c40 + uVar2;
    _DAT_3ffc7c50 = _DAT_3ffc7c50 + uVar2;
    _DAT_3ffca260 = _DAT_3ffca260 + uVar2;
  }
  _DAT_3ffca254 = (undefined4)((ulonglong)uVar3 >> 0x20);
  _DAT_3ffca250 = (undefined4)uVar3;
  DAT_3ffca1d9 = 1;
  memw();
  memw();
  return;
}

