// Function : FUN_401330f4
// Address  : 0x401330f4
// Size     : 71 bytes


undefined4
FUN_401330f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,int param_7,int param_8,uint param_9,int *param_10
            ,int param_11)

{
  undefined4 uVar1;
  
  uVar1 = 0xffff9f00;
  if ((uint)(param_7 + param_11) <= param_9) {
    memw();
    uVar1 = FUN_40132b7c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_10,
                         param_8 + param_7,param_11);
    *param_10 = *param_10 + param_11;
  }
  memw();
  return uVar1;
}

