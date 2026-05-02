// Function : FUN_4015b14c
// Address  : 0x4015b14c
// Size     : 64 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015b14c(void)

{
  if (*(char *)(_DAT_3ffbfdf0 + 4) != -1) {
    (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffbfdf0 + 0x24);
    (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffbfdf0 + 0x38);
    FUN_4015b0fc(4);
  }
  if (*(code **)(_DAT_3ffbfdf0 + 0x1c) != (code *)0x0) {
    (**(code **)(_DAT_3ffbfdf0 + 0x1c))(*(undefined4 *)(_DAT_3ffbfdf0 + 0x20),4);
  }
  return;
}

