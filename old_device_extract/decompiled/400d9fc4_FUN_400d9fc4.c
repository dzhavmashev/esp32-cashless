// Function : FUN_400d9fc4
// Address  : 0x400d9fc4
// Size     : 26 bytes


void FUN_400d9fc4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)&LAB_40183e8b_1)(*(undefined4 *)(param_1 + 8));
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  FUN_400f06a4(0x3ffc5490,"dress: ",uVar1);
  return;
}

