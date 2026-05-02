// Function : FUN_4013b1ec
// Address  : 0x4013b1ec
// Size     : 120 bytes


int FUN_4013b1ec(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                int param_6,undefined4 param_7,int param_8,undefined4 param_9,int param_10,
                undefined4 param_11)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
LAB_4013b20a:
    if (((((param_4 == 0) || (iVar1 = FUN_4013183c(param_1 + 0x2c,param_4,param_5), iVar1 == 0)) &&
         ((param_6 == 0 || (iVar1 = FUN_4013183c(param_1 + 0x38,param_6,param_7), iVar1 == 0)))) &&
        ((param_8 == 0 || (iVar1 = FUN_4013183c(param_1 + 0x20,param_8,param_9), iVar1 == 0)))) &&
       ((param_10 == 0 || (iVar1 = FUN_4013183c(param_1 + 0x14,param_10,param_11), iVar1 == 0)))) {
      iVar1 = 0;
      goto LAB_4013b217;
    }
  }
  else {
    iVar1 = FUN_4013183c(param_1 + 8,param_2,param_3);
    if (iVar1 == 0) {
      uVar2 = FUN_401317d8(param_1 + 8);
      *(undefined4 *)(param_1 + 4) = uVar2;
      goto LAB_4013b20a;
    }
  }
  iVar1 = iVar1 + -0x4080;
LAB_4013b217:
  memw();
  return iVar1;
}

