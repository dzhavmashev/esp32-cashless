// Function : FUN_4017c854
// Address  : 0x4017c854
// Size     : 178 bytes


void FUN_4017c854(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int *param_5,
                 int *param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_30;
  uint auStack_2c [11];
  
  iVar1 = FUN_4017c100(param_1,1);
  if (iVar1 == 0) {
    (*(code *)&SUB_40094c54)(&DAT_3f4260d0,0x30a,0,"/dtoa.c");
  }
  local_30 = param_4 & 0xfffff;
  uVar5 = param_4 >> 0x14 & 0x7ff;
  if (uVar5 != 0) {
    local_30 = local_30 | 0x100000;
  }
  if (param_3 == 0) {
    iVar4 = FUN_4017c340(&local_30);
    uVar2 = iVar4 + 0x20;
    *(uint *)(iVar1 + 0x14) = local_30;
    iVar4 = 1;
    *(undefined4 *)(iVar1 + 0x10) = 1;
  }
  else {
    auStack_2c[0] = param_3;
    uVar2 = FUN_4017c340(auStack_2c);
    if (uVar2 == 0) {
      *(uint *)(iVar1 + 0x14) = auStack_2c[0];
    }
    else {
      uVar3 = local_30 << 0x20 - (0x20 - (-uVar2 & 0x1f));
      local_30 = local_30 >> (uVar2 & 0x1f);
      *(uint *)(iVar1 + 0x14) = uVar3 | auStack_2c[0];
    }
    iVar4 = 1;
    if (local_30 != 0) {
      iVar4 = 2;
    }
    *(uint *)(iVar1 + 0x18) = local_30;
    *(int *)(iVar1 + 0x10) = iVar4;
  }
  if (uVar5 == 0) {
    *param_5 = uVar2 - 0x432;
    iVar1 = FUN_4017c2f8(*(undefined4 *)(iVar1 + iVar4 * 4 + 0x10));
    *param_6 = iVar4 * 0x20 - iVar1;
  }
  else {
    *param_5 = (uVar5 - 0x433) + uVar2;
    *param_6 = 0x35 - uVar2;
  }
  return;
}

