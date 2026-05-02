// Function : FUN_4015f7f0
// Address  : 0x4015f7f0
// Size     : 452 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4015f7f0(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  (*(code *)&SUB_4008b530)(0x3ffc1a48,0,0x80);
  (*(code *)&SUB_4008b530)(0x3ffca0ec,0,0xc0);
  _DAT_3ffbffb4 = FUN_40165e88();
  if (_DAT_3ffbffb4 == 0) {
    _DAT_3ffbffb4 = 0x40;
    memw();
  }
  else {
    memw();
    memw();
  }
  memw();
  FUN_40147fe4(6,1,3,0x3f4357b8,_DAT_3ffbffb4);
  iVar1 = FUN_40165eb8();
  if (iVar1 == 0) {
    _DAT_3ffbffc8 = FUN_40165ec4();
    if (_DAT_3ffbffc8 == 0) {
      _DAT_3ffbffc8 = 10;
      memw();
    }
    else {
      memw();
      memw();
    }
    memw();
    iVar1 = FUN_4015f6d8(8,_DAT_3ffbffc8,500);
    if (iVar1 != 0) goto LAB_4015f9a6;
    uVar3 = 0x3f435795;
  }
  else {
    _DAT_3ffbffc8 = FUN_40165ec4();
    if (_DAT_3ffbffc8 == 0) {
      _DAT_3ffbffc8 = 10;
      memw();
    }
    else {
      memw();
      memw();
    }
    uVar3 = 0x3f435771;
  }
  memw();
  FUN_40147fe4(6,1,3,uVar3,_DAT_3ffbffc8);
  _DAT_3ffbff64 = FUN_40165f1c();
  if (_DAT_3ffbff64 == 0) {
    _DAT_3ffbff64 = 0x20;
    memw();
  }
  else {
    memw();
    memw();
  }
  memw();
  FUN_40147fe4(6,1,3,0x3f43574c,_DAT_3ffbff64);
  iVar1 = FUN_40165e94();
  if (iVar1 == 0) {
    _DAT_3ffbff3c = FUN_40165ea0();
    if (_DAT_3ffbff3c == 0) {
      _DAT_3ffbff3c = 0x20;
      memw();
    }
    else {
      memw();
      memw();
    }
    memw();
    iVar1 = FUN_4015f6d8(1,param_1,0x640 - (uint)DAT_3ffbff38);
    uVar3 = 0x3f43572e;
    if (iVar1 != 0) goto LAB_4015f9a6;
  }
  else {
    _DAT_3ffbff3c = FUN_40165eac();
    if (_DAT_3ffbff3c == 0) {
      _DAT_3ffbff3c = 0x20;
      memw();
    }
    else {
      memw();
      memw();
    }
    param_1 = (uint)_DAT_3ffbff3c;
    uVar3 = 0x3f43570f;
  }
  memw();
  FUN_40147fe4(6,1,3,uVar3,param_1);
  iVar1 = FUN_40165f44();
  if (iVar1 != 0) {
    uVar3 = FUN_40165ed0();
    iVar1 = FUN_4015f6d8(9,uVar3,0x640 - (uint)DAT_3ffbffd8);
    if (iVar1 != 0) {
LAB_4015f9a6:
      memw();
      FUN_4015f7b4();
      return iVar1;
    }
    uVar3 = FUN_40165ed0();
    FUN_40147fe4(6,1,3,0x3f4356f2,uVar3);
  }
  iVar1 = 0x3ffca0ec;
  iVar2 = 0;
  do {
    *(int *)(iVar1 + 0x2c) = iVar2 + 0x3ffc1a48;
    iVar2 = iVar2 + 0x20;
    *(undefined1 *)(iVar1 + 0x1a) = 5;
    memw();
    memw();
    FUN_4018a7b8(iVar1);
    iVar1 = iVar1 + 0x30;
  } while (iVar2 != 0x80);
  return 0;
}

