// Function : FUN_4014f5cc
// Address  : 0x4014f5cc
// Size     : 87 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014f5cc(void)

{
  undefined4 uVar1;
  
  DAT_3ffc89d9 = 2;
  memw();
  if ((*_DAT_3ffbfc54 & 0xfd) == 0) {
    memw();
    FUN_40147fe4(1,3,4,0x3f433758);
    uVar1 = 0xffffffff;
  }
  else if (_DAT_3ffc8864 == 0) {
    FUN_40147fe4(1,4,4,0x3f433742);
    FUN_4014e3b4();
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_4014e3b4();
  }
  return uVar1;
}

