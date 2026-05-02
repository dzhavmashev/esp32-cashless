// Function : FUN_400fddf8
// Address  : 0x400fddf8
// Size     : 123 bytes


void FUN_400fddf8(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  if ((int)param_2 < 0x20) {
    memw();
    *(int *)(iVar1 + 0x4c) = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  }
  else {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar1 + 0x58) =
         *(uint *)(iVar1 + 0x58) & 0xffffff00 | 1 << 0x20 - (0x20 - (param_2 & 0x1f)) & 0xffU;
    memw();
  }
  iVar1 = iVar1 + (param_2 + 0x20) * 4;
  memw();
  uVar2 = 0x8000;
  if (param_3 != 0) {
    uVar2 = 0x2000;
  }
  memw();
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xfffc1fff | uVar2;
  memw();
  return;
}

