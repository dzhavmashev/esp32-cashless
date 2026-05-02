// Function : FUN_4016894c
// Address  : 0x4016894c
// Size     : 70 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016894c(void)

{
  int iVar1;
  
  if (_DAT_3ffca40c != 0) {
    iVar1 = FUN_40165e64();
    if ((iVar1 != 0) && (*(int *)(_DAT_3ffca40c + 0x38) != 0)) {
      (**(code **)(_DAT_3ffc1a34 + 0x130))();
      *(undefined4 *)(_DAT_3ffca40c + 0x38) = 0;
    }
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(_DAT_3ffca40c);
  }
  _DAT_3ffca40c = 0;
  DAT_3ffc7e60 = 0;
  memw();
  memw();
  return;
}

