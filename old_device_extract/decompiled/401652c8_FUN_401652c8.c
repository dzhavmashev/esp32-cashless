// Function : FUN_401652c8
// Address  : 0x401652c8
// Size     : 49 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401652c8(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  do {
    iVar1 = _DAT_3ffc7d60 + _DAT_3ffc06f8;
    memw();
    _DAT_3ffc7d60 = iVar1;
    iVar2 = FUN_40166f94(0);
    uVar3 = iVar1 - iVar2;
  } while (_DAT_3ffc06f8 < uVar3);
  return uVar3 / 1000 + 1;
}

