// Function : FUN_4014e3b4
// Address  : 0x4014e3b4
// Size     : 121 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4014e3b4(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *_DAT_3ffbfc54 & 0xfd;
  if ((*_DAT_3ffbfc54 & 0xfd) == 0) {
    if (_DAT_3ffc8864 != 0) {
      uVar2 = 1;
    }
    return -uVar2;
  }
  FUN_401518e4(0);
  iVar1 = FUN_4014e314();
  FUN_40147fe4(1,4,4,0x3f4337ec,*(undefined1 *)(_DAT_3ffc8800 + 0x154),0);
  iVar1 = -(uint)(iVar1 != 0);
  *(undefined1 *)(_DAT_3ffc8800 + 0x154) = 0;
  memw();
  memw();
  FUN_40147fe4(1,0xc,4,0x3f4337d3,8);
  FUN_4015a448(8);
  if (_DAT_3ffc8864 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}

