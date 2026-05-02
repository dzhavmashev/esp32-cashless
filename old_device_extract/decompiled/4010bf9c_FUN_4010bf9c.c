// Function : FUN_4010bf9c
// Address  : 0x4010bf9c
// Size     : 26 bytes


undefined1 FUN_4010bf9c(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0xf0;
  if (param_2 != 0) {
    uVar1 = FUN_4010beb4(param_1,param_2,*(undefined2 *)(param_2 + 8),0);
  }
  return uVar1;
}

