// Function : FUN_40109f14
// Address  : 0x40109f14
// Size     : 64 bytes


bool FUN_40109f14(int param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (*(byte *)(param_1 + 0x1f) < 2) {
    iVar2 = (*(byte *)(param_1 + 0x1f) + 1) * 0x18;
    if ((&DAT_3ffc5cec)[iVar2] == '\x06') {
      bVar1 = true;
      if ((((*(int *)(&DAT_3ffc5cd8 + iVar2) == 0) && (*(int *)(&DAT_3ffc5cdc + iVar2) == 0)) &&
          (*(int *)(&DAT_3ffc5ce0 + iVar2) == 0)) && (*(int *)(&DAT_3ffc5ce4 + iVar2) == 0)) {
        bVar1 = false;
      }
    }
    else {
      bVar1 = *(int *)(&DAT_3ffc5cd8 + iVar2) != 0;
    }
  }
  return bVar1;
}

