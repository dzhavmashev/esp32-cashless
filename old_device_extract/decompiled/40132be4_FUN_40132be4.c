// Function : FUN_40132be4
// Address  : 0x40132be4
// Size     : 94 bytes


int FUN_40132be4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 *param_9,undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(*param_1 + 4) == 6) {
    *param_9 = param_7;
    memw();
    iVar1 = FUN_40141600(param_1[0xf]);
    iVar2 = -0x12;
  }
  else {
    if (*(int *)(*param_1 + 4) != 8) {
      return -0x6080;
    }
    *param_9 = param_7;
    memw();
    iVar2 = -0xf;
    iVar1 = FUN_40142ac8(param_1[0xf],param_7,param_2,param_3,param_4,param_5,param_6,param_8,
                         param_10,param_11);
  }
  if (iVar1 == iVar2) {
    iVar1 = -0x6300;
  }
  return iVar1;
}

