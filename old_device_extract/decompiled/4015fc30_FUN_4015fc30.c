// Function : FUN_4015fc30
// Address  : 0x4015fc30
// Size     : 353 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015fc30(uint param_1,int param_2,undefined4 param_3,undefined1 param_4,undefined1 param_5,
                 undefined1 param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = param_1 & 0xff;
  if (param_2 == 2) {
    *(undefined1 *)(uVar1 * 10 + 0x3ffca1b2) = param_4;
    *(undefined1 *)(uVar1 * 10 + 0x3ffca1b3) = param_5;
    memw();
    memw();
    return;
  }
  if (param_2 != 0) {
    if (param_2 != 1) {
      FUN_40147fe4(6,1,1,"type=%d",uVar1);
      return;
    }
    if (((uint)DAT_3ffc072d & 1 << ((byte)param_1 & 0x1f)) != 0) {
      DAT_3ffc072d = DAT_3ffc072d & ((byte)(1 << 0x20 - (0x20 - (param_1 & 0x1f))) ^ 0xff);
      memw();
      memw();
      FUN_40164f8c(uVar1);
    }
    iVar2 = (*(code *)&SUB_40002ed0)(DAT_3ffc072d);
    if (iVar2 == 0) {
      memw();
      _DAT_3ff73084 = _DAT_3ff73084 & 0x7fffffff;
      memw();
      memw();
      FUN_40186b04();
    }
    if (uVar1 == 0) {
      FUN_40147fe4(1,0xc,4,0x3f434c2d,2);
      uVar3 = 2;
    }
    else {
      if (uVar1 != 1) {
        if (uVar1 != 3) {
          return;
        }
        FUN_4015fc08();
        return;
      }
      FUN_40147fe4(1,0xc,4,0x3f434c14,10);
      uVar3 = 10;
    }
    FUN_4015a448(uVar3);
    return;
  }
  if (uVar1 == 0) {
    FUN_40147fe4(1,0xc,4,0x3f434c5f);
    uVar3 = 1;
  }
  else {
    if (uVar1 != 1) {
      if (uVar1 == 3) {
        FUN_4015fbfc();
      }
      goto LAB_4015fc96;
    }
    FUN_40147fe4(1,0xc,4,0x3f434c46,9);
    uVar3 = 9;
  }
  FUN_4015a448(uVar3);
LAB_4015fc96:
  iVar2 = uVar1 * 10;
  (*(code *)&SUB_4008b3d0)(iVar2 + 0x3ffca1ac,param_3,6);
  *(undefined1 *)(iVar2 + 0x3ffca1b2) = param_4;
  *(undefined1 *)(iVar2 + 0x3ffca1b3) = param_5;
  memw();
  DAT_3ffc072d = (byte)(1 << 0x20 - (0x20 - (param_1 & 0x1f))) | DAT_3ffc072d;
  memw();
  memw();
  iVar2 = (*(code *)&SUB_40002ed0)();
  if (iVar2 != 0) {
    memw();
    _DAT_3ff73084 = _DAT_3ff73084 | 0x80000000;
    memw();
  }
  memw();
  FUN_4015f9e4(uVar1,param_6);
  return;
}

