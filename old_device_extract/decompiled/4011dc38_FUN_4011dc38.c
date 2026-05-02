// Function : FUN_4011dc38
// Address  : 0x4011dc38
// Size     : 39 bytes


undefined4
FUN_4011dc38(undefined4 param_1,undefined1 param_2,undefined2 param_3,undefined4 param_4,int param_5
            )

{
  undefined4 uVar1;
  
  if ((param_5 == 0) || (*(char *)(param_5 + 0x14) != '\x06')) {
    uVar1 = FUN_4011dbb4(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar1 = FUN_4011dbec();
  }
  return uVar1;
}

