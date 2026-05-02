// Function : FUN_40117f9c
// Address  : 0x40117f9c
// Size     : 100 bytes


undefined1
FUN_40117f9c(undefined4 param_1,int *param_2,int param_3,undefined1 param_4,undefined1 param_5,
            undefined1 param_6,undefined4 param_7)

{
  undefined1 uVar1;
  
  if (((((param_3 != 0) && (param_2 != (int *)0x0)) && (*param_2 == 0)) &&
      ((param_2[1] == 0 && (param_2[2] == 0)))) && (param_2[3] == 0)) {
    param_2 = (int *)FUN_401174f8(param_7,param_3);
    if (param_2 == (int *)0x0) {
      return 0xfc;
    }
    if (((*param_2 == 0) && (param_2[1] == 0)) && ((param_2[2] == 0 && (param_2[3] == 0)))) {
      return 0xfc;
    }
  }
  memw();
  uVar1 = FUN_40117c04(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return uVar1;
}

