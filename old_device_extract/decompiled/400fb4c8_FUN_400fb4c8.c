// Function : FUN_400fb4c8
// Address  : 0x400fb4c8
// Size     : 28 bytes


undefined4 FUN_400fb4c8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x110b;
  if (*(int *)(param_1 + 0xc) == -2) {
    uVar1 = FUN_40184b28(param_1,0xfffffffc);
  }
  return uVar1;
}

