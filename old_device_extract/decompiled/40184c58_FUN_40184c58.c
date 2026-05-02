// Function : FUN_40184c58
// Address  : 0x40184c58
// Size     : 91 bytes


void FUN_40184c58(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_1;
  if (param_2 == 3) {
    memw();
    memw();
    *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) | 4;
    memw();
    uVar1 = *(uint *)(iVar2 + 0x20) & 0xffffffcf;
    uVar3 = 0x10;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) & 0xfffffffb;
    uVar1 = (param_2 & 3) << 4;
    memw();
    uVar3 = *(uint *)(iVar2 + 0x20) & 0xffffffcf;
    memw();
  }
  memw();
  *(uint *)(iVar2 + 0x20) = uVar3 | uVar1;
  memw();
  return;
}

