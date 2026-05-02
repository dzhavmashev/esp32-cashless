// Function : FUN_4010da34
// Address  : 0x4010da34
// Size     : 46 bytes


undefined1 FUN_4010da34(undefined4 param_1,int param_2,int param_3,char param_4)

{
  undefined1 uVar1;
  
  uVar1 = 0xf0;
  if (param_2 != 0) {
    if (param_3 == 0) {
      uVar1 = 0;
      if (param_4 == '\0') {
        uVar1 = FUN_4010da08(param_2);
      }
    }
    else {
      FUN_4010cddc(param_2,*(undefined2 *)(param_3 + 8));
      FUN_4010bb10(param_3);
      uVar1 = 0;
    }
  }
  return uVar1;
}

