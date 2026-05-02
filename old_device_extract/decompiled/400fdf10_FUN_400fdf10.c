// Function : FUN_400fdf10
// Address  : 0x400fdf10
// Size     : 81 bytes


void FUN_400fdf10(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  memw();
  iVar1 = 80000000;
  if ((*(uint *)(iVar2 + 0x20) & 0x8000000) == 0) {
    iVar1 = 1000000;
  }
  param_2 = (uint)(iVar1 << 4) / param_2;
  memw();
  memw();
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfff00000 | (param_2 << 8) >> 0xc;
  memw();
  memw();
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xff0fffff | (param_2 & 0xf) << 0x14;
  memw();
  return;
}

