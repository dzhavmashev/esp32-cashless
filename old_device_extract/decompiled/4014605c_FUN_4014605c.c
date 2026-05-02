// Function : FUN_4014605c
// Address  : 0x4014605c
// Size     : 67 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014605c(void)

{
  int iVar1;
  
  if (_DAT_3ffc790c == 0) {
    if (_DAT_3ffc1a34 == 0) {
      return 0x3001;
    }
    _DAT_3ffc790c = (**(code **)(_DAT_3ffc1a34 + 0x4c))();
    if (_DAT_3ffc790c == 0) {
      memw();
      return 0x101;
    }
  }
  iVar1 = FUN_4014dd48();
  if (iVar1 == 0) {
    (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc790c);
  }
  return 0;
}

