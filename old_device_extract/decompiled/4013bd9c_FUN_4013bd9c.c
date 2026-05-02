// Function : FUN_4013bd9c
// Address  : 0x4013bd9c
// Size     : 65 bytes


undefined4
FUN_4013bd9c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xa4) == 0) {
    memw();
    uVar1 = FUN_4013bc9c(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else if (*(int *)(param_1 + 0xa4) == 1) {
    memw();
    uVar1 = FUN_4013bb58();
  }
  else {
    uVar1 = 0xffffbf00;
  }
  return uVar1;
}

