// Function : FUN_4018ba14
// Address  : 0x4018ba14
// Size     : 99 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4018ba14(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  
  iVar2 = FUN_4015f694(param_2);
  if (iVar2 == 1) {
    iVar2 = FUN_4018b19c(param_2 * 0x14 + 0x3ffbff18,param_3,param_5);
    return iVar2;
  }
  if (iVar2 == 2) {
    iVar2 = param_2 * 0x14;
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
    iVar1 = *(int *)(iVar2 + 0x3ffbff18);
    if (iVar1 == 0) {
      iVar2 = (uint)*(byte *)(iVar2 + 0x3ffbff20) * 0xc;
      *(short *)(iVar2 + 0x3ffc7c62) = *(short *)(iVar2 + 0x3ffc7c62) + 1;
      memw();
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
      return 0;
    }
    *(int *)(iVar2 + 0x3ffbff18) = *(int *)(iVar1 + 0x28);
    *(undefined4 *)(iVar1 + 0x28) = 0;
    piVar3 = (int *)(param_2 * 0xc + 0x3ffc7c58);
    *piVar3 = *piVar3 + 1;
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
    puVar4 = *(uint **)(iVar1 + 4);
    *(short *)(iVar1 + 0x16) = (short)param_3;
    memw();
    if (puVar4 == (uint *)0x0) {
      memw();
    }
    else {
      puVar4[1] = *(int *)(iVar1 + 0x10) + (uint)*(byte *)(iVar2 + 0x3ffbff24);
      memw();
      memw();
      *puVar4 = *puVar4 & 0xfffff000 |
                (param_3 & 0xffff) + (uint)*(byte *)(iVar2 + 0x3ffbff24) & 0xfff;
    }
    if (param_5 != 0) {
      memw();
      (*(code *)&SUB_4008b3d0)(puVar4[1],param_5,param_3);
    }
    **(uint **)(iVar1 + 0x2c) = **(uint **)(iVar1 + 0x2c) | *(uint *)(param_2 * 0x14 + 0x3ffbff1c);
    *(uint *)(*(int *)(iVar1 + 0x2c) + 4) = *(uint *)(*(int *)(iVar1 + 0x2c) + 4) | 0xf;
    memw();
    return iVar1;
  }
  return 0;
}

