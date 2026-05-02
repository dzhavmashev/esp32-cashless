// Function : FUN_400ed674
// Address  : 0x400ed674
// Size     : 381 bytes


undefined4 FUN_400ed674(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 uVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined8 uVar12;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    uVar8 = 0;
    if (*(int *)(param_1 + 0x2c) == 0) {
      pcVar7 = *(char **)(param_1 + 4);
      if (*pcVar7 != -0x17) {
        FUN_400ed41c(param_1);
        uVar6 = 8;
        goto LAB_400ed698;
      }
      iVar1 = func_0x40094d68(0x10);
      *(int *)(param_1 + 8) = iVar1;
      if (iVar1 == 0) {
        uVar12 = func_0x40085c04();
        uVar2 = FUN_401847ec("Aborted");
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),1000,0);
        FUN_4012105c(" > %u\r\n",uVar3,uVar2,0xcc,"\n\r\n");
        return 0;
      }
      func_0x4008b3d8(iVar1,pcVar7,0x10);
      uVar8 = 0x10;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_400ed654(param_1 + 0x14,0,*(undefined4 *)(param_1 + 0x10));
    }
  }
  else {
    uVar8 = 0;
  }
  iVar1 = *(int *)(param_1 + 0x24);
  uVar4 = *(uint *)(*(int *)(param_1 + 0x30) + 0xc);
  uVar11 = uVar4 + iVar1;
  if ((uint)(*(int *)(param_1 + 0x10) - iVar1) < 0x10000 || (uVar11 & 0xffff) != 0) {
    if (((uVar4 & 0xffff) != 0 && uVar11 < (uVar4 & 0xffff0000) + 0x10000) ||
       ((uVar4 + *(int *)(param_1 + 0x10) & 0xffff0000) <= uVar11)) {
      uVar2 = 0x1000;
      goto LAB_400ed7a4;
    }
  }
  else {
    uVar2 = 0x10000;
LAB_400ed7a4:
    iVar1 = FUN_400efea4(0x3ffc53f4,*(int *)(param_1 + 0x30),iVar1,uVar2);
    if (iVar1 == 0) {
      FUN_400ed41c(param_1);
      uVar6 = 2;
      goto LAB_400ed698;
    }
  }
  iVar9 = *(int *)(param_1 + 0x30);
  iVar1 = *(int *)(param_1 + 0xc);
  iVar10 = *(int *)(param_1 + 4);
  if (((*(char *)(iVar9 + 0x25) == '\0') &&
      (iVar5 = FUN_401845f0(param_1,iVar10 + (uVar8 >> 2),iVar1 - uVar8), iVar5 == 0)) ||
     (iVar1 = FUN_400efebc(0x3ffc53f4,iVar9,uVar8 + *(int *)(param_1 + 0x24),iVar10 + uVar8,
                           iVar1 - uVar8), iVar1 != 0)) {
    if ((*(int *)(param_1 + 0x24) == 0) && (*(int *)(param_1 + 0x2c) == 0)) {
      **(undefined1 **)(param_1 + 4) = 0xe9;
    }
    FUN_400f060c(param_1 + 0x44,*(undefined4 *)(param_1 + 4),*(undefined2 *)(param_1 + 0xc));
    iVar9 = *(int *)(param_1 + 0x24);
    iVar1 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(int *)(param_1 + 0x24) = iVar9 + iVar1;
    if (*(int *)(param_1 + 0x1c) == 0) {
      return 1;
    }
    FUN_400ed654(param_1 + 0x14,iVar9 + iVar1,*(undefined4 *)(param_1 + 0x10));
    return 1;
  }
  FUN_400ed41c(param_1);
  uVar6 = 1;
LAB_400ed698:
  *param_1 = uVar6;
  return 0;
}

