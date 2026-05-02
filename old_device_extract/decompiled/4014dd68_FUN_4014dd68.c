// Function : FUN_4014dd68
// Address  : 0x4014dd68
// Size     : 60 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014dd68(byte param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_3ffc89da == '\x01') {
    if ((param_1 & 0xfd) == 1) {
      uVar1 = FUN_4015908c();
    }
    if ((byte)(param_1 - 2) < 2) {
      uVar1 = 0x102;
      if (*(code **)(_DAT_3ffc87ec + 0x10) != (code *)0x0) {
        uVar1 = (**(code **)(_DAT_3ffc87ec + 0x10))();
      }
    }
  }
  return uVar1;
}

