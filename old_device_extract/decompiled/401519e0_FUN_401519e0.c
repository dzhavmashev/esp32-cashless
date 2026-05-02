// Function : FUN_401519e0
// Address  : 0x401519e0
// Size     : 80 bytes


int FUN_401519e0(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = FUN_4015fb34(param_1 + -0x12,1,param_2 + 0x12);
  if (iVar1 != 0) {
    puVar2 = *(uint **)(iVar1 + 4);
    puVar2[1] = puVar2[1] + 0x12;
    *(short *)(iVar1 + 0x16) = *(short *)(iVar1 + 0x16) + -0x12;
    memw();
    memw();
    memw();
    memw();
    *puVar2 = *puVar2 & 0xfffff000 | (*puVar2 & 0xfff) - 0x12 & 0xfff;
  }
  memw();
  return iVar1;
}

