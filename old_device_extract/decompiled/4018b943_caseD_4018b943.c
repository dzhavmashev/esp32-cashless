// Function : caseD_4018b943
// Address  : 0x4018b943
// Size     : 184 bytes


/* WARNING: Removing unreachable block (ram,0x4018bf42) */
/* WARNING: Removing unreachable block (ram,0x4018bf7e) */
/* WARNING: Removing unreachable block (ram,0x4018bf8c) */
/* WARNING: Removing unreachable block (ram,0x4018bf93) */
/* WARNING: Removing unreachable block (ram,0x4018bf9f) */
/* WARNING: Removing unreachable block (ram,0x4018bfa4) */
/* WARNING: Removing unreachable block (ram,0x4018bfa9) */
/* WARNING: Removing unreachable block (ram,0x4018bfc6) */
/* WARNING: Removing unreachable block (ram,0x4018bfc9) */
/* WARNING: Removing unreachable block (ram,0x4018bfdc) */
/* WARNING: Removing unreachable block (ram,0x4018bfde) */
/* WARNING: Removing unreachable block (ram,0x4018bff3) */
/* WARNING: Removing unreachable block (ram,0x4018bff5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_4018a7d6::caseD_4018b943(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  int in_t0;
  
  iVar2 = func_0x401d26e8();
  if (in_t0 != 0) {
    return;
  }
  iVar1 = param_2 * 0x14;
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  iVar3 = *(int *)(iVar1 + 0x3ffbff18);
  if (iVar3 != 0) {
    *(int *)(iVar1 + 0x3ffbff18) = *(int *)(iVar3 + 0x28);
    *(undefined4 *)(iVar3 + 0x28) = 0;
    piVar4 = (int *)(param_2 * 0xc + 0x3ffc7c58);
    *piVar4 = *piVar4 + 1;
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
    puVar5 = *(uint **)(iVar3 + 4);
    *(undefined2 *)(iVar3 + 0x16) = 0;
    memw();
    if (puVar5 == (uint *)0x0) {
      memw();
    }
    else {
      puVar5[1] = *(int *)(iVar3 + 0x10) + (uint)*(byte *)(iVar1 + 0x3ffbff24);
      memw();
      memw();
      *puVar5 = *puVar5 & 0xfffff000 | (uint)*(byte *)(iVar1 + 0x3ffbff24);
    }
    if (iVar2 != 0) {
      memw();
      (*(code *)&SUB_4008b3d0)(puVar5[1],iVar2,0);
    }
    **(uint **)(iVar3 + 0x2c) = **(uint **)(iVar3 + 0x2c) | *(uint *)(param_2 * 0x14 + 0x3ffbff1c);
    *(uint *)(*(int *)(iVar3 + 0x2c) + 4) = *(uint *)(*(int *)(iVar3 + 0x2c) + 4) | 0xf;
    memw();
    return;
  }
  iVar2 = (uint)*(byte *)(iVar1 + 0x3ffbff20) * 0xc;
  *(short *)(iVar2 + 0x3ffc7c62) = *(short *)(iVar2 + 0x3ffc7c62) + 1;
  memw();
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  return;
}

