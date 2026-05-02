// Function : FUN_40156a8c
// Address  : 0x40156a8c
// Size     : 107 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40156a8c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(_DAT_3ffc8800 + 0xe4);
  if ((iVar1 != 0) && (*(int *)(_DAT_3ffc8800 + 0x98) == 5)) {
    if (*(int *)(param_1 + 0x44) == 0) {
      *(uint *)(iVar1 + 0x2e0) =
           *(uint *)(iVar1 + 0x2e0) | 1 << 0x20 - (0x20 - (*(byte *)(param_1 + 4) & 0x1f));
      memw();
      FUN_40147fe4(1,0x20,3,0x3f434ee4,*(undefined1 *)(param_1 + 4));
    }
    else if ((*(ushort *)(*(int *)(param_1 + 0x44) + 2) & 0x4000) != 0) {
      FUN_40147fe4(1,0x20,3,0x3f434ec7,*(undefined1 *)(param_1 + 4));
      *(uint *)(iVar1 + 0x2e4) = *(uint *)(iVar1 + 0x2e4) | 4;
    }
  }
  memw();
  return 0;
}

