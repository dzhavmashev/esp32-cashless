// Function : FUN_40165e1c
// Address  : 0x40165e1c
// Size     : 34 bytes


void FUN_40165e1c(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = ((param_1 & 0xff) + 4) * 4;
  uVar2 = *(uint *)(iVar1 + 0x3ffc0708);
  *(undefined4 *)(iVar1 + 0x3ffc0708) = 0;
  memw();
  FUN_4016658c(param_1 & 0xff,uVar2 & 0xff);
  return;
}

