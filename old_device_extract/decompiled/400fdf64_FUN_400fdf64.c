// Function : FUN_400fdf64
// Address  : 0x400fdf64
// Size     : 68 bytes


void FUN_400fdf64(int *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  memw();
  iVar2 = 80000000;
  if ((*(uint *)(*param_1 + 0x20) & 0x8000000) == 0) {
    iVar2 = 1000000;
  }
  memw();
  uVar1 = *(uint *)(*param_1 + 0x14);
  memw();
  memw();
  memw();
  *param_2 = (uint)(iVar2 << 4) / ((uVar1 & 0xfffff) << 4 | uVar1 >> 0x14 & 0xf);
  memw();
  return;
}

