// Function : FUN_4018be94
// Address  : 0x4018be94
// Size     : 384 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018be94(void)

{
  undefined8 uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint local_30 [12];
  
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != 0)) || (_DAT_3ffc1a40 == 0)) {
    if ((((DAT_3ffca1e8 != '\0') && (DAT_3ffca1e9 == '\0')) &&
        ((DAT_3ffca1ea == '\0' && ((DAT_3ffca1eb == '\0' && (DAT_3ffca1ec == '\0')))))) &&
       ((DAT_3ffca1e6 != '\0' && ((DAT_3ffca1e7 == '\0' && (_DAT_3ffca2f8 == 0)))))) {
      iVar2 = FUN_40163758(1);
      goto LAB_4018bf1f;
    }
  }
  else if (((((DAT_3ffca1e8 != '\0') && (DAT_3ffca1ea == '\0')) && (DAT_3ffca1eb == '\0')) &&
           ((DAT_3ffca1ec == '\0' && (DAT_3ffca1e6 != '\0')))) && (_DAT_3ffca2f8 == 0)) {
    iVar2 = FUN_40162b40(1);
LAB_4018bf1f:
    bVar3 = 1;
    if (iVar2 == 0) goto LAB_4018bf3c;
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
    if (iVar2 != 0) {
      bVar3 = DAT_3ffca1f0 ^ 1;
      goto LAB_4018bf3c;
    }
  }
  bVar3 = 0;
LAB_4018bf3c:
  uVar1 = CONCAT44(_DAT_3ffca24c,_DAT_3ffca248);
  if ((bVar3 & 1) != 0) {
    _DAT_3ffca248 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    memw();
    (*(code *)&SUB_40087d08)(3,1);
    (**(code **)(_DAT_3ffc1a34 + 0x1a0))(1);
    (**(code **)(_DAT_3ffc1a34 + 0x1a0))(2);
    FUN_4018b860(0);
    uVar1 = _DAT_3ffca248;
    if (DAT_3ffc1a44 != '\0') {
      memw();
      if ((DAT_3ffc1a3c == 0) && (_DAT_3ffc1a40 != 0)) {
        memw();
        local_30[0] = (uint)DAT_3ffc1a3c;
        iVar2 = FUN_40146820(local_30);
        uVar1 = _DAT_3ffca248;
        if ((iVar2 == 0) && (local_30[0] == 3)) {
          FUN_4018b860(1);
          uVar1 = _DAT_3ffca248;
        }
      }
    }
    _DAT_3ffca24c = (int)((ulonglong)uVar1 >> 0x20);
    _DAT_3ffca248 = (uint)uVar1;
    _DAT_3ffc7c38 = _DAT_3ffc7c38 + 1;
    uVar4 = _DAT_3ffca248 - _DAT_3ffca250;
    iVar2 = (_DAT_3ffca24c - _DAT_3ffca254) - (uint)(_DAT_3ffca248 < uVar4);
    _DAT_3ffc7c4c = (uint)(_DAT_3ffc7c48 + uVar4 < _DAT_3ffc7c48) + _DAT_3ffc7c4c + iVar2;
    _DAT_3ffc7c54 = (uint)(_DAT_3ffc7c50 + uVar4 < _DAT_3ffc7c50) + _DAT_3ffc7c54 + iVar2;
    DAT_3ffca1d9 = 2;
    memw();
    memw();
    _DAT_3ffc7c48 = _DAT_3ffc7c48 + uVar4;
    _DAT_3ffc7c50 = _DAT_3ffc7c50 + uVar4;
    _DAT_3ffca248 = uVar1;
    (*(code *)&SUB_40087d08)(3,0);
    uVar1 = _DAT_3ffca248;
  }
  _DAT_3ffca24c = (int)((ulonglong)uVar1 >> 0x20);
  _DAT_3ffca248 = (uint)uVar1;
  return;
}

