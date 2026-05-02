// Function : FUN_400da2f0
// Address  : 0x400da2f0
// Size     : 30 bytes


void FUN_400da2f0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x48);
  uVar2 = *(int *)(param_1 + 0x3c) * 2;
  *(uint *)(param_1 + 0x3c) = (uVar2 < uVar1) * uVar2 + (uVar2 >= uVar1) * uVar1;
  FUN_400f06a4(0x3ffc5490,"nnected");
  return;
}

