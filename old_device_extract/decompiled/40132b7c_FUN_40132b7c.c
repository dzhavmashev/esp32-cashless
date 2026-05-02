// Function : FUN_40132b7c
// Address  : 0x40132b7c
// Size     : 100 bytes


undefined4
FUN_40132b7c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 *param_9,undefined4 param_10,undefined4 param_11)

{
  undefined4 uVar1;
  
  if (*(int *)(*param_1 + 4) == 6) {
    *param_9 = param_7;
    memw();
    uVar1 = FUN_401415d0(param_1[0xf],1,param_7,param_2,param_3,param_4,param_5,param_6,param_8,
                         param_11,param_10);
  }
  else {
    uVar1 = 0xffff9f80;
    if (*(int *)(*param_1 + 4) == 8) {
      *param_9 = param_7;
      memw();
      uVar1 = FUN_40142a1c(param_1[0xf]);
    }
  }
  return uVar1;
}

