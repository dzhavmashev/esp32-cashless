// Function : FUN_40153a2c
// Address  : 0x40153a2c
// Size     : 281 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40153a2c(int *param_1,int param_2,uint param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar4 = _DAT_3ffc8800;
  uVar8 = param_3 & 0xff;
  uVar5 = 0;
  iVar6 = *param_1;
  bVar1 = iVar6 != _DAT_3ffc8800;
  if (iVar6 != _DAT_3ffc8800) {
    uVar5 = *(undefined1 *)((int)param_1 + 0x26);
  }
  if ((uVar8 == 0) || (uVar8 == 3)) {
    iVar7 = 2;
  }
  else {
    iVar7 = 3;
    if ((2 < uVar8) && (iVar7 = 1, 5 < uVar8)) {
      iVar7 = 0;
    }
  }
  *(uint *)(*(int *)(param_2 + 0x2c) + 4) =
       *(uint *)(*(int *)(param_2 + 0x2c) + 4) & 0xffffff0f | iVar7 << 4;
  *(uint *)(*(int *)(param_2 + 0x2c) + 4) =
       *(uint *)(*(int *)(param_2 + 0x2c) + 4) & 0xfffffff0 | param_3 & 0xf;
  iVar7 = *(int *)(param_2 + 0x2c);
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar2 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    memw();
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  *(int *)(iVar7 + 0x18) = iVar2;
  *(uint *)(*(int *)(param_2 + 0x2c) + 0x10) =
       *(uint *)(*(int *)(param_2 + 0x2c) + 0x10) & 0xfff7ffff | (uint)bVar1 << 0x13;
  **(uint **)(param_2 + 0x2c) = **(uint **)(param_2 + 0x2c) | param_4;
  *(uint *)(*(int *)(param_2 + 0x2c) + 0x10) =
       *(uint *)(*(int *)(param_2 + 0x2c) + 0x10) & 0xffff0fff |
       (*(byte *)(param_1 + 0xae) & 0xf) << 0xc;
  memw();
  uVar3 = FUN_4016000c((uint)bVar1,uVar5);
  *(undefined4 *)(param_2 + 0x24) = uVar3;
  if (iVar6 == iVar4) {
    iVar4 = *(int *)(param_2 + 0x2c);
    if (*(char *)(iVar6 + 0x168) == '\x04') {
      uVar8 = *(uint *)(iVar4 + 0x10) | 0x10000;
      memw();
    }
    else {
      uVar8 = *(uint *)(iVar4 + 0x10) & 0xfffeffff;
    }
    *(uint *)(iVar4 + 0x10) = uVar8;
  }
  memw();
  return;
}

