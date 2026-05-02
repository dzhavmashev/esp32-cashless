// Function : FUN_401479d8
// Address  : 0x401479d8
// Size     : 106 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401479d8(void)

{
  int iVar1;
  
  iVar1 = _DAT_3ffc8800;
  if (_DAT_3ffc8800 != 0) {
    if (*(char *)(_DAT_3ffc8800 + 0x168) == '\x03') {
      FUN_4014aea0(_DAT_3ffc8800);
    }
    (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
    _DAT_3ffc8800 = 0;
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(*(undefined4 *)(iVar1 + 0xe8));
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar1);
    FUN_4015c604();
    FUN_4015c8f0();
    FUN_4015fb80(0,0);
  }
  FUN_40160064(0,_DAT_3ffc8800);
  return;
}

