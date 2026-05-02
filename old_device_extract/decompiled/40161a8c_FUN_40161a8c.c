// Function : FUN_40161a8c
// Address  : 0x40161a8c
// Size     : 310 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161a8c(void)

{
  longlong lVar1;
  longlong lVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  longlong lVar8;
  
  pbVar3 = (byte *)(**(code **)(_DAT_3ffc1a34 + 0x1c4))();
  lVar1 = CONCAT44(_DAT_3ffca244,_DAT_3ffca240);
  lVar2 = CONCAT44(_DAT_3ffca23c,_DAT_3ffca238);
  if (pbVar3 != (byte *)0x0) {
    lVar8 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    iVar4 = (**(code **)(_DAT_3ffc1a34 + 0x1c0))();
    iVar5 = (**(code **)(_DAT_3ffc1a34 + 0x1bc))();
    lVar8 = lVar8 + (ulonglong)((uint)*pbVar3 * iVar5 * iVar4);
    uVar6 = (uint)lVar8;
    (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca2b8);
    pcVar7 = *(code **)(_DAT_3ffc1a34 + 0xf8);
    iVar4 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    (*pcVar7)(0x3ffca2b8,uVar6 - iVar4,0);
    _DAT_3ffca238 = CONCAT44(_DAT_3ffca23c,_DAT_3ffca238);
    if ((pbVar3[1] & 2) != 0) {
      _DAT_3ffca238 = lVar8;
      if (_DAT_3ffca368 == 0) {
        iVar4 = FUN_40163758(1);
        if ((iVar4 != 0) || (_DAT_3ffca2f8 != 0)) {
          pcVar7 = *(code **)(_DAT_3ffc1a34 + 0x19c);
          iVar4 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
          (*pcVar7)(1,0,uVar6 - iVar4);
          FUN_40161194();
        }
        DAT_3ffca1f0 = 1;
        memw();
        memw();
      }
      else {
        pcVar7 = *(code **)(_DAT_3ffc1a34 + 0x19c);
        iVar4 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
        (*pcVar7)(1,0,uVar6 - iVar4);
      }
    }
    lVar1 = CONCAT44(_DAT_3ffca244,_DAT_3ffca240);
    lVar2 = _DAT_3ffca238;
    if ((pbVar3[1] & 1) != 0) {
      if (DAT_3ffca1e5 == '\0') {
        _DAT_3ffca240 = lVar8 + -1000;
      }
      else {
        _DAT_3ffca240 =
             CONCAT44((int)((ulonglong)lVar8 >> 0x20) - (uint)(uVar6 < uVar6 - _DAT_3ffca210),
                      uVar6 - _DAT_3ffca210);
        memw();
      }
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca2cc);
      iVar4 = _DAT_3ffca240;
      pcVar7 = *(code **)(_DAT_3ffc1a34 + 0xf8);
      iVar5 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
      (*pcVar7)(0x3ffca2cc,iVar4 - iVar5,0);
      lVar1 = _DAT_3ffca240;
      lVar2 = _DAT_3ffca238;
    }
  }
  _DAT_3ffca23c = (undefined4)((ulonglong)lVar2 >> 0x20);
  _DAT_3ffca238 = (undefined4)lVar2;
  _DAT_3ffca244 = (undefined4)((ulonglong)lVar1 >> 0x20);
  _DAT_3ffca240 = (int)lVar1;
  return;
}

