// Function : FUN_400fb454
// Address  : 0x400fb454
// Size     : 23 bytes


undefined4 FUN_400fb454(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x110b;
  if (*(int *)(param_1 + 0xc) == -1) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x10) = param_2;
  }
  memw();
  return uVar1;
}

