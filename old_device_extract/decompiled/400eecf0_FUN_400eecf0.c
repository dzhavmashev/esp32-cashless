// Function : FUN_400eecf0
// Address  : 0x400eecf0
// Size     : 112 bytes


void FUN_400eecf0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  FUN_400f0d4c(param_1,param_2);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  FUN_400f0d4c(param_1 + 0x14,param_2 + 0x14);
  FUN_400f0d4c(param_1 + 0x24,param_2 + 0x24);
  FUN_400f0d4c(param_1 + 0x34,param_2 + 0x34);
  FUN_400f0d4c(param_1 + 0x44,param_2 + 0x44);
  uVar1 = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  uVar1 = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  *(undefined1 *)(param_1 + 100) = *(undefined1 *)(param_2 + 100);
  *(undefined1 *)(param_1 + 0x65) = *(undefined1 *)(param_2 + 0x65);
  return;
}

