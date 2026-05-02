// Function : FUN_40171410
// Address  : 0x40171410
// Size     : 122 bytes


uint * FUN_40171410(uint param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint *unaff_a10;
  uint *puVar2;
  uint *in_t0;
  uint *local_30;
  uint uStack_2c;
  
  if (param_1 == 0x50) {
    puVar2 = (uint *)(param_3 + 3U & 0xfffffffc);
    local_30 = (uint *)*puVar2;
    unaff_a10 = puVar2 + 1;
    goto LAB_401714de;
  }
  if (0xc < (param_1 & 0xf)) {
    local_30 = in_t0;
    unaff_a10 = (uint *)(*(code *)&SUB_40094bc8)();
    goto LAB_401714c6;
  }
  iVar1 = (param_1 & 0xf) << 2;
switchD_4017143d_caseD_40171439:
  iVar1 = *(int *)((int)&switchD_4017143d::switchdataD_3f424d64 + iVar1);
  switch(iVar1) {
  case 0x40170a5e:
    puVar2 = (uint *)(int)(short)iVar1;
    unaff_a10 = (uint *)(param_3 + 2);
    goto LAB_40170ab2;
  case 0x40170a81:
    puVar2 = (uint *)((uint)local_30 | (uint)&switchD_4017143d::switchdataD_3f424d64);
LAB_40170ab2:
    if (puVar2 != (uint *)0x0) {
      if ((param_1 & 0x70) == 0x10) {
        param_2 = param_3;
      }
      puVar2 = (uint *)((int)puVar2 + param_2);
      if ((char)param_1 < '\0') {
        puVar2 = (uint *)*puVar2;
      }
    }
    *param_4 = (uint)puVar2;
    return unaff_a10;
  case 0x40171439:
    goto switchD_4017143d_caseD_40171439;
  case 0x40171443:
    unaff_a10 = (uint *)FUN_4017127c(param_3);
    break;
  case 0x4017144f:
    unaff_a10 = (uint *)FUN_401712a4();
    break;
  case 0x4017145e:
    local_30 = (uint *)(uStack_2c | (uint)&switchD_4017143d::switchdataD_3f424d64);
LAB_40171475:
    unaff_a10 = (uint *)(param_3 + 2);
    break;
  case 0x40171472:
    local_30 = (uint *)(int)(short)iVar1;
    goto LAB_40171475;
  case 0x40171495:
    local_30 = (uint *)((uint)local_30 | (uint)&switchD_4017143d::switchdataD_3f424d64);
    break;
  case 0x401714b8:
    local_30 = (uint *)((uint)local_30 | (uint)&switchD_4017143d::switchdataD_3f424d64);
  }
LAB_401714c6:
  if (local_30 != (uint *)0x0) {
    if ((param_1 & 0x70) == 0x10) {
      param_2 = param_3;
    }
    local_30 = (uint *)((int)local_30 + param_2);
    if ((char)param_1 < '\0') {
      local_30 = (uint *)*local_30;
    }
  }
LAB_401714de:
  *param_4 = (uint)local_30;
  return unaff_a10;
}

