// Function : FUN_401478ac
// Address  : 0x401478ac
// Size     : 100 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401478ac(void)

{
  int iVar1;
  
  iVar1 = _DAT_3ffc8804;
  if (_DAT_3ffc8804 != 0) {
    if (*(char *)(_DAT_3ffc8804 + 0x168) == '\x03') {
      FUN_4014aea0(_DAT_3ffc8804);
    }
    (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
    _DAT_3ffc8804 = 0;
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(*(undefined4 *)(iVar1 + 0xec));
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar1);
    FUN_4015fb80(0,1);
  }
  FUN_40160064(1,_DAT_3ffc8804);
  return;
}

