// Function : FUN_401702c4
// Address  : 0x401702c4
// Size     : 42 bytes


void FUN_401702c4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = FUN_4017061c();
  *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  puVar2 = (undefined4 *)FUN_40170294(param_1,param_2,param_3);
  *puVar2 = 1;
  FUN_40170f54(puVar2 + 0x10);
  FUN_40170020(puVar2 + 0x10);
  piVar3 = (int *)FUN_401701ec();
  cust0();
  iVar4 = *piVar3;
  iVar1 = (int)puVar2 + 0x41;
  piVar3[1] = iVar1;
  if (iVar4 != 0) {
    uVar5 = *(uint *)(iVar4 + 0x30) + 0xbcd4d500;
    if (((uint)(uVar5 < *(uint *)(iVar4 + 0x30)) + *(int *)(iVar4 + 0x34) + -0x474e5544 == 0) &&
       (uVar5 < 2)) {
      *(int *)(iVar4 + 0x14) = -*(int *)(iVar4 + 0x14);
    }
    else {
      *piVar3 = 0;
    }
    iVar1 = iVar4 + 0x30;
    FUN_40171178(iVar1);
    FUN_40170020(iVar1);
  }
  FUN_401701ec();
  (*(code *)&SUB_40094d80)(iVar1);
  return;
}

