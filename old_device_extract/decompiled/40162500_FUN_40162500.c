// Function : FUN_40162500
// Address  : 0x40162500
// Size     : 439 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162500(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  
  if (DAT_3ffca1e5 != '\0') {
    memw();
    _DAT_3ff73cb8 = _DAT_3ff73cb8 & 0xfff1ffff;
    memw();
    memw();
    FUN_4018bca8();
    FUN_40161174();
    (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca27c);
    (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca290);
    _DAT_3ffca1f2 = 0;
    memw();
    if (DAT_3ffca1d9 != '\0') {
      memw();
      FUN_4018bdc0();
      DAT_3ffca1d9 = '\0';
      memw();
      memw();
      FUN_401636d0();
    }
    uVar2 = _DAT_3ffca264;
    uVar1 = _DAT_3ffca260;
    uVar10 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    uVar8 = (uint)uVar10 - _DAT_3ffca258;
    memw();
    FUN_40147fe4(6,0x1000,3,0x3f435886,uVar1,uVar2,uVar8,
                 ((int)((ulonglong)uVar10 >> 0x20) - _DAT_3ffca25c) - (uint)((uint)uVar10 < uVar8));
    DAT_3ffca1f0 = 1;
    DAT_3ffca1e7 = 0;
    DAT_3ffca1e8 = 0;
    DAT_3ffca1e3 = 0;
    DAT_3ffca1f1 = 0;
    DAT_3ffca1e5 = '\0';
    DAT_3ffca340 = 0;
    DAT_3ffca359 = 0;
    _DAT_3ffca35c = 0;
    _DAT_3ffca35e = 3;
    memw();
    memw();
    FUN_40162224(0);
    iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
    if (iVar3 != 0) {
      FUN_40161bf8();
    }
    if (DAT_3ffca2f5 != '\0') {
      DAT_3ffca2f5 = '\x02';
      memw();
      memw();
      FUN_401615fc();
      if (_DAT_3ffca2f8 == 0) {
        FUN_4016133c();
      }
    }
    if (((DAT_3ffc1a44 != '\0') && (memw(), DAT_3ffc1a3c == '\0')) && (_DAT_3ffc1a40 != 0)) {
      uVar10 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
      uVar7 = (uint)uVar10 - _DAT_3ffca258;
      uVar8 = ((int)((ulonglong)uVar10 >> 0x20) - _DAT_3ffca25c) - (uint)((uint)uVar10 < uVar7);
      uVar9 = _DAT_3ffca264 << 0xc;
      uVar1 = _DAT_3ffca260 >> 0x14;
      uVar2 = _DAT_3ffca264 >> 0x14;
      uVar4 = FUN_40147614();
      uVar5 = (*(code *)&SUB_4000c8b0)(_DAT_3ffca260,_DAT_3ffca264);
      memw();
      uVar6 = (*(code *)&SUB_4000c8b0)(uVar7,uVar8);
      FUN_40187020(uVar5,uVar6);
      (*(code *)&SUB_40002c34)();
      memw();
      FUN_40147fe4(6,0x1000,3,0x3f435830,uVar9 | uVar1,uVar2,uVar8 * 0x1000 | uVar7 >> 0x14,
                   uVar8 >> 0x14,uVar4);
      FUN_40148118(0);
    }
  }
  return;
}

