// Function : FUN_40161844
// Address  : 0x40161844
// Size     : 341 bytes


/* WARNING: Removing unreachable block (ram,0x40161952) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161844(void)

{
  bool bVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  
  iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
  if (iVar2 == 0) {
    if (_DAT_3ffca1fc != 0) {
      if (_DAT_3ffca1fc == 1) {
        _DAT_3ffca230 = (uint)DAT_3ffca1e3 * _DAT_3ffca204 + _DAT_3ffca230;
        _DAT_3ffca234 = (uint)(_DAT_3ffca230 < (uint)DAT_3ffca1e3 * _DAT_3ffca204) + _DAT_3ffca234;
        goto LAB_401618cd;
      }
      if (_DAT_3ffca1fc == 2) {
        _DAT_3ffca230 = (uint)_DAT_3ffca1f8 * _DAT_3ffca204 + _DAT_3ffca230;
        _DAT_3ffca234 = (uint)(_DAT_3ffca230 < (uint)_DAT_3ffca1f8 * _DAT_3ffca204) + _DAT_3ffca234;
        goto LAB_401618fa;
      }
    }
  }
  else if (DAT_3ffca1e6 != '\0') {
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x1c0))();
    uVar4 = _DAT_3ffca230 + iVar2 * _DAT_3ffca204;
    _DAT_3ffca234 = (uint)(uVar4 < _DAT_3ffca230) + _DAT_3ffca234;
    memw();
    _DAT_3ffca230 = uVar4;
LAB_401618cd:
    memw();
    goto LAB_401618fa;
  }
  _DAT_3ffca234 = (uint)(_DAT_3ffca230 + _DAT_3ffca204 < _DAT_3ffca230) + _DAT_3ffca234;
  memw();
  _DAT_3ffca230 = _DAT_3ffca230 + _DAT_3ffca204;
LAB_401618fa:
  memw();
  uVar7 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  bVar1 = false;
  iVar5 = 0x65;
  uVar4 = _DAT_3ffca230;
  iVar2 = _DAT_3ffca234;
  while ((CONCAT44(iVar2,uVar4) <= uVar7 ||
         ((uVar6 = uVar4 - (int)uVar7, iVar2 - (int)(uVar7 >> 0x20) == (uint)(uVar4 < uVar6) &&
          (uVar6 < 5000))))) {
    uVar6 = uVar4 + _DAT_3ffca204;
    iVar2 = (uint)(uVar6 < uVar4) + iVar2;
    bVar1 = true;
    iVar5 = iVar5 + -1;
    uVar4 = uVar6;
    if (iVar5 == 0) {
      memw();
      _DAT_3ffca230 = uVar6;
      _DAT_3ffca234 = iVar2;
      FUN_40147fe4(6,0x1000,2,0x3f436fac,uVar6,iVar2,_DAT_3ffca204);
LAB_40161974:
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca27c);
      uVar4 = _DAT_3ffca230;
      pcVar3 = *(code **)(_DAT_3ffc1a34 + 0xf8);
      iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
      (*pcVar3)(0x3ffca27c,uVar4 - iVar2,0);
      return;
    }
  }
  if (bVar1) {
    _DAT_3ffca230 = uVar4;
    _DAT_3ffca234 = iVar2;
  }
  goto LAB_40161974;
}

