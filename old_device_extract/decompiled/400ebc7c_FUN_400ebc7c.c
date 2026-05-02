// Function : FUN_400ebc7c
// Address  : 0x400ebc7c
// Size     : 459 bytes


void FUN_400ebc7c(undefined2 *param_1,undefined1 *param_2,char param_3,int param_4,int param_5,
                 int param_6,char param_7,char param_8,int param_9,ushort param_10,
                 undefined2 param_11,char *param_12)

{
  undefined1 uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  
  *param_1 = 0;
  uVar6 = (uint)param_10;
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if ((uVar6 == 0) && (param_9 != 0)) {
    uVar3 = func_0x4008c024();
    uVar6 = 0xffff;
    if (uVar3 < 0x10000) {
      uVar6 = uVar3 & 0xffff;
    }
  }
  if ((param_12 == (char *)0x0) || (*param_12 == '\0')) {
    uVar1 = 3;
    goto LAB_400ebcde;
  }
  iVar4 = func_0x4008c024(param_12);
  iVar5 = 0;
  if (param_6 != 0) {
    iVar5 = func_0x4008c024(param_6);
    iVar5 = uVar6 + 4 + iVar5;
  }
  iVar8 = 0;
  if (param_4 != 0) {
    iVar8 = func_0x4008c024(param_4);
    iVar8 = iVar8 + 2;
  }
  iVar9 = 0;
  if (param_5 != 0) {
    iVar9 = func_0x4008c024(param_5);
    iVar9 = iVar9 + 2;
  }
  iVar9 = iVar8 + iVar5 + iVar4 + 0xc + iVar9;
  iVar4 = FUN_400ebc28(param_1,iVar9,0);
  if (iVar4 == 0) {
    uVar1 = 1;
    goto LAB_400ebcde;
  }
  **(undefined1 **)(param_1 + 2) = 0x10;
  iVar4 = FUN_401845b0(iVar9,*(int *)(param_1 + 2) + 1);
  iVar5 = FUN_400ec628(&DAT_3f409948,*(int *)(param_1 + 2) + iVar4 + 1);
  iVar5 = iVar4 + 1 + iVar5;
  *(undefined1 *)(*(int *)(param_1 + 2) + iVar5) = 4;
  bVar7 = 0;
  if (param_3 != '\0') {
    bVar7 = 2;
  }
  if (param_4 != 0) {
    bVar7 = bVar7 | 0x80;
  }
  if (param_5 != 0) {
    bVar7 = bVar7 | 0x40;
  }
  if (param_6 != 0) {
    if (param_7 == '\0') {
      bVar2 = 4;
    }
    else {
      bVar2 = 0x24;
    }
    bVar7 = bVar7 | bVar2;
    if (param_8 == '\x01') {
      bVar2 = 8;
    }
    else {
      if (param_8 != '\x02') goto LAB_400ebda6;
      bVar2 = 0x10;
    }
    bVar7 = bVar7 | bVar2;
  }
LAB_400ebda6:
  *(byte *)(*(int *)(param_1 + 2) + iVar5 + 1) = bVar7;
  *(char *)(*(int *)(param_1 + 2) + iVar5 + 2) = (char)((ushort)param_11 >> 8);
  *(char *)(*(int *)(param_1 + 2) + iVar5 + 3) = (char)param_11;
  iVar4 = FUN_400ec628(param_12,*(int *)(param_1 + 2) + iVar5 + 4);
  iVar4 = iVar5 + 4 + iVar4;
  if ((param_6 != 0) && (param_9 != 0)) {
    iVar5 = FUN_400ec628(param_6,*(int *)(param_1 + 2) + iVar4);
    iVar4 = iVar4 + iVar5;
    *(char *)(*(int *)(param_1 + 2) + iVar4) = (char)(uVar6 >> 8);
    *(char *)(*(int *)(param_1 + 2) + iVar4 + 1) = (char)uVar6;
    func_0x4008b3d8(*(int *)(param_1 + 2) + iVar4 + 2,param_9,uVar6);
    iVar4 = uVar6 + iVar4 + 2;
  }
  if (param_4 != 0) {
    iVar5 = FUN_400ec628(param_4,*(int *)(param_1 + 2) + iVar4);
    iVar4 = iVar4 + iVar5;
  }
  if (param_5 != 0) {
    FUN_400ec628(param_5,*(int *)(param_1 + 2) + iVar4);
  }
  uVar1 = 0;
LAB_400ebcde:
  *param_2 = uVar1;
  return;
}

