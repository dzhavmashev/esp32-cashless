// Function : FUN_401702f0
// Address  : 0x401702f0
// Size     : 92 bytes


void FUN_401702f0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = (int *)FUN_4017061c();
  iVar3 = *piVar1;
  iVar2 = piVar1[1] + 1;
  piVar1[1] = iVar2;
  if (iVar3 != 0) {
    uVar4 = *(uint *)(iVar3 + 0x30) + 0xbcd4d500;
    if (((uint)(uVar4 < *(uint *)(iVar3 + 0x30)) + *(int *)(iVar3 + 0x34) + -0x474e5544 == 0) &&
       (uVar4 < 2)) {
      *(int *)(iVar3 + 0x14) = -*(int *)(iVar3 + 0x14);
    }
    else {
      *piVar1 = 0;
    }
    iVar2 = iVar3 + 0x30;
    FUN_40171178(iVar2);
    FUN_40170020(iVar2);
  }
  FUN_401701ec();
  (*(code *)&SUB_40094d80)(iVar2);
  return;
}

