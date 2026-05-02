// Function : FUN_400fb430
// Address  : 0x400fb430
// Size     : 34 bytes


undefined4 FUN_400fb430(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0xc) - 1U < 0xfffffffe) && (*(int *)(param_1 + 0xc) != -0x10)) {
    *param_2 = *(undefined4 *)(param_1 + 0x10);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x1101;
  }
  memw();
  return uVar1;
}

