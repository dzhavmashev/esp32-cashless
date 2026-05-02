// Function : FUN_4017007c
// Address  : 0x4017007c
// Size     : 96 bytes


void FUN_4017007c(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_t0;
  
  piVar1 = (int *)FUN_40170600();
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    return;
  }
  uVar4 = *(uint *)(iVar2 + 0x30) + 0xbcd4d500;
  if (((uint)(uVar4 < *(uint *)(iVar2 + 0x30)) + *(int *)(iVar2 + 0x34) + -0x474e5544 == 0) &&
     (uVar4 < 2)) {
    iVar3 = *(int *)(iVar2 + 0x14);
    if (iVar3 < 0) {
      iVar3 = iVar3 + 1;
      if (iVar3 == 0) {
        *piVar1 = *(int *)(iVar2 + 0x10);
      }
    }
    else {
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar2 + 0x10);
        goto LAB_401700c5;
      }
      if (iVar3 < 0) {
        iVar2 = in_t0;
        FUN_401701ec();
        iVar3 = iVar2;
      }
    }
    *(int *)(iVar2 + 0x14) = iVar3;
  }
  else {
    iVar3 = 0;
LAB_401700c5:
    *piVar1 = iVar3;
    FUN_40171218(iVar2 + 0x30);
  }
  return;
}

