// Function : FUN_400fdfa8
// Address  : 0x400fdfa8
// Size     : 99 bytes


void FUN_400fdfa8(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((param_2 & 1) == 0) {
    memw();
    uVar1 = *(uint *)(iVar2 + 0x24) & 0xff7fffff;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) & 0xff80ffff | (param_3 & 0x7f) << 0x10;
    memw();
    uVar1 = *(uint *)(iVar2 + 0x24) | 0x800000;
  }
  memw();
  *(uint *)(iVar2 + 0x24) = uVar1;
  memw();
  if ((param_2 & 2) == 0) {
    uVar1 = *(uint *)(iVar2 + 0x20) & 0xffff7fff;
  }
  else {
    uVar1 = *(uint *)(iVar2 + 0x20) | 0x8000;
  }
  memw();
  *(uint *)(iVar2 + 0x20) = uVar1;
  memw();
  return;
}

