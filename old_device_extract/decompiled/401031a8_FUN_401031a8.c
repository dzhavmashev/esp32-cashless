// Function : FUN_401031a8
// Address  : 0x401031a8
// Size     : 146 bytes


void FUN_401031a8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char *param_5
                 ,undefined2 param_6,undefined4 param_7,undefined4 param_8,int param_9)

{
  int iVar1;
  
  if ((((((*param_5 == '\0' && param_5[1] == '\0') && param_5[2] == '\0') && param_5[3] == '\0') &&
       param_5[4] == '\0') && param_5[5] == '\0') &&
     (((((*(char *)(param_1 + 0x23a) == '\0' && *(char *)(param_1 + 0x23b) == '\0') &&
        *(char *)(param_1 + 0x23c) == '\0') && *(char *)(param_1 + 0x23d) == '\0') &&
      *(char *)(param_1 + 0x23e) == '\0') && *(char *)(param_1 + 0x23f) == '\0')) {
    param_5 = (char *)(param_1 + 0x23a);
  }
  if (param_9 != 0) {
    memw();
    iVar1 = FUN_40106090(param_2,param_3,*(undefined4 *)(param_1 + 0x1f0),param_4,param_7,param_8,
                         param_9);
    if (iVar1 != 0) {
      return;
    }
  }
  FUN_40102d10(param_1,param_5,param_6,param_7,param_8);
  return;
}

