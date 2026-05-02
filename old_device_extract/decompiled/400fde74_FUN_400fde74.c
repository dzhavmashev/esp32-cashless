// Function : FUN_400fde74
// Address  : 0x400fde74
// Size     : 111 bytes


void FUN_400fde74(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = iVar2 + (param_2 + 0x20) * 4;
  memw();
  memw();
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xfffc1fff;
  if ((int)param_2 < 0x20) {
    memw();
    *(int *)(iVar2 + 0x4c) = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  }
  else {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0x58) =
         *(uint *)(iVar2 + 0x58) & 0xffffff00 | 1 << 0x20 - (0x20 - (param_2 & 0x1f)) & 0xffU;
    memw();
  }
  memw();
  return;
}

