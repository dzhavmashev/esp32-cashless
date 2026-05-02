// Function : FUN_40125cf4
// Address  : 0x40125cf4
// Size     : 433 bytes


undefined4 FUN_40125cf4(int param_1,int param_2,char *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_44 [4];
  uint uStack_40;
  int iStack_3c;
  uint uStack_38;
  uint uStack_34;
  int iStack_28;
  
  (*(code *)&SUB_4008b530)(auStack_44,0,0x24);
  if ((param_1 == 0) || (param_2 == 0)) {
    return 5;
  }
  if (param_3 == (char *)0x0 || param_4 == 0) {
    return 1;
  }
  uVar2 = 2;
  if ((*param_3 != '0') && (uVar2 = 4, *param_3 != 'D')) {
    uVar2 = 1;
  }
  if ((uVar2 & *(uint *)(param_1 + 4)) == 0) {
    return 10;
  }
  if (uVar2 == 2) {
    memw();
    iVar1 = FUN_40105cf0(param_3,param_4,auStack_44);
    FUN_40106368(2,uStack_40);
    uVar4 = 2;
LAB_40125d65:
    FUN_40106368(uVar4,iStack_3c);
    if (iVar1 != 0) {
      return 1;
    }
  }
  else if (uVar2 != 4) {
    memw();
    iVar1 = FUN_40105eec(param_3,param_4,auStack_44);
    FUN_40106368(1,uStack_40);
    uVar4 = 1;
    goto LAB_40125d65;
  }
  if (iStack_3c != *(int *)(param_1 + 0x10)) {
    return 2;
  }
  uStack_38 = uStack_38 & *(uint *)(param_1 + 8);
  if (uStack_38 == 0) {
    return 4;
  }
  uVar4 = 0x80;
  if (((uStack_38 & 0x80) == 0) && (uVar4 = 0x100, (uStack_38 & 0x100) == 0)) {
    if ((uStack_38 & 1) == 0) {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    *(undefined4 *)(param_2 + 0x1bc) = uVar4;
    memw();
  }
  else {
    *(undefined4 *)(param_2 + 0x1bc) = uVar4;
  }
  if (uVar2 == 2) {
    uVar2 = *(uint *)(param_1 + 0x24);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0xc);
  }
  uStack_40 = uStack_40 & uVar2;
  if (uStack_40 == 0) {
    return 3;
  }
  *(byte *)(param_2 + 0x1dc) = (byte)(uStack_34 >> 10) & 1;
  memw();
  iVar1 = *(int *)(param_1 + 0x44);
  *(byte *)(param_2 + 0x1dd) = (byte)(uStack_34 >> 0xb) & 1;
  memw();
  if (iVar1 == 2) {
    if ((uStack_34 & 0x80) == 0) {
      return 7;
    }
    if ((uStack_40 & 2) != 0) {
      return 7;
    }
    if (iStack_28 != 0x20) {
      return 8;
    }
  }
  else {
    uVar2 = 0;
    if (iVar1 == 0) goto LAB_40125e2f;
  }
  uVar2 = uStack_34 >> 7 & 1;
  memw();
LAB_40125e2f:
  *(byte *)(param_2 + 0x19c) = *(byte *)(param_2 + 0x19c) & 0xef | (byte)(uVar2 << 4);
  memw();
  uVar4 = 8;
  if (((uStack_40 & 8) == 0) && (uVar4 = 0x800, (uStack_40 & 0x800) == 0)) {
    uVar4 = 2;
  }
  uVar3 = 1;
  *(undefined4 *)(param_2 + 0x1b8) = uVar4;
  if (*param_3 == '0') {
    uVar3 = 2;
  }
  *(undefined4 *)(param_2 + 0x1b4) = uVar3;
  if ((*(int *)(param_2 + 0x1ac) == 0) || (*(uint *)(param_2 + 0x1b0) < param_4)) {
    (*(code *)&SUB_40094d80)();
    iVar1 = (*(code *)&SUB_40094d60)(param_4);
    *(int *)(param_2 + 0x1ac) = iVar1;
    if (iVar1 == 0) {
      memw();
      return 6;
    }
  }
  memw();
  (*(code *)&SUB_4008b3d0)(*(undefined4 *)(param_2 + 0x1ac),param_3,param_4);
  *(uint *)(param_2 + 0x1b0) = param_4;
  memw();
  return 0;
}

