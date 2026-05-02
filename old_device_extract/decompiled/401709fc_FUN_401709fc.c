// Function : FUN_401709fc
// Address  : 0x401709fc
// Size     : 70 bytes


uint * FUN_401709fc(uint *param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint *unaff_a10;
  uint *puVar2;
  uint *local_30;
  uint uStack_2c;
  
  if (param_1 == (uint *)0x50) {
    puVar2 = (uint *)(param_3 + 3U & 0xfffffffc);
    local_30 = (uint *)*puVar2;
    unaff_a10 = puVar2 + 1;
    goto LAB_40170aca;
  }
  if (0xc < ((uint)param_1 & 0xf)) {
    puVar2 = (uint *)FUN_40170aac();
    return puVar2;
  }
  iVar1 = ((uint)param_1 & 0xf) << 2;
switchD_40170a29_caseD_40170a25:
  iVar1 = *(int *)((int)&switchD_40170a29::switchdataD_3f424d30 + iVar1);
  switch(iVar1) {
  case 0x401706d4:
    return (uint *)&DAT_3f424c50;
  case 0x40170718:
    FUN_40170698(param_1);
    return param_1;
  case 0x40170a25:
    goto switchD_40170a29_caseD_40170a25;
  case 0x40170a2f:
    unaff_a10 = (uint *)FUN_40170998(param_3);
    break;
  case 0x40170a3b:
    unaff_a10 = (uint *)FUN_401709c0();
    break;
  case 0x40170a4a:
    local_30 = (uint *)(uStack_2c | (uint)&switchD_40170a29::switchdataD_3f424d30);
LAB_40170a61:
    unaff_a10 = (uint *)(param_3 + 2);
    break;
  case 0x40170a5e:
    local_30 = (uint *)(int)(short)iVar1;
    goto LAB_40170a61;
  case 0x40170a81:
    local_30 = (uint *)((uint)local_30 | (uint)&switchD_40170a29::switchdataD_3f424d30);
    break;
  case 0x40170aa4:
    local_30 = (uint *)((uint)local_30 | (uint)&switchD_40170a29::switchdataD_3f424d30);
  }
  if (local_30 != (uint *)0x0) {
    if (((uint)param_1 & 0x70) == 0x10) {
      param_2 = param_3;
    }
    local_30 = (uint *)((int)local_30 + param_2);
    if ((char)param_1 < '\0') {
      local_30 = (uint *)*local_30;
    }
  }
LAB_40170aca:
  *param_4 = (uint)local_30;
  return unaff_a10;
}

