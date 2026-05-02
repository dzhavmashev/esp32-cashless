// Function : FUN_400d6fec
// Address  : 0x400d6fec
// Size     : 50 bytes


void FUN_400d6fec(int param_1)

{
  undefined4 uVar1;
  
  FUN_400f0780(0x3ffc5490,"g state");
  uVar1 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  FUN_400e7730(*(undefined4 *)(param_1 + 0x18),2);
  FUN_400f0780(0x3ffc5490,"g state");
  return;
}

