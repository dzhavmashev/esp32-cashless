// Function : FUN_4013b170
// Address  : 0x4013b170
// Size     : 115 bytes


int FUN_4013b170(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((((((param_2 == 0) || (iVar2 = FUN_4013167c(param_1 + 8,param_2), iVar2 == 0)) &&
        ((param_3 == 0 || (iVar2 = FUN_4013167c(param_1 + 0x2c,param_3), iVar2 == 0)))) &&
       ((param_4 == 0 || (iVar2 = FUN_4013167c(param_1 + 0x38,param_4), iVar2 == 0)))) &&
      ((param_5 == 0 || (iVar2 = FUN_4013167c(param_1 + 0x20,param_5), iVar2 == 0)))) &&
     ((param_6 == 0 || (iVar2 = FUN_4013167c(param_1 + 0x14,param_6), iVar2 == 0)))) {
    iVar2 = 0;
    if (param_2 != 0) {
      uVar1 = FUN_401317d8(param_1 + 8);
      iVar2 = 0;
      *(undefined4 *)(param_1 + 4) = uVar1;
      memw();
    }
  }
  else {
    iVar2 = iVar2 + -0x4080;
  }
  return iVar2;
}

