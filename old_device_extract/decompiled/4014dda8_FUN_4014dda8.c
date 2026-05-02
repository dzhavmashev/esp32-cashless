// Function : FUN_4014dda8
// Address  : 0x4014dda8
// Size     : 124 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014dda8(byte param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (DAT_3ffc89da == '\x01') {
    uVar1 = 0;
    if ((param_1 & 0xfd) == 1) {
      iVar2 = FUN_40150e2c();
      if (1 < *(int *)(iVar2 + 4) + 1U) {
        iVar2 = FUN_4014d7f8(iVar2 + (uint)*(byte *)(iVar2 + 0x9f) * 0x8c + 0x10b);
        DAT_3ffc89f2 = iVar2 == 0;
        memw();
      }
      DAT_3ffc8a50 = 0;
      memw();
      memw();
      uVar1 = FUN_40158fe4(&DAT_3ffc89fe);
    }
    if ((byte)(param_1 - 2) < 2) {
      uVar1 = 0x102;
      if (*(code **)(_DAT_3ffc87ec + 0xc) != (code *)0x0) {
        uVar1 = (**(code **)(_DAT_3ffc87ec + 0xc))();
      }
    }
  }
  return uVar1;
}

