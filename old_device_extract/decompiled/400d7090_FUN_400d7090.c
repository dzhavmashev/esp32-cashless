// Function : FUN_400d7090
// Address  : 0x400d7090
// Size     : 27 bytes


void FUN_400d7090(int param_1)

{
  undefined4 uVar1;
  
  FUN_400f0780(0x3ffc5490,"l state");
  uVar1 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  FUN_400e7730(*(undefined4 *)(param_1 + 0x18),1);
  return;
}

