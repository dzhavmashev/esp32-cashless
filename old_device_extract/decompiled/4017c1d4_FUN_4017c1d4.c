// Function : FUN_4017c1d4
// Address  : 0x4017c1d4
// Size     : 136 bytes


int FUN_4017c1d4(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = *(int *)(param_2 + 0x10);
  uVar4 = *(uint *)(param_2 + 0x14);
  uVar6 = (uVar4 & 0xffff) * param_3 + param_4;
  uVar5 = (uVar4 >> 0x10) * param_3 + (uVar6 >> 0x10);
  uVar4 = uVar5 >> 0x10;
  *(uint *)(param_2 + 0x14) = uVar5 * 0x10000 + (uVar6 & 0xffff);
  iVar1 = param_2;
  if (uVar4 != 0) {
    if (*(int *)(param_2 + 8) <= iVar3) {
      iVar1 = FUN_4017c100(param_1,*(int *)(param_2 + 4) + 1);
      iVar2 = iVar1;
      if (iVar1 == 0) {
        iVar2 = (*(code *)&SUB_40094c54)(&DAT_3f4260d0,0xb5,0,"/dtoa.c");
      }
      (*(code *)&SUB_4008b3d0)(iVar2 + 0xc,param_2 + 0xc,(*(int *)(param_2 + 0x10) + 2) * 4);
      FUN_4017c190(param_1,param_2);
    }
    *(uint *)(iVar1 + (iVar3 + 4) * 4 + 4) = uVar4;
    *(int *)(iVar1 + 0x10) = iVar3 + 1;
  }
  return iVar1;
}

