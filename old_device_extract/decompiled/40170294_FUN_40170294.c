// Function : FUN_40170294
// Address  : 0x40170294
// Size     : 46 bytes


void FUN_40170294(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + -0x60) = 0;
  *(undefined4 *)(param_1 + -0x50) = param_2;
  *(undefined4 *)(param_1 + -0x4c) = param_3;
  uVar1 = FUN_40170204();
  *(undefined4 *)(param_1 + -0x48) = uVar1;
  uVar1 = func_0x401701dc();
  *(undefined4 *)(param_1 + -0x20) = 0x432b2b00;
  *(undefined4 *)(param_1 + -0x44) = uVar1;
  *(undefined4 *)(param_1 + -0x1c) = 0x474e5543;
  *(undefined4 *)(param_1 + -0x18) = 0x40170250;
  return;
}

