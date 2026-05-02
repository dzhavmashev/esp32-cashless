// Function : FUN_40151700
// Address  : 0x40151700
// Size     : 74 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40151700(void)

{
  int iVar1;
  
  if (_DAT_3ffc7a5c != 0) {
    iVar1 = FUN_40165e64();
    if ((iVar1 != 0) && (*(int *)(_DAT_3ffbfc54 + 0x494) != 0)) {
      (**(code **)(_DAT_3ffc1a34 + 0x130))();
      *(undefined4 *)(_DAT_3ffbfc54 + 0x494) = 0;
    }
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(_DAT_3ffc7a5c);
  }
  _DAT_3ffc7a5c = 0;
  memw();
  return;
}

