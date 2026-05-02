// Function : FUN_4013c4d0
// Address  : 0x4013c4d0
// Size     : 60 bytes


undefined4
FUN_4013c4d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xa4) == 0) {
    memw();
    uVar1 = FUN_4013c434(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else if (*(int *)(param_1 + 0xa4) == 1) {
    memw();
    uVar1 = FUN_4013c404();
  }
  else {
    uVar1 = 0xffffbf00;
  }
  return uVar1;
}

